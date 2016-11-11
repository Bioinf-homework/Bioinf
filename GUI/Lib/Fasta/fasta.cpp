#include <iostream>
#include <fstream>
#include <string>
//#include <string.h>
#include <vector>

#include <unistd.h>
#include <string.h> 　
#include <limits.h>

#define MAX_SIZE (PATH_MAX+1)
using namespace std;

class fasta
{
public:
	fasta(string s);
	int isset(char x);
	void GetFindlist();
	int match(string t);
	int maxofst(string t);
	int n;
	vector<char> key;
	vector< vector<int> > value;
private:
	
};

fasta::fasta(string s)
{
	n =s.length();
	//cout << n;
	for (int i = 0; i < n; i++)
	{
		int index = isset(s[i]);
		if (index != -1)
		{
			value[index].push_back(i);
		}
		else
		{
			//新的key
			key.push_back(s[i]);
			vector<int> start_index(1,i);
			value.push_back(start_index);
		}
	}
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
	strcat(buf,"/file.txt");
	// 清空输出文件
	ofstream file;
	file.open(buf);
	file.clear();
	file.close();
}

int fasta::isset(char x)
{
	vector<char>::iterator t;
	int i=0;
	for (t = key.begin(); t != key.end(); t++,i++)
	{
		if (*t == x)
		{
			return i;
		}
	}
	return -1;
}
void fasta::GetFindlist()
{
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
	strcat(buf,"/findlist.txt");
	ofstream file;
	file.open(buf);
	file.clear();

	vector<char>::iterator t;
	int t2;
	for (t = key.begin(),t2 = 0; t != key.end(); t++, t2++)
	{
		file << *t << " ";
		for (int i = 0; i < value[t2].size(); i++)
		{
			file << value[t2][i] << " ";
		}
		file << endl;
	}
}

int fasta::maxofst(string t)
{
	if (t.length() < n)
	{
		return n;
	}
	else
	{
		return t.length();
	}
}

int fasta::match(string t)
{
	//int arrsize = maxofst(t);
	//cout << "位移表长：" << arrsize << endl;
	vector<int > result(t.length() + n);
	for (int i = 0; i < t.length(); i++)
	{
		int index = isset(t[i]);
		//cout << t[i];
		// 字母不存在 -1
		if (index == -1)
		{
			continue;
		}
		else
		{
			// 在查找表中有的值，计算距离。
			vector<int>::iterator t1;
			for (t1 = value[index].begin(); t1 != value[index].end(); t1++)
			{
				int r = *t1 - i;
				result[t.length() + r]++;
			}
		}
	}

	vector<int>::iterator t2;
	int max = 0, maxindex;
	int index = t.length();
	index = -index-1;
	for (t2 = result.begin(); t2 != result.end(); t2++)
	{
		//cout << *t2 << " ";
		index++;
		if (*t2 > max)
		{
			maxindex = index;
			max = *t2;
		}

	}

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
	// cout << buf << endl;

	ofstream file;
	// 追加写
	strcat(buf,"/file.txt");
	file.open(buf, ios::app);

	//file << "Hello file/n" << 75;
	file << "最大匹配位移" << "\t" << maxindex << "\t"<<"次数" << max << endl;

	file.close();

	cout << "最大匹配位移" << "\t" << maxindex << "\t"<<"次数" << max << endl;
	return 0;
}

vector<string> Readlines(char* filename)
{
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
	strcat(buf,filename);
	cout << buf << endl;

	vector<string> data;
	ifstream rfp;
	
	rfp.open(buf);
	while (!rfp.eof())
	{
		string tmp;
		rfp >> tmp;
		data.push_back(tmp);
		//cout << data <<endl;
	}

	rfp.close();
	return data;
};

string Readaline(char* filename)
{
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
	strcat(buf,filename);
	cout << buf << endl;

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

	string s;
	s = Readaline("s.txt");
	// cout << s;

	fasta x(s);
	x.GetFindlist();

	vector<string> data;

	data = Readlines("data.txt");

	vector<string>::iterator t2;

	for (t2 = data.begin(); t2 != data.end(); t2++)
	{
		x.match(*t2);
		cout << endl;
	}

	return 0;
}

