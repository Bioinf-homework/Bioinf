#include <iostream>
#include <string>
#include <vector>

#include <fstream>

#include <unistd.h>
#include <string.h> 　
#include <limits.h>

#define MAX_SIZE (PATH_MAX + 1)
using namespace std;

class Solution {
public:
    int DNAM[4][4] = { { 1, -5, -5, -1 }, { -5, 1, -1, -5 }, { -5, -1, 1, -5 }, { -1, -5, -5, 1 } };
    /* int AAM[20][20]; */

    int dnatoint( char a )
    {
        // cout << a;
        /* return 0; */
        if ( a == 'A' )
            return(0);
        if ( a == 'T' )
            return(1);
        if ( a == 'C' )
            return(2);
        if ( a == 'G' )
            return(3);
    }


    void NW( string s, string t )
    {
        int n   = s.length();
        int m   = t.length();

        vector< vector<int> >   Matrix( m + 1, vector<int>( n + 1, 0 ) );
        vector< vector<int> >   Status( m + 1, vector<int>( n + 1, 0 ) );

        for ( int i = 0; i <= m; i++ )
        {
            Matrix[i][0] = -2 * i;
            Status[i][0] = 2;
        }
        for ( int i = 0; i <= n; i++ )
        {
            Matrix[0][i] = -2 * i;
            Status[0][i] = 1;
        }

        /* printM(Matrix); */
        for ( int i = 1; i <= m; i++ )
        {
            for ( int j = 1; j <= n; j++ )
            {
                /* cout << i << j <<endl; */
                int x1, x2, x3;
                x1 = Matrix[i][j - 1] - 2;
                /* cout << x1; */
                x2 = Matrix[i - 1][j] - 2;
                /*
                 * cout << x2;
                 * cout << dnatoint(s[j-1]);
                 */
                int weigh = DNAM[dnatoint( s[j - 1] )][dnatoint( t[i - 1] )];
//                cout << weigh <<endl;
                x3 = Matrix[i - 1][j - 1] + weigh;
                if ( s[j - 1] == t[i - 1] )
                {
                    Status[i][j] = 0;
                }else  {
                    if ( Matrix[i - 1][j] <= Matrix[i][j - 1] && Matrix[i - 1][j - 1] + weigh <= Matrix[i][j - 1] - 2 )
                    {
                        Status[i][j] += 1;
                    }
                    if ( Matrix[i][j - 1] <= Matrix[i - 1][j] && Matrix[i - 1][j - 1] <= Matrix[i - 1][j] - 2 )
                    {
                        Status[i][j] += 2;
                    }
                    if ( Matrix[i][j - 1] - 2 <= Matrix[i - 1][j - 1] + weigh && Matrix[i - 1][j] - 2 <= Matrix[i - 1][j - 1] + weigh )
                    {
                        Status[i][j] += 4;
                    }
                }
               Matrix[i][j] = maxoflist( x1, x2, x3 );

            }
        }
        PrintPath( Matrix, Status ,s ,t);
        printM( Matrix, 1 );
        printM( Status, 3 );
    };


    void SW( string s, string t )
    {
        int n   = s.length();
        int m   = t.length();

        vector< vector<int> >   Matrix( m + 1, vector<int>( n + 1, 0 ) );
        vector< vector<int> >   Status( m + 1, vector<int>( n + 1, 0 ) );
        /* printM(Matrix); */
        for ( int i = 1; i <= m; i++ )
        {
            for ( int j = 1; j <= n; j++ )
            {
                /* cout << i << j <<endl; */
                int x1, x2, x3;
                x1 = Matrix[i][j - 1] - 2;
                /* cout << x1; */
                x2 = Matrix[i - 1][j] - 2;

                int weigh = DNAM[dnatoint( s[j - 1] )][dnatoint( t[i - 1] )];
                x3 = Matrix[i - 1][j - 1] + weigh;
                if ( s[j - 1] == t[i - 1] )
                {
                    Status[i][j] = 0;
                }else  {



                    if ( Matrix[i - 1][j] <= Matrix[i][j - 1] && Matrix[i - 1][j - 1] + weigh <= Matrix[i][j - 1] - 2 )
                    {
                        Status[i][j] += 1;
                    }
                    if ( Matrix[i][j - 1] <= Matrix[i - 1][j] && Matrix[i - 1][j - 1] <= Matrix[i - 1][j] - 2 )
                    {
                        Status[i][j] += 2;
                    }
                    if ( Matrix[i][j - 1] - 2 <= Matrix[i - 1][j - 1] + weigh && Matrix[i - 1][j] - 2 <= Matrix[i - 1][j - 1] + weigh )
                    {
                        Status[i][j] += 4;
                    }
                }

                Matrix[i][j] = maxoflist( 0, x1, x2, x3 );
                if (Matrix[i][j] == 0)
                {
                    Status[i][j] = 8;
                }
            }
        }
        PrintPath( Matrix, Status ,s ,t, 1);
        printM( Matrix, 2 );
        printM( Status, 3 );
    };


