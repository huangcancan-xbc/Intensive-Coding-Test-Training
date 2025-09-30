// 牛客：削减整数
// 链接：https://ac.nowcoder.com/acm/problem/219038

// 方法：贪心 + 数学
//每次减去 a，如果 x 是 2a 的倍数，则把 a 升级为 2a；
//否则 a 保持不变，直到 x 为 0。

#include <iostream>
using namespace std;

int t, x;
int func()
{
    int ret = 0, a = 1;
    while (x)
    {
        x -= a;
        if (x % (2 * a) == 0)       // 数学原理（有效则可以提取公因数）
        {
            a *= 2;
        }
        ret++;
    }

    return ret;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> x;
        cout << func() << endl;
    }

    return 0;
}