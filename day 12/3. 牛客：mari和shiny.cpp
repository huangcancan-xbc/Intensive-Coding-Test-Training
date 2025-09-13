// 牛客：mari和shiny
// 链接：https://ac.nowcoder.com/acm/problem/26226

// 最初的想法是用哈希表存储三个字母的数量，如果字符串中有 s 出现了 a 次，h 出现了 b 次，y 出现了 c 次，那么能组成的 shy 子序列数量 = a * b * c。
// 但这个推理忽略了一个关键点：字符在子序列中需要满足先后顺序！syhy是一个很好的反例，也不能排序，否则就打乱了子序列的顺序。

// 方法：多状态的线性DP
// 推导过程在文件同级目录下
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    string str;
    cin >> n >> str;

    vector<long long> s(n + 1, 0), h(n + 1, 0), y(n + 1, 0);
    s[0] = str[0] == 's' ? 1 : 0;

    for (int i = 1; i < n; i++)
    {
        s[i] = str[i] == 's' ? s[i - 1] + 1 : s[i - 1];
        h[i] = str[i] == 'h' ? s[i - 1] + h[i - 1] : h[i - 1];
        y[i] = str[i] == 'y' ? h[i - 1] + y[i - 1] : y[i - 1];
    }

    cout << y[n - 1];
    return 0;
}



// 空间优化：使用变量进行状态转移
#include <iostream>
#include <string>
using namespace std;

int n;
string str;

int main()
{
    cin >> n >> str;

    long long s = 0, h = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        char ch = str[i];

        if (ch == 's')
        {
            s++;
        }
        else if (ch == 'h')
        {
            h += s;
        }
        else if (ch == 'y')
        {
            y += h;
        }
    }

    cout << y << endl;

    return 0;
}