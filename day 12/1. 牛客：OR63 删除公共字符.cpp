// 牛客：OR63 删除公共字符
// 链接：https://www.nowcoder.com/practice/f0db4c36573d459cae44ac90b90c6212?tpId=182&tqId=34789&ru=/exam/oj

// 方法：字符串模拟 + 哈希表
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
    string a, b;
    getline(cin, a);
    cin >> b;
    unordered_set<char> hash;

    for (auto x : b)
    {
        hash.insert(x);
    }

    for (auto& x : a)
    {
        if (hash.find(x) == hash.end())
        {
            cout << x;
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
    string s, t;
    getline(cin, s);
    getline(cin, t);

    bool hash[300] = { 0 };
    for (char ch : t)
    {
        hash[ch] = true;
    }

    string ret;
    for (auto ch : s)
    {
        if (!hash[ch])
        {
            ret += ch;
        }
    }

    cout << ret << endl;
    return 0;
}



// 使用 bitset 优化
#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main()
{
    string a, b;
    getline(cin, a);
    cin >> b;

    bitset<256> hash;

    for (char ch : b)
    {
        hash.set(ch);               // 将该字符所在位置设为 1
    }

    for (char ch : a)
    {
        if (!hash.test(ch))         // 如果该字符不在 b 中
        {
            cout << ch;
        }
    }

    return 0;
}




// remove_if + erase 优化
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main()
{
    string a, b;
    getline(cin, a);
    cin >> b;

    unordered_set<char> del(b.begin(), b.end());        // 初始化哈希表

    a.erase(remove_if(a.begin(), a.end(), [&](char c) {
        return del.count(c);
        }), a.end());

    cout << a << endl;

    return 0;
}