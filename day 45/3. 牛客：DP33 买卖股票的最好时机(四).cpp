// 牛客：DP33 买卖股票的最好时机(四)
// 链接：https://www.nowcoder.com/share/jump/5170733851759400026829

// 方法：动态规划
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;  // n 表示天数，k 表示最多能完成的交易次数（一买一卖算一次）

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];  // 输入每天的股价
    }

    // 优化：交易次数最多不会超过 n/2（因为一次交易需要两天：买+卖）
    k = min(k, n / 2);

    // f[i][j]：第 i 天持有股票，最多完成 j 次交易的最大收益
    // g[i][j]：第 i 天没有股票，最多完成 j 次交易的最大收益
    vector<vector<int>> f(n, vector<int>(k + 1));
    vector<vector<int>> g(n, vector<int>(k + 1));

    // 初始化
    for (int j = 0; j <= k; j++)
    {
        f[0][j] = -0x3f3f3f3f;  // 默认不可达状态
        g[0][j] = -0x3f3f3f3f;  // 默认不可达状态
    }

    f[0][0] = -v[0];  // 第 0 天买入股票（花钱，所以是 -v[0]）
    g[0][0] = 0;      // 第 0 天不买，收益为 0

    // 状态转移
    for (int i = 1; i < n; i++)      // 枚举天数
    {
        for (int j = 0; j <= k; j++) // 枚举交易次数
        {
            // f[i][j]：第 i 天持有股票
            // 两种情况：
            // 1. 昨天就持有（f[i-1][j]）
            // 2. 昨天没股票，今天买入（g[i-1][j] - v[i]）
            f[i][j] = max(f[i - 1][j], g[i - 1][j] - v[i]);

            // g[i][j]：第 i 天没有股票
            // 两种情况：
            // 1. 昨天也没有股票（g[i-1][j]）
            // 2. 昨天有股票，今天卖出（f[i-1][j-1] + v[i]），此时交易次数+1
            g[i][j] = g[i - 1][j];
            if (j >= 1)
            {
                g[i][j] = max(g[i][j], f[i - 1][j - 1] + v[i]);
            }
        }
    }

    // 最终答案：最后一天不持有股票时的最大收益
    int ret = 0;
    for (int j = 0; j <= k; j++)
    {
        ret = max(ret, g[n - 1][j]);
    }

    cout << ret << endl;
    return 0;
}




// 优化：
#include <iostream>
using namespace std;

const int N = 1010, M = 110;
int n, k, p[N];
int f[N][M], g[N][M];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    k = min(k, n / 2);
    for (int j = 0; j <= k; j++)
    {
        f[0][j] = g[0][j] = -0x3f3f3f3f;
    }

    f[0][0] = -p[0], g[0][0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            f[i][j] = max(f[i - 1][j], g[i - 1][j] - p[i]);
            g[i][j] = g[i - 1][j];

            if (j >= 1)
            {
                g[i][j] = max(g[i][j], f[i - 1][j - 1] + p[i]);
            }
        }
    }

    int ret = 0;
    for (int j = 0; j <= k; j++)
    {
        ret = max(ret, g[n - 1][j]);
    }

    cout << ret << endl;

    return 0;
}