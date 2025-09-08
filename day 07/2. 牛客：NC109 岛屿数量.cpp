// 牛客：NC109 岛屿数量
// 链接：https://www.nowcoder.com/practice/0c9664d1554e466aa107d899418e814e?tpId=196&tqId=37167&ru=/exam/oj

// 方法一：宽搜 BFS
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 判断岛屿数量
     * @param grid char字符型vector<vector<>>
     * @return int整型
     */

    int n, m, ret = 0;
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    bool vis[205][205] = { 0 };

    void bfs(vector<vector<char> >& grid, int i, int j)
    {
        queue<pair<int, int>> q;
        q.push({ i,j });

        while (q.size())
        {
            auto [a, b] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int x = a + dx[k], y = b + dy[k];
                if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '1' && !vis[x][y])
                {
                    q.push({ x,y });
                    vis[x][y] = true;
                }
            }
        }

    }

    int solve(vector<vector<char> >& grid)
    {
        // write code here
        n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    ret++;
                    bfs(grid, i, j);
                }
            }
        }

        return ret;
    }
};



// 优解：
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 判断岛屿数量
     * @param grid char字符型vector<vector<>>
     * @return int整型
     */

    int dx[4] = { 0, 1, -1, 0 };
    int dy[4] = { 1, 0, 0, -1 };
    int m, n, ret = 0;

    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        grid[i][j] = '0';               // 把该位置先变成 '0'

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1')
            {
                dfs(grid, x, y);
            }
        }
    }

    int solve(vector<vector<char> >& grid)
    {
        // write code here
        m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    ret++;              // 发现一个岛屿
                    dfs(grid, i, j);    // 把这个岛屿全部修改成 '0'
                }
            }
        }
        return ret;
    }
};





// 方法二：深搜 DFS
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 判断岛屿数量
     * @param grid char字符型vector<vector<>>
     * @return int整型
     */
    int rows, cols;                                 // 网格行数、列数
    const int dx[4] = { -1, 1, 0, 0 };
    const int dy[4] = { 0, 0, -1, 1 };

    void dfs(vector<vector<char> >& grid, int x, int y)
    {
        // 边界条件 + 如果当前不是陆地就直接返回
        if (x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] != '1')
        {
            return;
        }

        grid[x][y] = '0';                           // 标记为已访问（将陆地淹没）

        for (int i = 0; i < 4; ++i)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            dfs(grid, newX, newY);
        }
    }

    int solve(vector<vector<char> >& grid)
    {
        rows = grid.size(), cols = grid[0].size();
        if (rows == 0)
        {
            return 0;
        }

        int ret = 0;

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++ret;                          // 找到新岛屿
                    dfs(grid, i, j);                // 淹没整个岛屿
                }
            }
        }

        return ret;
    }
};