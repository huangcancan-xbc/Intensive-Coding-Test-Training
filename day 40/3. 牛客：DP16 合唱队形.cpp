// 牛客：DP16 合唱队形
// 链接：https://www.nowcoder.com/practice/0045cd3e39634a66ada63c2adeb49234?tpId=230&tqId=39759&ru=/exam/oj

// 方法：动态规划（2个最长上升子序列模型）

//f[i] = 以 i 结尾的最长上升子序列长度。
//g[i] = 以 i 开始的最长下降子序列长度。
//最长「山形」 = max(f[i] + g[i] - 1)。
//答案 = 总人数 n - 山形长度。

#include <iostream>
using namespace std;

const int N = 1010;
int n;
int arr[N], f[N], g[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    // 从前向后
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }

    // 从后向前
    for (int i = n; i >= 1; i--)
    {
        g[i] = 1;
        for (int j = i + 1; j <= n; j++)
        {
            if (arr[i] > arr[j])
            {
                g[i] = max(g[i], g[j] + 1);
            }
        }
    }

    int len = 0;
    for (int i = 1; i <= n; i++)
    {
        len = max(len, f[i] + g[i] - 1);
    }

    cout << n - len << endl;

    return 0;
}




// 二分优化：
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1010;
int n;
int arr[N];
int f[N], g[N];

// 求 LIS 长度数组：O(n log n)
void getLIS(int a[], int n, int lis[])
{
    vector<int> tail; // 维护 LIS 的最小结尾
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        auto it = lower_bound(tail.begin(), tail.end(), x);
        if (it == tail.end())
        {
            tail.push_back(x);
            lis[i] = tail.size();
        }
        else
        {
            *it = x;
            lis[i] = it - tail.begin() + 1;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    // 1. 从左往右求 f[i]（以 i 结尾的 LIS 长度）
    getLIS(arr, n, f);

    // 2. 从右往左求 g[i]（以 i 开始的 LDS 长度 = 反向 LIS）
    int revArr[N];
    for (int i = 0; i < n; i++) revArr[i] = arr[n - 1 - i];
    getLIS(revArr, n, g);
    reverse(g, g + n); // 反转回来，保证 g[i] 对应 arr[i]

    // 3. 枚举山峰位置
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        len = max(len, f[i] + g[i] - 1);
    }

    cout << n - len << endl;
    return 0;
}