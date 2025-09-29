// 牛客：游游的重组偶数
// 链接：https://www.nowcoder.com/questionTerminal/d1ac7f15d5dc40b39a7d6cb11a01407e

// 方法：字符串/模拟/数学
#include <iostream>
#include <string>
using namespace std;

int q;
string s;

bool check(char x)
{
    return (x == '0' || x == '2' || x == '4' || x == '6' || x == '8');
}

int main()
{
    cin >> q;

    while (q--)
    {
        cin >> s;
        int count0 = 0;
        for (auto x : s)
        {
            if (x == '0')
            {
                count0++;
            }
        }

        if (count0)
        {
            for (auto x : s)
            {
                if (x != '0')
                {
                    cout << x;
                }
            }

            while (count0--)
            {
                cout << 0;
            }
            cout << endl;
            continue;
        }

        int index = 0;
        bool flag = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (check(s[i]))
            {
                index = i;
                flag = true;
                s += s[i];
                break;
            }
        }

        if (flag)
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (i != index)
                {
                    cout << s[i];
                }
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}




// 优解：
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int q;
    string s;
    cin >> q;

    while (q--)
    {
        cin >> s;
        int n = s.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if ((s[i] - '0') % 2 == 0)
            {
                swap(s[i], s[n - 1]);
                break;
            }
        }

        if ((s[n - 1] - '0') % 2 == 0)
        {
            cout << s << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}