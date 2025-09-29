// 牛客：体操队形
// 链接：https://ac.nowcoder.com/acm/problem/229386

// 方法：DFS + 回溯（优解）
#include <iostream>
using namespace std;

const int N = 15;                       // 支持最大 n 为 10，略加冗余
int n, ret;                             // n：人数，ret：合法方案总数
int v[N];                               // v[i] 表示第 i 个人想排在 v[i] 前面
bool vis[N];                            // vis[i] 表示编号为 i 的人是否已被安排入队

void dfs(int pos)
{
    if (pos == n + 1)                   // 所有位置都安排完了，说明找到一个合法方案
    {
        ret++;
        return;
    }

    for (int i = 1; i <= n; i++)        // 尝试将编号为 i 的人放在当前位置
    {
        if (vis[i])
        {
            continue;                   // 如果 i 已经被安排过，就跳过
        }

        if (vis[v[i]])                  // 如果 i 想排在 v[i] 前面，但 v[i] 已经安排了（排在了前面）
        {
            return;                     // 当前排列一定不合法，直接剪枝退出整个分支
        }

        vis[i] = true;                  // 标记 i 被使用
        dfs(pos + 1);                   // 递归进入下一个位置
        vis[i] = false;                 // 回溯，撤销状态
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    dfs(1);                             // 从第一个位置开始构造队形
    cout << ret << endl;                // 输出总的合法方案数

    return 0;
}


// 据搜索：其他解法：

//拓扑排序 + 统计所有合法拓扑序（记忆化搜索）
//等价转化
//这是一个前置约束问题，可以建一个有向图：如果 v[i] != i，就建一条边：i -> v[i]，表示 i 必须排在 v[i] 前面
//这是一个拓扑排序计数问题，即：有多少个拓扑排序合法。

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, ans = 0;
vector<int> g[11];
int in[11];                 // 入度数组
bool vis[11];               // 是否已经被安排

void dfs(int depth)
{
    if (depth == n)
    {
        ++ans;
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i] && in[i] == 0)
        {
            vis[i] = true;
            for (int to : g[i]) --in[to];

            dfs(depth + 1);

            for (int to : g[i]) ++in[to];
            vis[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        if (x != i)              // 有要求：i 要排在 x 前面 => i → x
        {
            g[i].push_back(x);
            ++in[x];
        }
    }

    dfs(0);
    cout << ans << endl;
    return 0;
}


// DFS + 剪枝（回溯搜索 + 拓扑依赖）
#include <iostream>
#include <vector>
using namespace std;

int n, ans = 0;
vector<int> a;
bool used[11];
vector<int> path;

bool canPlace(int cur)
{
    if (a[cur] == cur) return true;                  // 无要求
    for (int x : path)
    {
        if (x == a[cur])
        {
            return true;                             // 满足：前面已经排了要求排在他前面的人
        }
    }

    return false;
}

void dfs()
{
    if (path.size() == n)
    {
        ++ans;
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (used[i]) continue;
        if (!canPlace(i)) continue;

        used[i] = true;
        path.push_back(i);
        dfs();
        path.pop_back();
        used[i] = false;
    }
}

int main()
{
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    dfs();
    cout << ans << endl;
    return 0;
}