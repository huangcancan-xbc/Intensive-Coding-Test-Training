// 牛客：爱丽丝的人偶
// 链接：https://ac.nowcoder.com/acm/problem/213471

// 方法：贪心/构造/找规律
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n), ret(n);
    int val = 1;
    for (int i = 0; i < n; i++)
    {
        v[i] = val++;
    }

    sort(v.begin(), v.end());           // 后来发现其实不需要

    int index1 = 0;
    for (int i = 0; i < n; i += 2)
    {
        ret[i] = v[index1++];
    }
    int index2 = n - 1;
    for (int i = 1; i < n; i += 2)
    {
        ret[i] = v[index2--];
    }

    for (int i = 0; i < n; i++)
    {
        cout << ret[i] << ' ';
    }

    return 0;
}




// 优解：
#include <iostream>
using namespace std;

int n;

int main()
{
    cin >> n;

    int left = 1, right = n;

    while (left <= right)
    {
        cout << left << " ";            // 先输出小的
        left++;

        if (left <= right)
        {
            cout << right << " ";       // 再输出大的
            right--;
        }
    }

    return 0;
}