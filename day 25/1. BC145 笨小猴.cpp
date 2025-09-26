// 牛客：BC145 笨小猴
// 链接：https://www.nowcoder.com/practice/17865bc2a75c4944a872ef709958c56e?tpId=290&tqId=39933&ru=/exam/oj

// 方法：哈希 + 模拟 + 数学
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string s;
int maxn, minn = 100;
int count[30];
bool is(int x)
{
    for (int i = 2; i < x; i++)
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
    cin >> s;
    if (s.size() == 0)
    {
        cout << "No Answer" << endl << 0 << endl;
        return 0;
    }

    for (auto x : s)
    {
        count[x - 'a']++;
        maxn = max(maxn, count[x - 'a']);
    }

    for (int i = 0; i < 30; i++)
    {
        if (count[i] > 0)
        {
            minn = min(minn, count[i]);
        }
    }

    // if(!is(maxn-minn)||maxn-minn<2)
    if (!is(maxn - minn) || maxn == minn || maxn - minn == 1)
    {
        cout << "No Answer" << endl << 0 << endl;
    }
    else
    {
        cout << "Lucky Word" << endl << maxn - minn << endl;
    }

    return 0;
}




// 优解：
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string s;
bool isprim(int n)
{
    if (n < 2)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

int main()
{
    cin >> s;
    int hash[26] = { 0 };
    for (auto ch : s)
    {
        hash[ch - 'a']++;
    }

    int minn = 1000, maxn = 0;
    for (int i = 0; i < 26; i++)
    {
        if (hash[i])
        {
            minn = min(minn, hash[i]);
            maxn = max(maxn, hash[i]);
        }
    }

    if (isprim(maxn - minn))
    {
        cout << "Lucky Word" << endl;
        cout << maxn - minn << endl;
    }
    else
    {
        cout << "No Answer" << endl;
        cout << 0 << endl;
    }

    return 0;
}