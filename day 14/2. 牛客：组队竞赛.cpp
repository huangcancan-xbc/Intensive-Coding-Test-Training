// 牛客：组队竞赛
// 链接：https://www.nowcoder.com/questionTerminal/6736cc3ffd1444a4a0057dee89be789b

// 方法：贪心
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	long long n, ret = 0;
	cin >> n;
	vector<long long> v(n * 3);
	for (int i = 0; i < n * 3; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int pos = n * 3 - 2;
	while (n--)
	{
		ret += v[pos];
		pos -= 2;
	}
	
	cout << ret << endl;

	return 0;
}




// 用双端队列来模拟：
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    long long n, ret = 0;
    cin >> n;
    vector<long long> v(3 * n);
    for (int i = 0; i < 3 * n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());                   // 1: 先排序，便于后续双端队列操作

    deque<long long> dq;
    for (auto x : v)
    {
        dq.push_back(x);                        // 2: 把排好序的所有元素 push 到 deque 中(前小后大)
    }

    // 3: 组队：每次3个选手 —— [pop_back(最大), pop_front(最小牺牲), pop_back(中间累加)]
    for (int i = 0; i < n; i++)
    {
        // 末尾值不累加，它对应本队的 max
        long long Max = dq.back();
        dq.pop_back();

        // 头部值直接舍弃，相当于给最弱的队伍当 a
        long long Min = dq.front();
        dq.pop_front();

        // 中间值直接累加到 ret
        long long Mid = dq.back();
        dq.pop_back();

        ret += Mid;
    }

    cout << ret << endl;
    return 0;
}