// 牛客：DP23 不相邻取数
// 链接：https://www.nowcoder.com/practice/a2be806a0e5747a088670f5dc62cfa1e?tpId=230&tqId=39763&ru=/exam/oj

// 方法：动态规划（打家劫舍）
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    if (n == 1)
    {
        cout << v[0] << endl;           // 特判：当只有一个数时，直接输出
        return 0;
    }

    vector<long long> dp(n);            // dp[i] 表示考虑前 i+1 个数的最大和
    dp[0] = v[0];                       // 只选第一个数
    dp[1] = max(v[0], v[1]);            // 只能选 a[0] 或 a[1]，不能都选

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + v[i]);  // 选或不选 a[i]
    }

    cout << dp[n - 1] << endl;
    return 0;
}




#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> v(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<long long> f(n + 1), g(n + 1);           // f[i] 表示选择第 i 个数的最大和，g[i] 表示不选第 i 个数的最大和
    f[0] = v[0];                                    // 第一个数只能选

    for (int i = 1; i <= n; i++)
    {
        f[i] = g[i - 1] + v[i];                     // 选第 i 个数的最大和
        g[i] = max(f[i - 1], g[i - 1]);             // 不选第 i 个数的最大和
    }

    cout << max(f[n], g[n]) << endl;
    return 0;
}
// 或者（优解）：
#include <iostream>
using namespace std;

const int N = 2e5 + 10;
int n;
int arr[N];
int f[N], g[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        f[i] = g[i - 1] + arr[i];
        g[i] = max(f[i - 1], g[i - 1]);
    }

    cout << max(f[n], g[n]) << endl;

    return 0;
}