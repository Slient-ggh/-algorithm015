//49.³óÊý
#include "stdafx.h"
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int nthUglyNumber(int n) {
		
		//³¬Ê±
		//int num = 0;
		//int tmp;
		//int i;
		//while (num < n)
		//{
		//	tmp = i;
		//	if (!(tmp % 5) || !(tmp % 3) || !(tmp % 2))
		//	{
		//		while (tmp % 5 == 0) tmp /= 5;
		//		while (tmp % 3 == 0) tmp /= 3;
		//		while (tmp % 2 == 0) tmp /= 2;
		//	}				
		//	if (tmp == 1) num++;
		//	i++;
		//}
		//return num;


		vector<int> dp(n + 1, 1);
		int a2 = 0;
		int a3 = 0;
		int a5 = 0;
		int i = 1;
		int t;
		while (i < n)
		{
			dp[i] = 2 * dp[a2] < 3 * dp[a3] ? 2 * dp[a2] : 3 * dp[a3];
			if (dp[i] > 5 * dp[a5]) dp[i] = 5 * dp[a5];
			if (dp[i] == 2 * dp[a2])a2++;
			if (dp[i] == 3 * dp[a3])a3++;
			if (dp[i] == 5 * dp[a5])a5++;
			i++;
		}
		return dp[i - 1];
	}
};
int main()
{
	Solution S;
	int n = S.nthUglyNumber(10);
	return 0;
}