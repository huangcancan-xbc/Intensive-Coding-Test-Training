// 牛客：十字爆破
// 链接：https://ac.nowcoder.com/acm/problem/205836

// 方法一：暴力枚举（超时）
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<long long>> v, ret;

long long sum(int x, int y)
{
	long long val = 0;
	for (int i = 0; i < m; i++)
	{
		val += v[x][i];
	}
	for (int i = 0; i < n; i++)
	{
		val += v[i][y];
	}

	return val - v[x][y];
}

int main()
{
	scanf("%d%d", &n, &m);
	v.resize(n, vector<long long>(m));
	ret.resize(n, vector<long long>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ret[i][j] = sum(i, j);
			printf("%long longd ", ret[i][j]);
		}

		printf("\n");
	}

	return 0;
}



// 方法二：空间换时间
// 既然会超时，那么就使用空间暂存一下数据，减少计算量，从而实现空间换时间：
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
long long n, m;
long long row[N], col[N];						// 行和列的和的数组

int main()
{
	scanf("%ld %ld", &n, &m);
	long long arr[n][m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%lld", &arr[i][j]);
			row[i] += arr[i][j];				// 计算该行所有元素的和
			col[j] += arr[i][j];				// 计算该列所有元素的和
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%lld ", row[i] + col[j] - arr[i][j]);
		}

		printf("\n");
	}

	return 0;
}