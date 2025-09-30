// 牛客：排序子序列
// 链接：https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471

// 方法：模拟 + 贪心
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, ret = 0;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int i = 0;
    while (i < n)
    {
        if (i == n - 1)
        {
            ret++;
            break;
        }

        if (v[i] < v[i + 1])
        {
            while (i + 1 < n && v[i] <= v[i + 1])
            {
                i++;
            }

            ret++;
        }
        else if (v[i] > v[i + 1])
        {
            while (i + 1 < n && v[i] >= v[i + 1])
            {
                i++;
            }
            ret++;
        }
        else if (v[i] == v[i + 1])
        {
            i++;
        }
        i++;
    }

    cout << ret << endl;
    return 0;
}



#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int ret = 1;                    // 最少一个段
    int flag = 0;                   // 当前趋势，0=平稳，1=上升，-1=下降

    for (int i = 1; i < n; ++i)
    {
        if (flag == 0)
        {
            if (a[i] > a[i - 1])
            {
                flag = 1;           // 上升趋势
            }
            else if (a[i] < a[i - 1])
            {
                flag = -1;          // 下降趋势
            }
            // 相等则继续看下一位
        }
        else if (flag == 1)
        {
            if (a[i] < a[i - 1])
            {
                ++ret;              // 趋势反转，切新段
                flag = 0;           // 重置趋势
            }
        }
        else if (flag == -1)
        {
            if (a[i] > a[i - 1])
            {
                ++ret;              // 趋势反转，切新段
                flag = 0;           // 重置趋势
            }
        }
    }

    cout << ret << endl;
    return 0;
}



// 优解：
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n;
int arr[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ret = 0, i = 0;
    while (i < n)
    {
        if (i == n - 1)
        {
            ret++;
            break;
        }

        if (arr[i] < arr[i + 1])
        {
            while (i + 1 < n && arr[i] <= arr[i + 1])
            {
                i++;
            }
            ret++;
        }
        else if (arr[i] > arr[i + 1])
        {
            while (i + 1 < n && arr[i] >= arr[i + 1])
            {
                i++;
            }
            ret++;
        }
        else
        {
            while (i + 1 < n && arr[i] == arr[i + 1])
            {
                i++;
            }
        }
        i++;
    }

    cout << ret << endl;
    return 0;
}