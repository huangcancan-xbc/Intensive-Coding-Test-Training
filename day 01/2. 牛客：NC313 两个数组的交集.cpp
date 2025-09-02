// 牛客：NC313 两个数组的交集
// 链接：https://www.nowcoder.com/practice/56ea71d1f4e94de2aaec10e985874cce?tpId=196&tqId=40269&ru=/exam/oj
// https://www.nowcoder.com/practice/56ea71d1f4e94de2aaec10e985874cce

// 方法：哈希表
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums1 int整型vector
     * @param nums2 int整型vector
     * @return int整型vector
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        // write code here
        unordered_map<int, int> hash;
        set<int> ans;
        vector<int> ret;
        for (auto x : nums1)
        {
            hash[x] = 1;
        }

        for (auto x : nums2)
        {
            if (hash.count(x))
            {
                ans.insert(x);
            }
        }

        for (auto x : ans)
        {
            ret.push_back(x);
        }

        return ret;
    }
};



// 优解：
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums1 int整型vector
     * @param nums2 int整型vector
     * @return int整型vector
     */

    bool hash[1010] = { 0 };                // 用数组模拟哈希表
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ret;
        for (auto x : nums1)
        {
            hash[x] = true;                 // 标记出现过的数
        }

        for (auto x : nums2)
        {
            if (hash[x])                    // 若出现过，则加入结果集
            {
                ret.push_back(x);
                hash[x] = false;            // 避免重复加入
            }
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
     * @param nums1 int整型vector
     * @param nums2 int整型vector
     * @return int整型vector
     */

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> ret;
        for (int num : nums2)
        {
            if (set1.count(num))
            {
                ret.insert(num);
            }
        }

        return vector<int>(ret.begin(), ret.end());
    }
};



// 双指针：
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums1 int整型vector
     * @param nums2 int整型vector
     * @return int整型vector
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ret;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                i++;
            }
            else if (nums1[i] > nums2[j])
            {
                j++;
            }
            else
            {
                if (ret.empty() || ret.back() != nums1[i])
                {
                    ret.push_back(nums1[i]);
                }

                i++;
                j++;
            }
        }
        return ret;
    }
};



// set_intersection 函数
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums1 int整型vector
     * @param nums2 int整型vector
     * @return int整型vector
     */

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> ret;
        set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(ret));

        return ret;
    }
};