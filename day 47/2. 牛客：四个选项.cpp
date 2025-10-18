// 牛客：四个选项
// 链接：https://ac.nowcoder.com/acm/problem/202493

// 方法：DFS + 递归 + 回溯 + 哈希
#include <iostream>
#include <vector>
using namespace std;

int cnt[5];           // cnt[i] 表示选项 i (1=A,2=B,3=C,4=D) 还剩多少次可用
int m, x, y;          // m 条附加条件，每条约束两个题号 (x,y)
bool same[13][13];    // same[i][j] = true 表示第 i 题和第 j 题必须相同答案

int ret;              // 记录最终方案数
vector<int> path;     // path[pos] 记录第 pos 题选的答案 (用 1-4 表示 A-D)

// 检查当前位置 pos 是否能填选项 cur
bool isSame(int pos, int cur)
{
    // 遍历之前已经填过的题目
    for (int i = 1; i < pos; i++)
    {
        // 如果 pos 和 i 题要求相同，但之前 i 题填的答案 != cur
        if (same[pos][i] && path[i] != cur)
        {
            return false; // 冲突，不合法
        }
    }
    return true;          // 没有冲突，可以填
}

// 回溯搜索：当前处理第 pos 题
void dfs(int pos)
{
    if (pos > 12)         // 已经填完 12 道题
    {
        ret++;            // 找到一个合法方案
        return;
    }

    // 尝试四个选项 A-D
    for (int i = 1; i <= 4; i++)
    {
        if (cnt[i] == 0)
        {
            continue;     // 这个选项的数量已经用完，跳过
        }

        if (!isSame(pos, i))
        {
            continue;       // 不满足“相同答案”的约束，跳过
        }

        // 尝试选这个答案
        cnt[i]--;           // 该答案数量减少
        path.push_back(i);  // 记录答案

        dfs(pos + 1);       // 递归到下一题

        // 回溯
        path.pop_back();
        cnt[i]++;
    }
}

int main()
{
    // 输入四个选项的数量
    for (int i = 1; i <= 4; i++)
    {
        cin >> cnt[i];
    }

    // 输入 m 条约束
    cin >> m;
    while (m--)
    {
        cin >> x >> y;
        same[x][y] = same[y][x] = true; // 无向关系，两题必须相同
    }

    path.push_back(0);              // 在 path[0] 填个占位符，方便从下标 1 开始存题目
    dfs(1);                         // 从第 1 题开始搜索

    cout << ret << endl;            // 输出方案数

    return 0;
}