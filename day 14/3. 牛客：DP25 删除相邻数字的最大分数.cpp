// 牛客：DP25 删除相邻数字的最大分数
// 链接：https://www.nowcoder.com/practice/3bcf72c738b6494bbe1ebe0ffde56152?tpId=230&tqId=40419&ru=/exam/oj

// 方法：DP（打家劫舍问题的变形）
// 类比为“抢劫房子”的问题，房子就是数值 i，不能连续选择相邻的数值。
// f[i] 表示选择第 i 个数的最大收益。
// g[i] 表示不选择第 i 个数的最大收益。
#include <iostream>
#include <vector>
using namespace std;

int sum[100010];

int main()
{
    int n, maxval = 0;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum[v[i]] += v[i];
        maxval = max(maxval, v[i]);
    }

    vector<int> f(100010), g(100010);

    for (int i = 1; i <= maxval; i++)
    {
        f[i] = g[i - 1] + sum[i];
        g[i] = max(f[i - 1], g[i - 1]);
    }

    cout << max(f[maxval], g[maxval]) << endl;

    return 0;
}



// 优解：
#include <iostream>
using namespace std;

const int N = 1e4 + 10;
int sum[N]; // sum[i] 表示 i 出现的总和
int n;
int f[N], g[N];

int main()
{
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        sum[x] += x;
    }

    for (int i = 1; i < N; i++)
    {
        f[i] = g[i - 1] + sum[i];
        g[i] = max(f[i - 1], g[i - 1]);
    }

    cout << max(f[N - 1], g[N - 1]) << endl;

    return 0;
}