// 牛客：JD7 集合
// 链接：https://www.nowcoder.com/practice/635ff765d4af45b5bf8e3756ed415792?tpId=134&tqId=33860&ru=/exam/oj

// 方法：去重排序
#include <iostream>
#include <set>
using namespace std;

int n, m, x;
set<int> s;

int main()
{
    cin >> n >> m;
    while (n--)
    {
        cin >> x;
        s.insert(x);
    }

    while (m--)
    {
        cin >> x;
        s.insert(x);
    }

    for (auto x : s)
    {
        cout << x << ' ';
    }

    return 0;
}