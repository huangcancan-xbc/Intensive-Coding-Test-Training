// 牛客：装箱问题
// 链接：https://ac.nowcoder.com/acm/problem/16693

// 方法：动态规划（01背包）
#include <iostream>
#include <vector>
using namespace std;

int V, n, v[35];

int main()
{
    cin >> V >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(V + 1));      // dp[i][j] 表示前 i 个物品，放入容量为 j 的背包，能装的最大体积
    for (int i = 1; i <= n; i++)                            // 遍历每个物品
    {
        for (int j = 0; j <= V; j++)                        // 遍历容量
        {
            dp[i][j] = dp[i - 1][j];                        // 不选当前物品
            if (j - v[i] >= 0)                              // 如果背包容量大于当前物品的体积，则选择当前物品
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + v[i]);   // 选择当前物品
            }
        }
    }

    cout << V - dp[n][V] << endl;

    return 0;
}
// 或者：
#include <iostream>
#include <vector>
using namespace std;

int V, n, v[35];

int main()
{
    cin >> V >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(V + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i - 1])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i - 1]] + v[i - 1]);
            }
        }
    }

    cout << V - dp[n][V] << endl;

    return 0;
}


// 优解：
#include <iostream>
using namespace std;

const int N = 35, M = 2e4 + 10;

int n, v;
int arr[N];
int dp[N][M];

int main()
{
    cin >> v >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= v; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= arr[i])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[i]] + arr[i]);
            }
        }
    }

    cout << (v - dp[n][v]) << endl;
    return 0;
}



// 空间优化：
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 35, M = 2e4 + 10;

int n, v;
int arr[N];
int dp[M];                                  // 一维数组：dp[j] 表示容量为 j 时的最大装入体积

int main()
{
    cin >> v >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];                      // 输入每个物品的体积
    }

    for (int i = 1; i <= n; i++)            // 遍历每个物品
    {
        for (int j = v; j >= arr[i]; j--)   // 背包容量从大到小遍历（防止状态污染）
        {
            dp[j] = max(dp[j], dp[j - arr[i]] + arr[i]);    // 状态转移
        }
    }

    cout << (v - dp[v]) << endl;            // 背包剩余空间 = 总容量 - 已装体积

    return 0;
}