    void PrintPath( vector<vector <int> > Matrix, vector<vector <int> > Status ,string s , string t, int state=0)
    {
        char buf[MAX_SIZE];
       /* 获取当前程序绝对路径 */
       int cnt = readlink( "/proc/self/exe", buf, MAX_SIZE );
       if ( cnt < 0 || cnt >= MAX_SIZE )
       {
           /* printf("***Error***\n"); */
       }

       int i;
       for ( i = cnt; i >= 0; --i )
       {
           if ( buf[i] == '/' )
           {
               buf[i + 1] = '\0';
               break;
           }
       }
       strcat( buf, "/path.txt" );

        ofstream file;
        file.open(buf);
        file.clear();

        i   = Matrix.size() - 1;
        int j   = Matrix[0].size() - 1;
        int f   = Status[Matrix.size() - 1][Matrix[0].size() - 1];
        /* hui(Matrix,Status,i,j); */
        if (state == 1)
        {
            int maxflag = -1000;
            int tmpi,tmpj;
            for ( int i = 0; i < Matrix.size(); i++ )
            {
                for ( int j = 0; j < Matrix[0].size(); j++ )
                {
//                    cout <<Matrix[i][j] << "\t";
                    if ( Matrix[i][j] >= maxflag )
                    {
                        tmpi = i;
                        tmpj = j;
                        maxflag = Matrix[i][j];
                    }
                }
            }
            i = tmpi;
            j = tmpj;
            f   = Status[tmpi][tmpj];
        }


        vector<int> s1;
        vector<int> t1;

        while ( i != 0 && j != 0 )
        {

            file << "(" << i << "," << j << ")" << "->";
             s1.push_back(i);
             t1.push_back(j);
            if ( f == 4 || f == 0 || f == 7 || f == 6 || f == 5 )
            {
                i   -= 1;
                j   -= 1;
            }
            if ( f == 2 || f == 3 )
            {
                i -= 1;
            }
            if ( f == 1 )
            {
                j -= 1;
            }
            if ( f == 8 )
            {
                break;
            }
            f   = Status[i][j];

        }

        char buf2[MAX_SIZE];
       /* 获取当前程序绝对路径 */
       cnt = readlink( "/proc/self/exe", buf2, MAX_SIZE );
       if ( cnt < 0 || cnt >= MAX_SIZE )
       {
           /* printf("***Error***\n"); */
       }

       for ( i = cnt; i >= 0; --i )
       {
           if ( buf2[i] == '/' )
           {
               buf2[i + 1] = '\0';
               break;
           }
       }
       strcat( buf2, "/show.txt" );

        ofstream file2;
        file2.open(buf2);
        file2.clear();

        for (int x = s1.size() - 1; x >= 0; --x)
        {

            if (Status[s1[x]][t1[x]] == 4 ||Status[s1[x]][t1[x]] == 5|| Status[s1[x]][t1[x]] == 6 || Status[s1[x]][t1[x]] == 7)
            {
                file2 << s[t1[x]-1] << "XX";
                file2 << t[s1[x]-1] <<endl;
            }
            if (Status[s1[x]][t1[x]] == 0)
            {
                file2 << s[t1[x]-1] << "---";
                file2 << t[s1[x]-1] <<endl;
            }
            if (Status[s1[x]][t1[x]]  == 2 || Status[s1[x]][t1[x]]  == 3)
            {
                file2 << "\t";
                file2<< t[s1[x]-1] <<endl;
            }
            if (Status[s1[x]][t1[x]]  == 1)
            {
                file2 << s[t1[x]-1] << "\t";
                file2 << " "<<endl;
            }
        }
        file2.close();
    };


    void printM( vector< vector<int> > F, int type )
    {
       char buf[MAX_SIZE];
       /* 获取当前程序绝对路径 */
       int cnt = readlink( "/proc/self/exe", buf, MAX_SIZE );
       if ( cnt < 0 || cnt >= MAX_SIZE )
       {
           /* printf("***Error***\n"); */
       }
       /* 获取当前目录绝对路径，即去掉程序名 */
       int i;
       for ( i = cnt; i >= 0; --i )
       {
           if ( buf[i] == '/' )
           {
               buf[i + 1] = '\0';
               break;
           }
       }
        /* printf("current absolute path:%s\n", buf); */
        ofstream file;

        if ( type != 3 )
        {
            /* code */
           strcat( buf, "/result.txt" );
            // file.open( "result.txt"  );
        }else  {
           strcat( buf, "/status.txt" );
            // file.open( "status.txt"  );
        }
        /* strcat(buf,"/result.txt"); */

       file.open( buf );
        file.clear();

        /* file << F[F.size()-1][F[0].size()-1] << endl; */
        int maxflag = -1000;
        for ( int i = 0; i < F.size(); i++ )
        {
            for ( int j = 0; j < F[0].size(); j++ )
            {
                file << F[i][j] << "\t";
                if ( F[i][j] > maxflag )
                    maxflag = F[i][j];
            }
            file << endl;
        }
        if ( type == 1 )
        {
            file << "NW最大算法得分：\t";
            file << maxflag;
        }
        if ( type == 2 )
        {
            file << "SW最大算法得分：\t";
            file << maxflag;
        }
        file.close();
    }


    int maxoflist( int x, int x1, int x2, int x3 = -9999 )
    {
        int f1  = max( x, x1 );
        int f2  = max( x2, x3 );
        if ( f1 > f2 )
            return(f1);
        else
            return(f2);
    };
};


string Readaline( char* filename )
{
   char buf[MAX_SIZE];
   /* 获取当前程序绝对路径 */
   int cnt = readlink( "/proc/self/exe", buf, MAX_SIZE );
   if ( cnt < 0 || cnt >= MAX_SIZE )
   {
       /* printf("***Error***\n"); */
   }

   int i;
   for ( i = cnt; i >= 0; --i )
   {
       if ( buf[i] == '/' )
       {
           buf[i + 1] = '\0';
           break;
       }
   }
   strcat( buf, filename );

    string      data;
    ifstream    rfp;

    rfp.open( buf );
    rfp >> data;

    rfp.close();
    return(data);
};


int main()
{
    string s, t, c;
    s   = Readaline( "s.txt" );
    t   = Readaline( "t.txt" );
    c   = Readaline( "choice.txt" );


    Solution x;

    if ( c[0] == '1' )
    {
        x.NW( s, t );
    }else  {
        x.SW( s, t );
    }

    return(0);
}


