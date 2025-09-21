// 牛客：DP6 连续子数组最大和(ACM版本)
// 链接：https://www.nowcoder.com/practice/1718131e719746e9a56fb29c40cc8f95?tpId=230&tqId=39753&ru=/exam/oj

// 方法一：滑动窗口
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n, ret = LLONG_MIN;
    cin >> n;

    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    long long sum = 0;
    for (int left = 0, right = 0; right < n; right++)
    {
        sum += v[right];
        ret = max(ret, sum);

        while (sum < 0)
        {
            sum -= v[left++];
        }
    }

    cout << ret << endl;

    return 0;
}




// 方法二：动态规划
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    long long n, ret = LLONG_MIN;
    cin >> n;

    vector<long long> v(n), dp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    dp[0] = v[0];

    ret = max(ret, dp[0]);         // 特判长度为一的情况
    // long long ret = dp[0];

    for (int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i - 1], 0LL) + v[i];
        ret = max(ret, dp[i]);
    }

    cout << ret << endl;
    return 0;
}



// 优化：
#include <iostream>
#include <climits>
using namespace std;

const int N = 2e5 + 10;
int n;
int dp[N];
int arr[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    int ret = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], 0) + arr[i];
        ret = max(ret, dp[i]);
    }

    cout << ret << endl;
    return 0;
}




// 使用滚动数组优化空间复杂度
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long ret = LLONG_MIN, sum = 0;

    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        sum = max(sum, 0LL) + x;  // 如果当前和为负，直接加0即可，相当于舍弃之前的负数
        ret = max(ret, sum);      // 记录最大值
    }

    cout << ret << endl;
    return 0;
}
// 或者：
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    long long sum = v[0];        // 当前和
    long long ret = v[0];        // 最大值

    for (int i = 1; i < n; i++)
    {
        if (sum < 0) sum = 0;    // 如果之前的和是负的，直接断开，重开一段
        sum += v[i];             // 否则累加当前值
        ret = max(ret, sum);     // 更新最大值
    }

    cout << ret << endl;
    return 0;
}