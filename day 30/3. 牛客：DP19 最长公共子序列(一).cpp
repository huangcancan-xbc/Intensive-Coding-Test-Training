// 牛客：DP19 最长公共子序列(一)
// 链接：https://www.nowcoder.com/practice/672ab5e541c64e4b9d11f66011059498?tpId=230&tqId=39761&ru=/exam/oj

// 方法：动态规划
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m;
string s1, s2;

int main()
{
    cin >> n >> m >> s1 >> s2;

    // dp[i][j]表示s1前i个字符与s2前j个字符的最长公共子序列长度
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])             // 如果当前字符匹配（注意字符串索引从0开始）
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;    // 当前公共长度 = 前i-1和j-1个字符的最长公共子序列长度 + 1
            }
            else
            {
                // 字符不匹配时，取"排除s1当前字符"或"排除s2当前字符"两种情况的最大值
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}



// 优解：
#include <iostream>
using namespace std;

const int N = 1010;
int n, m;
char s1[N];
char s2[N];
int dp[N][N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s1[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> s2[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i] == s2[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}