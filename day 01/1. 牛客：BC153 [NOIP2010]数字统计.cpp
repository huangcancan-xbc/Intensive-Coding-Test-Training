// 牛客：BC153 [NOIP2010]数字统计
// 链接：https://www.nowcoder.com/practice/179d9754eeaf48a1b9a49dc1d438525a?tpId=290&tqId=39941&ru=/exam/oj
// https://ac.nowcoder.com/acm/problem/16599


// 方法：枚举 + 数字拆分
#include <iostream>
#include <string>
using namespace std;

int is(int x)
{
    int count = 0;
    string s = to_string(x);
    for (auto x : s)
    {
        if (x == '2')
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int left, right, ret = 0;
    cin >> left >> right;

    for (int i = left; i <= right; i++)
    {
        ret += is(i);
    }

    cout << ret;
    return 0;
}



// 写法二：
#include <iostream>
using namespace std;

int main()
{
    int left, right, ret = 0;
    cin >> left >> right;

    for (int i = left; i <= right; i++)
    {
        int temp = i;
        while (temp)
        {
            if (temp % 10 == 2)
            {
                ret++;
            }
            temp /= 10;
        }

    }

    cout << ret;
    return 0;
}