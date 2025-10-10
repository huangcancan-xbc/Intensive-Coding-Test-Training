// 牛客：神奇的字母（二）
// 链接：https://ac.nowcoder.com/acm/problem/205832

// 方法：哈希
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    string s;
    unordered_map<char, int> hash;
    while (getline(cin, s))
    {
        for (auto x : s)
        {
            hash[x]++;
        }
    }

    char ret;
    int val = 0;
    for (auto [a, b] : hash)
    {
        if (b > val)
        {
            val = b;
            ret = a;
        }
    }

    cout << ret << endl;

    return 0;
}



// 优化：
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int hash[26] = { 0 };
    char ret = 0;
    int maxCount = 0;

    while (cin >> s)
    {
        for (auto ch : s)
        {
            if (++hash[ch - 'a'] > maxCount)
            {
                ret = ch;
                maxCount = hash[ch - 'a'];
            }
        }
    }

    cout << ret << endl;

    return 0;
}