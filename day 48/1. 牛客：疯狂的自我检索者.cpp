// 牛客：疯狂的自我检索者
// 链接：https://ac.nowcoder.com/acm/problem/205826

// 方法：数学/模拟/贪心
#include <iostream>
#include <vector>
using namespace std;

long long n, m, sum = 0, ret = 0;

int main()
{
    cin >> n >> m;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    printf("%.5lf %.5lf", (double)(sum + m) / n, (double)(sum + m * 5) / n);
    //printf("%.5lf %.5lf\n", (sum + m) * 1.0 / n, (sum + m * 5) * 1.0 / n);

    return 0;
}