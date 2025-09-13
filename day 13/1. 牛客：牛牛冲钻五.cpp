// 牛客：牛牛冲钻五
// 链接：https://ac.nowcoder.com/acm/problem/227309
// 或者：https://ac.nowcoder.com/acm/contest/11215/A

// 方法：模拟
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int a, b, ret = 0;
        string s;
        cin >> a >> b >> s;
        int count = 1;

        for (int i = 0; i < a; i++)
        {
            if (i > 0 && s[i] == 'W' && s[i - 1] == 'W')
            {
                count++;
            }
            else
            {
                count = 1;
            }

            if (count >= 3)
            {
                ret += b;
            }
            else if (s[i] == 'W')
            {
                ret += 1;
            }
            else if (s[i] == 'L')
            {
                ret -= 1;
            }
        }

        cout << ret << endl;
    }

    return 0;
}




// 优解：
#include <iostream>
#include <string>
using namespace std;

int t, n, k;
string s;

int fun()
{
    int ret = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'L')
        {
            ret--;
        }
        else
        {
            if (i - 1 >= 0 && i - 2 >= 0 && s[i - 1] == 'W' && s[i - 2] == 'W')
            {
                ret += k;
            }
            else
            {
                ret += 1;
            }
        }
    }
    return ret;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> s;
        cout << fun() << endl;
    }

    return 0;
}