// 牛客：小红的ABC
// 链接：https://ac.nowcoder.com/acm/problem/230720

// 当时也不知道是题读错了还是理解错了，直接就用最长回文子串做了，哇去了。

// 方法一：暴力枚举
#include <iostream>
#include <string>
using namespace std;

bool is(const string& s, int l, int r)
{
    while (l < r)
    {
        if (s[l] != s[r])
        {
            return false;
        }

        ++l;
        --r;
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    for (int len = 2; len <= n; len++)                  // 这里是枚举最短回文串的长度，从 2 开始枚举
    {
        for (int i = 0; i + len - 1 < n; i++)           // 枚举起始位置
        {
            int j = i + len - 1;
            if (is(s, i, j))                            // 是回文就直接返回
            {
                cout << len << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;                                 // 所有子串都不是回文
    return 0;
}





// 方法二：字符串 + 找规律（优解）

// 只需要看看是否存在长度为 2 或 3 的回文子串即可，如果存在长度为 2 的回文子串，直接输出
// 如果存在长度为 3 的回文子串，则需要再看看字符串后面没有遍历的部分是否存在长度为 2 的回文子串
// 长度为 2（例aa）和长度为 3（例aba）在这道题中能包含长度为 4（abba）及其更高的回文子串！
#include <iostream>
#include <string>
using namespace std;

int n, ret = -1;
string s;

int main()
{
    cin >> s;
    n = s.size();

    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n && s[i] == s[i + 1])
        {
            ret = 2;
            break;
        }

        if (i + 2 < n && s[i] == s[i + 2])
        {
            ret = 3;
        }
    }

    cout << ret << endl;
    return 0;
}




// 方法三：动态规划
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    bool dp[100][100] = { false };
    int minLen = n + 1;

    for (int len = 2; len <= n; ++len)
    {
        for (int i = 0; i + len - 1 < n; ++i)
        {
            int j = i + len - 1;

            if (s[i] == s[j])
            {
                if (len == 2 || len == 3)
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }

            if (dp[i][j])
            {
                minLen = min(minLen, len);
            }
        }
    }

    cout << (minLen == n + 1 ? -1 : minLen) << endl;

    return 0;
}