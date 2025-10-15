// 牛客：kotori和素因子
// 链接：https://ac.nowcoder.com/acm/problem/50042

// 方法：DFS + 递归枚举 + 剪枝 + 回溯
#include <iostream>
#include <cmath>
using namespace std;

int n, v[10], ret = 0x3f3f3f3f, path_sum = 0;
bool vis[1010];

bool check(int x)
{
    if (x < 2)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }

    return true;
}

void dfs(int pos)
{
    if (pos == n)
    {
        ret = min(ret, path_sum);
        return;
    }

    for (int i = 2; i <= v[pos]; i++)
    {
        if (v[pos] % i == 0 && check(i) && !vis[i])
        {
            path_sum += i;
            vis[i] = true;

            dfs(pos + 1);

            path_sum -= i;
            vis[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    dfs(0);

    if (ret == 0x3f3f3f3f)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ret << endl;
    }

    return 0;
}