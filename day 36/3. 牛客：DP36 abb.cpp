// 牛客：DP36 abb
// 链接：https://www.nowcoder.com/practice/0a8bbf8b9b5b4280957849ef4f240f07?tpId=230&tqId=38957&ru=/exam/oj

// 方法一：“滑动窗口” + 数学 + 哈希
// 结果值的数据量有点大，需要开 long long，当时忘记了，通过 80%。
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    long long n, ret = 0;
    string s;
    cin >> n >> s;

    unordered_map<char, int> hash;
    for (auto x : s)
    {
        hash[x]++;
    }

    for (int i = 0; i < s.size(); i++)  // 枚举abb的a，后面看b的组合数量情况
    {
        for (auto [a, b] : hash)
        {
            if (s[i] != a)
            {
                // 数学：“C3 2：表示从3个元素中选2个，有多少种选择”，b * (b - 1) / 2是展开计算公式
                ret += b * (b - 1) / 2;
            }
        }
        hash[s[i]]--;                   // 避免重复计算（abaccb：当下标为2时，第一个b不能参与计算！）
    }

    cout << ret << endl;
    return 0;
}
// 优化：
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    long long n, ret = 0;
    string s;
    cin >> n >> s;

    vector<long long> cnt(26, 0);
    for (char c : s) cnt[c - 'a']++;

    // 计算总的组合数
    long long sum = 0;
    for (int i = 0; i < 26; i++)
    {
        sum += cnt[i] * (cnt[i] - 1) / 2;
    }

    for (int i = 0; i < n; i++)
    {
        int idx = s[i] - 'a';
        
        ret += sum - cnt[idx] * (cnt[idx] - 1) / 2; // 总组合数减去该字符的组合数，就是当前能形成的 "abb" 数量

        sum -= cnt[idx] * (cnt[idx] - 1) / 2;       // 去掉旧组合
        cnt[idx]--;                                 // 减少一个该字符
        sum += cnt[idx] * (cnt[idx] - 1) / 2;       // 加上新组合
    }

    cout << ret << endl;
    return 0;
}





// 方法二：动态规划 + 哈希
#include <iostream>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int n;
char s[N];
LL dp[N];
LL f[26];
LL g[26];

int main()
{
    cin >> n >> s;

    LL ret = 0;
    for (int i = 0; i < n; i++)
    {
        int x = s[i] - 'a';
        dp[i] = f[x];
        ret += dp[i];

        f[x] = f[x] + i - g[x];
        g[x] = g[x] + 1;
    }

    cout << ret << endl;
}

// 优化（优解）：
#include <iostream>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int n;
char s[N];
LL f[26];                           // f[c]：当前已处理的字符中，字符 c 对应的贡献和
LL g[26];                           // g[c]：字符 c 出现的次数

int main()
{
    cin >> n >> s;

    LL ret = 0;
    for (int i = 0; i < n; i++)
    {
        int x = s[i] - 'a';         // 当前字符转换成 0~25 的索引

        ret += f[x];                // 累加该字符的贡献值（当前位置与之前相同字符位置差的和）

        // 更新 f[x]：i - g[x] 表示当前字符与之前出现的相同字符之间的下标差
        // f[x] 已经存储了之前所有相同字符的差值和，这里加上新的贡献
        f[x] = f[x] + i - g[x];
        g[x] = g[x] + 1;            // 更新 g[x]：该字符出现次数加 1
    }

    cout << ret << endl;
    return 0;
}