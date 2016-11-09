// fasta.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <string>
//#include <string.h>
#include <vector>


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

	// 清空输出文件
	ofstream file;
	file.open("file.txt");
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
	vector<char>::iterator t;
	int t2;
	for (t = key.begin(),t2 = 0; t != key.end(); t++, t2++)
	{
		cout << *t << " ";
		for (int i = 0; i < value[t2].size(); i++)
		{
			cout << value[t2][i] << " ";
		}
		cout << endl;
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

	ofstream file;
	// 追加写
	file.open("file.txt", ios::app);

	//file << "Hello file/n" << 75;
	file << "最大位移量" << "\t" << maxindex << "\t" << max << endl;

	file.close();

	cout << "最大位移量" << "\t" << maxindex << "\t" << max << endl;
	return 0;
}

vector<string> Readlines(char* filename)
{
	vector<string> data;
	ifstream rfp;
	rfp.open(filename);
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
	string data;
	ifstream rfp;
	rfp.open(filename);
	rfp >> data;
	//cout << data << endl;
	rfp.close();
	return data;
};

int _tmain(int argc, _TCHAR* argv[])
{
	string s;
	s = Readaline("s.txt");
	//s = "HARFYAAQIVL";
	//cout << s;

	//string t = "A";
	//string t = Readaline("data.txt");
	
	fasta x(s);
	x.GetFindlist();

	//x.match(t);

	

	vector<string> data;

	data = Readlines("data.txt");

	//
	vector<string>::iterator t2;

	for (t2 = data.begin(); t2 != data.end(); t2++)
	{
		//cout << *t2 << endl;
		x.match(*t2);
		cout << endl;
	}

	system("pause");
	return 0;
}

