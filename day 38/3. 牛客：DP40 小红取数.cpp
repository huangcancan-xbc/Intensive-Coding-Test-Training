// 牛客：DP40 小红取数
// 链接：https://www.nowcoder.com/practice/6a7b2b6c9e3a4f56b1db9f8ca08d889b?tpId=230&tqId=38958&ru=/exam/oj

// 方法：01背包 + 同余定理
#include <iostream>
#include <vector>
using namespace std;

int n, k;

int main()
{
    cin >> n >> k;
    vector<long long> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(k, -1e15));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][(j - v[i] % k + k) % k] + v[i]);
        }
    }

    if (dp[n][0] == 0)
    {
        cout << -1 << endl;
    }
    else {
        cout << dp[n][0] << endl;
    }

    return 0;
}



// 优化：
#include <iostream>
#include <cstring>
using namespace std;

typedef long long LL;
const int N = 1010;
int n, k;
LL a[N];
LL dp[N][N];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    memset(dp, -0x3f, sizeof dp);
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][(j - a[i] % k + k) % k] + a[i]);
        }
    }

    if (dp[n][0] <= 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[n][0] << endl;
    }

    return 0;
}




// 最终一维滚动优化
#include <iostream>
#include <vector>
using namespace std;
using LL = long long;
const LL LL_MAX = (LL)(-1e13);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<LL> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    vector<LL> dp(k, LL_MAX);
    dp[0] = 0;

    for (int i = 0; i < n; ++i)
    {
        int ra = (int)(a[i] % k);
        vector<LL> ndp = dp; // 拷贝，防止当前轮重复使用

        for (int j = 0; j < k; ++j)
        {
            if (dp[j] == LL_MAX)
            {
                continue;
            }

            int nr = (j + ra) % k;
            ndp[nr] = max(ndp[nr], dp[j] + a[i]);
        }

        dp.swap(ndp);
    }

    if (dp[0] == 0)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << dp[0] << '\n';
    }

    return 0;
}