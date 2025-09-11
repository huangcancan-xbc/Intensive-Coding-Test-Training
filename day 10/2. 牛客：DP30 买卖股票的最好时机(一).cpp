// 牛客：DP30 买卖股票的最好时机(一)
// 链接：https://www.nowcoder.com/practice/351b87e53d0d44928f4de9b6217d36bb?tpId=230&tqId=39767&ru=/exam/oj

// 方法一：暴力（超时）
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ret = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            ret = max(ret, v[j] - v[i]);
        }
    }

    cout << ret << endl;

    return 0;
}




// 方法二：贪心：固定前一个数（优解）
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ret = 0, minval = v[0];
    for (int i = 1; i < n; i++)
    {
        ret = max(ret, v[i] - minval);
        minval = min(minval, v[i]);
    }

    cout << (ret < 0 ? 0 : ret) << endl;
    return 0;
}
// 或者固定后一个数：
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ret = 0, minval = v[0];
    for (int i = 1; i < n; i++)
    {
        minval = min(minval, v[i]);
        ret = max(ret, v[i] - minval);
    }

    cout << ret << endl;
    return 0;
}




// 方法二：DP
// dp[i][0] 表示第i天持有股票所得现金。
// dp[i][1] 表示第i天不持有股票所得最多现金。

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, ret = 0;
    cin >> n;

    if (n == 0)
    {
        return 0;
    }

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] -= v[0];
    dp[0][1] = 0;

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], -v[i]);
        dp[i][1] = max(dp[i - 1][1], v[i] + dp[i - 1][0]);
    }

    cout << dp[n - 1][1] << endl;

    return 0;
}