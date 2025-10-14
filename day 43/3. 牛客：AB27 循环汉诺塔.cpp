// 牛客：AB27 循环汉诺塔
// 链接：https://www.nowcoder.com/share/jump/5170733851759317618499

// 方法：动态规划/找规律/递推
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
int n;

int main()
{
    cin >> n;
    int x = 1, y = 2;
    for (int i = 2; i <= n; i++)
    {
        int xx = x, yy = y;
        x = (2 * yy + 1) % MOD;
        y = ((2 * yy) % MOD + 2 + xx) % MOD;
    }

    cout << x << " " << y << endl;

    return 0;
}