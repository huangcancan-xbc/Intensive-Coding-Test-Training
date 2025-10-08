// 牛客：DP18 滑雪
// 链接：https://www.nowcoder.com/practice/36d613e0d7c84a9ba3af3ab0047a35e0?tpId=230&tqId=39760&ru=/exam/oj

// 方法一：递归/DFS
#include <iostream>
using namespace std;

const int N = 1010;
int n, m, ret = 0;
int v[N][N];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int dfs(int i, int j)
{
    int len = 1;
    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k], y = j + dy[k];
        if (x >= 0 && x < n && y >= 0 && y < m && v[x][y] < v[i][j])
        {
            len = max(len, 1 + dfs(x, y));
        }
    }

    return len;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ret = max(ret, dfs(i, j));
        }
    }

    cout << ret << endl;

    return 0;
}





// 方法二：记忆化搜索
#include <iostream>
using namespace std;

const int N = 1010;
int n, m, ret = 0;
int v[N][N];
int dp[N][N];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int dfs(int i, int j)
{
    if (dp[i][j])
    {
        return dp[i][j];
    }

    int len = 1;
    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k], y = j + dy[k];
        if (x >= 0 && x < n && y >= 0 && y < m && v[x][y] < v[i][j])
        {
            len = max(len, 1 + dfs(x, y));
        }
    }

    dp[i][j] = len;

    return len;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ret = max(ret, dfs(i, j));
        }
    }

    cout << ret << endl;

    return 0;
}