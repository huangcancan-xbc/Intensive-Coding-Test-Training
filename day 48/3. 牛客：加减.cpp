// 牛客：加减
// 链接：https://ac.nowcoder.com/acm/problem/224938

// 方法：枚举 + 排序 + 前缀和 + 滑动窗口 + 贪心
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
LL n, k;
LL arr[N];
LL sum[N]; // 前缀和数组

LL cal(int l, int r)
{
    int mid = (l + r) / 2;
    return (mid - l - r + mid) * arr[mid] - (sum[mid - 1] - sum[l - 1]) + (sum[r] - sum[mid]);
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    sort(arr + 1, arr + 1 + n);
    // 初始化前缀和数组
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + arr[i];
    }

    int left = 1, right = 1, ret = 1;
    while (right <= n)
    {
        // 进窗口
        LL cost = cal(left, right);

        while (cost > k) // 判断
        {
            left++; // 出窗口
            cost = cal(left, right);
        }

        // 更新结果
        ret = max(ret, right - left + 1);
        right++;
    }

    cout << ret << endl;

    return 0;
}