// 牛客：除2！
// 链接：https://ac.nowcoder.com/acm/problem/213140

// 方法：堆 + 贪心
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	long long n, k, sum = 0;
	long long x;
	cin >> n >> k;

	priority_queue<long long> q;

	while (n--)
	{
		cin >> x;
		sum += x;

		if (x % 2 == 0)
		{
			q.push(x);
		}
	}

	while (k-- && q.size())
	{
		long long temp = q.top() / 2;
		q.pop();
		sum -= temp;

		// if (temp % 2 != 1)
		if (temp % 2 == 0)
		{
			q.push(temp);
		}
	}

	cout << sum << endl;

	return 0;
}




// 优解：
#include <iostream>
#include <queue>
using namespace std;

typedef long long LL;
LL n, k;
priority_queue<LL> heap;

int main()
{
	cin >> n >> k;
	LL sum = 0, x;

	while (n--)
	{
		cin >> x;
		sum += x;

		if (x % 2 == 0)
		{
			heap.push(x);
		}
	}

	while (heap.size() && k--)
	{
		LL t = heap.top() / 2;
		heap.pop();
		sum -= t;

		if (t % 2 == 0)
		{
			heap.push(t);
		}
	}

	cout << sum << endl;

	return 0;
}