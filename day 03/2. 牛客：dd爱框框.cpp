// 牛客：dd爱框框
// 链接：https://ac.nowcoder.com/acm/problem/221681

// 方法：滑动窗口
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long n, x;
    cin >> n >> x;

    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    long long left = 0, right = 0, sum = 0, len = 0x3f3f3f3f;   // 初始化左右指针、当前窗口内元素之和sum及最小子数组长度len
    int l = 0, r = 0;                                           // 记录最终结果的左右边界（1-based）

    while (right < n)                                           // 右指针遍历整个数组
    {
        sum += v[right++];                                      // 扩大窗口：加上当前右端元素，并右移右指针

        while (sum >= x)                                        // 当窗口内的和大于等于x时，尝试收缩左边界以找到更小的符合条件的子数组
        {
            long long length = right - left;                    // 当前窗口长度（注意此时right已经+1了，所以直接减去left即可得到当前窗口长度）
            if (length < len)
            {
                len = length;                                   // 更新最小子数组长度
                l = left + 1, r = right;                        // 记录当前最优解的左右边界（因为1-based索引，因此left加1）
            }

            sum -= v[left++];                                   // 收缩窗口左边界：减去当前左端元素，并右移左指针
        }
    }

    cout << l << ' ' << r << endl;                              // 输出满足条件的最短子数组区间（1-based）

    return 0;
}




// 优解：
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e7 + 5;                                          // 定义一个常量N，表示数组的最大长度
int v[N], n, x;                                                 // 声明数组v和变量n（数组长度）、x（目标值）

int main()
{
    cin >> n >> x;

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];                                            // 循环从1开始，读取n个整数到数组v中
    }

    int left = 0, right = 0, sum = 0;                           // 初始化左右指针、当前窗口内元素之和sum
    int len = 0x3f3f3f3f, l = 0, r = 0;                         // 初始化最小子数组长度len及记录最终结果的左右边界l和r

    while (right <= n)                                          // 右指针遍历整个数组（注意这里是<=n，因为right是从1开始的）
    {
        sum += v[right];                                        // 扩大窗口：加上当前右端元素，并增加右指针的位置

        while (sum >= x)                                        // 当窗口内的和大于等于x时，尝试收缩左边界以找到更小的符合条件的子数组
        {
            if (right - left + 1 < len)                         // 如果当前窗口长度小于已知最短长度
            {
                len = right - left + 1;                         // 更新最短长度
                l = left;                                       // 记录当前最优解的左边界
                r = right;                                      // 记录当前最优解的右边界
            }

            sum -= v[left++];                                   // 收缩窗口左边界：减去当前左端元素，并右移左指针
        }

        right++;                                                // 移动右指针，继续扩大窗口
    }

    cout << l << ' ' << r << endl;                              // 输出满足条件的最短子数组区间（题目要求1-based索引，因此left加1）

    return 0;
}