// 牛客：NC1 大数加法（大数加法模板）
// 链接：https://www.nowcoder.com/practice/11ae12e8c6fe48f883cad618c2e81475?tpId=196&tqId=37176&ru=/exam/oj

// 方法：模拟
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t)
    {
        // write code here
        int i = s.size() - 1, j = t.size() - 1, temp = 0;
        string ret;

        while (i >= 0 || j >= 0 || temp)
        {
            if (i >= 0)
            {
                temp += s[i--] - '0';
            }
            if (j >= 0)
            {
                temp += t[j--] - '0';
            }

            ret += temp % 10 + '0';
            temp /= 10;
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};





class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t)
    {
        // write code here
        int i = s.size() - 1, j = t.size() - 1, temp = 0;
        string ret;

        while (i >= 0 || j >= 0 || temp)
        {
            temp += (i >= 0) ? s[i--] - '0' : 0;
            temp += (j >= 0) ? t[j--] - '0' : 0;

            ret += temp % 10 + '0';
            temp /= 10;
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};