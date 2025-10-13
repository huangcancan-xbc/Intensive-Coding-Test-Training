// 牛客：DP44 兑换零钱
// 链接：https://www.nowcoder.com/share/jump/5170733851759053482084

// 方法：动态规划
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    int n, aim;
    cin >> n >> aim;

    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(aim + 1, 0x3f3f3f3f));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= aim; j++)
        {
            dp[i][j] = dp[i - 1][j];                        // 不用第 i 种硬币
            if (j >= v[i] && dp[i][j - v[i]] != 0x3f3f3f3f) // 可以使用第 i 种并且前状态可达
            {
                dp[i][j] = min(dp[i][j], dp[i][j - v[i]] + 1); // 完全背包转移
            }
        }
    }

    if (dp[n][aim] >= 0x3f3f3f3f)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[n][aim] << endl;
    }

    return 0;
}




// 优化：
#include <iostream>
#include <cstring>
using namespace std;

const int N = 10010, M = 5010;
int n, aim;
int arr[N];
int dp[M];

int main()
{
    cin >> n >> aim;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = arr[i]; j <= aim; j++)
        {
            dp[j] = min(dp[j], dp[j - arr[i]] + 1);
        }
    }

    if (dp[aim] >= 0x3f3f3f3f)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[aim] << endl;
    }

    return 0;
}