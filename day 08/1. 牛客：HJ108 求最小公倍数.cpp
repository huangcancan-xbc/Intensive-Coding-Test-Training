// 牛客：HJ108 求最小公倍数
// 链接：https://www.nowcoder.com/practice/22948c2cad484e0291350abad86136c3?tpId=37&tqId=21331&ru=/exam/oj

// 方法一：使用库函数 lcm()
#include <iostream>
#include <numeric>          // c++17 引入的库 lcm() 函数
using namespace std;

int main()
{
    long a, b;
    cin >> a >> b;

    cout << lcm(a, b);
    return 0;
}



// 方法二：GNU 扩展
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long a, b;
    cin >> a >> b;

    cout << (a * b) / __gcd(a, b);
    return 0;
}



// 方法三：辗转相除法
// A 和 B 的最小公倍数：A*B/两者的最大公约数
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

int main()
{
    long a, b;
    cin >> a >> b;

    cout << (a * b) / gcd(a, b);
    return 0;
}



// 方法四：手动实现
#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << (a * b) / gcd(a, b) << endl;
    // cout << lcm(a, b) << endl;
    return 0;
}