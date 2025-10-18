// 力扣：42. 接雨水
// 链接：https://leetcode.cn/problems/trapping-rain-water/description/

// 方法一：动态规划/前缀和
class Solution
{
public:
    int trap(vector<int>& height)
    {
        int n = height.size(), ret = 0;
        vector<int> left(n), right(n);

        // 预处理左侧最大值数组
        left[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], height[i]);
        }

        // 预处理右侧最大值数组
        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(right[i + 1], height[i]);
        }

        // 求结果
        for (int i = 1; i < n - 1; i++)
        {
            ret += min(left[i], right[i]) - height[i];
        }

        return ret;
    }
};




// 方法二：单调栈
class Solution
{
public:
    int trap(vector<int>& height)
    {
        int n = height.size(), ret = 0;
        stack<int> st; // 单调递减栈，存放下标

        for (int i = 0; i < n; i++)
        {
            // 如果当前柱子比栈顶柱子高，就会形成“接水区间”
            while (!st.empty() && height[i] > height[st.top()])
            {
                int top = st.top(); // 取出栈顶作为“凹槽底”
                st.pop();

                if (st.empty())
                {
                    break; // 左边没有界限，无法接水
                }

                int left = st.top();             // 左边界
                int width = i - left - 1;        // 接水的宽度
                int high = min(height[left], height[i]) - height[top];
                // 有效高度 = 两边较小高度 - 凹槽底高度

                ret += width * high;
            }

            st.push(i); // 当前下标入栈
        }

        return ret;
    }
};




// 方法三：双指针
class Solution
{
public:
    int trap(vector<int>& height)
    {
        int n = height.size(), ret = 0;
        int left = 0, right = n - 1;   // 左右指针
        int left_max = 0, right_max = 0;

        while (left < right)
        {
            if (height[left] < height[right])
            {
                // 左边较矮，水位取决于左边
                if (height[left] >= left_max)
                {
                    left_max = height[left]; // 更新左边最大高度
                }
                else
                {
                    ret += left_max - height[left]; // 能接水
                }
                left++;
            }
            else
            {
                // 右边较矮，水位取决于右边
                if (height[right] >= right_max)
                {
                    right_max = height[right]; // 更新右边最大高度
                }
                else
                {
                    ret += right_max - height[right]; // 能接水
                }
                right--;
            }
        }

        return ret;
    }
};