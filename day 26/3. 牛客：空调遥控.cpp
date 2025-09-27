// 牛客：空调遥控
// 方法：https://ac.nowcoder.com/acm/problem/229310

// |a[i] - K| <= p      →        -p <= a[i] - K <= p        →       K - p <= a[i] <= K + p
// 注意：对于每个 v[i]，其能接受的温度区间是 [v[i] - p, v[i] + p]

// 方法一：暴力（超时）
#include <iostream>
#include <vector>
using namespace std;

long long n, p, ret, maxval, minval = 0x3f3f3f3f;

int main()
{
    cin >> n >> p;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        maxval = max(maxval, v[i]);
        minval = min(minval, v[i]);
    }

    for (int i = minval - p; i <= maxval + p; i++)
    {
        long long temp = 0;
        for (int i = 0; i < n; i++)
        {
            if (abs(v[i] - i) <= p)
            {
                temp++;
            }
        }

        ret = max(ret, temp);
    }

    cout << ret << endl;

    return 0;
}




// 方法二：排序 + 二分
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long n, p, ret;

int main()
{
    cin >> n >> p;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        long left = v[i] - p, right = v[i] + p;
        long l = lower_bound(v.begin(), v.end(), left) - v.begin();
        long r = upper_bound(v.begin(), v.end(), right) - v.begin();

        ret = max(ret, r - l);
    }

    cout << ret << endl;

    return 0;
}
// 手动实现：lower_bound 和 upper_bound
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long n, p, ret;
int lower(const vector<long>& v, long target)
{
    long l = 0, r = v.size();           // 注意：右边界是 arr.size()，非 arr.size()-1
    while (l < r)
    {
        long mid = l + (r - l) / 2;
        if (v[mid] >= target)
        {
            r = mid;                    // mid 可能就是答案，继续缩右边
        }
        else
        {
            l = mid + 1;                // 排除左边
        }

    }
    return l;
}

int upper(const vector<long>& v, long target)
{
    long l = 0, r = v.size();
    while (l < r)
    {
        long mid = l + (r - l) / 2;
        if (v[mid] > target)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}

int main()
{
    cin >> n >> p;
    vector<long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        long left = v[i] - p, right = v[i] + p;
        long l = lower(v, left);
        long r = upper(v, right);

        ret = max(ret, r - l);
    }

    cout << ret << endl;

    return 0;
}



// 方法三：滑动窗口

// 每个 v[i]，其能接受的温度区间是 [v[i] - p, v[i] + p]，我们想选一个合适的 K，使得有最多的 a[i] 落在这个长度为 2p 的闭区间 [K - p, K + p] 内。
// 即在一个数组中，找一个连续子区间，其最大值和最小值之差不超过 2p，这个区间中包含的元素最多。
// 所以有 max - min <= 2*p，我们只需要维护窗口内最大值与最小值的差在 2*p之间。
// 枚举所有的温度，二分出符合要求的学生区间，然后统计个数。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long n, p, ret;

int main()
{
    cin >> n >> p;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int left = 0, right = 0;
    p *= 2;
    while (right < n)
    {
        while (v[right] - v[left] > p)
        {
            left++;
        }

        ret = max(ret, (long)(right - left + 1));
        right++;
    }

    cout << ret << endl;

    return 0;
}
// 或者（优解）：
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;
int n, p;
int arr[N];

int main()
{
    cin >> n >> p;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int ret = 0, left = 0, right = 0;
    p *= 2;

    while (right < n)
    {
        while (arr[right] - arr[left] > p)
        {
            left++;
        }

        ret = max(ret, right - left + 1);
        right++;
    }

    cout << ret << endl;

    return 0;
}




// 方法四：差分 + 前缀和
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e6 + 10;               // 最大温度值（温度上限为 1e6）

int main()
{
    int n, p;
    cin >> n >> p;

    vector<int> diff(MAX + 2, 0);       // 差分数组（注意要多开一点防止越界）

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;                       // 每个人的温度诉求值 v[i]

        // 每个人可以接受的温度范围是 [x - p, x + p]
        int l = max(0, x - p);          // 区间左端点，不能小于0
        int r = min(MAX, x + p);        // 区间右端点，不能大于最大值

        diff[l] += 1;                   // 差分标记：l位置开始 +1
        diff[r + 1] -= 1;               // r+1 位置开始 -1，表示 r 结束
    }

    int ret = 0, sum = 0;
    for (int i = 0; i <= MAX; ++i)
    {
        sum += diff[i];                 // 前缀和，表示当前温度 i 有多少人接受
        ret = max(ret, sum);            // 找出最大的 sum，即最多能同时训练的人数
    }

    cout << ret << endl;                // 输出结果
    return 0;
}