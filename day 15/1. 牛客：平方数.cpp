// 牛客：平方数
// 链接：https://ac.nowcoder.com/acm/problem/205350

// 方法：数学模拟
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long x;
    cin >> x;

    long long a = sqrt(x);
    long long x1 = a * a, x2 = (a + 1) * (a + 1);
    if (x - x1 < x2 - x)
    {
        cout << x1 << endl;
    }
    else
    {
        cout << x2 << endl;
    }

    return 0;
}




#include <iostream>
#include <cmath>
using namespace std;

long long check(long long x)
{
    long long a = sqrt(x);                         // 找到 x 的整数平方根
    long long lower = a * a;                       // a 的平方
    long long upper = (a + 1) * (a + 1);           // a+1 的平方

    return (x - lower < upper - x) ? lower : upper;
}

int main()
{
    long long x;
    cin >> x;
    cout << check(x) << endl;
    return 0;
}