// 牛客：HJ63 DNA序列
// 链接：https://www.nowcoder.com/practice/e8480ed7501640709354db1cc4ffd42a?tpId=37&tqId=21286&ru=/exam/oj

// 方法：滑动窗口
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int n, ret = 0, start = 0, count = 0;
	cin >> s >> n;

	for (int left = 0, right = 0; right < s.size(); right++)
	{
		if (s[right] == 'G' || s[right] == 'C')
		{
			count++;
		}

		if (right - left + 1 > n)
		{
			if (s[left] == 'G' || s[left] == 'C')
			{
				count--;
			}
			left++;
		}
		
		if (count > ret)
		{
			start = left;
			ret = count;
		}
	}

	cout << s.substr(start, n) << endl;

	return 0;
}



// 或者：
#include <iostream>
#include <string>
using namespace std;

string s;
int x;

int main()
{
	cin >> s >> x;

	int begin = -1;					// 标记结果的起始位置
	int maxCount = 0;				// 存储之前的窗口里面 C + G 的个数
	int count = 0;					// 统计窗口内 C + G
	int left = 0, right = 0, n = s.size();

	while (right < n)
	{
		if (s[right] == 'C' || s[right] == 'G')
		{
			count++;
		}

		while (right - left + 1 > x)
		{
			if (s[left] == 'C' || s[left] == 'G')
			{
				count--;
			}
			left++;
		}

		if (right - left + 1 == x)
		{
			if (count > maxCount)
			{
				begin = left;
				maxCount = count;
			}
		}

		right++;
	}

	cout << s.substr(begin, x) << endl;

	return 0;
}