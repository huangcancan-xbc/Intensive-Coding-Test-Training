// 牛客：DP10 最大子矩阵
// 链接：https://www.nowcoder.com/practice/a5a0b05f0505406ca837a3a76a5419b3?tpId=230&tqId=40416&ru=/exam/oj

// 方法一：暴力枚举所有子矩阵（超时）
// 时间复杂度：O(n^6)
// 空间复杂度：O(1)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> v[i][j];
        }
    }

    int ret = -127 * n;

    // 四重循环暴力枚举所有子矩阵
    for (int r1 = 0; r1 < n; ++r1)                  // 起始行
    {
        for (int r2 = r1; r2 < n; ++r2)             // 结束行
        {
            for (int c1 = 0; c1 < n; ++c1)          // 起始列
            {
                for (int c2 = c1; c2 < n; ++c2)     // 结束列
                {
                    int sum = 0;

                    // 遍历这个子矩阵内的所有元素
                    for (int i = r1; i <= r2; ++i)
                    {
                        for (int j = c1; j <= c2; ++j)
                        {
                            sum += v[i][j];         // 计算矩阵和
                        }
                    }

                    ret = max(ret, sum);            // 更新最大和
                }
            }
        }
    }

    cout << ret << endl;

    return 0;
}




// 方法二：动态规划 + 前缀和
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    auto dp = v;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> v[i][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + v[i][j];
        }
    }

    int ret = -127 * n;                             // 最小可能和

    // 枚举所有子矩阵
    for (int r1 = 1; r1 <= n; ++r1)
    {
        for (int r2 = r1; r2 <= n; ++r2)
        {
            for (int c1 = 1; c1 <= n; ++c1)
            {
                for (int c2 = c1; c2 <= n; ++c2)
                {
                    int sum = dp[r2][c2]            // 右下角元素
                        - dp[r1 - 1][c2]            // 左上角元素
                        - dp[r2][c1 - 1]            // 左下角元素
                        + dp[r1 - 1][c1 - 1];       // 右上角元素
                    ret = max(ret, sum);
                }
            }
        }
    }

    cout << ret << endl;
    return 0;
}



// 优解：
#include <iostream>
using namespace std;

const int N = 110;
int n;
int dp[N][N];

int main()
{
    int x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + x;
        }
    }

    int ret = -127 * N;
    for (int x1 = 1; x1 <= n; x1++)
    {
        for (int y1 = 1; y1 <= n; y1++)
        {
            for (int x2 = x1; x2 <= n; x2++)
            {
                for (int y2 = y1; y2 <= n; y2++)
                {
                    ret = max(ret, dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]);
                }
            }
        }
    }

    cout << ret << endl;
    return 0;
}