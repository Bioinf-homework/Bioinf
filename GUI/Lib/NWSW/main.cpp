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
        cout << a;
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
            Status[i][0] = 1;
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
                /*
                 * x3 = 0;
                 * cout << x1;
                 */
                cout << i << "  " << j << x1 << "  " << x2 << "  " << x3 << " " << weigh << endl;
                Matrix[i][j] = maxoflist( x1, x2, x3 );

/*
 *                int index = maxoflist(0,x1,x2,x3);
 *                Status[i][j] = index;
 */
            }
        }
        PrintPath( Matrix, Status );
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
                /*
                 * cout << x2;
                 * cout << dnatoint(s[j-1]);
                 */
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
                /*
                 * cout << x1;
                 * cout << i <<"  "<< j << x1 << "  " <<x2<<"  " << x3<<endl;
                 */
                Matrix[i][j] = maxoflist( 0, x1, x2, x3 );
/*
 *                int index = maxoflist(0,x1,x2,x3);
 *                Status[i][j] = index;
 */
            }
        }
        PrintPath( Matrix, Status );
        printM( Matrix, 2 );
        printM( Status, 3 );
    };


    void PrintPath( vector<vector <int> > Matrix, vector<vector <int> > Status )
    {
        // printM( Status, 3 );
        char buf[MAX_SIZE];
        /* 获取当前程序绝对路径 */
        int cnt = readlink( "/proc/self/exe", buf, MAX_SIZE );
        if ( cnt < 0 || cnt >= MAX_SIZE )
        {
            /* printf("***Error***\n"); */
        }
        /* 获取当前目录绝对路径，即去掉程序名 */
        for ( int i = cnt; i >= 0; --i )
        {
            if ( buf[i] == '/' )
            {
                buf[i + 1] = '\0';
                break;
            }
        }
        /* printf("current absolute path:%s\n", buf); */
        strcat( buf, "path.txt" );
        ofstream file;
        file.open( buf );
        file.clear();
        int i   = Matrix.size() - 1;
        int j   = Matrix[0].size() - 1;
        int f   = Status[Matrix.size() - 1][Matrix[0].size() - 1];
        /* hui(Matrix,Status,i,j); */
        file << "(" << i << "," << j << ")" << "->";
        while ( i != 0 && j != 0 )
        {
            cout << i << "," << j  << " " << f << endl;
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
            f   = Status[i][j];
            file << "(" << i << "," << j << ")" << "->";
            /* file << "(" << i << "," << j << "):" << Matrix[i][j] << endl; */
        }
        // file << "(0,0)";
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
        if ( type != 3 )
        {
            /* code */
            strcat( buf, "/result.txt" );
        }else  {
            strcat( buf, "/status.txt" );
        }
        /* strcat(buf,"/result.txt"); */
        ofstream file;
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
    strcat( buf, filename );
    /* cout << buf << endl; */

    string      data;
    ifstream    rfp;

    rfp.open( buf );
    rfp >> data;
    /* cout << data << endl; */
    rfp.close();
    return(data);
};


int main()
{
    string s, t, c;
    s   = Readaline( "s.txt" );
    t   = Readaline( "t.txt" );
    c   = Readaline( "choice.txt" );

    /* cout << c <<endl; */

    Solution x;
    /* x.loadMM(); */
    // cout << x.DNAM[0][0];

    
    if ( c[0] == '1' )
    {
        x.NW( s, t );
    }else  {
        x.SW( s, t );
    }

    // x.NW( s, t );
    /* Solution x("ATGCAGCTGCTT","CGTATAGCTACTG"); */
    return(0);
}


