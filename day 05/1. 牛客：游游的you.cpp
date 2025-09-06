// 牛客：游游的you
// 链接：https://www.nowcoder.com/questionTerminal/cd117803b3364b218a8b3dcc498dee25

// 方法：模拟 + 贪心
#include <iostream>
using namespace std;

int main()
{
	int q;
	cin >> q;

	while (q--)
	{
		int a, b, c, ret = 0;
		cin >> a >> b >> c;

		int cnt2 = min(a, min(b, c));
		b -= cnt2;

		if (b)
		{
			b--;
		}

		ret += 2 * cnt2 + b;
		cout << ret << endl;
	}

	return 0;
}



// 优解：
#include <iostream>
using namespace std;

int main()
{
	int q, a, b, c;
	cin >> q;

	while (q--)
	{
		cin >> a >> b >> c;
		int x = min(a, min(b, c));
		cout << (x * 2 + max(b - x - 1, 0)) << endl;
	}

	return 0;
}