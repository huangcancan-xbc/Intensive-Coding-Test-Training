// 牛客：JZ61 扑克牌顺子
// 链接：https://www.nowcoder.com/practice/762836f4d43d43ca9deb273b3de8e1f4?tpId=13&tqId=11198&ru=/exam/oj

// 优解：方法一：找规律：

// 顺子定义：连续的5张牌，不允许重复；
// 0可补任意数，只要实际牌之间的最大差距 ≤ 4 就能用 0 补齐；
// 不能重复：因为一旦重复，就不能构成连续；
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型vector
     * @return bool布尔型
     */
    bool IsContinuous(vector<int>& numbers)
    {
        // write code here
        bool hash[14] = { 0 };
        int maxVal = 0, minVal = 14;            // 牌中的最大值和最小值

        for (auto x : numbers)
        {
            if (x)                              // if (x != 0)。跳过大小王
            {
                if (hash[x])
                {
                    return false;               // 如果这张牌出现过，说明重复，不可能是顺子
                }

                hash[x] = true;                 // 标记该数字已出现
                maxVal = max(maxVal, x);        // 更新最大值
                minVal = min(minVal, x);        // 更新最小值
            }
        }

        return maxVal - minVal <= 4;            // 最大值与最小值的差不能超过4，否则即使补牌也凑不成顺子
    }
};




// 方法二：排序模拟
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型vector
     * @return bool布尔型
     */
    bool IsContinuous(vector<int>& numbers)
    {
        // write code here
        sort(numbers.begin(), numbers.end());

        int count = 0;                           // 大小王数量
        for (int i = 0; i < 4; i++)
        {
            if (numbers[i] == 0)
            {
                count++;
                continue;
            }

            if (numbers[i] == numbers[i + 1])    // 有重复，无法构成顺子
            {
                return false;
            }
        }

        return numbers[4] - numbers[count] <= 4;
    }
};




// 方法三：使用 unordered_set:
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型vector
     * @return bool布尔型
     */
    bool IsContinuous(vector<int>& numbers)
    {
        // write code here
        unordered_set<int> hash;
        int maxVal = 0, minVal = 14;

        for (int num : numbers)
        {
            if (num == 0)
            {
                continue;
            }

            if (hash.count(num))
            {
                return false;  // 有重复
            }

            hash.insert(num);

            maxVal = max(maxVal, num);
            minVal = min(minVal, num);
        }

        return maxVal - minVal <= 4;
    }
};