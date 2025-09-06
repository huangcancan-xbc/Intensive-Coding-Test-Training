// 牛客：NC10 大数乘法（模板）
// 链接：https://www.nowcoder.com/practice/c4c488d4d40d4c4e9824c3650f7d5571?tpId=196&tqId=37177&ru=/exam/oj


// 方法：模拟
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串 第一个整数
     * @param t string字符串 第二个整数
     * @return string字符串
     */
    string solve(string s, string t)
    {
        // write code here
        int len1 = s.size(), len2 = t.size();
        string ret = "";
        vector<int> temp(len1 + len2, 0);

        for (int i = len1 - 1; i >= 0; i--)
        {
            for (int j = len2 - 1; j >= 0; j--)
            {
                int cur = (s[i] - '0') * (t[j] - '0');      // 当前两位相乘的结果
                int sum = cur + temp[i + j + 1];            // 加上已有的值（之前进位可能产生）

                temp[i + j + 1] = sum % 10;                 // 当前位
                temp[i + j] += sum / 10;                    // 进位加到前一位
            }
        }

        for (auto x : temp)                                 // 忽略前导0
        {
            if (!(ret.empty() && x == 0))
            {
                ret.push_back(x + '0');
            }
        }

        return ret.empty() ? "0" : ret;
    }
};
//我认为这里的难点其实是 temp 下标位置的确定，最开始看可能有点迷，但实际上是模拟出来的规律：
//比如举例：123 * 456：
//i = 2, j = 2: s[2] = 3, t[2] = 6 → 18 → 加到 temp[5]
//i = 2, j = 1 : s[2] = 3, t[1] = 5 → 15 → 加到 temp[4]
//i = 2, j = 0 : s[2] = 3, t[0] = 4 → 12 → 加到 temp[3]
//...
//直到全部乘完





// 优解：无进位相乘再相加
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串 第一个整数
     * @param t string字符串 第二个整数
     * @return string字符串
     */
    string solve(string s, string t)
    {
        // write code here
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        int len1 = s.size(), len2 = t.size();
        vector<int> temp(len1 + len2);

        for (int i = 0; i < len1; i++)
        {
            for (int j = 0; j < len2; j++)
            {
                temp[i + j] += (s[i] - '0') * (t[j] - '0');
            }
        }

        int c = 0;
        string ret;
        for (auto x : temp)
        {
            c += x;
            ret += c % 10 + '0';
            c /= 10;
        }
        while (c)
        {
            ret += c % 10 + '0';
            c /= 10;
        }

        while (ret.size() > 1 && ret.back() == '0')
        {
            ret.pop_back();
        }

        reverse(ret.begin(), ret.end());
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
     * @param s string字符串 第一个整数
     * @param t string字符串 第二个整数
     * @return string字符串
     */
    string solve(string s, string t)
    {
        // write code here
        int len1 = s.size(), len2 = t.size();
        vector<int> temp(len1 + len2, 0);                   // 临时数组保存各位的乘积和（不进位）

        // 从后往前（低位向高位）模拟乘法
        for (int i = len1 - 1; i >= 0; i--)
        {
            for (int j = len2 - 1; j >= 0; j--)
            {
                int mul = (s[i] - '0') * (t[j] - '0');      // 当前位乘法

                // 注意：i 和 j 是从 size() - 1 开始倒着走的，所以 i + j 会比实际的索引小，为了正确地将结果放到对应的 权重位 上，就用了 i + j + 1。
                temp[i + j + 1] += mul;                     // 暂存到对应位置，不进位
            }
        }

        // 统一进位处理
        int c = 0;
        string ret;
        for (int i = temp.size() - 1; i >= 0; i--)
        {
            int sum = temp[i] + c;
            ret.push_back((sum % 10) + '0');                // 当前位
            c = sum / 10;                                   // 更新进位
        }

        // 如果还有进位继续加
        while (c)
        {
            ret.push_back((c % 10) + '0');
            c /= 10;
        }

        // 去除前导0（注意此时是反的）
        while (ret.size() > 1 && ret.back() == '0')
        {
            ret.pop_back();
        }

        reverse(ret.begin(), ret.end());                    // 最后翻转结果字符串
        return ret;
    }
};