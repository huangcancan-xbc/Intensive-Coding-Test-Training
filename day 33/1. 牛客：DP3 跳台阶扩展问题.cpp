// 牛客：DP3 跳台阶扩展问题
// 链接：https://www.nowcoder.com/practice/953b74ca5c4d44bb91f39ac4ddea0fee?tpId=230&tqId=39750&ru=/exam/oj

// 方法一：找规律（手推1-5的情况）
// 发现答案就是前一个答案的2倍，或者说答案是2的n-1次方。
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long> v(n + 1);
    v[1] = 1, v[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        v[i] = v[i - 1] * 2;
    }

    cout << v[n] << endl;

    return 0;
}


// 优解：
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << (1 << (n - 1)) << endl;
    // cout << pow(2, n - 1) << endl;
    return 0;
}



// 方法二：动态规划
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long dp[n + 1];
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0;
        for (int j = 1; j <= i; j++)
        {
            dp[i] += dp[i - j];
        }
    }

    cout << dp[n] << endl;

    return 0;
}