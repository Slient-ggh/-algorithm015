#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	/* ����˵��:
	* depth: ��ʾ��ǰ�����
	* perm: ��ǰ�����
	* nums: ����������
	* used: ʹ�����
	*/
	void generate(int depth, vector<int>&perm, vector<int>& nums, vector<bool>& used, vector<vector<int>>& res) {
		//�ݹ������������ȼ���
		if (depth == nums.size())
		{
			res.push_back(perm);
			return;
		}
		// ���߼�
		// ��ѡ��
		for (int i = 0; i < nums.size(); i++)
		{
			// ��ǰ����û�б�ʹ��, û���ù���false
			if (used[i]) continue;
			//ȥ��
			if (i> 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

			used[i] = true;
			perm[depth] = nums[i];
			//�ݹ鿪ʼ
			generate(depth + 1, perm, nums, used, res);
			//����״̬�����ݣ�
			used[i] = false;
		}
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		
		sort(nums.begin(), nums.end());
		//������
		vector<vector<int>> res;
		//��ʾʹ��״̬
		vector<bool> used(nums.size(), false);
		//��ǰ�����
		vector<int> perm(nums.size());
		//����ȥ��ȫ����
		generate(0, perm, nums, used, res);

		return res;
	}

};