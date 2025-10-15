// 牛客：最小差值
// 链接：https://ac.nowcoder.com/acm/problem/207376

// 方法：暴力模拟
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 求最小差值
     * @param a int整型vector 数组a
     * @return int整型
     */
    int minDifference(vector<int>& a)
    {
        // write code here
        long long n = a.size(), ret = INT_MAX;

        sort(a.begin(), a.end());

        for (int i = 1; i < n; i++)
        {
            ret = min(ret, (long long)(a[i] - a[i - 1]));
        }

        return ret;
    }
};