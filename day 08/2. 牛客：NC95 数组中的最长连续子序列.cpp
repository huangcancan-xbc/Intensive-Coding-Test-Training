// 牛客：NC95 数组中的最长连续子序列
// 链接：https://www.nowcoder.com/practice/eac1c953170243338f941959146ac4bf?tpId=196&tqId=37143&ru=/exam/oj

// 方法一：排序 + 模拟（注意如何处理重复数字）
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * max increasing subsequence
     * @param arr int整型vector the array
     * @return int整型
     */
    int MLS(vector<int>& arr)
    {
        // write code here
        // 排序使得连续的自然数相邻排列
        sort(arr.begin(), arr.end());

        int n = arr.size(), ret = 0;            // 记录最长连续子序列的长度

        for (int i = 0; i < n; )
        {
            int j = i + 1;                      // j是用来扫描的指针
            int count = 1;                      // 当前连续序列的长度，初始为1

            while (j < n)
            {
                if (arr[j] - arr[j - 1] == 1)
                {
                    count++;                    // 找到连续的数，长度加1
                    j++;
                }
                else if (arr[j] - arr[j - 1] == 0)
                {
                    j++;                        // 去重，跳过重复的数字
                }
                else
                {
                    break;                      // 非连续，跳出
                }
            }

            ret = max(ret, count);              // 更新最大值
            i = j;                              // 从下一个新段开始
        }

        return ret;
    }
};




// 方法二：哈希表
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * max increasing subsequence
     * @param arr int整型vector the array
     * @return int整型
     */
    int MLS(vector<int>& arr)
    {
        // write code here
        unordered_set<int> hash;                // 哈希集合，用于快速查找元素是否存在

        for (int num : arr)
        {
            hash.insert(num);                   // 将所有数字加入集合中（去重 + 快速查找）
        }

        int ret = 0;                            // 最长连续长度

        for (int num : arr)
        {
            if (hash.find(num - 1) == hash.end())           // 只从连续序列的“起点”开始（即：前一个数不在集合中）
            {
                int cur = num;
                int count = 1;

                while (hash.find(cur + 1) != hash.end())    // 不断向后寻找连续的数
                {
                    cur++;
                    count++;
                }

                ret = max(ret, count);          // 更新最大长度
            }
        }

        return ret;
    }
};