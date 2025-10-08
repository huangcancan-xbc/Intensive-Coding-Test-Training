// 牛客：NC51 合并k个已排序的链表
// 链接：https://www.nowcoder.com/practice/65cfde9e5b9b4cf2b6bafa5f3ef33fa6?tpId=196&tqId=37081&ru=/exam/oj


// 方法一：堆
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param lists ListNode类vector
     * @return ListNode类
     */
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        // write code here
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> heap;
        for (auto head : lists)
        {
            while (head)
            {
                heap.push({ head->val,head });
                head = head->next;
            }
        }

        ListNode ret(0);
        ListNode* tail = &ret;

        while (heap.size())
        {
            ListNode* temp = heap.top().second;
            heap.pop();

            tail->next = temp;
            tail = tail->next;
        }

        tail->next = nullptr;

        return ret.next;

    }
};




// 堆优化：
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param lists ListNode类vector
     * @return ListNode类
     */
    struct cmp
    {
        bool operator()(ListNode* l1, ListNode* l2)
        {
            return l1->val > l2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        // write code here
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
        for (auto head : lists)
        {
            if (head != nullptr)
            {
                heap.push(head);
            }
        }

        ListNode* ret = new ListNode(0);
        ListNode* tail = ret;

        while (heap.size())
        {
            ListNode* temp = heap.top();
            heap.pop();
            tail = tail->next = temp;

            if (temp->next != nullptr)
            {
                heap.push(temp->next);
            }
        }

        tail->next = nullptr;

        return ret->next;
    }
};




// 方法二：分治递归
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param lists ListNode类vector
     * @return ListNode类
     */
     // 合并两个有序链表
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode dummy(0);        // 哨兵节点
        ListNode* tail = &dummy;  // 结果链表的尾指针

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // 拼接剩余部分
        if (l1)
        {
            tail->next = l1;
        }
        if (l2)
        {
            tail->next = l2;
        }

        return dummy.next;
    }

    // 分治递归
    ListNode* merge(vector<ListNode*>& lists, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        if (left == right)
        {
            return lists[left];
        }

        int mid = left + (right - left) / 2;
        ListNode* l1 = merge(lists, left, mid);
        ListNode* l2 = merge(lists, mid + 1, right);

        return mergeTwoLists(l1, l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        // write code here
        if (lists.empty())
        {
            return nullptr;
        }

        return merge(lists, 0, (int)lists.size() - 1);
    }
};