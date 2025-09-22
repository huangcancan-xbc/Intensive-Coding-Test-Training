// 牛客：DP22 最长回文子序列
// 链接：https://www.nowcoder.com/practice/82297b13eebe4a0981dbfa53dfb181fa?tpId=230&tqId=39762&ru=/exam/oj

// 方法：动态规划
//
//基础的区间 dp 问题：
//状态表示 ：dp[i][j] 表示：字符串[i, j] 范围内的最长回文子序列的长度；
//状态转移方程 ：
//当 i == j 的时候，只有一个字符，长度为 1；
//当 i < j 的时候，分情况讨论：
//    s[i] == s[j]：dp[i][j] = dp[i + 1][j - 1] + 2；
//    s[i] != s[j]：dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])；
//返回值 ：dp[0][n - 1]。

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;

int main()
{
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = n - 1; i >= 0; i--)
    {
        dp[i][i] = 1;                                   // 单个字符为回文串

        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == s[j])                           // 如果两个字符相同，则继续判断是否为回文串
            {
                if (i + 1 < j)                          // 如果长度大于2，两侧的字符也相同，“递归”判断
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;    // 此时回文字串的长度是内部的回文串的长度加两侧字符（2）
                }
                else if(i + 1 == j)                     // 如果长度为2，则为回文串
                {
                    dp[i][j] = 2;                       // 此时回文字串的长度为2
                }
            }
            else                                        // 如果两个字符不同，则此时需要判断两侧各向内部一个字符的回文串
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[0][n - 1] << endl;                       // 返回从 0 到 n-1 的最长回文子序列的长度

    return 0;
}
// 或者：
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;

int main()
{
    cin >> s;
    int n = s.size();                               // 获取字符串的长度

    vector<vector<int>> dp(n, vector<int>(n, 0));   // dp[i][j] 表示子字符串 s[i...j] 内的最长回文子序列的长度

    for (int i = n - 1; i >= 0; i--)                // 从字符串的末尾开始遍历，保证我们在填充 dp 数组时先处理小的区间
    {
        dp[i][i] = 1;                               // 这里表示 i 和 j 相等，单个字符本身是回文子序列，长度为 1

        for (int j = i + 1; j < n; j++)             // 对于每个 i，遍历 i 后面的子字符串
        {
            // 如果字符相等，考虑将这两个字符作为回文子序列的一部分
            if (s[i] == s[j])
            {
                // 如果 i + 1 < j，表示两个字符之间还有其他字符，则取左边和右边的最长回文子序列的长度之和 + 2，如果 i + 1 = j，则只有两个字符，长度为 2
                dp[i][j] = (i + 1 < j) ? dp[i + 1][j - 1] + 2 : 2;
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); // 如果左右边界字符不相等，就取左右边界内部相邻一个字符到另一边界的最长回文子序列的长度，取最大值
            }
        }
    }

    cout << dp[0][n - 1] << endl;                   // 最终，dp[0][n-1] 存储的是整个字符串 s 的最长回文子序列长度

    return 0;
}




// 优解：
#include <iostream>
#include <string>
using namespace std;

int dp[1010][1010];

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    for (int i = n - 1; i >= 0; i--)
    {
        dp[i][i] = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == s[j])
            {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[0][n - 1] << endl;
    return 0;
}