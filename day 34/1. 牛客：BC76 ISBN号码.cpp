// 牛客：BC76 ISBN号码
// 链接：https://www.nowcoder.com/practice/95712f695f27434b9703394c98b78ee5?tpId=290&tqId=39864&ru=/exam/oj

// 方法：字符串模拟
#include <iostream>
#include <string>
using namespace std;

string s;
int MOD = 11;

int main()
{
    cin >> s;

    int val = 1, sum = 0;
    for (int i = 0; i < s.size() - 2; i++)
    {
        if (i == 1 || i == 5)
        {
            continue;
        }

        sum += ((s[i] - '0') * val++);

    }

    sum %= MOD;

    if ((sum == 10 && s.back() == 'X') || sum == (s.back() - '0'))
    {
        cout << "Right" << endl;
    }
    else
    {
        for (int i = 0; i < s.size() - 1; i++)
        {
            cout << s[i];
        }

        if (sum == 10)
        {
            cout << 'X' << endl;
        }
        else
        {
            cout << sum << endl;
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
    string s;
    cin >> s;

    int sum = 0, count = 1, n = s.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            sum += (s[i] - '0') * count;
            count++;
        }
    }

    sum %= 11;

    if (sum == s[n - 1] - '0' || (sum == 10 && s[n - 1] == 'X'))
    {
        cout << "Right" << endl;
    }
    else
    {
        s[n - 1] = sum == 10 ? 'X' : sum + '0';
        cout << s << endl;
    }

    return 0;
}