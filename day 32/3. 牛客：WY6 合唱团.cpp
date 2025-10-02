// 牛客：WY6 合唱团
// 链接：https://www.nowcoder.com/practice/661c49118ca241909add3a11c96408c8?tpId=122&tqId=33652&ru=/exam/oj

// 方法（优解）：动态规划 + 状态转移范围限制
#include <iostream>
using namespace std;

typedef long long LL;
const int N = 55;                                   // 最多 50 个数
const int M = 15;                                   // 最多选 10 个数
const LL INF = 0x3f3f3f3f3f3f3f3f;                  // 无穷大 (负无穷时取 -INF)

int n, k, d;                                        // n: 数组长度，k: 选几个人，d: 下标最大距离限制
LL arr[N];                                          // 存储输入数组，从下标 1 开始
LL f[N][M];                                         // f[i][j]：以第 i 个人为最后一个人，选 j 个人，能取得的最大乘积
LL g[N][M];                                         // g[i][j]：以第 i 个人为最后一个人，选 j 个人，能取得的最小乘积（处理负数）

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    cin >> k >> d;                                  // 输入要选几个人 和 最大相隔距离

    for (int i = 1; i <= n; i++)                    // 遍历每一行（即每个第 i 个人作为最后一个人）
    {
        f[i][1] = g[i][1] = arr[i];                 // 只选 1 个人时，最大最小乘积都是他自己

        for (int j = 2; j <= min(i, k); j++)        // 选 j 个人，j 必须 <= i（不可能选超过 i 个）
        {
            f[i][j] = -INF;                         // 初始化最大值
            g[i][j] = INF;                          // 初始化最小值

            // 从第 j-1 个位置开始选，prev 是第 j-1 个人的位置，要满足 i - prev <= d，因此 prev >= i - d
            // 同时 prev 至少是 j-1（要保证前面有 j-1 个人）
            for (int prev = max(i - d, j - 1); prev <= i - 1; prev++)
            {
                // 枚举所有合法的 prev，从第 prev 个人转移过来
                // arr[i] 是当前选中的人，乘上前 j-1 人的最大 or 最小乘积
                LL a = f[prev][j - 1] * arr[i];
                LL b = g[prev][j - 1] * arr[i];

                f[i][j] = max(f[i][j], max(a, b));  // 取 max 更新 f[i][j]
                g[i][j] = min(g[i][j], min(a, b));  // 取 min 更新 g[i][j]
            }
        }
    }

    LL ret = -INF;
    for (int i = k; i <= n; i++)                    // 枚举以第 i 个人结尾，选了 k 个人的最大乘积
    {
        ret = max(ret, f[i][k]);
    }

    cout << ret << endl;
    return 0;
}