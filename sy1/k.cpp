#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string Readaline(char* filename)
{
    string data;
    ifstream rfp;
	rfp.open(filename);
	rfp >> data;
	rfp.close();
    return data;
};

string K(int from,int to)
{
    string data = Readaline("data.txt");
    int len = data.length();
	string sub;
	try
	{
		if ((from) > (to) || (from) < 0 || (from) > len || (to) > len || (to) < 0)
		{
			sub = "mdzz";
		}
		else
		{
			if (from == 0&&to == 0)
			{
				sub = "mdzz";
			}
			else if (from == 0)//ֻ��j�������ȡ��׺
			{
				sub = data.substr(data.length() - (to));
			}
			else if (to == 0)//ֻ��i�������ȡǰ׺
			{
				sub = data.substr(0, (from));
			}
			else//
			{
				sub = data.substr((from), (to) - (from));

			}
		}
	}
	catch (char *str)
	{
		sub = "��Ҫ������";
	}
	return sub;
};

int main()
{

    cout << K(0,3);
    return 0;
}
