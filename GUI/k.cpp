#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
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

const char* hello(const char* name)
{
	cout << "hello" << name << endl;
}

extern "C" {  
	void he(const char* name)
	{
		hello(name);
	}
    char * test(int i,int j)
    {
    	string x = K(i,j);
    	// const char *c=x.data();

	char* c;
	const int len = x.length();
	c = new char[len+1];
	strcpy(c,x.c_str());

    	// cout << "string is" <<x <<endl;
    	// cout  << "char * is"  << c <<endl;
    	return c;
    }
}  
// g++ -o libk.so -shared -fPIC k.cpp -w