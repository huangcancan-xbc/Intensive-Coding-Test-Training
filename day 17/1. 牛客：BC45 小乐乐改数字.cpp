// 牛客：BC45 小乐乐改数字
// 链接：https://www.nowcoder.com/practice/fcd30aac9c4f4028b23919a0c649824d?tpId=290&tqId=39833&ru=/exam/oj

// 处理字符串和整形在时空复杂度上各有优劣，字符串模拟的方法在时间复杂度上更优，但在空间复杂度上更差。整形的方法在时间复杂度上更差，但在空间复杂度上更优。

// 方法：字符串模拟
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '0' || s[i] == '2' || s[i] == '4' || s[i] == '6' || s[i] == '8')
		{
			s[i] = '0';
		}
		else
		{
			s[i] = '1';
		}
	}

	cout << stol(s) << endl;

	return 0;
}



// 使用整形进行读入和处理
#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;

	long long ret = 0, base = 1;

	while (n > 0)
	{
		int digit = n % 10;						// 取最低位
		int x = (digit % 2 == 0) ? 0 : 1;		// 判断奇偶
		ret += x * base;						// 按位构造新数
		base *= 10;
		n /= 10;
	}

	cout << ret << endl;
	return 0;
}