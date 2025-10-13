// 牛客：小红的子串
// 链接：https://ac.nowcoder.com/acm/problem/260770

// 方法：滑动窗口 + 前缀和思想 + 哈希表
//我们要统计子串中不同字符个数在[l, r] 区间内的子串数量。
//也就是说：满足种类 ≤ r 的子串再减去 满足种类 ≤ l - 1 的子串 = 种类在[l, r] 的子串。
//
//find(x) 统计 ≤x 的子串个数，用滑动窗口实现。
//题目要求[l, r]，所以用 find(r) - find(l - 1)。
//思路就像「前缀和」处理区间问题，只不过这里是「子串个数的前缀和」。

#include <iostream>
#include <string>
using namespace std;

int n, l, r;
string s;

// 找出字符种类在 [1,x] 之间的子串个数
long long find(int x)
{
    long long ret = 0;
    if (x == 0)
    {
        return 0;
    }

    // 滑动窗口
    int left = 0, right = 0;
    int hash[26] = { 0 }, count = 0;            // 统计窗口内字符种类个数

    while (right < n)
    {
        if (hash[s[right] - 'a']++ == 0)
        {
            count++;
        }

        while (count > x)
        {
            if (hash[s[left] - 'a']-- == 1)
            {
                count--;
            }

            left++;
        }

        ret += right - left + 1;
        right++;
    }

    return ret;
}

int main()
{
    cin >> n >> l >> r >> s;

    cout << find(r) - find(l - 1) << endl;

    return 0;
}