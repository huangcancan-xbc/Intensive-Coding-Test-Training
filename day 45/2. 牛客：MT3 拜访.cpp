// 牛客：MT3 拜访
// 链接：https://www.nowcoder.com/share/jump/5170733851759397735027

// 方法：BFS
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param CityMap int整型vector<vector<>>
     * @param n int整型
     * @param m int整型
     * @return int整型
     */
    int _n, _m;
    int x1, y1, x2, y2;
    int dist[15][15] = { 0 };
    int cnt[15][15] = { 0 };
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };

    int bfs(vector<vector<int> >& CityMap)
    {
        memset(dist, -1, sizeof dist);
        queue<pair<int, int>> q;
        q.push({ x1, y1 });
        dist[x1][y1] = 0;
        cnt[x1][y1] = 1;

        while (q.size())
        {
            auto [a, b] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int x = a + dx[i], y = b + dy[i];
                if (x >= 0 && x < _n && y >= 0 && y < _m && CityMap[x][y] != -1)
                {
                    if (dist[x][y] == -1)                   // 第一次到这个位置
                    {
                        dist[x][y] = dist[a][b] + 1;
                        cnt[x][y] += cnt[a][b];
                        q.push({ x, y });
                    }
                    else                                    // 不是第一次到这个位置
                    {
                        if (dist[a][b] + 1 == dist[x][y])   // 是不是最短路
                        {
                            cnt[x][y] += cnt[a][b];
                        }
                    }
                }
            }
        }

        return cnt[x2][y2];
    }

    int countPath(vector<vector<int> >& CityMap, int n, int m)
    {
        // write code here
        _n = n, _m = m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (CityMap[i][j] == 1)
                {
                    x1 = i, y1 = j;
                }
                else if (CityMap[i][j] == 2)
                {
                    x2 = i, y2 = j;
                }
            }
        }

        return bfs(CityMap);
    }
};



// 或者：
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param CityMap int整型vector<vector<>>
     * @param n int整型
     * @param m int整型
     * @return int整型
     */
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    typedef pair<int, int> PII;

    int countPath(vector<vector<int> >& CityMap, int n, int m)
    {
        // write code here
        int x1, y1, x2, y2;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (CityMap[i][j] == 1)
                {
                    x1 = i, y1 = j;
                }

                if (CityMap[i][j] == 2)
                {
                    x2 = i, y2 = j;
                }
            }
        }

        vector<vector<int>> dist(n, vector<int>(m, 1e9));   // 最短距离
        vector<vector<int>> cnt(n, vector<int>(m, 0));      // 路径数
        queue<PII> q;

        dist[x1][y1] = 0;
        cnt[x1][y1] = 1;
        q.push({ x1,y1 });

        while (!q.empty())
        {
            auto [a, b] = q.front(); q.pop();

            for (int k = 0; k < 4; k++)
            {
                int x = a + dx[k], y = b + dy[k];
                if (x < 0 || x >= n || y < 0 || y >= m || CityMap[x][y] == -1)
                {
                    continue;
                }

                // 如果发现更短路径
                if (dist[x][y] > dist[a][b] + 1)
                {
                    dist[x][y] = dist[a][b] + 1;
                    cnt[x][y] = cnt[a][b];   // 路径数继承
                    q.push({ x,y });
                }
                // 如果发现相同最短路径
                else if (dist[x][y] == dist[a][b] + 1)
                {
                    cnt[x][y] += cnt[a][b];
                }
            }
        }

        return cnt[x2][y2];
    }
};