// 牛客：DP31 买卖股票的最好时机(二)
// 链接：https://www.nowcoder.com/practice/fbc5dad3e215457fb82a3ae688eb7281?tpId=230&tqId=39768&ru=/exam/oj

// 方法一：DP
// dp[i][0] 表示第i天持有股票所得现金。
// dp[i][1] 表示第i天不持有股票所得最多现金
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] -= prices[0];
    dp[0][1] = 0;

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    cout << dp[n - 1][1] << endl;

    return 0;
}



// 方法二：贪心算法（优解）
// 因为可以无限次交易，因此，只要股票的价格有上升，就统统把利润拿到手。所以贪心算法：只要当前的股价比前一天的股价高，就买入，否则就卖出。
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int arr[N];

int main()
{
    int n, ret = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            ret += arr[i] - arr[i - 1];
        }
    }

    cout << ret << endl;

    return 0;
}