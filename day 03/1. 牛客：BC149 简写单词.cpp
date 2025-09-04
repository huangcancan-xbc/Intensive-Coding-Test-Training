// 牛客：BC149 简写单词
// 链接：https://www.nowcoder.com/practice/0cfa856bf0d649b88f6260d878f35bb4?tpId=290&tqId=39937&ru=/exam/oj

// 方法：字符串模拟
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	getline(cin, s);

	string ret;
	ret += s[0];
	if (ret[0] >= 'a' && ret[0] <= 'z')
	{
		ret[0] -= 32;
	}

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			i++;
			if (s[i] >= 'a' && s[i] <= 'z')
			{
				ret += s[i] - 32;
			}
			else
			{
				ret += s[i];
			}
		}
	}

	cout << ret << endl;

	return 0;
}



// 优解：
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	while (cin >> s)						// 会自动跳过空格
	{
		if (s[0] >= 'a' && s[0] <= 'z')
		{
			cout << (char)(s[0] - 32);		// 转换为大写字母，注意类型转换
		}
		else
		{
			cout << s[0];
		}
	}

	return 0;
}