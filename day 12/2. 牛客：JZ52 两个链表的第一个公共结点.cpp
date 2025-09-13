// 牛客：JZ52 两个链表的第一个公共结点
// 链接：https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=13&tqId=11189&ru=/exam/oj

// 方法一：先统计两个链表的长度，再对齐再一起走找第一个公共结点

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution
{
public:
    // 辅助函数：计算链表长度
    int GetLength(ListNode* head)
    {
        int count = 0;
        while (head)
        {
            ++count;
            head = head->next;
        }

        return count;
    }

    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
    {
        // 1. 计算两个链表的长度
        int len1 = GetLength(pHead1);
        int len2 = GetLength(pHead2);

        // 2. 让长的链表先走“长度差”步
        ListNode* cur1 = len1 > len2 ? pHead1 : pHead2;
        ListNode* cur2 = len1 > len2 ? pHead2 : pHead1;
        int diff = abs(len1 - len2);

        while (diff--)
        {
            cur1 = cur1->next;                  // 先让长的链表走“差值”步
        }

        // 3. 一起走，直到找到第一个公共结点（地址相同）
        while (cur1 && cur2)
        {
            if (cur1 == cur2)
            {
                return cur1;                    // 找到第一个公共结点
            }

            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        return nullptr;                         // 没有公共结点
    }
};





// 方法二：等量关系（优解）
// 通过两个指针交替遍历两个链表，利用“长度差抵消”的原理，使它们在第一次相遇时即为第一个公共结点。


/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution
{
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode* cur1 = pHead1, * cur2 = pHead2;
		while (cur1 != cur2)
		{
			cur1 = cur1 != NULL ? cur1->next : pHead2;
			cur2 = cur2 != NULL ? cur2->next : pHead1;
		}

		return cur1;
	}
};