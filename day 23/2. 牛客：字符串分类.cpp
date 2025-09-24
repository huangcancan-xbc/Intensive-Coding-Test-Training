// 牛客：字符串分类
// 链接：https://www.nowcoder.com/questionTerminal/9fbb4d95e6164cd9ab52e859fbe8f4ec

// 方法一：哈希
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;
    set<vector<int>> hash;
    while (n--)
    {
        cin >> s;
        vector<int> v(26, 0);
        for (auto x : s)
        {
            v[x - 'a']++;
        }

        hash.insert(v);
    }
    cout << hash.size() << endl;

    return 0;
}



// 方法二：哈希 + 排序
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

int n;
string s;

int main()
{
    cin >> n;
    unordered_set<string> hash;

    while (n--)
    {
        cin >> s;
        sort(s.begin(), s.end());
        hash.insert(s);
    }

    cout << hash.size() << endl;
    return 0;
}