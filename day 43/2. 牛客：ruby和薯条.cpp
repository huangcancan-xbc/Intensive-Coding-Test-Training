// 牛客：ruby和薯条
// 链接：https://ac.nowcoder.com/acm/problem/26224

// 方法一：排序 + 二分
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 找第一个 >= key 的下标
int lower(vector<long long>& v, int left, int right, long long key)
{
    int ret = right + 1;                // 默认返回 end() 位置
    while (left <= right)
    {
        int mid = (left + right) >> 1;
        if (v[mid] >= key)
        {
            ret = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return ret;
}

// 找第一个 > key 的下标
int upper(vector<long long>& v, int left, int right, long long key)
{
    int ret = right + 1;
    while (left <= right)
    {
        int mid = (left + right) >> 1;
        if (v[mid] > key)
        {
            ret = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return ret;
}

int main()
{
    long long n, l, r;
    cin >> n >> l >> r;

    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());   // 排序

    long long ret = 0;
    for (int i = 0; i < n; i++)
    {
        // 搜索区间：右侧 [i+1, n-1]
        int low = lower(v, i + 1, n - 1, v[i] + l);
        int high = upper(v, i + 1, n - 1, v[i] + r);
        ret += (high - low);
    }

    cout << ret << "\n";
    return 0;
}




// 使用库函数 lower_bound 和 upper_bound
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    long long n, l, r;
    cin >> n >> l >> r;

    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());   // 先排序

    long long ret = 0;

    for (int i = 0; i < n; i++)
    {
        // 对于固定的 v[i]，找右边满足条件的范围
        // 目标区间： [v[i] + l, v[i] + r]
        auto low = lower_bound(v.begin() + i + 1, v.end(), v[i] + l);
        auto high = upper_bound(v.begin() + i + 1, v.end(), v[i] + r);
        ret += (high - low);   // 区间长度就是满足条件的对数
    }

    cout << ret << "\n";
    return 0;
}






// 优解：
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;
int n, l, r;
int arr[N];

int main()
{
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    sort(arr + 1, arr + n + 1);

    long long ret = 0;
    for (int i = 2; i <= n; i++)                    // 枚举右端点 arr[i]
    {
        int L, R;

        // 找左边界 L，目标：找到最小的 j，使得 arr[j] >= arr[i] - r
        int left = 1, right = i - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;

            if (arr[mid] >= arr[i] - r)
            {
                right = mid;                        // 往左收缩
            }
            else
            {
                left = mid + 1;                     // 否则往右
            }
        }

        if (arr[left] >= arr[i] - r)
        {
            L = left;
        }
        else
        {
            L = left + 1;                           // 没找到则顺延
        }

        // 找右边界 R，目标：找到最大的 j，使得 arr[j] <= arr[i] - l
        left = 1, right = i - 1;
        while (left < right)
        {
            int mid = (left + right + 1) / 2;       // 注意这里取右中位数，避免死循环
            
            if (arr[mid] <= arr[i] - l)
            {
                left = mid;                         // 满足条件，往右找更大
            }
            else
            {
                right = mid - 1;                    // 否则往左
            }
        }

        if (arr[left] <= arr[i] - l)
        {
            R = left;
        }
        else
        {
            R = left - 1;
        }

        // 累加答案，只有当 L <= R 时，区间才合法
        if (R >= L)
        {
            ret += R - L + 1;
        }
    }

    cout << ret << endl;
    return 0;
}




// 解法二：排序 + 前缀和 + 滑动窗口
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;
int n, l, r;
int arr[N];

// 找出差值在 [0, x] 之间一共有多少对
long long find(int x)
{
    int left = 0, right = 0;
    long long ret = 0;
    while (right < n)
    {
        while (arr[right] - arr[left] > x)
        {
            left++;
        }

        ret += right - left;
        right++;
    }

    return ret;
}

int main()
{
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    cout << find(r) - find(l - 1) << endl;

    return 0;
}




// 解法三：排序 + 数学 + 双指针
// l <= |arr[i]-arr[j]| <= r    =>   通过 sort 规定 i > j，则 l <= arr[i]-arr[j] <= r
// 数学移项得 arr[i]-r <= arr[j] <= arr[i]-l
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    long long l, r;
    cin >> n >> l >> r;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    long long ans = 0;
    int left = 0, right = 0;

    for (int i = 0; i < n; i++)
    {
        // 区间目标：[arr[i] - r, arr[i] - l]
        long long low = arr[i] - r;
        long long high = arr[i] - l;

        while (left < i && arr[left] < low)
        {
            left++;             // 移动 left 指针，找到第一个 >= low 的位置
        }

        while (right < i && arr[right] <= high)
        {
            right++;            // 移动 right 指针，找到最后一个 <= high 的位置
        }

        
        if (right > left)
        {
            ans += (right - left);      // [left, right) 就是合法区间
        }
    }

    cout << ans << "\n";
    return 0;
}