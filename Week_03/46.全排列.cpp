#include"stdafx.h"
#include<vector>
using namespace std;

vector<vector<int>> backTrack(vector<vector<int>>& res, vector<int> s, int first, int len)
{
	if (first == len)
	{
		res.emplace_back(s);
		return res;
	}

	for (int i = first; i < len; i++)
	{
		swap(s[i], s[first]);
		backTrack(res, s, first + 1, len);
		swap(s[i], s[first]);
	}

	return res;
}
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> Res;
		backTrack(Res, nums, 0, nums.size());
		return Res;
	}
};
int main()
{

	return 0;
}