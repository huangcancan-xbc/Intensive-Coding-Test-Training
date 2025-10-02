// 牛客：BC157 素数回文
// 链接：https://www.nowcoder.com/practice/d638855898fb4d22bc0ae9314fed956f?tpId=290&tqId=39945&ru=/exam/oj

// 方法：字符串模拟 + 数学
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string s;

int main()
{
    cin >> s;

    for (int i = s.size() - 2; i >= 0; i--)
    {
        s += s[i];
    }

    long long x = stoll(s);

    if (x < 2)
    {
        cout << "noprime" << endl;
    }
    else
    {
        for (long long i = 2; i <= sqrt(x); i++)
        {
            if (x % i == 0)
            {
                cout << "noprime" << endl;
                return 0;
            }
        }

        cout << "prime" << endl;
    }

    return 0;
}



// 优解：
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

long long change(string s)
{
    for (int i = s.size() - 2; i >= 0; i--)
    {
        s += s[i];
    }

    return stoll(s);
}

bool isprim(long long x)
{
    if (x <= 1)
    {
        return false;
    }

    for (long long i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
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
    long long x = change(s);
    if (isprim(x))
    {
        cout << "prime" << endl;
    }
    else
    {
        cout << "noprime" << endl;
    }

    return 0;
}