// 牛客：NC164 最长上升子序列(二)
// 链接：https://www.nowcoder.com/practice/4af96fa010c44638a7e112abf65f7237?tpId=196&tqId=39285&ru=/exam/oj

// 方法一：动态规划（超时）

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 该数组最长严格上升子序列的长度
     * @param a int整型vector 给定的数组
     * @return int整型
     */
    int LIS(vector<int>& a)
    {
        // write code here
        int n = a.size();
        if (n == 0)
        {
            return 0;
        }

        vector<int> dp(n, 1);                   // 初始化所有 dp[i] 为 1
        int ret = 1;                            // 最终结果至少为 1（非空数组）

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (a[j] < a[i])                // 满足严格上升条件
                {
                    dp[i] = max(dp[i], dp[j] + 1);      // 状态转移
                }
            }

            ret = max(ret, dp[i]);              // 记录最大长度
        }

        return ret;
    }
};




// 方法二：二分查找 + 贪心
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 该数组最长严格上升子序列的长度
     * @param a int整型vector 给定的数组
     * @return int整型
     */

    int dp[100010], pos = 0;                    // dp[i] 表示长度为 i 的上升子序列的最小末尾元素，pos 为当前最长上升子序列的长度

    int LIS(vector<int>& a)
    {
        for (auto x : a)                        // 遍历数组中的每个元素 x
        {
            if (pos == 0 || x > dp[pos])        // 如果 x 大于当前最长上升子序列的最后一个元素，则可以直接扩展这个序列
            {
                dp[++pos] = x;                  // 把 x 追加到当前 LIS 的尾部，pos 长度加一
            }
            else                                // 否则，使用二分查找在 dp[1..pos] 中找到第一个 ≥ x 的位置，将其替换为 x
            {
                int left = 1, right = pos;
                while (left < right)
                {
                    int mid = left + (right - left) / 2;

                    if (dp[mid] >= x)
                    {
                        right = mid;            // dp[mid] 可能是候选位置，继续向左找更小的满足条件的位置
                    }
                    else
                    {
                        left = mid + 1;         // dp[mid] < x，不可能是答案，向右找
                    }
                }

                dp[left] = x;                   // 替换掉较大值，维护更小的结尾
            }
        }

        return pos;                             // 返回最长上升子序列的长度
    }
};