// 牛客：DP59 数位染色
// 链接：https://www.nowcoder.com/practice/adf828f399de4932955734a4eac12757?tpId=230&tqId=38956&ru=/exam/oj

// 方法：动态规划
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;

int main()
{
    cin >> s;

    int n = s.size(), sum = 0;
    for (auto x : s)
    {
        sum += (x - '0');
    }

    if (sum % 2 != 0)
    {
        cout << "No" << endl;
    }
    else
    {
        sum /= 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
        dp[0][0] = true;

        for (int i = 1; i <= n; i++)
        {
            int temp = s[i - 1] - '0';
            for (int j = 0; j <= sum; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= temp)
                {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - temp];
                }
            }
        }

        if (dp[n][sum])
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




// 优解：
#include <iostream>
using namespace std;

const int N = 20, M = N * 9;
long long x;
int n, sum;
int arr[N];
bool dp[M];

bool fun()
{
    if (sum % 2 == 1)
    {
        return false;
    }

    sum /= 2;
    dp[0] = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = sum; j >= arr[i]; j--)
        {
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }

    return dp[sum];
}

int main()
{
    cin >> x;
    while (x)
    {
        arr[n++] = x % 10;
        sum += x % 10;
        x /= 10;
    }

    if (fun())
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}