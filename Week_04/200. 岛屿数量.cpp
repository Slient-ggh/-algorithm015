#include <iostream>
#include"stdafx.h"
#include<vector>
using namespace std;

class Solution {
	void dfs(vector<vector<char>>& grid, int i, int j)
	{
		//左边界||上边界||       下边界     ||       右边界      ||       水         
		if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') return;
		//界内且是陆地，下次遍历前把相邻的所有岛沉掉
		grid[i][j] = '0';
		//下边的沉了
		dfs(grid, i + 1, j);
		//右边的沉了
		dfs(grid, i, j + 1);
		//上边的沉了
		dfs(grid, i - 1, j);
		//左边的沉了
		dfs(grid, i, j - 1);
	}
public:
	int numIslands(vector<vector<char>>& grid) {
		int res = 0;

		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == '1')
				{
					res++;
					dfs(grid, i, j);
				}
			}
		}
		return res;
	}
};

int main()
{
	Solution S;
	vector<vector<char>> grid = { {'1'} };
	int x = S.numIslands(grid);
}