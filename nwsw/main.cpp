#include <iostream>
#include <string>
#include <vector>

#include <fstream>

#include <unistd.h>
#include <string.h> 　
#include <limits.h>

#define MAX_SIZE (PATH_MAX+1)
using namespace std;

class Solution {
public:

	void NW(string s,string t) {
		int n = s.length();
		int m = t.length();

        vector< vector<int> > Matrix(m+1, vector<int>(n+1, 0));

        for(int i=0;i<=m;i++)
        {
            Matrix[i][0] = -2*i;
        }
        for(int i=0;i<=n;i++)
        {
            Matrix[0][i] = -2*i;
        }

        //printM(Matrix);
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                //cout << i << j <<endl;
                int x1,x2,x3;
                x1 = Matrix[i][j-1] - 2;
                //cout << x1;
                x2 = Matrix[i-1][j] - 2;
                //cout << x2;
                if(s[j-1] == t[i-1])
                {
                    x3 = Matrix[i-1][j-1] + 4;
                }
                else
                {
                    x3 = Matrix[i-1][j-1] - 2;
                }
                //cout << x1;
                //cout << i <<"  "<< j << x1 << "  " <<x2<<"  " << x3<<endl;
                Matrix[i][j] = maxoflist(x1,x2,x3);
//                int index = maxoflist(0,x1,x2,x3);
//                Status[i][j] = index;
            }
        }
        printM(Matrix);
	};


	void SW(string s,string t) {
		int n = s.length();
		int m = t.length();

        vector< vector<int> > Matrix(m+1, vector<int>(n+1, 0));
        vector< vector<int> > Status(m+1, vector<int>(n+1, 0));
        //printM(Matrix);
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                //cout << i << j <<endl;
                int x1,x2,x3;
                x1 = Matrix[i][j-1] - 2;
                //cout << x1;
                x2 = Matrix[i-1][j] - 2;
                //cout << x2;
                if(s[j-1] == t[i-1])
                {
                    x3 = Matrix[i-1][j-1] + 4;
                }
                else
                {
                    x3 = Matrix[i-1][j-1] - 2;
                }
                //cout << x1;
                //cout << i <<"  "<< j << x1 << "  " <<x2<<"  " << x3<<endl;
                Matrix[i][j] = maxoflist(0,x1,x2,x3);
//                int index = maxoflist(0,x1,x2,x3);
//                Status[i][j] = index;
            }
        }
        printM(Matrix);
	};

	void printM(vector< vector<int> > F)
	{
        unsigned int i,j;
        for(i=0;i<F.size();i++)
        {
            for(j=0;j<F[0].size();j++)
            {
                cout << F[i][j] << " ";
            }
            cout << endl;
        }
	}

	int maxoflist(int x,int x1,int x2,int x3=-99)
	{
        int f1 = max(x,x1);
        int f2 = max(x2,x3);
        if(f1>f2)
            return f1;
        else
            return f2;
	};

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

    Solution x;
    //x.SW("ATGCAGCTGCTT","CGTATAGCTACTG");
    x.NW(s,t);
    //Solution x("ATGCAGCTGCTT","CGTATAGCTACTG");
    return 0;
}
