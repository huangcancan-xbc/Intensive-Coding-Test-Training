// 牛客：DP45 分割等和子集
// 链接：https://www.nowcoder.com/practice/65ade309fa4d4067a9add749721bfdc0?tpId=230&tqId=40433&ru=/exam/oj

// 方法：动态规划
#include <iostream>
#include <vector>
using namespace std;

int n, sum;

int main()
{
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    if (sum % 2 == 1)
    {
        cout << "false" << endl;
    }
    else
    {
        // dp[i][j] 表示前 i 个数的和为 j 是否存在
        vector<vector<bool>> dp(n + 1, vector<bool>(sum / 2 + 1));
        dp[0][0] = true;                            // 前 0 个数的和为 0 存在为 true

        for (int i = 1; i <= n; i++)                // 遍历前 i 个数
        {
            for (int j = 0; j <= sum / 2; j++)      // 和要从 0 开始遍历
            {
                dp[i][j] = dp[i - 1][j];            // 表示不选第 i 个数
                if (j >= v[i - 1])                  // 如果当前的数可以选
                {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - v[i - 1]]; // 选择第 i 个数
                }
            }
        }

        if (dp[n - 1][sum / 2])
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }

    return 0;
}
// 优解：
#include <iostream>
using namespace std;

const int N = 510, M = 510 * 110 / 2;
int n;
int arr[N];
int dp[N][M];

int main()
{
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    if (sum % 2 == 1)
    {
        cout << "false" << endl;
    }
    else
    {
        sum /= 2;
        dp[0][0] = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= arr[i])
                {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i]];
                }
            }
        }

        if (dp[n][sum])
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }

    return 0;
}




// 方法二：递归（DFS）
#include <iostream>
#include <vector>
using namespace std;

int n, sum;
bool dfs(vector<int>& v, int pos, int target)
{
    if (pos >= n)
    {
        return false;               // 已经遍历完所有数，但还没有找到 target，返回 false
    }

    if (target == 0)
    {
        return true;                // 找到 target，返回 true
    }

    return dfs(v, pos + 1, target - v[pos]) || dfs(v, pos + 1, target);
}

int main()
{
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    if (sum % 2 == 1)
    {
        cout << "false" << endl;
    }
    else
    {
        bool ret = dfs(v, 0, sum / 2);
        cout << (ret == true ? "true" : "false") << endl;
    }

    return 0;
}