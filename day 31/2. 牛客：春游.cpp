// 牛客：春游
// 链接：https://ac.nowcoder.com/acm/problem/219035

// 方法：模拟 + 分情况讨论
// 这道题其实非常简单，主要恶心的是分情况讨论，不能以常规思维考虑，还要考虑到很多边界条件：
// 比如：当2人船坐不满多出一个人时，需要考虑这多出来的1个人是单独选择2人船/3人船，还是和其他一条2人船的人合在一起坐3人船。
// 其他情况类比

#include <iostream>
using namespace std;

long long t, n, a, b;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b;
        long long ret = 0;

        if (n < 3)
        {
            cout << min(a, b) << endl;
            continue;
        }

        if (3 * a >= 2 * b)
        {
            int count = n / 3;
            ret = count * b;

            if (n % 3 == 1)
            {
                ret = min(ret + a, min(ret + b, ret - b + 2 * a));
            }
            else if (n % 3 == 2)
            {
                ret = min(min(ret + a, ret + b), ret - b + 3 * a);
            }

            cout << ret << endl;
        }
        else
        {
            int count = n / 2;
            long long ret = count * a;

            if (n % 2 == 1)
            {
                ret = min(min(ret + a, ret + b), ret - a + b);
            }

            cout << ret << endl;
        }
    }

    return 0;
}



// 优解：
#include <iostream>
using namespace std;

typedef long long LL;
LL t, n, a, b;

LL fun()
{
    if (n <= 2)
    {
        return min(a, b);
    }

    LL ret = 0;
    if (a * 3 < b * 2)
    {
        ret += n / 2 * a;
        n %= 2;

        if (n)
        {
            ret += min(min(a, b), b - a);
        }
    }
    else
    {
        ret += n / 3 * b;
        n %= 3;

        if (n == 1)
        {
            ret += min(min(a, b), 2 * a - b);
        }

        if (n == 2)
        {
            ret += min(min(a, b), 3 * a - b);
        }
    }

    return ret;
}

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n >> a >> b;
        cout << fun() << endl;
    }

    return 0;
}