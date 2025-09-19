// 牛客：chika和蜜柑
// 链接：https://ac.nowcoder.com/acm/problem/26221

// 方法一：“堆” + 自定义排序（TOPK问题的一种）
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<long long, long long> PII;
const int N = 2e+5;
PII v[N];
int n, k;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].second;
    }

    sort(v, v + n, [&](const PII& a, const PII& b)
        {
            if (a.second != b.second)
            {
                return a.second > b.second;
            }
            else
            {
                return a.first < b.first;
            }
        });

    long long acid = 0, sweet = 0;
    for (int i = 0; i < k; i++)
    {
        acid += v[i].first;
        sweet += v[i].second;
    }

    cout << acid << ' ' << sweet << endl;

    return 0;
}




// 方法二：堆 + 自定义排序(实实在在的TOPK堆)
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef pair<long long, long long> PII;
vector<long long> acid, sweet;
int n, k;

struct cmp
{
    bool operator()(const PII& a, const PII& b)
    {
        if (a.second != b.second)
        {
            return a.second > b.second;
        }

        return a.first < b.first;
    }
};

int main()
{
    cin >> n >> k;
    acid.resize(n);                 // 注意重新分配空间，避免越界
    sweet.resize(n);                // 注意重新分配空间，避免越界

    for (int i = 0; i < n; i++)
    {
        cin >> acid[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> sweet[i];
    }

    priority_queue<PII, vector<PII>, cmp> q;

    for (int i = 0; i < n; i++)
    {
        PII cur = { acid[i],sweet[i] };
        q.push(cur);

        if ((int)q.size() > k)
        {
            q.pop();
        }
    }

    long long sum_acid = 0, sum_sweet = 0;
    while ((int)q.size())
    {
        sum_acid += q.top().first;
        sum_sweet += q.top().second;
        q.pop();
    }

    cout << sum_acid << ' ' << sum_sweet << endl;

    return 0;
}