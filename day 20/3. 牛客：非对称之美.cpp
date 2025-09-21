// 牛客：非对称之美
// 链接：https://ac.nowcoder.com/acm/problem/214851

// 方法：找规律/贪心
//只需要判断原字符串是否是回文串：
//如果不是回文串，答案就是 s.length()
//如果是回文串，检查是否所有字符都相同
//	是：没有任何非回文子串 0
//	否：输出 s.length() - 1（去掉任一字符必然不再是回文）

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool is(string s)
{
    string ss = s;
    reverse(ss.begin(), ss.end());

    return ss == s;
}

bool same(string s)
{
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] != s[i - 1])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string s;
    cin >> s;

    if (is(s))
    {
        if (same(s))
        {
            cout << 0 << endl;
        }
        else
        {
            cout << s.size() - 1 << endl;
        }
    }
    else
    {
        cout << s.size() << endl;
    }

    return 0;
}



// 优解：
#include <iostream>
#include <string>
using namespace std;

int n;
string s;

int fun()
{
    bool flag = false;
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[0])
        {
            flag = true;
            break;
        }
    }

    if (flag == false)
    {
        return 0;
    }

    flag = true;
    int left = 0, right = n - 1;

    while (left < right)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        return n - 1;
    }
    else
    {
        return n;
    }
}

int main()
{
    cin >> s;
    n = s.size();
    cout << fun() << endl;
    return 0;
}