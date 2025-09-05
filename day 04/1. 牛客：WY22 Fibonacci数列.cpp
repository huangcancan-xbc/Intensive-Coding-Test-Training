// 牛客：WY22 Fibonacci数列
// 链接：https://www.nowcoder.com/practice/18ecd0ecf5ef4fe9ba3f17f8d00d2d66?tpId=122&tqId=33668&ru=/exam/oj

// 方法：模拟
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>
using namespace std;

int main()
{
	long long n, ret = INT_MAX;
	cin >> n;

	vector<long long> v(40);
	v[0] = 0, v[1] = 1;
	for (int i = 2; i < 40; i++)
	{
		v[i] = v[i - 1] + v[i - 2];
		if (n == v[i])
		{
			cout << 0;
			return 0;
		}
		else
		{
			ret = min(ret, abs(n - v[i]));
		}
	}

	cout << ret << endl;

	return 0;
}



// 优解：滚动数组：让 n 处于 b 和 c 之间，然后计算 n 与 b、c 之间的距离，取最小值即可。
#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;

	int a = 0, b = 1, c = 1;
	while (n > c)
	{
		a = b;
		b = c;
		c = a + b;
	}

	cout << min(c - n, n - b) << endl;

	return 0;
}