#include"stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int size = s.length();
		vector<int> dp(size, 0);
		int maxVal = 0;
		for (int i = 1; i < size; i++)
		{
			if (s[i] == ')')
			{
				if (s[i - 1] == '(')
				{
					dp[i] = 2;
					if (i - 2 >= 0)
						dp[i] += dp[i - 2];
				}
				else if (dp[i - 1] > 0)
				{
					if ((i - 1 - dp[i - 1]) >= 0 && s[i - 1 - dp[i - 1]] == '(')
					{
						dp[i] = dp[i - 1] + 2;
						if ((i - 2 - dp[i - 1]) >= 0)
							dp[i] += dp[i - 2 - dp[i - 1]];
					}
				}
			}
			maxVal = max(maxVal, dp[i]);
		}
		return maxVal;
	}
};
int main()
{
	string s = "(())()()))";
	Solution S;
	int x = S.longestValidParentheses(s);
	return 0;
}