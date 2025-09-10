// 牛客：BC146 添加逗号
// 链接：https://www.nowcoder.com/practice/f51c317e745649c0900996fd3f683aed?tpId=290&tqId=39934&ru=/exam/oj

// 方法：字符串模拟
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    if (n < 4)
    {
        cout << s << endl;
        return 0;
    }

    string ret;
    int count = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        count++;
        ret += s[i];
        if (count == 3 && i != 0)
        {
            ret += ',';
            count = 0;
        }
    }

    reverse(ret.begin(), ret.end());
    cout << ret << endl;

    return 0;
}



// 优解 —— 下标与位数的映射关系，简单模拟一下即可：n - i - 1 表示：当前字符后面还有多少位；
// 如果后面剩下的位数是 3 的倍数，而且当前不是最后一位，就加一个逗号。
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    string ret;
    int n = s.size();

    for (int i = 0; i < n; i++)         // 从左往右逐位添加
    {
        ret += s[i];                    // 加入当前数字字符

        // 判断是否需要加逗号
        // 条件1：当前位置不是最后一位（最后一位后面不能加逗号）
        // 条件2：当前位后剩下的位数是3的倍数（例如：980,364,535 → 从左边第3、6位后加逗号）
        if ((n - i - 1) % 3 == 0 && i != n - 1)
        {
            ret += ',';                 // 插入逗号
        }
    }

    cout << ret << endl;
    return 0;
}