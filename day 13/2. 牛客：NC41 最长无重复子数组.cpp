// 牛客：NC41 最长无重复子数组
// 链接：https://www.nowcoder.com/practice/b56799ebfd684fb394bd315e89324fb4?tpId=196&tqId=37149&ru=/exam/oj
// 或者：https://www.nowcoder.com/practice/b56799ebfd684fb394bd315e89324fb4

// 方法：滑动窗口（优解）
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param arr int整型vector the array
     * @return int整型
     */

    int hash[100010] = { 0 };
    int maxLength(vector<int>& arr)
    {
        // write code here
        int left = 0, right = 0, ret = 1;
        while (right < arr.size())
        {
            hash[arr[right]]++;
            while (hash[arr[right]] > 1)
            {
                hash[arr[left]]--;
                left++;
            }

            ret = max(ret, right - left + 1);
            right++;
        }

        return ret;
    }
};




// 方法二：DP
//思想：
// dp[i] 表示以第 i 个元素结尾的最长无重复子数组长度
// lastPos[x] 表示元素 x 上一次出现的位置，初始为 - 1
//
//状态转移：
// 1. 假设 dp[i - 1] 是当前以 i - 1 结尾的最长无重复子数组长度；
// 2. 如果 arr[i] 没有出现在 dp[i - 1] 对应的子数组中，就可以接上当前元素：dp[i] = dp[i - 1] + 1；
// 3. 如果 arr[i] 在 dp[i - 1] 中已经出现过（即 lastPos[arr[i]] >= i - dp[i - 1]），
// 说明当前子数组中有重复元素，需要“从上一次出现的位置的下一位”重新计算长度；
// dp[i] = i - lastPos[arr[i]];
//4. 所以统一写作：
// dp[i] = min(dp[i - 1] + 1, i - lastPos[arr[i]])
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param arr int整型vector the array
     * @return int整型
     */

    int maxLength(vector<int>& arr)
    {
        // write code here
        int n = arr.size();

        
        const int N = 100000;               // 数组元素值最大为 10^5，使用定长数组即可（若值域更大改为 unordered_map）
        vector<int> lastPos(N + 1, -1);     // 初始化：所有元素的上一次出现位置为 -1（表示未出现过）

        vector<int> dp(n, 0);               // dp[i]：以第 i 个元素结尾的最长无重复子数组长度
        dp[0] = 1;                          // 只有一个元素，长度为 1
        lastPos[arr[0]] = 0;                // 记录第一个元素出现的位置
        int ret = 1;                        // 初始化最大值为 1

        for (int i = 1; i < n; i++)
        {
            int last = lastPos[arr[i]];     // 获取当前元素上一次出现的位置（若从未出现，值为 -1）

            // 如果上次出现的位置不在当前子数组范围内，可以继续往后延伸，否则必须从 last+1 开始截断（即合法子数组从 last+1 到 i）
            dp[i] = min(dp[i - 1] + 1, i - last);

            lastPos[arr[i]] = i;            // 更新当前元素的上次出现位置
            ret = max(ret, dp[i]);          // 更新全局最大值
        }

        return ret;
    }
};