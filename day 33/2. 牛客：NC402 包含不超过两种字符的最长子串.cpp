// 牛客：NC402 包含不超过两种字符的最长子串
// 链接：https://www.nowcoder.com/practice/90d6a362fa7d4c519d557da797bb02ce?tpId=196&tqId=40552&ru=/exam/oj

// 方法：滑动窗口
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

int main()
{
    cin >> s;

    int left = 0, right = 0, n = s.size();
    int hash[26] = { 0 };               // 记录每个字符的出现次数
    int count = 0;                      // 记录当前窗口中不同字符的数量
    int ret = 0;                        // 记录最长子串的长度

    while (right < n)
    {
        if (hash[s[right] - 'a'] == 0)
        {
            count++;                    // 新字符加入，不同字符数量加 1
        }

        hash[s[right] - 'a']++;
        right++;

        while (count > 2)
        {
            hash[s[left] - 'a']--;
            if (hash[s[left] - 'a'] == 0)
            {
                count--;                // 某个字符完全移出窗口，不同字符数量减 1
            }

            left++;
        }

        ret = max(ret, right - left);
    }

    cout << ret << endl;
    return 0;
}



// 或者（优解）：
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int left = 0, right = 0, n = s.size();
    int hash[26] = { 0 };               // 统计窗口内每种字符出现了多少次
    int count = 0;                      // 统计窗口内一共有多少种字符
    int ret = 0;

    while (right < n)
    {
        if (hash[s[right] - 'a']++ == 0)
        {
            count++;                    // 0->1，窗口内多了一种字符
        }

        while (count > 2)
        {
            if (hash[s[left++] - 'a']-- == 1)
            {
                count--;                // 1->0，窗口内少了一种字符
            }
        }

        ret = max(ret, right - left + 1);
        right++;
    }

    cout << ret << endl;
    return 0;
}