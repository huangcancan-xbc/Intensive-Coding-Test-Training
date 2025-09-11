// 牛客：OR26 最长回文子串
// 链接：https://www.nowcoder.com/practice/b4525d1d84934cf280439aeecc36f4af?tpId=182&tqId=34752&ru=/exam/oj

// 方法一：中心扩展算法
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param A string字符串
     * @return int整型
     */
    int getLongestPalindrome(string A)
    {
        // write code here
        int n = A.size();
        int ret = 1;

        for (int i = 0; i < n; i++)
        {
            // 奇数情况
            int left = i - 1, right = i + 1;
            while (left >= 0 && right < n && A[left] == A[right])
            {
                left--;
                right++;
            }
            ret = max(ret, right - left - 1);

            // 偶数情况
            left = i, right = i + 1;
            while (left >= 0 && right < n && A[left] == A[right])
            {
                left--;
                right++;
            }
            ret = max(ret, right - left - 1);
        }

        return ret;
    }
};




// 方法二：DP
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param A string字符串
     * @return int整型
     */
    int getLongestPalindrome(string A)
    {
        // write code here
        int n = A.size();                                   // 获取字符串的长度

        vector<vector<bool>> dp(n, vector<bool>(n, false)); // dp[i][j] 表示 s[i] 到 s[j] 是否是回文子串
        int len = 1;

        // 动态规划，从下往上填充 dp 数组
        for (int i = n - 1; i >= 0; i--)                    // 从字符串的最后一个字符开始
        {
            for (int j = i; j < n; j++)                     // 对每个 i 开始，逐个判断 s[i] 到 s[j] 是否为回文
            {
                if (A[i] == A[j])                           // 如果 s[i] 等于 s[j]，可能是回文
                {
                    // 如果 i+1 到 j-1 的子串是回文，或者 i 和 j 相邻（i+1 > j-1），就是回文
                    dp[i][j] = (i + 1 < j) ? dp[i + 1][j - 1] : true;
                }

                if (dp[i][j] && j - i + 1 > len)            // 如果 dp[i][j] 为 true，且当前子串长度大于已记录的最大长度，则更新
                {
                    len = j - i + 1;                        // 更新回文子串的最大长度
                }
            }
        }

        return len;
    }
};




// 方法三：马拉车算法
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param A string字符串
     * @return int整型
     */
    int getLongestPalindrome(string A)
    {
        // write code here
        // 步骤1：对原字符串进行预处理，在每个字符之间插入 '#'，并在首尾添加边界符，例如: "abba" -> "^#a#b#b#a#$"
        string T = "^";                                     // 左边界符，防止越界
        for (char ch : A)
        {
            T += "#" + string(1, ch);
        }
        T += "#$";                                          // 右边界符

        int n = T.size();
        vector<int> p(n, 0);                                // p[i] 表示以 i 为中心的回文半径（包括自己）

        int cur = 0;                                        // 当前回文中心
        int right = 0;                                      // 当前回文右边界
        int ret = 0;                                        // 记录最长回文子串的长度

        // 步骤2：遍历处理后的字符串
        for (int i = 1; i < n - 1; ++i)
        {
            int mirror = 2 * cur - i;                       // i 关于 cur 的对称位置

            if (i < right)
            {
                p[i] = min(right - i, p[mirror]);           // 利用对称性质初始化回文半径
            }

            
            while (T[i + p[i] + 1] == T[i - p[i] - 1])      // 尝试中心扩展，匹配两侧字符
            {
                p[i]++;
            }

            
            if (i + p[i] > right)                           // 如果新扩展的回文超过了当前最右边界，则更新 cur 和 right
            {
                cur = i;
                right = i + p[i];
            }

            
            ret = max(ret, p[i]);                           // 更新最大长度（去掉插入符号后长度为 p[i]）
        }

        return ret;                                         // 返回最长回文子串的实际长度
    }
};