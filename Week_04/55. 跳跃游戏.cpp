#include "stdafx.h"
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size() - 1;
		int k = 0;//可到达最远位置下标
		for (int i = 0; i <= n; i++)
		{
			if (i > k) return false;
			k = max(k, i + nums[i]);
		}
		return true;
	}
};
int main()
{
	vector<int> nums = { 0,2,3 };
	Solution S;
	bool res = S.canJump(nums);
	return 0;
}