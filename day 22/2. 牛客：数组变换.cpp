// 牛客：数组变换
// 链接：https://www.nowcoder.com/questionTerminal/c55f4f15cc3f4ff0adede7f9c69fa0c1

// 方法：贪心/数学/找规律
//1. 只需看当前数组中的最大值 maxval，如果 maxval/v[i] 本身就除不尽，则说明 v[i] 不能通过 x2 变成 maxval
//    否则，如果 maxval/v[i] 能被 2 整除，则说明 v[i] 能通过 x2 变成 maxval
//2. 因为 v[i] 需要通过 x2 变成 maxval，所以 maxval/v[i] 必须是 2 的幂次方，下面只需要判断 maxval/v[i] 是不是 2 的幂次方即可

#include <iostream>
using namespace std;

int n, v[55], maxval;
bool func()
{
    for (int i = 0; i < n; i++)
    {
        // 1. 判断每个数是否能被 v[i] 整除
        if (maxval % v[i] != 0)
        {
            return false;
        }

        // 2. 判断 v[i] 是否是 2 的幂次方
        int x = maxval / v[i];
        // if(x & (x - 1)!= 0)
        if (x - (x & -x) != 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        maxval = max(maxval, v[i]);
    }

    if (func())
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}




//这个问题也等价于：每个数除掉它的因子 2（不断除以2直到变为奇数），看所有奇数部分是否相等
//如果所有数的“奇数部分”相等，则可以通过若干次乘2操作使它们变相同；否则不行。
#include <iostream>
using namespace std;

int n, v[55];

// 不断除以 2，直到变成奇数
int check(int x)
{
    while (x % 2 == 0)
    {
        x /= 2;
    }

    return x;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // 所有数的奇数部分都必须相等
    int base = check(v[0]);
    for (int i = 1; i < n; i++)
    {
        if (check(v[i]) != base)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}