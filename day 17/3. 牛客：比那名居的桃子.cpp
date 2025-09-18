// 牛客：比那名居的桃子
// 链接：https://ac.nowcoder.com/acm/problem/224679

// 方法一：暴力枚举
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    long long maxh = 0, maxs = 0, ret = 0;

    for (int i = 0; i <= n - k; i++)
    {
        long long happy = 0, shame = 0;
        for (int j = i; j < i + k; j++)
        {
            happy += a[j];
            shame += b[j];
        }

        if (happy > maxh || (happy == maxh && shame < maxs) || (happy == maxh && shame == maxs && i < ret))
        {
            maxh = happy;
            maxs = shame;
            ret = i + 1;                    // 天数不是从 0 开始的，所以要加 1
        }
    }
    cout << ret << endl;

    return 0;
}




// 方法二：滑动窗口
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    long long sumh = 0, sums = 0, ret = 0;
    long long maxh = 0, maxs = 0;
    for (int left = 0, right = 0; right < n; right++)
    {
        sumh += a[right];
        sums += b[right];

        if (right - left + 1 > k)
        {
            sumh -= a[left];
            sums -= b[left];
            left++;
        }

        if (right - left + 1 == k)
        {
            if (sumh > maxh || (sumh == maxh && sums < maxs) || (sumh == maxh && sums == maxs && left < ret))
            {
                maxh = sumh;
                maxs = sums;
                ret = left + 1;             // 天数不是从 0 开始的，所以要加 1
            }
        }
    }
    cout << ret << endl;

    return 0;
}




// 方法三：前缀和
// 注意下标的映射关系！
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<long long> a(n + 1), b(n + 1);
    vector<long long> suma(n + 1, 0), sumb(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        suma[i] = suma[i - 1] + a[i];       // 构建 a 的前缀和
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        sumb[i] = sumb[i - 1] + b[i];       // 构建 b 的前缀和
    }

    long long maxh = 0, maxs = 0, ret = 0;

    for (int i = 1; i <= n - k + 1; i++)
    {
        long long tempa = suma[i + k - 1] - suma[i - 1];
        long long tempb = sumb[i + k - 1] - sumb[i - 1];

        if (tempa > maxh || (tempa == maxh && tempb < maxs) || (tempa == maxh && tempb == maxs && i < ret))
        {
            maxh = tempa;
            maxs = tempb;
            ret = i;                        // 这里已经全部替换了从 1 开始自然就不需要加1了！
        }
    }

    cout << ret << endl;

    return 0;
}