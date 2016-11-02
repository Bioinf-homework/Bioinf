
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class fasta
{
public:
	fasta(string s);
	~fasta();
	int isset(char x);
	void GetFindlist();
	int match(string t);
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

int fasta::match(string t)
{
	vector<int > result(2*n);
	for (int i = 0; i < t.length(); i++)
	{
		int index = isset(t[i]);
		if (index == -1)
		{
			continue;
		}
		else
		{
			// 在查找表中有的值，计算距离。
			vector<int>::iterator t;

			for (t = value[index].begin(); t != value[index].end(); t++)
			{
				//cout << *t << " ";
				int r = *t - i;
				result[n+r]++;
				//cout << r;
			}
			
			//value[index].begin();
			//result.push_back()
		}
	}

	vector<int>::iterator t2;

	for (t2 = result.begin(); t2 != result.end(); t2++)
	{
		cout << *t2 << " ";
	}
	return 0;
}

fasta::~fasta()
{
}

int _tmain(int argc, _TCHAR* argv[])
{
	string s;
	s = "HARFYAAQIVL";
	//string t = "A";
	string t = "VDMAAQIA";
	
	fasta x(s);
	x.GetFindlist();

	x.match(t);

	system("pause");
	
	return 0;
}

