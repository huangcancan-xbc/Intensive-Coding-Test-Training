// 牛客：kotori和迷宫
// 链接：https://ac.nowcoder.com/acm/problem/50041

// 方法：BFS/DFS
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 35;
int x1, y1;                             // 记录起点 'k' 的位置
int n, m;
char arr[N][N];
int dist[N][N];                         // dist[i][j] 表示从起点到 (i,j) 的最短步数
queue<pair<int, int>> q;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs()
{
    memset(dist, -1, sizeof dist);      // 初始化所有位置为 -1，表示未访问
    dist[x1][y1] = 0;                   // 起点到自身距离为 0
    q.push({ x1, y1 });

    while (q.size())
    {
        auto [x2, y2] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int a = x2 + dx[i], b = y2 + dy[i];

            if (a >= 1 && a <= n && b >= 1 && b <= m && dist[a][b] == -1 && arr[a][b] != '*')
            {
                dist[a][b] = dist[x2][y2] + 1;      // 距离加一

                if (arr[a][b] != 'e')               // 如果当前不是终点 'e'，就继续向外扩展
                {
                    q.push({ a, b });
                }

                // 如果是 'e'，我们也记录距离，但不再扩展，因为终点不需要继续走
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'k')
            {
                x1 = i, y1 = j;             // 记录起点位置
            }
        }
    }

    bfs();

    int count = 0;                          // 记录可达的 'e' 数量
    int ret = 1e9;                          // 记录所有可达 'e' 中最短的路径长度

    // 枚举地图，寻找所有可达的 'e'
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] == 'e' && dist[i][j] != -1)
            {
                count++;                    // 可达的终点 +1
                ret = min(ret, dist[i][j]); // 记录最短距离
            }
        }
    }

    if (count == 0)
    {
        cout << -1 << endl;                 // 没有任何可达的终点
    }
    else
    {
        cout << count << " " << ret << endl;// 输出可达终点数量和最短路径
    }

    return 0;
}