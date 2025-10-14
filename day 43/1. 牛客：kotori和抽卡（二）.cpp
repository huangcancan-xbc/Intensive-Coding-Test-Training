// 牛客：kotori和抽卡（二）
// 链接：https://ac.nowcoder.com/acm/problem/50044

// 方法：高中数学概率
#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    double ret = 1.0;
    for (int i = n; i >= n - m + 1; i--)
    {
        ret *= i;
    }

    for (int i = m; i >= 2; i--)
    {
        ret /= i;
    }

    for (int i = 0; i < m; i++)
    {
        ret *= 0.8;
    }

    for (int i = 0; i < n - m; i++)
    {
        ret *= 0.2;
    }

    printf("%.4lf", ret);

    return 0;
}