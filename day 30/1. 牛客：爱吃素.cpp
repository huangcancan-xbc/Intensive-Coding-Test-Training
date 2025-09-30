// 牛客：爱吃素
// 链接：https://ac.nowcoder.com/acm/problem/227310

// 方法：数学
#include <iostream>
#include <cmath>
using namespace std;

long long t, a, b;
bool is(long long x)
{
    if (x < 2)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> a >> b;

        if (a == 1 || b == 1)
        {
            if (is(a * b))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}




// 优解：
#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;

bool isprim(LL x)
{
    if (x < 2) return false;
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0) return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        LL a, b;
        cin >> a >> b;

        if ((a == 1 && isprim(b)) || (b == 1 && isprim(a)))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}