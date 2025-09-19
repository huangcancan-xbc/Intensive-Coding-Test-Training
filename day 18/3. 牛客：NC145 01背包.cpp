// 牛客：NC145 01背包
// 链接：https://www.nowcoder.com/practice/2820ea076d144b30806e72de5e5d4bbf?tpId=196&tqId=37561&ru=/exam/oj

// 方法一：动态规划
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算01背包问题的结果
     * @param V int整型 背包的体积
     * @param n int整型 物品的个数
     * @param vw int整型vector<vector<>> 第一维度为n,第二维度为2的二维数组,vw[i][0],vw[i][1]分别描述i+1个物品的vi,wi
     * @return int整型
     */
    int knapsack(int V, int n, vector<vector<int> >& vw)
    {
        // write code here
        // 定义一个二维dp数组，dp[i][j]表示使用前i个物品时，背包容量为j时能获得的最大价值
        vector<vector<int>> dp(n + 1, vector<int>(V + 1, 0));

        for (int i = 1; i <= n; i++)            // 遍历每个物品
        {
            for (int j = 0; j <= V; j++)        // 遍历背包容量
            {
                dp[i][j] = dp[i - 1][j];        // 不选当前物品的情况，继承前一行的值

                if (j >= vw[i - 1][0])          // 当前物品的重量小于等于背包容量，尝试选当前物品
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - vw[i - 1][0]] + vw[i - 1][1]);
                }
            }
        }

        return dp[n][V];                        // 返回最终结果，背包容量为V时的最大价值
    }
};



// 方法二：一维状态压缩
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算01背包问题的结果
     * @param V int整型 背包的体积
     * @param n int整型 物品的个数
     * @param vw int整型vector<vector<>> 第一维度为n,第二维度为2的二维数组,vw[i][0],vw[i][1]分别描述i+1个物品的vi,wi
     * @return int整型
     */
    int knapsack(int V, int n, vector<vector<int> >& vw)
    {
        // write code here
        vector<int> dp(V + 1, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = V; j >= vw[i][0]; j--)
            {
                dp[j] = max(dp[j], dp[j - vw[i][0]] + vw[i][1]);
            }
        }

        return dp[V];
    }
};


// 优解：
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算01背包问题的结果
     * @param V int整型 背包的体积
     * @param n int整型 物品的个数
     * @param vw int整型vector<vector<>> 第一维度为n,第二维度为2的二维数组,vw[i][0],vw[i][1]分别描述i+1个物品的vi,wi
     * @return int整型
     */
    int dp[1010] = { 0 };
    int knapsack(int V, int n, vector<vector<int> >& vw)
    {
        // write code here
        for (int i = 0; i < n; i++)
        {
            for (int j = V; j >= vw[i][0]; j--)
            {
                dp[j] = max(dp[j], dp[j - vw[i][0]] + vw[i][1]);
            }
        }

        return dp[V];
    }
};