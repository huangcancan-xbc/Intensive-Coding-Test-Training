// 牛客：宵暗的妖怪
// 链接：https://ac.nowcoder.com/acm/problem/213484

// 方法：动态规划
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> v(n + 1), dp(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    for (int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 3] + v[i - 1]);
    }
    cout << dp[n] << endl;

    return 0;
}




// 优化：
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;

int n;
LL arr[N];
LL dp[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 3] + arr[i - 1]);
    }

    cout << dp[n] << endl;

    return 0;
}