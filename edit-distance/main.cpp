#include <iostream>
#include <vector>
#include <string>

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
		for (int i = 0; i < Matrix.size(); i++)
		{
			for (int j = 0; j < Matrix[0].size(); j++)
			{
				cout << Matrix[i][j];
			}
			cout << endl;
		}
	}

};


int main()
{
	Solution s1;
	cout << s1.minDistance("AACDA","ADF")<<endl;

	// system("pause");
	return 0;
}
