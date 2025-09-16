// 牛客：分组
// 链接：https://ac.nowcoder.com/acm/problem/229023

//题目有点难理解：
//1. 有 n 个学生，每个人只擅长一个声部（用数字表示：a[i]）。
//2. 需要将这些学生分成 恰好 m 个小组。
//3. 每个小组的学生只能来自同一个声部，不能混声部。
//4. 不同小组可以来自同一个声部（比如高音分成多个组）。
//5. 目标是：让所有组中人数最多的组，人数尽量少。

// 方法一：暴力枚举
#include <iostream>
#include <unordered_map>
using namespace std;

int n, m;
unordered_map<int, int> cnt;                    // 统计每种声部的人数

bool check(int x)                               // 判断最多人数为 x 时，能否分成 m 组
{
    int g = 0;                                  // 能分成多少组
    for (auto& [a, b] : cnt)
    {
        g += b / x + (b % x == 0 ? 0 : 1);
    }
    return g <= m;
}

int main()
{
    cin >> n >> m;
    int hmax = 0;                               // 统计声部最多的人数
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        hmax = max(hmax, ++cnt[x]);
    }

    int kinds = cnt.size();
    if (kinds > m)                              // 处理边界情况
    {
        cout << -1 << endl;
    }
    else
    {
        for(int i = 1; i <= hmax; i++)          // 枚举所有的最多人数
        {
            if(check(i))
            {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}




// 方法二：二分优化
#include <iostream>
#include <unordered_map>
using namespace std;

int n, m;
unordered_map<int, int> cnt;                    // 统计每种声部的人数

bool check(int x)                               // 判断最多人数为 x 时，能否分成 m 组
{
    int g = 0;                                  // 能分成多少组
    for (auto& [a, b] : cnt)
    {
        g += b / x + (b % x == 0 ? 0 : 1);
    }
    return g <= m;
}

int main()
{
    cin >> n >> m;
    int hmax = 0;                               // 统计声部最多的人数
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        hmax = max(hmax, ++cnt[x]);
    }

    int kinds = cnt.size();
    if (kinds > m)                              // 处理边界情况
    {
        cout << -1 << endl;
    }
    else
    {
        int l = 1, r = hmax;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (check(mid))
            {
                r = mid;                        // mid 可行，尝试更小
            }
            else
            {
                l = mid + 1;                    // mid 不可行，增大
            }
        }

        cout << l << endl;
    }

    return 0;
}