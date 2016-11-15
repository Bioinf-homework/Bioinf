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

		//边界设置

		for (int i = 0; i < Matrix.size(); i++)
		{
			Matrix[i][0] = i;
		}

		for (int j = 0; j < Matrix[0].size(); j++)
		{
			Matrix[0][j] = j;
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
				}
				else
				{
					Matrix[i][j] = min(Matrix[i - 1][j - 1], min(Matrix[i - 1][j], Matrix[i][j - 1])) + 1;
				}
			}
		}
		GetMatrix(Matrix);
		return Matrix[m][n];
	};
	void GetMatrix(vector<vector <int> > Matrix){

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
		strcat(buf,"/result.txt");
		ofstream file;
		file.open(buf);
		file.clear();

		file << "编辑距离为：\t" <<  Matrix[Matrix.size()-1][Matrix[0].size()-1] << endl;

		for (int i = 0; i < Matrix.size(); i++)
		{
			for (int j = 0; j < Matrix[0].size(); j++)
			{
				file << Matrix[i][j] << "\t";
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
	cout << s1.minDistance(s, t)<<endl;

	// system("pause");
	return 0;
}
