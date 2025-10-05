// 牛客：NC138 矩阵最长递增路径
// 链接：https://www.nowcoder.com/practice/7a71a88cdf294ce6bdf54c899be967a2?tpId=196&tqId=37184&ru=/exam/oj

// 方法一：递归/暴搜（理论会超时）
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 递增路径的最大长度
     * @param matrix int整型vector<vector<>> 描述矩阵的每个数
     * @return int整型
     */
    int m, n;
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };

    int dfs(vector<vector<int>>& matrix, int i, int j)
    {
        int len = 1;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j])
            {
                len = max(len, 1 + dfs(matrix, x, y));
            }
        }

        return len;
    }

    int solve(vector<vector<int> >& matrix)
    {
        // write code here
        m = matrix.size(), n = matrix[0].size();

        int ret = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ret = max(ret, dfs(matrix, i, j));
            }
        }

        return ret;
    }
};



// 方法二：备忘录/记忆化搜索
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 递增路径的最大长度
     * @param matrix int整型vector<vector<>> 描述矩阵的每个数
     * @return int整型
     */
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    int n, m;
    vector<vector<int>> dp;     // 记忆化数组
    int dfs(vector<vector<int>>& matrix, int x, int y)
    {
        if (dp[x][y] != 0)
        {
            return dp[x][y];    // 已经算过了
        }

        int maxlen = 1;         // 至少为 1（包含当前点）

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] > matrix[x][y])
            {
                maxlen = max(maxlen, dfs(matrix, nx, ny) + 1);  // 递归查找更长路径
            }
        }

        dp[x][y] = maxlen;
        return maxlen;
    }

    int solve(vector<vector<int> >& matrix)
    {
        // write code here
        n = matrix.size();
        m = matrix[0].size();
        dp = vector<vector<int>>(n, vector<int>(m, 0));  // 初始化 dp

        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ret = max(ret, dfs(matrix, i, j));  // 枚举所有起点
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
     * 递增路径的最大长度
     * @param matrix int整型vector<vector<>> 描述矩阵的每个数
     * @return int整型
     */
    int m, n;
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    int memo[1010][1010];

    int dfs(vector<vector<int>>& matrix, int i, int j)
    {
        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }

        int len = 1;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j])
            {
                len = max(len, 1 + dfs(matrix, x, y));
            }
        }

        memo[i][j] = len;
        return len;
    }

    int solve(vector<vector<int> >& matrix)
    {
        // write code here
        m = matrix.size(), n = matrix[0].size();
        memset(memo, -1, sizeof(memo));

        int ret = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ret = max(ret, dfs(matrix, i, j));
            }
        }

        return ret;
    }
};