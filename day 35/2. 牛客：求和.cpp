// 牛客：求和
// 链接：https://www.nowcoder.com/questionTerminal/af6d52eb400b40fd9652b089216f113e

// 方法：DFS（优解）
#include <iostream>
using namespace std;

int n, m;
bool vis[11];
int sum;

void dfs(int x)
{
    if (sum == m)
    {
        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
            {
                cout << i << " ";
            }
        }

        cout << endl;
        return;                     // 注意这里要return，否则会出现重复输出
    }

    if (sum > m || x > n)
    {
        return;                     // 注意边界条件进行返回！
    }

    // 选
    sum += x;
    vis[x] = true;
    dfs(x + 1);
    sum -= x;

    // 不选
    vis[x] = false;
    dfs(x + 1);
}

int main()
{
    cin >> n >> m;
    dfs(1);
    return 0;
}



// 或者：
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> path;                   // 存当前组合

void dfs(int start, int sum)
{
    if (sum == m)                   // 找到一组解
    {
        for (int num : path)
        {
            cout << num << " ";
        }

        cout << endl;
        return;
    }

    for (int i = start; i <= n; i++)
    {
        if (sum + i > m)
        {
            break;                  // 剪枝：当前数过大就没必要继续
        }

        path.push_back(i);          // 选当前数
        dfs(i + 1, sum + i);
        path.pop_back();            // 回溯
    }
}

int main()
{
    cin >> n >> m;
    dfs(1, 0);
    return 0;
}