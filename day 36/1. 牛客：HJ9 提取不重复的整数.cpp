// 牛客：HJ9 提取不重复的整数
// 链接：https://www.nowcoder.com/practice/253986e66d114d378ae8de2e6c4577c1?tpId=37&tqId=21232&ru=/exam/oj

// 方法：字符串模拟 + 哈希
#include <iostream>
#include <string>
using namespace std;

string s;
bool vis[10];

int main()
{
    cin >> s;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (vis[s[i] - '0'] == false)
        {
            cout << s[i];
        }

        vis[s[i] - '0'] = true;
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
    cin >> s;
    bool hash[10] = { 0 };

    for (int i = s.size() - 1; i >= 0; i--)
    {
        int x = s[i] - '0';

        if (!hash[x])
        {
            cout << x;
            hash[x] = true;
        }
    }

    return 0;
}