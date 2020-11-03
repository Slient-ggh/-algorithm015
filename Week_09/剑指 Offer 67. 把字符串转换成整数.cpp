#include"stdafx.h"
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int strToInt(string str) {
		string numstr = "";
		int num = 0;
		int i = 0;
		while (str[i] == ' ') i++;//去掉空格
		int flag = str[i] == '-' ? -1 : 1;//确定正负
		if (str[i] == '+' || str[i] == '-') i++;//略过符号
		while (str[i] == '0') i++;//去掉前面无用0
		while (str[i] >= '0'&&str[i] <= '9')//记录有效数字
		{
			numstr += str[i++];
		}
		int n = numstr.size() - 1;
		if (n == -1) return 0;
		if (n > 9 || (n == 9 && numstr[0] >= '3')) return flag == 1 ? INT_MAX : INT_MIN;
		char c[10] = {'0','0', '0', '0', '0', '0', '0', '0'};
		if (n == 9)
		{
			for (int j = 0; j <= n; j++)
			{
				c[j] = numstr[j];
			}
			if (strcmp(c, "2147483647") >= 0 && flag == 1) return INT_MAX;
			if (strcmp(c, "2147483648") >= 0 && flag == -1) return INT_MIN;
		}
		int j = 0;
		while (j <= n && flag == 1) 
			num = num * 10 + (numstr[j++] - '0');
		while (j <= n && flag == -1) 
			num = num * 10 - (numstr[j++] - '0');
		return num;
	}
};

//大神写法
class Solution {
public:
	int strToInt(string str) {
		int i = 0, flag = 1;
		int res = 0; //默认flag = 1，正数
		while (str[i] == ' ') i++;
		if (str[i] == '-') flag = -1;
		if (str[i] == '-' || str[i] == '+') i++;
		for (; i < str.size() && isdigit(str[i]); i++) {
			if (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] - '0' > 7)) //溢出判定
				return flag == 1 ? INT_MAX : INT_MIN;
			res = res * 10 + (str[i] - '0');
		}
		return flag * res;
	}
};

int main()
{
	Solution S;
	int res = S.strToInt("-2147483647");
}