// 牛客：NC393 取金币
// 链接：https://www.nowcoder.com/share/jump/5170733851759513876672

// 方法：区间DP
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param coins int整型vector
     * @return int整型
     */
    int arr[110] = { 0 };
    int dp[110][110] = { 0 };

    int getCoins(vector<int>& coins)
    {
        // write code here
        int n = coins.size();
        arr[0] = arr[n + 1] = 1;
        for (int i = 1; i <= n; i++)
        {
            arr[i] = coins[i - 1];
        }

        for (int i = n; i >= 1; i--)
        {
            for (int j = i; j <= n; j++)
            {
                for (int k = i; k <= j; k++)
                {
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j + 1]);
                }
            }
        }

        return dp[1][n];
    }
};