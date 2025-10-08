// 牛客：NC114 旋转字符串
// 链接：https://www.nowcoder.com/practice/80b6bb8797644c83bc50ac761b72981c?tpId=196&tqId=37172&ru=/exam/oj

// 注意不是找子串，如果当成了找子串，当A和B长度不同时，会报错！

// 方法：字符串
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 旋转字符串
     * @param A string字符串
     * @param B string字符串
     * @return bool布尔型
     */
    bool solve(string A, string B)
    {
        // write code here
        if (A.size() != B.size())
        {
            return false;
        }

        string AA = A + A;
        auto ret = AA.find(B);
        if (ret == -1)
        {
            return false;
        }

        return true;

    }
};



// 优解：
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 旋转字符串
     * @param A string字符串
     * @param B string字符串
     * @return bool布尔型
     */
    bool solve(string A, string B)
    {
        // write code here
        if (A.size() != B.size())
        {
            return false;
        }

        return (A + A).find(B) != -1;
        //return (A + A).find(B) != string::npos;
    }
};