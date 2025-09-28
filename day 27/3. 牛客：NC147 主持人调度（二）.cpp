// 牛客：NC147 主持人调度（二）
// 链接：https://www.nowcoder.com/practice/4edf6e6d01554870a12f218c94e8a299?tpId=196&tqId=37562&ru=/exam/oj

// 方法：贪心

// 方法一：直接暴力枚举（超时）
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算成功举办活动需要多少名主持人
     * @param n int整型 有n个活动
     * @param startEnd int整型vector<vector<>> startEnd[i][0]用于表示第i个活动的开始时间，startEnd[i][1]表示第i个活动的结束时间
     * @return int整型
     */
    int minmumNumberOfHost(int n, vector<vector<int> >& startEnd)
    {
        // write code here
        sort(startEnd.begin(), startEnd.end());

        vector<vector<pair<int, int>>> v;
        v.push_back({ {startEnd[0][0], startEnd[0][1]} });      // 第一个活动先放进去

        for (int i = 1; i < n; i++)
        {
            bool flag = false;
            for (int j = 0; j < v.size(); j++)
            {
                if (startEnd[i][0] >= v[j].back().second)       // 如果当前活动可以接在某个主持人的活动之后
                {
                    v[j].push_back({ startEnd[i][0], startEnd[i][1] });
                    flag = true;
                    break;
                }
            }

            if (!flag)                                          // 如果没找到主持人，新增主持人
            {
                v.push_back({ {startEnd[i][0], startEnd[i][1]} });
            }
        }

        return v.size();
    }
};


// 优化：
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算成功举办活动需要多少名主持人
     * @param n int整型 有n个活动
     * @param startEnd int整型vector<vector<>> startEnd[i][0]用于表示第i个活动的开始时间，startEnd[i][1]表示第i个活动的结束时间
     * @return int整型
     */
    int minmumNumberOfHost(int n, vector<vector<int> >& startEnd)
    {
        // write code here
        sort(startEnd.begin(), startEnd.end());
        vector<int> v;                          // 每个主持人最后一个活动的结束时间

        for (int i = 0; i < n; i++)
        {
            bool flag = false;

            for (int j = 0; j < v.size(); j++)
            {
                if (startEnd[i][0] >= v[j])     // 当前活动可以接到主持人 j
                {
                    v[j] = startEnd[i][1];      // 更新这个主持人最新的结束时间
                    flag = true;
                    break;
                }
            }

            if (!flag)
            {
                v.push_back(startEnd[i][1]);    // 如果没有找到主持人，就新增一个
            }
        }

        return v.size();                        // 主持人数量
    }
};




// 优化：
// 方法二：堆 + 贪心
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算成功举办活动需要多少名主持人
     * @param n int整型 有n个活动
     * @param startEnd int整型vector<vector<>> startEnd[i][0]用于表示第i个活动的开始时间，startEnd[i][1]表示第i个活动的结束时间
     * @return int整型
     */
    int minmumNumberOfHost(int n, vector<vector<int> >& startEnd)
    {
        // write code here
        sort(startEnd.begin(), startEnd.end());

        priority_queue<int, vector<int>, greater<int>> q;
        q.push(startEnd[0][1]);

        for (int i = 1; i < n; i++)
        {
            int a = startEnd[i][0], b = startEnd[i][1];
            if (q.top() <= a)
            {
                q.pop();
                q.push(b);
            }
            else
            {
                q.push(b);
            }
        }

        return q.size();
    }
};