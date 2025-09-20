// 牛客：对称之美
// 链接：https://ac.nowcoder.com/acm/problem/214850

// 方法：字符串 + 哈希
// 左右指针判断回文串。判断左右指针相等的时候，应该看看两个字符串中有没有相同的字符。

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<string> v(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }

        bool flag = true;                   // 标记是否所有对应对都有公共字符

        for (int i = 0; i < n / 2; ++i)
        {
            // 将左边字符串字符存入哈希集合
            unordered_set<char> st(v[i].begin(), v[i].end());

            bool is = false;                // 当前这对字符串是否有公共字符
            for (char ch : v[n - 1 - i])
            {
                if (st.count(ch))           // 找到公共字符
                {
                    is = true;
                    break;
                }
            }

            if (!is)                        // 没有公共字符，直接失败
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}



// 优解：
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int t, n;
string s;
bool vis[110][26];

bool check(int left, int right)
{
    for (int i = 0; i < 26; i++)
    {
        if (vis[left][i] && vis[right][i])
        {
            return true;
        }
    }

    return false;
}

int main()
{
    cin >> t;
    while (t--)
    {
        memset(vis, 0, sizeof vis);
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            for (auto x : s)
            {
                vis[i][x - 'a'] = true;
            }
        }

        int left = 0, right = n - 1;
        while (left < right)
        {
            if (!check(left, right))
            {
                break;
            }

            left++, right--;
        }

        if (left < right)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }

    return 0;
}