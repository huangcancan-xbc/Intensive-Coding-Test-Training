// 牛客：kotori和n皇后
// 链接：https://ac.nowcoder.com/acm/problem/50043

// 方法：数学 + 哈希
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

unordered_set<long long> hang;
unordered_set<long long> lie;
unordered_set<long long> zuo;
unordered_set<long long> you;
const int N = 1e5 + 10;

int main()
{
    int k;
    cin >> k;

    int v[N] = { 0 }, i = 1;

    while (k--)
    {
        long long x, y;
        cin >> x >> y;

        v[i] = v[i - 1];        // 关键点：继承之前的冲突，如果之前已经存在相互攻击的情况，那么后续都存在！
        if (hang.count(x) || lie.count(y) || zuo.count(y - x) || you.count(y + x))
        {
            v[i] = 1;
        }

        hang.insert(x);
        lie.insert(y);
        zuo.insert(y - x);
        you.insert(y + x);
        i++;
    }

    int t;
    cin >> t;

    while (t--)
    {
        int val;
        cin >> val;

        if (v[val] != 0)
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






// 优化：
#include <iostream>
#include <unordered_set>
using namespace std;

typedef long long LL;
int k, t;
int ret = 1e5 + 10; // 第一次出现互相攻击的皇后的个数
unordered_set<LL> row; // 标记行 y
unordered_set<LL> col; // 标记列 x
unordered_set<LL> dig1; // 标记主对角线 y - x
unordered_set<LL> dig2; // 标记副对角线 y + x

int main()
{
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y;

        if (ret != 1e5 + 10)
        {
            continue;                       // 继承之前的情况，这里不做处理，直接跳过
        }

        if (row.count(y) || col.count(x) || dig1.count(y - x) || dig2.count(y + x))
        {
            ret = i;
        }

        row.insert(y); col.insert(x); dig1.insert(y - x); dig2.insert(y + x);
    }

    cin >> t;
    while (t--)
    {
        int i;
        cin >> i;
        if (i >= ret)
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