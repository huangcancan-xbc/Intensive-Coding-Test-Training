// 牛客：经此一役小红所向无敌
// 链接：https://ac.nowcoder.com/acm/problem/223985

// 方法一：模拟
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long a, h, b, k, ret = 0;
    cin >> a >> h >> b >> k;

    while (h > 0 && k > 0)
    {
        ret += (a + b);
        h -= b, k -= a;
    }

    if (h < 1 && k < 1)
    {

    }
    else if (h < 1)
    {
        ret += (b * 10);
    }
    else if (k < 1)
    {
        ret += (a * 10);
    }

    cout << ret << endl;

    return 0;
}



// 方法二：数学（优解）
#include <iostream>
using namespace std;

typedef long long LL;
LL a, h, b, k;

int main()
{
    cin >> a >> h >> b >> k;
    LL ret = 0;

    // 1. 计算攻击回合数
    LL n = min(h / b, k / a);
    ret += n * (a + b);

    // 2. 计算剩余血量
    h -= n * b;
    k -= n * a;

    // 3. 判断是否都存活
    if (h > 0 && k > 0)
    {
        h -= b;
        k -= a;
        ret += a + b;
    }

    // 4. 判断是否有机会释放大招
    if (h > 0 || k > 0)
    {
        ret += 10 * (h > 0 ? a : b);
    }

    cout << ret << endl;

    return 0;
}