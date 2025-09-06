// 牛客：JZ62 孩子们的游戏(圆圈中最后剩下的数)（约瑟夫环）
// 链接：https://www.nowcoder.com/practice/f78a359491e64a50bce2d89cff857eb6?tpId=13&tqId=11199&ru=/exam/oj

// 优解：DP但其实是递推（也是下标映射问题）
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @param m int整型
     * @return int整型
     */
    int LastRemaining_Solution(int n, int m)
    {
        // write code here
        int f = 0;
        for (int i = 2; i <= n; i++)
        {
            f = (f + m) % i;
        }

        return f;
    }
};




// 方法二：队列模拟
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @param m int整型
     * @return int整型
     */
    queue<int>q;
    int LastRemaining_Solution(int n, int m)
    {
        // write code here
        for (int i = 0; i < n; i++)
        {
            q.push(i);                              // 先将所有数字放入队列
        }

        int index = 0;                              // 遍历的索引/“指针”
        while (q.size() > 1)
        {
            index++;
            if (index == m)                         // 跳过 m-1 个数字
            {
                index = 0;                          // 重新开始计数
                q.pop();                            // 弹出死去的人的数字
                continue;                           // 跳出本次循环，避免将其再次放入队列
            }

            // 将没有死去的人从队头放到队尾，达到环状删除效果
            q.push(q.front());                      // 没有死去的人，重新放入队列（模拟环状删除）
            q.pop();                                // 弹出第一个数字
        }

        return q.front();
    }
};





// 方法三：模拟

// 环形链表模拟：
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @param m int整型
     * @return int整型
     */

     // 定义链表结构体
    struct Node
    {
        int val;
        Node* next;
        Node(int v) : val(v), next(nullptr) {}
    };

    int LastRemaining_Solution(int n, int m)
    {
        // write code here
        // 创建循环链表
        Node* head = new Node(0);
        Node* cur = head;
        for (int i = 1; i < n; ++i)
        {
            cur->next = new Node(i);
            cur = cur->next;
        }
        cur->next = head;                   // 成环

        // 开始模拟删除过程
        Node* pre = cur;                    // 最后一个节点
        cur = head;
        while (cur != cur->next)
        {
            for (int i = 1; i < m; ++i)     // 找到要删除的前一个节点
            {
                pre = cur;
                cur = cur->next;
            }

            pre->next = cur->next;          // 删除 cur 节点
            delete cur;
            cur = pre->next;
        }

        int ret = cur->val;
        delete cur;

        return ret;
    }
};
// 或者：
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @param m int整型
     * @return int整型
     */
    int LastRemaining_Solution(int n, int m)
    {
        // write code here
        if (n == 0 || m == 0)
        {
            return -1;
        }

        // 创建一个循环链表
        struct Node
        {
            int val;
            Node* next;
            Node(int v) : val(v), next(nullptr) {}
        };

        // 构建环
        Node* head = new Node(0), * prev = head;
        for (int i = 1; i < n; ++i)
        {
            prev->next = new Node(i);
            prev = prev->next;
        }
        prev->next = head;                  // 成环

        Node* cur = head;
        while (cur != cur->next)            // 直到只剩一个节点
        {
            for (int i = 1; i < m - 1; ++i)
            {
                cur = cur->next;            // 找到待删除前一个节点（即走 m - 1 步）
            }

            // 删除 cur->next 节点
            Node* del = cur->next;
            cur->next = del->next;

            delete del;
            cur = cur->next;                // 继续下一个人
        }

        int ret = cur->val;
        delete cur;
        return ret;
    }
};




// 数组模拟：
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @param m int整型
     * @return int整型
     */
    int LastRemaining_Solution(int n, int m)
    {
        // write code here
        vector<bool> vis(n, false);         // 表示是否已出列
        int remaining = n;
        int index = 0;

        while (remaining > 1)
        {
            int count = 0;
            while (count < m)
            {
                if (!vis[index])
                {
                    count++;
                }
                if (count == m)
                {
                    break;
                }
                index = (index + 1) % n;
            }

            vis[index] = true;              // 当前这个出列
            remaining--;
            index = (index + 1) % n;        // 下一个起点
        }

        // 找到未出列的那个人
        for (int i = 0; i < n; ++i)
        {
            if (!vis[i])
            {
                return i;
            }
        }

        return -1;
    }
};
// 或者：
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @param m int整型
     * @return int整型
     */
    int LastRemaining_Solution(int n, int m)
    {
        // write code here
        if (n == 0 || m == 0)
        {
            return -1;
        }

        vector<int> people;
        for (int i = 0; i < n; ++i)
        {
            people.push_back(i);
        }

        int idx = 0;
        while (people.size() > 1)
        {
            idx = (idx + m - 1) % people.size();    // 找到要删除的人的位置
            people.erase(people.begin() + idx);     // 删除
        }

        return people[0];
    }
};