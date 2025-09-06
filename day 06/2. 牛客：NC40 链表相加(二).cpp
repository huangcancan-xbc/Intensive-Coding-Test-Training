// 牛客：NC40 链表相加(二)
// 链接：https://www.nowcoder.com/practice/c56f6c70fb3f4849bc56e33ff2a50b6b?tpId=196&tqId=37147&ru=/exam/oj

// 方法：逆序链表 + 模拟高精度加法


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
     * @param head1 ListNode类
     * @param head2 ListNode类
     * @return ListNode类
     */

    // 逆序链表（模板）
    ListNode* reverse(ListNode* head)
    {
        ListNode* newHead = new ListNode(0);        // 创建一个虚拟头结点（用于简化插入逻辑）
        ListNode* cur = head;                       // 当前遍历到的节点

        while (cur)
        {
            ListNode* next = cur->next;             // 保存下一个节点，避免断链
            cur->next = newHead->next;              // 当前节点插入到 newHead 后面（头插法）
            newHead->next = cur;
            cur = next;                             // 继续处理下一个节点
        }

        cur = newHead->next;                        // 获取反转后的链表头
        delete newHead;                             // 删除临时虚拟头节点，避免内存泄漏
        return cur;
    }

    ListNode* addInList(ListNode* head1, ListNode* head2)
    {
        // 第一步：将两个链表反转，方便从低位开始相加
        head1 = reverse(head1);
        head2 = reverse(head2);

        int t = 0;                                  // 进位变量

        // cur1 和 cur2 用于分别遍历两个链表
        ListNode* cur1 = head1;
        ListNode* cur2 = head2;

        ListNode* ret = new ListNode(0);            // 创建结果链表的虚拟头结点（用于简化后续插入逻辑）
        ListNode* prev = ret;                       // prev 用于构造新链表

        // 第二步：模拟高精度加法（每位相加 + 进位）
        while (cur1 || cur2 || t)
        {
            if (cur1)
            {
                t += cur1->val;                     // 加上第一个链表当前位
                cur1 = cur1->next;                  // 指针向后移动
            }
            if (cur2)
            {
                t += cur2->val;                     // 加上第二个链表当前位
                cur2 = cur2->next;
            }

            prev->next = new ListNode(t % 10);      // 创建新节点：当前位的值为 t % 10
            prev = prev->next;                      // 移动 prev 指针
            t /= 10;                                // 更新进位
        }

        // 第三步：反转结果链表（将低位转成高位）
        cur1 = ret->next;                           // 保存结果链表头指针（跳过虚拟头节点）
        ret->next = nullptr;
        delete ret;                                 // 删除 dummy 节点，避免内存泄漏

        return reverse(cur1);                       // 返回最终结果（高位在前）
    }
};