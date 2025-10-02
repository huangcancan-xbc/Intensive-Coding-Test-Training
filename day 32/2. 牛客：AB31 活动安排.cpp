// 牛客：AB31 活动安排
// 链接：https://www.nowcoder.com/practice/16d971e9e42e4f3b9b1e2b8794796a43?tpId=308&tqId=40488&ru=/exam/oj

// 方法：区间问题 + 排序 + 贪心
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n;

int main()
{
    cin >> n;
    vector<vector<long long>> v(n, vector<long long>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1];
    }

    sort(v.begin(), v.end());

    long long ret = 1, r = v[0][1];
    for (int i = 1; i < n; i++)
    {
        if (v[i][0] < r)
        {
            r = min(r, v[i][1]);
        }
        else
        {
            ret++;
            r = v[i][1];
        }
    }

    cout << ret << endl;

    return 0;
}




// 优解：
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;
const int N = 2e5 + 10;
int n;
PII arr[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr, arr + n);

    int ret = 0, r = arr[0].second;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].first < r)
        {
            r = min(r, arr[i].second);
        }
        else
        {
            ret++;
            r = arr[i].second;
        }
    }
    cout << ret + 1 << endl;
    return 0;
}