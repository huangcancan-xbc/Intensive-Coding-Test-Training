// 牛客：DP4 最小花费爬楼梯
// 链接：https://www.nowcoder.com/practice/9b969a3ec20149e3b870b256ad40844e?tpId=230&tqId=39751&ru=/exam/oj

// DP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1);
    vector<int> cost(n);

    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    for (int i = 2; i <= n; i++)
    {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }

    cout << dp[n];

    return 0;
}



// 优解：
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n;
int cost[N];
int dp[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> cost[i];

    for (int i = 2; i <= n; i++)
    {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }

    cout << dp[n] << endl;

    return 0;
}