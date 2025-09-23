// 牛客：添加字符
// 链接：https://www.nowcoder.com/questionTerminal/b2b816e20e8343b49abbaf493886ce26

// 方法：暴力枚举
// 枚举字符串 a、b 不相同字符的最小个数。
#include <iostream>
#include <string>
using namespace std;

string a, b;

int main()
{
    cin >> a >> b;
    int n = a.size(), m = b.size(), ret = m;    // 最多不同 n 个字符

    for (int i = 0; i <= m - n; i++)            // 枚举 A 对齐到 B 的每个位置（B 的子串长度为 n）
    {
        int temp = 0;                           // 当前对齐方式下，不相等字符的个数

        for (int j = 0; j < n; j++)
        {
            if (b[i + j] != a[j])               // 比较 A 和 B 当前对齐位置的字符
            {
                temp++;
            }
        }

        ret = min(ret, temp);                   // 更新最小差异
    }

    cout << ret << endl;
    return 0;
}