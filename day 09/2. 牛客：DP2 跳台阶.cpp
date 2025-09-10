// 牛客：DP2 跳台阶
// 链接：https://www.nowcoder.com/practice/bfb2a2b3cdbd4bd6bba0d4dca69aa3f0?tpId=230&tqId=39749&ru=/exam/oj

// 方法一：递推（滚动数组）
// 注意更新先后顺序，先更新c，再更新a和b！
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 0 || n == 1)
    {
        cout << n << endl;
        return 0;
    }

    long a = 1, b = 1, c = 0;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    cout << c << endl;

    return 0;
}



// 方法二：DP
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int arr[45] = { 0 };
    arr[0] = 1, arr[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    cout << arr[n] << endl;

    return 0;
}