// 牛客：NC101 压缩字符串(一)
// 链接：https://www.nowcoder.com/practice/c43a0d72d29941c1b65c857d8ac9047e?tpId=196&tqId=39317&ru=/exam/oj

// 方法一：模拟
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param param string字符串
     * @return string字符串
     */
    string compressString(string param)
    {
        // write code here
        string ret;
        int n = param.size();

        int i = 0;
        while (i < n)
        {
            ret += param[i];
            int count = 1;

            while (param[i] == param[i + 1])
            {
                count++;
                i++;
            }

            if (count > 1)
            {
                ret += to_string(count);
            }
            i++;
        }

        return ret;
    }
};




// 方法二：双指针
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param param string字符串
     * @return string字符串
     */
    string compressString(string param)
    {
        // write code here
        string ret;
        int left = 0, right = 0, n = param.size();
        while (left < n)
        {
            while (right + 1 < n && param[right] == param[right + 1])
            {
                right++;
            }

            int len = right - left + 1;
            ret += param[left];

            if (len > 1)
            {
                ret += to_string(len);
            }

            left = right + 1;
            right = left;
        }

        return ret;
    }
};