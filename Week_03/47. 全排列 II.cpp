#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	/* 参数说明:
	* depth: 表示当前的深度
	* perm: 当前的组合
	* nums: 给定的数组
	* used: 使用情况
	*/
	void generate(int depth, vector<int>&perm, vector<int>& nums, vector<bool>& used, vector<vector<int>>& res) {
		//递归结束条件：深度见底
		if (depth == nums.size())
		{
			res.push_back(perm);
			return;
		}
		// 主逻辑
		// 做选择
		for (int i = 0; i < nums.size(); i++)
		{
			// 当前数字没有被使用, 没有用过是false
			if (used[i]) continue;
			//去重
			if (i> 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

			used[i] = true;
			perm[depth] = nums[i];
			//递归开始
			generate(depth + 1, perm, nums, used, res);
			//重置状态（回溯）
			used[i] = false;
		}
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		
		sort(nums.begin(), nums.end());
		//输出结果
		vector<vector<int>> res;
		//表示使用状态
		vector<bool> used(nums.size(), false);
		//当前的组合
		vector<int> perm(nums.size());
		//进行去重全排列
		generate(0, perm, nums, used, res);

		return res;
	}

};