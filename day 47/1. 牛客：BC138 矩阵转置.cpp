// 牛客：BC138 矩阵转置
// 链接：https://www.nowcoder.com/share/jump/5170733851759566467236

// 方法一：使用交换
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> a(n, vector<long long>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    if (n == m)
    {
        // 方阵：原地转置
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                swap(a[i][j], a[j][i]); // 直接交换对角线两侧的元素
            }
        }

        // 输出 n*n
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
    else
    {
        // 非方阵：需要新矩阵 b
        vector<vector<long long>> b(m, vector<long long>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                swap(a[i][j], b[j][i]); // 用 swap 从 a 搬到 b
            }
        }

        // 输出 m*n
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << b[i][j] << " ";
            }

            cout << "\n";
        }
    }

    return 0;
}





// 方法二：找规律不交换（优解）
#include <iostream>
using namespace std;

const int N = 15;
int n, m;
int arr[N][N];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // ret[i][j] = arr[j][i]
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}