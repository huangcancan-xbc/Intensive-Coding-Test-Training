// 牛客：拼三角
// 链接：https://ac.nowcoder.com/acm/problem/219046
// https://ac.nowcoder.com/acm/contest/11163/A

// 方法一、优解：优化枚举法
// 分析参考：https://blog.csdn.net/w2022009105/article/details/142416900
#include <iostream>
#include <algorithm>
using namespace std;

int t;
int arr[6];

int main()
{
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 6; i++) cin >> arr[i];
        sort(arr, arr + 6);
        if ((arr[0] + arr[1] > arr[2] && arr[3] + arr[4] > arr[5]) ||
            (arr[0] + arr[2] > arr[3] && arr[1] + arr[4] > arr[5]) ||
            (arr[0] + arr[3] > arr[4] && arr[1] + arr[2] > arr[5]) ||
            (arr[0] + arr[4] > arr[5] && arr[1] + arr[2] > arr[3]))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}




// 方法二：暴力枚举法
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 判断三个边能否组成三角形
bool is(int a, int b, int c)
{
    int maxLen = max({ a, b, c });
    int sum = a + b + c;

    return maxLen < sum - maxLen;                               // 最长边 < 其余两边和
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        vector<int> v(6);
        for (int i = 0; i < 6; ++i)
        {
            cin >> v[i];
        }

        bool flag = false;

        // 枚举所有从6个数中选3个的组合 (C(6,3) = 20 种)
        for (int i = 0; i < 6; ++i)
        {
            for (int j = i + 1; j < 6; ++j)
            {
                for (int k = j + 1; k < 6; ++k)
                {
                    int a = v[i], b = v[j], c = v[k];           // 第一组三条边：i, j, k

                    // 剩下的三条边组成第二组
                    vector<int> temp;
                    for (int l = 0; l < 6; ++l)
                    {
                        if (l != i && l != j && l != k)
                        {
                            temp.push_back(v[l]);
                        }
                    }

                    if (is(a, b, c) && is(temp[0], temp[1], temp[2]))
                    {
                        flag = true;
                        break;
                    }
                }

                if (flag)
                {
                    break;
                }
            }

            if (flag)
            {
                break;
            }
        }

        cout << (flag ? "Yes" : "No") << endl;
    }

    return 0;
}




// 方法三：深搜 DFS

//三角形判定条件：任意两边之和必须大于第三边。
//枚举方案：从6根棍子中枚举所有3根组合方式，总共有 C(6, 3) = 20 种组合，然后检查剩下的3根是否也满足三角形条件。
//DFS（深度优先搜索）：递归方式遍历所有组合情况。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long a[10];                        // 存储6根棍子的长度（使用1~6位置）
vector<long long> path;                 // 当前选择的3根棍子
bool vis[10];                           // 标记每根棍子是否已被选择
bool flag;                              // 是否找到满足条件的方案

// 检查当前选出的两组三根棍子能否都组成三角形
bool check()
{
    vector<long long> p;                // 用于存储剩下的三根棍子
    long long sum1 = path[0] + path[1] + path[2];       // 第一组三根棍子的总长度
    long long sum2 = 0;

    for (int i = 1; i <= 6; i++)
    {
        if (!vis[i])                    // 如果这根棍子未被选择，属于第二组
        {
            p.push_back(a[i]);
            sum2 += a[i];               // 累加第二组的总长度
        }
    }

    // 分别找出两组中最长的棍子（用于三角形判断）
    long long max1 = max({ path[0], path[1], path[2] });
    long long max2 = max({ p[0], p[1], p[2] });

    sum1 -= max1, sum2 -= max2;         // 剩下两边之和

    if (sum1 > max1 && sum2 > max2)     // 三角形成立条件：任意两边之和 > 第三边，即剩下两边之和 > 最长边
    {
        return 1;                       // 成功组成两个三角形
    }

    return 0;                           // 失败：不能组成两个三角形
}

// 使用DFS遍历所有选择3根棍子的组合方式
void dfs(int index)
{
    if (path.size() == 3)               // 如果已经选了3根棍子
    {
        if (check())                    // 检查能否两组三角形同时成立
        {
            flag = 1;                   // 找到可行解
        }

        return;
    }

    for (int i = index; i <= 6; i++)
    {
        path.push_back(a[i]);           // 选择第i根棍子
        vis[i] = 1;                     // 标记为已使用

        dfs(i + 1);                     // 递归继续选择下一个棍子

        vis[i] = 0;                     // 回溯：取消选择
        path.pop_back();                // 回溯：移除当前棍子
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        for (int i = 1; i <= 6; i++)
        {
            cin >> a[i];
        }

        flag = 0;                       // 每组测试初始化 flag
        dfs(0);                         // 从位置0开始 DFS 枚举组合

        if (flag)
        {
            cout << "Yes" << endl;      // 找到合法方案
        }
        else
        {
            cout << "No" << endl;       // 无合法方案
        }
    }

    return 0;
}
// 或者：
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool flag = false;                                              // 全局标志：是否找到合法分组

bool is(int a, int b, int c)                                    // 判断三个边能否组成三角形
{
    int maxLen = max({ a, b, c });
    int sum = a + b + c;

    return maxLen < sum - maxLen;                               // 最长边 < 其余两边和
}

void dfs(vector<int>& v, vector<int>& v1, vector<bool>& vis, int idx, int count)
{
    if (flag)
    {
        return;                                                 // 如果已经找到，直接返回
    }

    if (count == 3)
    {
        vector<int> v2;                                         // 收集剩下的棍子为 v2
        for (int i = 0; i < 6; ++i)
        {
            if (!vis[i])
            {
                v2.push_back(v[i]);
            }
        }

        if (is(v1[0], v1[1], v1[2]) && is(v2[0], v2[1], v2[2])) // 判断两组是否都能构成三角形
        {
            flag = true;
        }

        return;
    }

    for (int i = idx; i < 6; ++i)
    {
        if (!vis[i])
        {
            vis[i] = true;
            v1.push_back(v[i]);

            dfs(v, v1, vis, i + 1, count + 1);                      // 深搜下一根

            v1.pop_back();
            vis[i] = false;
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        vector<int> v(6);
        for (int i = 0; i < 6; ++i)
        {
            cin >> v[i];
        }

        flag = false;
        vector<int> v1;
        vector<bool> vis(6, false);
        dfs(v, v1, vis, 0, 0);

        cout << (flag ? "Yes" : "No") << endl;
    }

    return 0;
}