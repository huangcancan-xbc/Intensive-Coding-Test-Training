// 牛客：NC383 主持人调度（一）
// 链接：https://www.nowcoder.com/practice/e160b104354649b69600803184094adb?tpId=196&tqId=40514&ru=/exam/oj

// 方法：排序 + 模拟
// 这里最重要的一点就是排序！！最开始以为给出的示例就是有序的导致部分正确，其实不然。

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param schedule int整型vector<vector<>>
     * @return bool布尔型
     */
    bool hostschedule(vector<vector<int> >& schedule)
    {
        // write code here
        int n = schedule.size();
        if (n == 1)
        {
            return true;
        }

        sort(schedule.begin(), schedule.end());

        for (int i = 1; i < n; i++)
        {
            if (schedule[i][0] < schedule[i - 1][1])
            {
                return false;
            }
        }

        return true;
    }
};