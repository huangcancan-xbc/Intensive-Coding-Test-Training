// 牛客：游游的水果大礼包
// 链接：https://ac.nowcoder.com/acm/problem/255193
// 或者：https://www.nowcoder.com/practice/fa0519c4469f4241bbdb7eabe7e3b295
// 或者：https://www.nowcoder.com/questionTerminal/3013527b237a48ffbd5640345b616748

// 很容易想到贪心，但是很不幸，贪心是错的。比如反例：n=2,m=100,a=3,b=2就会推翻贪心的策略。

// 正解方法：暴力枚举
#include <iostream>
using namespace std;

int main()
{
    long long n, m, a, b, ret = 0;
    cin >> n >> m >> a >> b;

    if (n < 2 && m < 2)
    {
        cout << 0 << endl;
        return 0;
    }

    for (long long i = 0; i <= min(n / 2, m); i++)
    {
        long long j = min(n - i * 2, (m - i) / 2);
        ret = max(ret, i * a + j * b);
    }
    cout << ret << endl;

    return 0;
}