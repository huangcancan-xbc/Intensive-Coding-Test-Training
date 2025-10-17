// 牛客：AOE还是单体？
// 链接：https://ac.nowcoder.com/acm/problem/205048

// 方法一：前缀和 + 排序 + 枚举
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; long long x;
    cin >> n >> x;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // 1. 排序，方便处理“群体践踏次数 = 某个怪物血量”的情况
    sort(a.begin(), a.end());

    // 2. 计算前缀和，方便快速求区间和
    vector<long long> num(n + 1, 0);         // num[i] 表示前 i 个数的和（下标从 1 开始）
    for (int i = 1; i <= n; i++)
    {
        num[i] = num[i - 1] + a[i - 1];
    }

    // 3. 初始答案：不用践踏，直接单点打死所有怪物
    long long ret = num[n];

    // 4. 枚举群体践踏次数 = a[j]
    for (int j = 0; j < n; j++)
    {
        long long k = a[j];                  // 踩的次数
        long long sum = k * x;               // 群体花费

        // 单体花费：剩余怪物血量和 - (n - (j+1)) * k
        // 注意：j 是下标，第 j 个元素 = a[j]，前 (j+1) 个怪物血量 ≤ k，已被群体踩死
        long long right = num[n] - num[j + 1];      // 后面怪物血量总和
        long long temp = right - (n - (j + 1)) * k;

        long long zong = sum + temp;
        ret = min(ret, zong);
    }

    cout << ret << "\n";
    return 0;
}




// 方法二：贪心 + 排序（优解）
//贪心策略：
//如果剩余怪物的数量大于×时：使用AOE
//如果剩余怪物的数量小于等于×时：使用单体
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;
int n, x;
int arr[N];

int main()
{
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    sort(arr + 1, arr + 1 + n);
    long long ret = 0;
    int index = max(0, n - x); // 处理 x 过大的情况
    ret += arr[index] * x;
    for (int i = index + 1; i <= n; i++)
    {
        ret += arr[i] - arr[index];
    }

    cout << ret << endl;

    return 0;
}