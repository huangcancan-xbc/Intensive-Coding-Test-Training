// 牛客：MT8 奇数位丢弃
// 链接：https://www.nowcoder.com/practice/196141ecd6eb401da3111748d30e9141?tpId=128&tqId=33775&ru=/exam/oj

// 注意是多组输入！！

// 方法一：暴力模拟
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;

    while (cin >> n)
    {
        vector<int> v;
        for (int i = 0; i <= n; i++)
        {
            v.push_back(i);
        }

        while (v.size() > 1)
        {
            vector<int> temp;
            for (int i = 0; i < v.size(); i++)
            {
                // 位置从 1 开始，所以 i%2==1 表示奇数位置
                if ((i + 1) % 2 == 0)
                {
                    temp.push_back(v[i]); // 保留偶数位置
                }
            }
            v = temp; // 更新序列
        }

        cout << v[0] << endl;
    }

    return 0;
}




// 方法二：数学方法（或者也可以看成约瑟夫环的变种）
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int i = 0;
        while (pow(2, i) <= n)
        {
            i++;
        }

        cout << (pow(2, i - 1) - 1) << endl;
    }

    return 0;
}


// 优解：
#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int ret = 1;
        while (ret - 1 <= n)
        {
            ret *= 2;
        }

        cout << ret / 2 - 1 << endl;
    }
    return 0;
}