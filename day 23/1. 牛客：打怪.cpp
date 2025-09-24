// 牛客：打怪
// 链接：https://ac.nowcoder.com/acm/problem/202487

// 方法一：暴力（超时）
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    int h, a, H, A, ret = 0;
    while (t--)
    {
        cin >> h >> a >> H >> A;
        if (A == 0)
        {
            cout << -1 << endl;
            continue;
        }

        int temp = H;
        while (h > 0)
        {
            H -= a;

            if (H < 1)
            {
                ret++;
                H = temp;
                continue;
            }
            h -= A;
        }
    }

    cout << ret << endl;

    return 0;
}



// 方法二：数学/模拟
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    int h, a, H, A, ret = 0;
    while (t--)
    {
        cin >> h >> a >> H >> A;
        int temp = h;
        if (A == 0)                     // 如果毛球怪攻击为0,结果是无数，输出-1
        {
            cout << -1 << endl;
            continue;
        }

        while (h > 0)                   // 模拟一个打怪的过程，而不是回合
        {
            H -= a;
            if (H < 1)
            {
                break;
            }
            h -= A;
        }

        int oneval = temp - h;          // oneval 是每击杀一个怪物所消耗的自身血量
        if (oneval == 0)                // 这里是一击必杀的情况，相当于毛球怪攻击为0
        {
            cout << -1 << endl;
            continue;
        }

        // 保持自身血量不为0，最多能击杀多少个怪物
        ret = temp % oneval == 0 ? temp / oneval - 1 : temp / oneval;
        cout << ret << endl;
    }

    return 0;
}
// 或者：
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    int h, a, H, A, ret = 0;
    while (t--)
    {
        cin >> h >> a >> H >> A;
        int temp = h;
        if (A == 0 || a >= H)           // 将上面一击必杀的情况和毛球怪攻击为0的情况整合
        {
            cout << -1 << endl;
            continue;
        }

        while (h > 0)
        {
            H -= a;
            if (H < 1)
            {
                break;
            }
            h -= A;
        }

        int oneval = temp - h;

        ret = temp % oneval == 0 ? temp / oneval - 1 : temp / oneval;
        cout << ret << endl;
    }

    return 0;
}


// 优解：
#include <iostream>
using namespace std;

int t;
int h, a, H, A;

int fun()
{
    if (a >= H)
    {
        return -1;
    }

    int m = (H / a) + (H % a != 0 ? 1 : 0);         // 一只毛球怪能抗多少次
    int n = m - 1;                                  // 在一轮（非一回合）中玩家被攻击的次数
    int x = n * A;                                  // 在一轮（非一回合）中击杀怪物的掉血量
    int ret = h / x - (h % x == 0 ? 1 : 0);
    return ret;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> h >> a >> H >> A;
        cout << fun() << endl;
    }
    return 0;
}