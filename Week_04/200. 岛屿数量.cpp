#include <iostream>
#include"stdafx.h"
#include<vector>
using namespace std;

class Solution {
	void dfs(vector<vector<char>>& grid, int i, int j)
	{
		//��߽�||�ϱ߽�||       �±߽�     ||       �ұ߽�      ||       ˮ         
		if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') return;
		//��������½�أ��´α���ǰ�����ڵ����е�����
		grid[i][j] = '0';
		//�±ߵĳ���
		dfs(grid, i + 1, j);
		//�ұߵĳ���
		dfs(grid, i, j + 1);
		//�ϱߵĳ���
		dfs(grid, i - 1, j);
		//��ߵĳ���
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