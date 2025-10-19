// 牛客：NC115 栈和排序
// 链接：https://www.nowcoder.com/share/jump/5170733851759573143461

// 方法：栈 + 贪心 + 哈希
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 栈排序
     * @param a int整型vector 描述入栈顺序
     * @return int整型vector
     */
    vector<int> solve(vector<int>& a)
    {
        // write code here
        int n = a.size();
        stack<int> st;
        bool hash[50010] = { 0 }; // 统计当前哪些元素已经进栈

        int aim = n;
        vector<int> ret;

        for (auto x : a)
        {
            st.push(x);
            hash[x] = true;

            // 先更新目标值
            while (hash[aim])
            {
                aim--;
            }

            // 出栈
            while (st.size() && st.top() >= aim)
            {
                ret.push_back(st.top());
                st.pop();
            }
        }

        return ret;
    }
};