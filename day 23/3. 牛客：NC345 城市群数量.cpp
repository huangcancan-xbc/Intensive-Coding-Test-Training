// 牛客：NC345 城市群数量
// 链接：https://www.nowcoder.com/practice/71cde4dee669475f94d8d38832374ada?tpId=196&tqId=40411&ru=/exam/oj

// 刚开始做时，觉得很简单，本质就是“岛屿数量”，求连通块的数量，但是我犯了一个致命的错误：
// 错误地将邻接矩阵 m 当成了地图去“上下左右”搜索（通过30%）
// 正确的做法是：用 BFS 或 DFS 直接在图中找连通分量

// 方法：图的遍历（主要是邻接矩阵的遍历）/BFS/DFS/Flood Fill/连通块的数量

// 方法一：DFS 遍历
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param m int整型vector<vector<>>
     * @return int整型
     */
    void dfs(vector<vector<int>>& m, vector<bool>& vis, int i)
    {
        vis[i] = true;                          // 标记城市 i 已访问

        for (int j = 0; j < m.size(); ++j)
        {
            if (m[i][j] == 1 && !vis[j])        // 遍历与城市 i 相连接的所有其他城市 j，查找有没有连着的城市还没访问
            {
                dfs(m, vis, j);                 // 递归访问所有连通的城市
            }
        }
    }

    int citys(vector<vector<int>>& m)
    {
        int n = m.size();                       // 城市数量
        vector<bool> vis(n, false);             // 标记每个城市是否访问过
        int ret = 0;                            // 连通块数量（城市群数量）

        for (int i = 0; i < n; ++i)             // 遍历所有城市 i ，寻找还没被访问过的城市，把它当作新的城市群的起点
        {
            if (!vis[i])
            {
                dfs(m, vis, i);                 // 从未访问的城市出发，DFS 遍历整块城市群
                ret++;                          // 每次新的 DFS 是一个新城市群
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
     *
     * @param m int整型vector<vector<>>
     * @return int整型
     */
    bool vis[210] = { 0 };
    void dfs(vector<vector<int>>& m, int pos)
    {
        vis[pos] = true;
        for (int i = 0; i < m.size(); i++)
        {
            if (!vis[i] && m[pos][i])
            {
                dfs(m, i);
            }
        }
    }

    int citys(vector<vector<int> >& m)
    {
        // write code here
        int n = m.size();
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                ret++;
                dfs(m, i);
            }
        }

        return ret;
    }
};




// 方法二：BFS 遍历
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param m int整型vector<vector<>>
     * @return int整型
     */

    void bfs(vector<vector<int>>& m, vector<bool>& vis, int start)
    {
        queue<int> q;
        q.push(start);
        vis[start] = true;

        while (!q.empty())
        {
            int u = q.front(); q.pop();
            for (int v = 0; v < m.size(); ++v)
            {
                if (m[u][v] == 1 && !vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }

    int citys(vector<vector<int>>& m)
    {
        int n = m.size();
        vector<bool> vis(n, false);
        int ret = 0;

        for (int i = 0; i < n; ++i)
        {
            if (!vis[i])
            {
                bfs(m, vis, i);
                ret++;
            }
        }

        return ret;
    }
};