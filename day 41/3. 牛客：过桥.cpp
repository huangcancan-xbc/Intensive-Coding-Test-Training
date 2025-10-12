// 牛客：过桥
// 链接：https://ac.nowcoder.com/acm/problem/229296

// 方法一：贪心 + BFS

//用 BFS 思维，把问题转化为「层数最少」。
//每一层就是一个[left..right] 区间，表示当前一次跳跃能到达的范围。
//在区间内扩展最远能到达的位置，形成下一层。
//当最远位置 >= n 时，返回当前层数，即最少跳跃次数。

#include <iostream>
using namespace std;

const int N = 2010;
int n;
int arr[N];

int bfs()
{
    int left = 1, right = 1;
    int ret = 0;

    while (left <= right)
    {
        ret++;
        int r = right;
        for (int i = left; i <= right; i++)
        {
            r = max(r, arr[i] + i);
            if (r >= n)
            {
                return ret;
            }
        }

        left = right + 1;
        right = r;
    }

    return -1;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    cout << bfs() << endl;

    return 0;
}




// 方法二：队列 + 贪心
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 2010;
int n;
int arr[N];
int dist[N];   // 记录到达每个位置的最少步数（0 表示未访问）

int bfs()
{
    queue<int> q;
    q.push(1);           // 从位置 1 出发
    dist[1] = 0;         // 起点步数是 0

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        // 遍历所有能到达的位置
        for (int v = u + 1; v <= min(n, u + arr[u]); v++)
        {
            if (dist[v] == 0 && v != 1)   // 没访问过
            {
                dist[v] = dist[u] + 1;    // 更新最少步数
                q.push(v);

                if (v == n) return dist[v];   // 到达终点，直接返回
            }
        }
    }

    return -1;  // 无法到达
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    cout << bfs() << endl;

    return 0;
}