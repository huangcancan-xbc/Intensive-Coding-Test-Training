// 牛客：天使果冻
// 链接：https://ac.nowcoder.com/acm/problem/219641

// 方法一：堆（超时）
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int q;
    cin >> q;

    while (q--)
    {
        priority_queue<int> heap;
        int x;
        cin >> x;

        for (int i = 0; i < x; i++)
        {
            heap.push(v[i]);
        }

        heap.pop();
        cout << heap.top() << endl;
    }

    return 0;
}



// 方法二：“双指针”
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n + 1), memo(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    int left = min(v[1], v[2]), right = max(v[1], v[2]);
    memo[2] = left;
    int i = 3;
    while (i <= n)
    {
        if (v[i] >= left && v[i] <= right)
        {
            left = v[i];
        }
        else if (v[i] >= right)
        {
            left = right;
            right = v[i];
        }

        memo[i] = left;
        ++i;
    }

    // for(auto x:memo)
    // {
    //     cout<<x<<' ';
    // }


    int x, q;
    cin >> q;
    while (q--)
    {
        cin >> x;
        cout << memo[x] << endl;
    }

    return 0;
}




// 方法三：递推/动态规划
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, q;
int arr[N];
int f[N], g[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    // 更新最大值以及次大值数组
    f[1] = arr[1];
    for (int i = 2; i <= n; i++)
    {
        int x = arr[i];
        f[i] = max(f[i - 1], x);

        if (x >= f[i - 1])
        {
            g[i] = f[i - 1];
        }
        else if (x >= g[i - 1])
        {
            g[i] = x;
        }
        else
        {
            g[i] = g[i - 1];
        }
    }

    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        cout << g[x] << endl;
    }

    return 0;
}