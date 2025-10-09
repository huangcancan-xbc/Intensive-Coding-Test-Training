// 牛客：dd爱旋转
// 链接：https://ac.nowcoder.com/acm/problem/221786

// 方法：找规律优化 + 模拟
// 寻找规律：
// 1. 顺时针旋180等价于一次行对称 + 一次列对称
// 2. 行镜像就是一次行对称
// 3. 消消乐：出现偶数次等于不对称/不翻转，奇数次才需要进行处理
#include <iostream>
#include <vector>
using namespace std;

void func1(vector<vector<int>>& v, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            swap(v[i][j], v[n - i - 1][j]);
        }
    }
}

void func2(vector<vector<int>>& v, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            swap(v[i][j], v[i][n - j - 1]);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    int count1 = 0, count2 = 0;
    int q, x;
    cin >> q;
    while (q--)
    {
        cin >> x;
        if (x == 1)
        {
            count1++;
            count2++;
        }
        else
        {
            count1++;
        }
    }

    if (count1 % 2 == 1)
    {
        func1(v, n);
    }

    if (count2 % 2 == 1)
    {
        func2(v, n);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}




// 优解：
#include <iostream>
using namespace std;

const int N = 1010;
int n;
int g[N][N];

void setRow() // 行对称
{
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            swap(g[i][j], g[n - 1 - i][j]);
        }
    }
}

void setCol() // 列对称
{
    for (int j = 0; j < n / 2; j++)
    {
        for (int i = 0; i < n; i++)
        {
            swap(g[i][j], g[i][n - 1 - j]);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }

    int q, x;
    cin >> q;

    int row = 0, col = 0;
    while (q--)
    {
        cin >> x;
        if (x == 1)
        {
            row++, col++;
        }
        else
        {
            row++;
        }
    }

    row %= 2;
    col %= 2;

    if (row)
    {
        setRow();
    }
    if (col)
    {
        setCol();
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << g[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}