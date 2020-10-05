#include"stdafx.h"
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		//Ôö£ºdp[i][j]=dp[i][j-1]+1;É¾£ºdp[i][j]=dp[i-1][j]+1;¸Ä£ºdp[i][j]=dp[i-1][j-1]+1
		int m = word1.length(), n = word2.length();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 0; i<m + 1; i++)
		{
			for (int j = 0; j<n + 1; j++)
			{
				if (i == 0) dp[i][j] = j;
				else if (j == 0) dp[i][j] = i;
				else if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
				else dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
			}
		}
		return dp[m][n];
	}
};

int main()
{
	Solution S;
	string word1 = "horse", word2 = "ros";

	int x = S.minDistance(word1, word2);
}