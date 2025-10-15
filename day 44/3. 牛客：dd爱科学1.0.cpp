// 牛客：dd爱科学1.0
// 链接：https://ac.nowcoder.com/acm/problem/221822

// 方法：动态规划 + 贪心 + 二分
#include <iostream>
#include <string>
using namespace std;

const int N = 1e6 + 10;
int n, ret;
string s;
int dp[N];

int main()
{
    cin >> n >> s;

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (ret == 0 || ch >= dp[ret])
        {
            dp[++ret] = ch;
        }
        else
        {
            int left = 1, right = ret;
            while (left < right)
            {
                int mid = left + (right - left) / 2;

                if (ch >= dp[mid])
                {
                    left = mid + 1;
                }
                else if (ch < dp[mid])
                {
                    right = mid;
                }
            }

            dp[left] = ch;
        }
    }

    cout << n - ret << endl;

    return 0;
}