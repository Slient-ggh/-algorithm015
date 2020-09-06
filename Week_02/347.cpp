//ǰk����ƵԪ��
#include"stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>
using namespace std;
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> map;//first:������ݣ�second������
		for (int i : nums) 
			map[i] ++; //����
		priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q; //��С��
		for (auto it : map)
		{
			if (q.size() == k)
			{ //��������
				if (it.second > q.top().first) 
				{ //����
					q.pop();
					q.push(make_pair(it.second, it.first));
				}
			}
			else 
				q.push(make_pair(it.second, it.first));
		}
		vector<int> res;
		while (q.size()) 
		{ //�����ȶ�����k����ƵԪ�ش���vector
			res.push_back(q.top().second);
			q.pop();
		}
		return vector<int>(res.rbegin(), res.rend());
	}
};
//leetcode-cn.com/problems/top-k-frequent-elements/solution/cjian-ji-dai-ma-by-orangeman-5/

int main()
{
	Solution S;
	vector<int> n = { 5,5,8,6,3,7,1,2,8,6,4,9,1,3,4,7,8,5,2,1,9,1,1 };
	vector<int> res;
	res = S.topKFrequent(n, 4);
	return 0;
}