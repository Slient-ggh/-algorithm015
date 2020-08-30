#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}
		int i = 0;
		int j = 1;
		while (j < nums.size())
		{
			if (nums[i] == nums[j])
			{
				j++;
			}
			else
			{
				nums[++i] = nums[j];
			}
		}
		return i + 1;
	}
};

int main()
{
	return 0;
}