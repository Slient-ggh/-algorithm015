#include"stdafx.h"
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		//dp[i][j]=min(dp[i-1][j],dp[i-1][j-1],dp[i][j-1])+1 if matrix[i][j]==1&&i>1&&j>1
		int m = matrix.size();
		if (!m) return 0;
		int n = matrix[0].size(), res = 0;
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				if (matrix[i][j] == '0')
					continue;
				else if (i == 0 || j == 0)
					dp[i][j] = matrix[i][j] - '0';
				else
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
				res = max(res, dp[i][j]);
			}
		}
		return res*res;
	}
};