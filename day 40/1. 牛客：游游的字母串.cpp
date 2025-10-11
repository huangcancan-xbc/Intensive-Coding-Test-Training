// 牛客：游游的字母串
// 链接：https://ac.nowcoder.com/acm/problem/255195

// 不要把问题想复杂了，数据量不算大，暴力枚举就行了，把问题复杂化反而不好解决。

// 方法：暴力枚举
#include <iostream>
#include <string>
#include <climits>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int ret = INT_MAX;

    for (char i = 'a'; i <= 'z'; i++)
    {
        int sum = 0;
        for (auto x : s)
        {
            sum += min(abs(i - x), 26 - abs(i - x));
        }

        ret = min(ret, sum);
    }
    cout << ret << endl;

    return 0;
}