// 牛客：DP39 字母收集
// 链接：https://www.nowcoder.com/practice/9740ce2df0a04399a5ade1927d34c1e1?tpId=230&tqId=38954&ru=/exam/oj

// 方法：DP
#include <iostream>
#include <vector>
using namespace std;

int check(char x)
{
    if (x == 'l')
    {
        return 4;
    }
    else if (x == 'o')
    {
        return 3;
    }
    else if (x == 'v')
    {
        return 2;
    }
    else if (x == 'e')
    {
        return 1;
    }

    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> v(n, vector<char>(m));
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i - 1][j] + check(v[i - 1][j - 1]), dp[i][j - 1] + check(v[i - 1][j - 1]));
        }
    }

    cout << dp[n][m];

    return 0;
}


// 或者：
#include <iostream>
using namespace std;

const int N = 510;
char g[N][N];
int dp[N][N];
int m, n;

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> g[i][j];
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int t = 0;
            if (g[i][j] == 'l')
            {
                t = 4;
            }
            else if (g[i][j] == 'o')
            {
                t = 3;
            }
            else if (g[i][j] == 'v')
            {
                t = 2;
            }
            else if (g[i][j] == 'e')
            {
                t = 1;
            }

            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + t;
        }
    }

    cout << dp[m][n] << endl;
    return 0;
}