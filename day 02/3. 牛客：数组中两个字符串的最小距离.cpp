// 牛客：数组中两个字符串的最小距离
// 链接：https://www.nowcoder.com/questionTerminal/2c6a0a8e1d20492f92941400036e0890

// 方法：小贪心/小DP

// 解题思路：每次只需要从当前位置开始，如果是两个目标字符串中的一个，就从左边（前面）开始找距离最近的另一个目标字符串，计算距离，更新最小距离。
// 使用两个变量 prev1 和 prev2 分别记录上一次出现 s1 和 s2 的位置（索引）。这种策略相当于 小贪心 + 滚动记录 的方式。
// 时间复杂度 O(n)，空间复杂度 O(1)。
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	string s1, s2, s;									// s1 和 s2 是要找的两个目标字符串，s 是临时变量用于读入字符串
	cin >> n >> s1 >> s2;

	int prev1 = -1, prev2 = -1, ret = 0x3f3f3f3f;		// 初始化 prev1 和 prev2 为 -1，ret 为一个较大的数
	for (int i = 0; i < n; i++)
	{
		cin >> s;

		if (s == s1)									// 当前字符串等于 s1
		{
			if (prev2 != -1)							// 如果前面已经出现过 s2
			{
				ret = min(ret, i - prev2);				// 更新最小距离（当前 s1 和上一个 s2 的距离）
			}
			prev1 = i;									// 更新 s1 的最新位置
		}
		else if (s == s2)								// 当前字符串等于 s2
		{
			if (prev1 != -1)							// 如果前面已经出现过 s1
			{
				ret = min(ret, i - prev1);				// 更新最小距离（当前 s2 和上一个 s1 的距离）
			}
			prev2 = i;									// 更新 s2 的最新位置
		}
	}

	if (ret == 0x3f3f3f3f)								// 如果最小距离没有被更新，说明其中一个字符串未出现
	{
		cout << -1;										// 输出 -1 表示无法计算距离
	}
	else
	{
		cout << ret;
	}

	return 0;
}