// 牛客：OR62 倒置字符串
// 链接：https://www.nowcoder.com/practice/ee5de2e7c45a46a090c1ced2fdc62355?tpId=182&tqId=34788&ru=/exam/oj


// 方法一：使用库函数进行分割
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    stringstream ss(s);
    vector<string> temps;
    string temp;

    while (ss >> temp)
    {
        temps.push_back(temp);
    }

    for (int i = temps.size() - 1; i >= 0; --i)
    {
        cout << temps[i];
        if (i > 0)
        {
            cout << ' ';
        }
    }

    cout << endl;
    return 0;
}
// 或者：
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    vector<string> ret;
    istringstream ss(s);
    string temp;

    while (getline(ss, temp, ' '))
    {
        ret.push_back(temp);
    }

    for (int i = ret.size() - 1; i >= 0; i--)
    {
        cout << ret[i];
        if (i != 0)
        {
            cout << ' ';
        }
    }

    return 0;
}




// 方法二：手动模拟
#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    reverse(s.begin(), s.end());
    int left = 0, n = s.size();

    while (left < n)
    {
        int right = left;
        while (right < n && s[right] != ' ')
        {
            right++;
        }

        reverse(s.begin() + left, s.begin() + right);
        while (right < n && s[right] == ' ')
        {
            right++;
        }
        left = right;
    }

    cout << s << endl;

    return 0;
}
// 或者：
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    int n = s.size() - 1, len = 0;
    for (int i = n; i >= 0; i--)
    {
        len++;
        if (s[i] == ' ')
        {
            cout << s.substr(i + 1, len - 1) << ' ';
            len = 0;
        }
        if (i == 0)
        {
            cout << s.substr(0, len);
        }
    }

    return 0;
}
// 或者：
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    int right = s.length() - 1;

    while (right >= 0)
    {
        while (right >= 0 && s[right] == ' ')
        {
            --right;                        // 跳过末尾空格
        }

        if (right < 0)
        {
            break;
        }

        int left = right;
        while (left >= 0 && s[left] != ' ')
        {
            --left;                         // 找到当前单词的开头
        }

        cout << s.substr(left + 1, right - left);

        right = left - 1;
        if (right >= 0)
        {
            cout << ' ';
        }
    }

    return 0;
}




// 方法三：栈模拟
#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    istringstream ss(s);
    stack<string> st;
    string temp;

    while (ss >> temp)
    {
        st.push(temp);
    }

    while (!st.empty())
    {
        cout << st.top();
        st.pop();

        if (!st.empty())
        {
            cout << ' ';
        }
    }

    return 0;
}