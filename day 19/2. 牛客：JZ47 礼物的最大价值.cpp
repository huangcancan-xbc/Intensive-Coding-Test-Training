// 牛客：JZ47 礼物的最大价值
// 链接：https://www.nowcoder.com/practice/2237b401eb9347d282310fc1c3adb134?tpId=265&tqId=39288&ru=/exam/oj

// 方法：动态规划
// 状态转移方程：ret[i][j] = max(ret[i - 1][j], ret[i][j - 1]) + grid[i - 1][j - 1]
// 解释：ret[i][j]表示从左上角到第i行第j列的路径的最大价值，ret[i - 1][j]表示从左上角到第i-1行第j列的路径的最大价值，ret[i][j - 1]表示从左上角到第i行第j-1列的路径的最大价值。
// 最后返回ret[n][m]即可。
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
    int maxValue(vector<vector<int> >& grid)
    {
        // write code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<long>> ret(n + 1, vector<long>(m + 1));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                ret[i][j] = max(ret[i - 1][j], ret[i][j - 1]) + grid[i - 1][j - 1];
            }
        }

        return ret[n][m];
    }
};



// 优解：
class Solution
{
private:
    int dp[210][210] = { 0 };

public:
    int maxValue(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }

        return dp[m][n];
    }
};