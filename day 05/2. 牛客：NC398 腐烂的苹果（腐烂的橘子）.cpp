// 牛客：NC398 腐烂的苹果（腐烂的橘子）
// 链接：https://www.nowcoder.com/practice/54ab9865ce7a45968b126d6968a77f34?tpId=196&tqId=40529&ru=/exam/oj

// 方法：多源BFS + 最短路问题
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param grid int整型vector<vector<>>
     * @return int整型
     */
    int rotApple(vector<vector<int> >& grid)
    {
        // write code here
        int n = grid.size(), m = grid[0].size();
        int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 }, ret = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({ i,j });
                }
            }
        }

        while (q.size())
        {
            ret++;                                  // 每进行一层BFS，相当于过了1分钟
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                auto [a, b] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int x = dx[k] + a, y = dy[k] + b;
                    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1)
                    {
                        q.push({ x,y });
                        grid[x][y] = 2;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        // 注意：BFS 的每一层之前就进行了 ret++，这意味着提前把第一层的时间算进去了。ret - 1 是为了扣除初始轮次（第 0 分钟）的影响，确保返回的是 实际传播腐烂的分钟数。
        return ret - 1;
    }
};




// 优解：
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param grid int整型vector<vector<>>
     * @return int整型
     */

    int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 }, ret = 0;
    bool vis[1010][1010] = { false };
    int rotApple(vector<vector<int> >& grid)
    {
        // write code here
        int n = grid.size(), m = grid[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({ i,j });
                }
            }
        }

        while (q.size())
        {
            ret++;
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                auto [a, b] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int x = dx[k] + a, y = dy[k] + b;
                    if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && grid[x][y] == 1)
                    {
                        q.push({ x,y });
                        vis[x][y] = true;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    return -1;
                }
            }
        }

        return ret - 1;
    }
};



// 腐烂的橘子代码搬运：
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param grid int整型vector<vector<>>
     * @return int整型
     */

    typedef pair<int, int> pii;
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    bool vis[1010][1010];
    int ret = 0;
    int n, m;

    int rotApple(vector<vector<int> >& grid)
    {
        // write code here
        n = grid.size(), m = grid[0].size();
        queue<pii> q;
        bool news = false;

        // 扫描网格，将所有腐烂的橘子加入队列，初始时这些橘子开始腐烂
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({ i, j });
                    vis[i][j] = true;
                }
                else if (grid[i][j] == 1)
                {
                    news = true;                        // 发现新鲜橘子
                }
            }
        }

        if (!news)
        {
            return 0;                                   // 如果没有新鲜橘子，直接返回0
        }

        int minute = 0;                                 // 记录腐烂过程所需的分钟数

        // 进行BFS
        while (q.size())
        {
            int size = q.size();                        // 当前层级的橘子数
            bool cur = false;                           // 当前层级是否有新鲜橘子腐烂

            for (int i = 0; i < size; i++)
            {
                auto [a, b] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int x = a + dx[k], y = b + dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 && !vis[x][y])
                    {
                        q.push({ x, y });
                        vis[x][y] = true;               // 标记新鲜橘子为已腐烂
                        cur = true;                     // 当前轮次有新鲜橘子腐烂
                    }
                }
            }

            if (cur)                                    // 如果这一轮有橘子腐烂，时间加1
            {
                minute++;
            }
        }

        // 再次扫描一遍网格，看是否还有新鲜橘子
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    return -1;                          // 仍然有新鲜橘子没有 腐烂
                }
            }
        }

        return minute;                                  // 返回腐烂过程所需的分钟数
    }
};