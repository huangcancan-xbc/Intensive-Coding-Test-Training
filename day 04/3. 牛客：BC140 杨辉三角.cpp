// 牛客：BC140 杨辉三角
// 链接：https://www.nowcoder.com/practice/e671c6a913d448318a49be87850adbcc?tpId=290&tqId=39928&ru=/exam/oj

// 方法：模拟/小DP
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> v(n + 1, vector<int>(n + 1, 1));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 2; j < i; j++)
		{
			v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%5d", v[i][j]);
		}

		cout << endl;
	}

	return 0;
}



// 优解：
#include <iostream>
using namespace std;

int dp[31][31];

int main()
{
	int n;
	cin >> n;

	dp[1][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%5d", dp[i][j]);
		}
		printf("\n");
	}

	return 0;
}