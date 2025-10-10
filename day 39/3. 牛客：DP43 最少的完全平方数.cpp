// 牛客：DP43 最少的完全平方数
// 链接：https://www.nowcoder.com/practice/4b2f5d4c00f44a92845bdad633965c04?tpId=230&tqId=40431&ru=/exam/oj

// 方法：动态规划 —— 完全背包
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // 1. 预处理所有 <= n 的完全平方数
    vector<int> v;
    for (int i = 1; i * i <= n; i++)
    {
        v.push_back(i * i);                 // 存入平方数
    }

    int m = v.size();                       // 可用平方数的个数

    // 2. 定义 dp 数组：dp[i][j] 表示前 i 个平方数能否组成 j 的最少数量
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));

    // 3. 初始化：组成 0 需要 0 个数
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }

    // 4. 状态转移
    for (int i = 1; i <= m; i++)            // 遍历平方数
    {
        for (int j = 1; j <= n; j++)        // 遍历目标数值
        {
            dp[i][j] = dp[i - 1][j];        // 不选当前平方数

            // 选当前平方数（可以重复选）
            if (j >= v[i - 1] && dp[i][j - v[i - 1]] != INT_MAX)
            {
                dp[i][j] = min(dp[i][j], dp[i][j - v[i - 1]] + 1);
            }
        }
    }

    cout << dp[m][n] << endl;               // 输出结果
    return 0;
}



// 优化：
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // 1. 预处理所有 <= n 的完全平方数
    vector<int> v;
    for (int i = 1; i * i <= n; i++)
    {
        v.push_back(i * i);    // 存入平方数
    }

    // 2. 定义 dp 数组：dp[j] 表示组成 j 的最少平方数个数
    vector<int> dp(n + 1, INT_MAX);

    // 3. 初始化：组成 0 需要 0 个数
    dp[0] = 0;

    // 4. 状态转移（完全背包）
    for (int i = 0; i < v.size(); i++)          // 遍历平方数
    {
        for (int j = v[i]; j <= n; j++)         // 从小到大遍历
        {
            if (dp[j - v[i]] != INT_MAX)        // 如果能凑出 j - v[i]
            {
                dp[j] = min(dp[j], dp[j - v[i]] + 1);
            }
        }
    }

    cout << dp[n] << endl;   // 输出结果
    return 0;
}



// 优解：
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e4 + 10;
int n;
int dp[N];

int main()
{
    cin >> n;
    memset(dp, 0x3f, sizeof dp);

    dp[0] = 0;

    for (int i = 1; i * i <= n; i++)
    {
        for (int j = i * i; j <= n; j++)
        {
            dp[j] = min(dp[j], dp[j - i * i] + 1);
        }
    }

    cout << dp[n] << endl;

    return 0;
}