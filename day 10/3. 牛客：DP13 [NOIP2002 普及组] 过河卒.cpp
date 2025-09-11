// 牛客：DP13 [NOIP2002 普及组] 过河卒
// 链接：https://www.nowcoder.com/practice/cc1a9bc523a24716a117b438a1dc5706?tpId=230&tqId=40428&ru=/exam/oj
// 或者洛谷：https://www.luogu.com.cn/problem/P1002


// 方法：DP（优解）
#include <iostream>
using namespace std;

int n, m, x, y;
long long dp[25][25];

int main()
{
    cin >> n >> m >> x >> y;
    x += 1, y += 1;
    dp[0][1] = 1;

    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 1; j <= m + 1; j++)
        {
            if ((i == x && j == y) || (i != x && j != y && abs(i - x) + abs(j - y) == 3))
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    cout << dp[n + 1][m + 1] << endl;

    return 0;
}