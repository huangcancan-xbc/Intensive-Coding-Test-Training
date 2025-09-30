// 牛客：AB33 相差不超过k的最多数
// 链接：https://www.nowcoder.com/practice/562630ca90ac40ce89443c91060574c6?tpId=308&tqId=40490&ru=/exam/oj

// 方法：排序 + 滑动窗口
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, k, ret;

int main()
{
    cin >> n >> k;
    vector<long long> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    long long left = 1, right = 1;
    while (right <= n)
    {
        while (v[right] - v[left] > k)
        {
            ++left;
        }

        ++right;
        ret = max(ret, right - left);
    }

    cout << ret << endl;
    return 0;
}



// 优解：
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;
int n, k;
int arr[N];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int left = 0, right = 0, ret = 1;
    while (right < n)
    {
        while (arr[right] - arr[left] > k)
        {
            left++;
        }

        ret = max(ret, right - left + 1);
        right++;
    }

    cout << ret << endl;
    return 0;
}