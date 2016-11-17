#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include <unistd.h>
#include <string.h> 　
#include <limits.h>

#define MAX_SIZE (PATH_MAX+1)
using namespace std;
// leetcode 72
class Solution {
public:
	int minDistance(string word1, string word2) {
		int n, m;
		n = word1.length();
		m = word2.length();

		vector< vector<int> > Matrix(m+1, vector<int>(n+1, 0));
		vector< vector<int> > Status(m+1, vector<int>(n+1, 0));
		//边界设置

		for (int i = 0; i < Matrix.size(); i++)
		{
			Matrix[i][0] = i;
			Status[i][0] = 2;
		}

		for (int j = 0; j < Matrix[0].size(); j++)
		{
			Matrix[0][j] = j;
			Status[0][j] = 1;
		}
		//GetMatrix(Matrix);
		for (int i = 1; i < Matrix.size(); i++)
		{
			for (int j = 1; j < Matrix[0].size(); j++)
			{
				// 状态转移..
				if (word1[j-1] == word2[i-1])
				{
					Matrix[i][j] = Matrix[i - 1][j - 1];
					Status[i][j] = 0;
				}
				else
				{
                    // 1,2,4  3,5,6,7

				    if (Matrix[i - 1][j] >= Matrix[i][j - 1] && Matrix[i - 1][j-1] >= Matrix[i][j - 1] )
                    {
//                        cout  <<  i <<"\t" <<j << endl;
//                        cout << Matrix[i - 1][j] << "\t" <<Matrix[i][j - 1]<< "\t"  <<Matrix[i - 1][j-1] <<endl;
                        Status[i][j] += 1;
                    }
                    if (Matrix[i][j - 1]>=Matrix[i - 1][j] && Matrix[i - 1][j-1] >= Matrix[i - 1][j] )
                    {
                        Status[i][j] += 2;
                    }
                    if (Matrix[i][j - 1]>=Matrix[i - 1][j-1] && Matrix[i - 1][j] >= Matrix[i - 1][j-1] )
                    {
                        Status[i][j] += 4;
                    }

                    Matrix[i][j] = min(Matrix[i - 1][j - 1], min(Matrix[i - 1][j], Matrix[i][j - 1])) + 1;
				}
			}
		}
		GetMatrix(Matrix,1);
		GetMatrix(Status,2);
		PrintPath(Matrix,Status);
		return Matrix[m][n];
	};
	void PrintPath(vector<vector <int> > Matrix,vector<vector <int> > Status)
	    {
	    	char buf[MAX_SIZE];
		//获取当前程序绝对路径
		int cnt = readlink("/proc/self/exe", buf, MAX_SIZE);
		if (cnt < 0 || cnt >= MAX_SIZE)
		{
		    // printf("***Error***\n");
		}
		//获取当前目录绝对路径，即去掉程序名
		int i;
		for (i = cnt; i >=0; --i)
		{
		    if (buf[i] == '/')
		    {
		        buf[i+1] = '\0';
		        break;
		    }
		}
		// printf("current absolute path:%s\n", buf);
		strcat(buf,"path.txt");
		ofstream file;
		file.open(buf);
		file.clear();
	        int i = Matrix.size()-1;
	        int j = Matrix[0].size()-1;
	        int f = Status[Matrix.size()-1][Matrix[0].size()-1];
	        // hui(Matrix,Status,i,j);
	        file << "(" << i << "," << j << "):" << Matrix[i][j] << endl;
	        while (i!=0&&j!=0)
	        {

	            if (f==4||f==0||f==7||f==6||f==5)
	            {
	                i -= 1;
	                j -= 1;
	            }
	            if (f==2||f==3)
	            {
	                i-=1;
	            }
	            if (f==1)
	            {
	                j-=1;
	            }

	            file << "(" << i << "," << j << "):" << Matrix[i][j] << endl;
	        }

	    };
	void GetMatrix(vector<vector <int> > Matrix,int type){

		char buf[MAX_SIZE];
		//获取当前程序绝对路径
		int cnt = readlink("/proc/self/exe", buf, MAX_SIZE);
		if (cnt < 0 || cnt >= MAX_SIZE)
		{
		    printf("***Error***\n");
		
		}
		//获取当前目录绝对路径，即去掉程序名
		int i;
		for (i = cnt; i >=0; --i)
		{
		    if (buf[i] == '/')
		    {
		        buf[i+1] = '\0';
		        break;
		    }
		}
		// printf("current absolute path:%s\n", buf);
		if (type == 1)
		{
			strcat(buf,"/result.txt");
		}
		else
		{
			strcat(buf,"/status.txt");
		}
		
		ofstream file;
		file.open(buf);
		file.clear();
		if (type == 1)
		{
			file << "编辑距离为：\t" <<  Matrix[Matrix.size()-1][Matrix[0].size()-1] << endl;
		}

		for (int i = 0; i < Matrix.size(); i++)
		{
			for (int j = 0; j < Matrix[0].size(); j++)
			{
				file << Matrix[i][j]<< "\t";;
			}
			file << endl;
		}
	}

};


string Readaline(char* filename)
{
	char buf[MAX_SIZE];
	//获取当前程序绝对路径
	int cnt = readlink("/proc/self/exe", buf, MAX_SIZE);
	if (cnt < 0 || cnt >= MAX_SIZE)
	{
	    // printf("***Error***\n");
	}
	//获取当前目录绝对路径，即去掉程序名
	int i;
	for (i = cnt; i >=0; --i)
	{
	    if (buf[i] == '/')
	    {
	        buf[i+1] = '\0';
	        break;
	    }
	}
	// printf("current absolute path:%s\n", buf);
	strcat(buf,filename);
	// cout << buf << endl;

	string data;
	ifstream rfp;
	
	rfp.open(buf);
	rfp >> data;
	//cout << data << endl;
	rfp.close();
	return data;
};


int main()
{
	string s,t;
	s = Readaline("s.txt");
	t = Readaline("t.txt");

	Solution s1;
	 s1.minDistance(s,t);
	// cout << s1.minDistance("AACDA","ADF")<<endl;

	// system("pause");
	return 0;
}
