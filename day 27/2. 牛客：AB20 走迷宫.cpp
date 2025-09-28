// 牛客：AB20 走迷宫
// 链接：https://www.nowcoder.com/practice/e88b41dc6e764b2893bc4221777ffe64?tpId=308&tqId=40477&ru=/exam/oj

// 注意层数统计时机、变量是否一一对应、数组下标映射的问题！
// 方法：BFS

// 方法一：层次遍历 BFS 写法
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool vis[1010][1010];

int n, m, x1, y1, x2, y2, ret = 0;
int bfs(vector<vector<char>>& v, int x1, int y1)
{
    queue<PII> q;
    q.push({ x1,y1 });
    vis[x1][y1] = true;

    while (q.size())
    {
        int size = q.size();                        // 当前层的节点数

        while (size--)
        {
            auto [a, b] = q.front();
            q.pop();

            if (a == x2 && b == y2)
            {
                return ret;                         // 如果找到目标点，返回层数
            }

            for (int i = 0; i < 4; i++)
            {
                int x = a + dx[i], y = b + dy[i];
                if (x >= 1 && x <= n && y >= 1 && y <= m && !vis[x][y] && v[x][y] == '.')
                {
                    q.push({ x,y });
                    vis[x][y] = true;
                }
            }
        }

        ret++;                                      // 层数+1
    }

    return -1;
}

int main()
{
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    vector<vector<char>> v(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> v[i][j];
        }
    }

    cout << bfs(v, x1, y1) << endl;

    return 0;
}




// 方法二：bfs + 数组记录距离
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1010;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int n, m;
int x1, y1, x2, y2;

char arr[N][N];                 // 地图：'.' 表示空地，'*' 表示障碍
int dist[N][N];                 // 距离数组：记录从起点到 (i,j) 的最短步数
// 注意：int dist[N][N] = { -1 };不会将全部元素初始化为 -1，只会将第一个元素 dist[0][0] 初始化为 -1，剩下的全部初始化为 0。
int bfs()
{
    if (arr[x2][y2] == '*')
    {
        return -1;              // 特判：如果目标位置是障碍物，那么直接返回 -1
    }

    memset(dist, -1, sizeof(dist));         // 初始化成 -1 表示没有访问过
    queue<pair<int, int>> q;
    q.push({ x1, y1 });
    dist[x1][y1] = 0;           // 起点距离设为 0

    while (q.size())
    {
        auto [a, b] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = a + dx[i], y = b + dy[i];
            if (x >= 1 && x <= n && y >= 1 && y <= m && arr[x][y] == '.' && dist[x][y] == -1)
            {
                q.push({ x, y });
                dist[x][y] = dist[a][b] + 1;// 更新距离

                if (x == x2 && y == y2)
                {
                    return dist[x2][y2];    // 如果到达目标点，直接返回答案
                }
            }
        }
    }
    return -1;
}

int main()
{
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << bfs() << endl;
    return 0;
}
// 或者：
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int n, m;
int x1, y1, x2, y2;
bool vis[1010][1010];
int dist[1010][1010]; // 记录每个点的最短距离

int bfs(vector<vector<char>>& g)
{
    queue<PII> q;
    q.push({ x1, y1 });
    vis[x1][y1] = true;
    dist[x1][y1] = 0;

    while (!q.empty())
    {
        auto [a, b] = q.front();
        q.pop();

        if (a == x2 && b == y2)
        {
            return dist[a][b];
        }

        for (int i = 0; i < 4; i++)
        {
            int x = a + dx[i], y = b + dy[i];
            if (x >= 1 && x <= n && y >= 1 && y <= m && !vis[x][y] && g[x][y] == '.')
            {
                vis[x][y] = true;
                dist[x][y] = dist[a][b] + 1; // 当前距离 + 1
                q.push({ x, y });
            }
        }
    }

    return -1; // 无法到达
}

int main()
{
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    vector<vector<char>> g(n + 1, vector<char>(m + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }

    cout << bfs(g) << endl;
    return 0;
}