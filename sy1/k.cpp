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
        if(from > len || to > len || from < -2|| to <-2)
        {
            sub = "mdzz";
        }
        else
        {
			if (from == -1&&to == -1)
			{
				sub = "mdzz";
			}
			else if (from == -1)//只有j的情况，取后缀
			{
				sub = data.substr(data.length() - (to));
			}
			else if (to == -1)//只有i的情况，取前缀
			{
				sub = data.substr(0, (from));
			}
			else{
                if (from > to) {
                    sub = "mdzz";
                }
                else{
                    sub = data.substr((from), (to) - (from));
                }
			}
        }

	}
	catch (char *str)
	{
		sub = "不要搞事情";
	}
	return sub;
};
int main()
{
// asdfghjkwertyuio

cout << K(1,3) <<endl;
cout << K(5,3) <<endl;
cout << K(-1,200) <<endl;
 cout << K(-1,3)<<endl;
    cout << K(3,-1)<<endl;
    return 0;
}
