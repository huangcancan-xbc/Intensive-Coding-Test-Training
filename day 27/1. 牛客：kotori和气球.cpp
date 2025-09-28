// 牛客：kotori和气球
// 链接：https://ac.nowcoder.com/acm/problem/50039

//注意看清取模的值，当时不小心看成1e9了，导致结果错误！

// 方法：数学/排列组合
#include <iostream>
using namespace std;

long long n, m, ret;

int main()
{
    cin >> n >> m;
    ret = n;

    if (n == 1 && m == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    else if (n == 1 && m != 1)
    {
        cout << 0 << endl;
        return 0;
    }

    n--;

    for (int i = 0; i < m - 1; i++)
    {
        ret *= n;
        ret %= 109;
    }
    cout << ret << endl;
    return 0;
}
// 或者：
#include <iostream>
using namespace std;

const int MOD = 109;

int main()
{
    int n, m;
    cin >> n >> m;
    int ret = n;

    for (int i = 0; i < m - 1; i++)
    {
        ret = ret * (n - 1) % MOD;
    }

    cout << ret << endl;
    return 0;
}