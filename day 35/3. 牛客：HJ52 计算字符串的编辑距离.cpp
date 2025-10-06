// 牛客：HJ52 计算字符串的编辑距离
// 链接：https://www.nowcoder.com/practice/3959837097c7413a961a135d7104c314?tpId=37&tqId=21275&ru=/exam/oj

// 方法：动态规划
#include <iostream>
#include <string>
using namespace std;

const int N = 1010;
string a, b;
int dp[N][N];                           // dp[i][j] 表示将 a[0..i-1] 变为 b[0..j-1] 所需的最小编辑次数

int main()
{
    cin >> a >> b;
    int n = a.size(), m = b.size();

    for (int j = 0; j <= m; j++)        // 初始化第一行：把空串变为 b[0..j-1]，需要 j 次插入
    {
        dp[0][j] = j;
    }

    for (int i = 0; i <= n; i++)        // 初始化第一列：把 a[0..i-1] 变为空串，需要 i 次删除
    {
        dp[i][0] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];    // 如果当前字符相等，不需要额外操作
            }
            else
            {
                // 如果不相等，有三种操作可选：
                // 1. 删除 a[i-1] → dp[i-1][j] + 1
                // 2. 插入 b[j-1] → dp[i][j-1] + 1
                // 3. 替换 a[i-1] 为 b[j-1] → dp[i-1][j-1] + 1
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}