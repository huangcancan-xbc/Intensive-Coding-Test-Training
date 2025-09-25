// 牛客：小葱的01串
// 链接：https://ac.nowcoder.com/acm/problem/230830

// 方法一：暴力枚举
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    s += s;  // 环形处理：把字符串复制一份接在后面

    int count0 = 0, count1 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0')
        {
            count0++;
        }
        else
        {
            count1++;
        }
    }

    int half = n / 2;
    int ret = 0;

    // 暴力枚举所有长度为 n/2 的子串起点
    for (int i = 0; i < n; ++i)
    {
        int red0 = 0, red1 = 0;
        for (int j = i; j < i + half; ++j)
        {
            if (s[j] == '0')
            {
                red0++;
            }
            else
            {
                red1++;
            }
        }

        int white0 = count0 - red0;
        int white1 = count1 - red1;

        if (red0 == white0 && red1 == white1)
        {
            ret++;
        }
    }

    cout << ret << endl;
    return 0;
}




// 方法二：滑动窗口（优解）
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int sum[2] = { 0 };                         // sum[0]：整个字符串中 '0' 的总数，sum[1]：'1' 的总数
    for (auto ch : s)
    {
        sum[ch - '0']++;                        // 统计整个串中 '0' 和 '1' 的数量
    }

    int left = 0, right = 0;                    // 滑动窗口左右指针
    int ret = 0;
    int half = n / 2;                           // 染红区域长度必须是 n / 2
    int count[2] = { 0 };                       // count[0]：当前窗口中 '0' 的个数，count[1]：'1' 的个数

    // 因为是环形串，将环转化为线性串时，只需要考虑长度为 n 的一圈，所以窗口只需滑动到 n - 1 即可，不需要整个 2n
    while (right < n - 1)
    {
        count[s[right] - '0']++;                // 当前字符加入窗口计数

        while (right - left + 1 > half)         // 如果窗口长度超过了 half，就移动左指针缩小窗口
        {
            count[s[left++] - '0']--;           // 移除左边界字符
        }

        if (right - left + 1 == half)           // 窗口长度刚好等于 half，检查是否满足条件
        {
            // 若红色区域（当前窗口）中 '0' 和 '1' 的数量正好是总量的一半，说明剩下的白色区域也一样多，是合法方案
            if (count[0] * 2 == sum[0] && count[1] * 2 == sum[1])
            {
                ret += 2;                       // 因为环形中对应的另一段也等价，算两种方案
            }
        }

        right++;                                // 移动窗口右边界
    }

    cout << ret << endl;                        // 输出合法方案数量
    return 0;
}