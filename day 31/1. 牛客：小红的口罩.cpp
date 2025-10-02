// 牛客：小红的口罩
// 链接：https://ac.nowcoder.com/acm/problem/229953

// 方法：贪心 + 小根堆
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long n, k, sum = 0, ret = -1;
    cin >> n >> k;

    vector<long> v(n);
    priority_queue<long, vector<long>, greater<long>> q;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        q.push(v[i]);
    }

    while (sum <= k)
    {
        sum += q.top();
        long temp = q.top() * 2;
        q.pop();
        q.push(temp);
        ret++;
    }

    cout << (ret == -1 ? 0 : ret) << endl;

    return 0;
}



// 优解：
#include <iostream>
#include <queue>
using namespace std;

int n, k;

int main()
{
    cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        heap.push(x);
    }

    int sum = 0, count = 0;
    while (true)
    {
        int t = heap.top();
        heap.pop();
        sum += t;
        heap.push(t * 2);
        count++;
        if (sum > k)
        {
            cout << count - 1 << endl;
            break;
        }
    }

    return 0;
}