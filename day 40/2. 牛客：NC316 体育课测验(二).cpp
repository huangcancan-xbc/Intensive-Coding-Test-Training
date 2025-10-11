// 牛客：NC316 体育课测验(二)
// 链接：https://www.nowcoder.com/practice/64a4c026b2aa4411984f560deec36323?tpId=196&tqId=40272&ru=/exam/oj

// 方法：拓扑排序

// 拓扑排序固定步骤：
//1. 建图
//    用邻接表表示有向边 u->v（表示 v 依赖 u，或 u 先于 v）。
//    同时维护一个 入度数组 in[]，记录每个点被指向的次数。
//2. 初始化队列
//    把所有 入度为 0 的点 入队。
//    这些点没有前置依赖，可以最先处理。
//3. 循环处理队列
//    队列不空时，取出队首元素 u，加入结果序列。
//    遍历 u 的所有出边 u->v，让 v 的入度减一：
//    如果 in[v] 变成 0，就把 v 入队。
//4. 检测是否有环
//    最后如果结果序列中的点数 == 总点数，说明无环，得到一个合法拓扑序。
//    否则说明有环（某些点入度始终 > 0），拓扑序不存在。

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numProject int整型
     * @param groups int整型vector<vector<>>
     * @return int整型vector
     */

    vector<int> findOrder(int numProject, vector<vector<int> >& groups)
    {
        // write code here
        vector<vector<int>> edges(numProject);
        vector<int> in(numProject);         //入度

        // 1. 建图
        for (auto x : groups)
        {
            int a = x[0], b = x[1];         // b指向a
            edges[b].push_back(a);
            in[a]++;                        // 注意是 a 的入度++
        }

        // 2. 将入度为0的点加入队列
        queue<int> q;
        for (int i = 0; i < numProject; i++)
        {
            if (in[i] == 0)
            {
                q.push(i);
            }
        }

        // 3. 拓扑排序
        vector<int> ret;
        while (q.size())
        {
            int a = q.front();
            q.pop();
            ret.push_back(a);               // 入度为0的点加入结果

            for (auto x : edges[a])         // 检查其指向的点的入度
            {
                if (--in[x] == 0)           // 入度减1，如果减到0，加入队列
                {
                    q.push(x);
                }
            }
        }

        if (ret.size() == numProject)
        {
            return ret;                     // 如果拓扑排序成功，返回结果
        }
        else
        {
            return {};
        }
    }
};