// 牛客：REAL122 最大差值
// 链接：https://www.nowcoder.com/share/jump/5170733851759052145323

// 方法：贪心 + 模拟
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param A int整型vector
     * @param n int整型
     * @return int整型
     */
    int getDis(vector<int>& A, int n)
    {
        // write code here
        int minval = A[0], ret = 0;
        for (int i = 1; i < n; i++)
        {
            ret = max(ret, A[i] - minval);
            minval = min(minval, A[i]);
        }

        return ret;
    }
};