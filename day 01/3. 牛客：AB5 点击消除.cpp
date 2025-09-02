// 牛客：AB5 点击消除
// 链接：https://www.nowcoder.com/practice/8d3643ec29654cf8908b5cf3a0479fd5?tpId=308&tqId=40462&ru=/exam/oj
// https://www.nowcoder.com/practice/8d3643ec29654cf8908b5cf3a0479fd5

// 经典的括号匹配：栈
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;

    stack<int> st;
    st.push(s[0]);

    for (int i = 1; i < s.size(); i++)
    {
        // 注意：if(st.top() == s[i] && !st.empty())，这个写法在 栈为空时，
        // 先访问了 st.top()，这是未定义行为，会导致程序崩溃或段错误。
        if (!st.empty() && st.top() == s[i])
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }

    string ret;
    while (st.size())
    {
        ret += st.top();
        st.pop();
    }

    if (ret.size() == 0)
    {
        cout << 0;
        return 0;
    }

    reverse(ret.begin(), ret.end());

    cout << ret;

    return 0;
}




// 优解：字符串模拟栈
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, st;
    cin >> s;

    for (auto x : s)
    {
        if (st.size() && st.back() == x)
        {
            st.pop_back();
        }
        else
        {
            st.push_back(x);
        }
    }

    cout << (st.size() == 0 ? "0" : st) << endl;
    return 0;
}