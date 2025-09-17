// 牛客：QR6 字符串替换
// 链接：https://www.nowcoder.com/practice/f094aed769d84cf3b799033c82fc1bf6?tpId=182&tqId=34710&ru=/exam/oj

// 方法：模拟
class StringFormat
{
public:
    string formatString(string A, int n, vector<char> arg, int m)
    {
        // write code here
        string ret;
        int i = 0, index = 0;
        while (i < n)
        {
            if (i + 1 < n && A[i] == '%' && A[i + 1] == 's')
            {
                ret += arg[index++];
                i++;
            }
            else
            {
                ret += A[i];
            }

            i++;
        }

        while (index < arg.size())
        {
            ret += arg[index++];
        }

        return ret;
    }
};

class StringFormat
{
public:
    string formatString(string A, int n, vector<char> arg, int m)
    {
        int j = 0;
        string ret;

        for (int i = 0; i < n; i++)
        {
            if (A[i] == '%')
            {
                if (i + 1 < n && A[i + 1] == 's')
                {
                    ret += arg[j++];
                    i++;
                }
                else
                {
                    ret += A[i];
                }
            }
            else
            {
                ret += A[i];
            }
        }

        while (j < m)
        {
            ret += arg[j++];
        }

        return ret;
    }
};




class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串 原串
     * @param arg char字符型vector 需替换数组
     * @return string字符串
     */
    string formatString(string str, vector<char>& arg)
    {
        // write code here
        string ret;
        int i = 0, index = 0;
        while (i < str.size())
        {
            if (i + 1 < str.size() && str[i] == '%' && str[i + 1] == 's')
            {
                ret += arg[index++];
                i++;
            }
            else
            {
                ret += str[i];
            }

            i++;
        }

        while (index < arg.size())
        {
            ret += arg[index++];
        }

        return ret;
    }
};