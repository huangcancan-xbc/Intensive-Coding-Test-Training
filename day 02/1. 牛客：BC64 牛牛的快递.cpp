// 牛客：BC64 牛牛的快递
// 链接：https://www.nowcoder.com/practice/41b42e7b3c3547e3acf8e90c41d98270?tpId=290&tqId=39852&ru=/exam/oj
// https://www.nowcoder.com/practice/41b42e7b3c3547e3acf8e90c41d98270


// 方法：模拟
#include <iostream>
using namespace std;

int main()
{
	double a;
	char b;
	cin >> a >> b;

	int ret = 0;

	if (a <= 1)
	{
		ret += 20;
	}
	else
	{
		if (a == (int)a)
		{
			ret += 20 + a - 1;
		}
		else
		{
			ret += 20 + a;
		}
	}

	if (b == 'y')
	{
		cout << ret + 5;
	}
	else
	{
		cout << ret;
	}

	return 0;
}




#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a;
	char b;
	cin >> a >> b;

	int ret = 0;

	if (a <= 1)
	{
		ret += 20;
	}
	else
	{
		ret += 20;
		a -= 1;
		ret += ceil(a);
	}

	if (b == 'y')
	{
		ret += 5;
	}

	cout << ret;

	return 0;
}



#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a;
	char b;
	cin >> a >> b;

	int ret = 0;

	if (a <= 1)
	{
		ret += 20;
	}
	else
	{
		ret += 20;
		double c = a - 1;
		if (c - (int)c > 0)
		{
			ret += (int)c + 1;
		}
		else
		{
			ret += (int)c;
		}
	}

	if (b == 'y')
	{
		ret += 5;
	}

	cout << ret;

	return 0;
}