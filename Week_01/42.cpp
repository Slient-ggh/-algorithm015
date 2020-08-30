#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		
		if (height.size() <= 2)
		{
			return 0;
		}
		if (height.size() == 3)
		{
			if (height[0] <= height[1])
			{
				return 0;
			}
			int min = height[0] < height[2] ? height[0] : height[2];
			if (min > height[1])
			{
				return min - height[1];
			}
			else
			{
				return 0;
			}
		}

		int max = 0;
		int maxIndex = 0;
		for (int i = 0; i < height.size(); i++) 
		{
			if (height[i] > max) 
			{
				max = height[i];
				maxIndex = i;
			}
		}

		int res = 0;
		int b = 0;
		for (int a = 0; a <= maxIndex; a++) 
		{
			if (height[a] < height[b]) 
			{
				res = res + (height[b] - height[a]);
			}
			else
			{
				b = a;
			}
		}
		b = height.size() - 1;
		for (int a = height.size() - 1; a >= maxIndex; a--) 
		{
			if (height[a] < height[b]) 
			{
				res = res + (height[b] - height[a]);
			}
			if (height[a] > height[b]) 
			{
				b = a;
			}
		}
		return res;
	}
};

int main()
{
	Solution A;
	vector<int> b;
	int a[] = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	for (int i = 0; i < 12; i++)
	{
		b.push_back(a[i]);
	}
	int c = A.trap(b);
	return 0;
}
