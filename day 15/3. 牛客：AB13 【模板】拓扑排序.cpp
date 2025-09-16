// 牛客：AB13 【模板】拓扑排序
// 链接：https://www.nowcoder.com/practice/88f7e156ca7d43a1a535f619cd3f495c?tpId=308&tqId=40470&ru=/exam/oj

// 方法：拓扑排序
// 1. 建图：用数据结构把题目中的信息存储起来
// 2. 把所有入度为 0 的点加入队列中
// 3. 当队列不为空时：
//    a. 取出队首元素 x（必要时保存拓扑排序的顺序）
//    b. 修改队头元素链接的点的信息（入度减 1）
//    c. 判断：如果入度为 0，再将其加入队列中
// 4. 直到队列为空，输出拓扑排序的结果

//判断是否有环：
// 1. 通过拓扑序列长度判断（推荐）：如果拓扑序列的长度等于顶点数 n，说明所有顶点都被成功排序，无环；否则有环。
// 2. 遍历入度数组 in：拓扑排序结束后，如果存在顶点的入度不为 0，说明这些顶点在环中。
// 3. 统计处理的顶点数量：在拓扑排序过程中维护一个计数器，记录已处理的顶点数量。如果最终计数器不等于 n，则有环。
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> edges(200010);
vector<int> ret;
int in[200010];
queue<int> q;

int main()
{
    cin >> n >> m;
    int a, b;

    while (m--)
    {
        cin >> a >> b;
        edges[a].push_back(b);              // 添加有向边 a->b
        in[b]++;                            // b的入度加1
    }

    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }

    while (q.size())
    {
        int x = q.front();
        q.pop();
        ret.push_back(x);

        for (auto y : edges[x])             // 遍历x的所有邻接顶点
        {
            if (--in[y] == 0)               // 如果入度减 1 后为 0，说明可以加入队列
            {
                q.push(y);
            }
        }
    }

    if (ret.size() == n)                    // 判断是否有环：如果拓扑序列包含所有顶点，则无环
    {
        for (int i = 0; i < n - 1; i++)
        {
            cout << ret[i] << " ";
        }

        cout << ret[n - 1];
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}




// 判断是否有环也可以遍历入度 in 数组，如果数组中有元素不为 0，说明有环，输出 -1；否则输出拓扑排序的结果。
// 注意不能遍历图来确定是否有环，图的数据不会改变，所以以此遍历判断，一定是永远都有环！
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> edges(200010);
vector<int> ret;
int in[200010];
queue<int> q;

int main()
{
    cin >> n >> m;
    int a, b;

    while (m--)
    {
        cin >> a >> b;
        edges[a].push_back(b);
        in[b]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }

    while (q.size())
    {
        int x = q.front();
        q.pop();
        ret.push_back(x);

        for (auto y : edges[x])
        {
            if (--in[y] == 0)
            {
                q.push(y);
            }
        }
    }

    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] != 0)
        {
            flag = true;
            break;
        }
    }

    if (!flag)
    {
        for (int i = 0; i < n - 1; i++)
        {
            cout << ret[i] << " ";
        }

        cout << ret[n - 1];
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}