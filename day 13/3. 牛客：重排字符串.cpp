// 牛客：重排字符串
// 链接：https://ac.nowcoder.com/acm/problem/222104

// 方法：贪心
// 1. 每次去处理一批相同的字符
// 2. 优先处理出现次数最多的字符
// 3. 每次摆放的时候间隔一个格子
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int hash[26] = { 0 }, maxcount = 0;
    char maxval;
    vector<char> ret(n);
    for (int i = 0; i < n; i++)
    {
        hash[s[i] - 'a']++;
        if (hash[s[i] - 'a'] > maxcount)
        {
            maxcount = hash[s[i] - 'a'];
            maxval = s[i];
        }
    }

    if (maxcount > (n + 1) / 2)
    {
        cout << "no" << endl;
    }
    else
    {
        cout << "yes" << endl;
        int i = 0;
        while (maxcount--)
        {
            ret[i] = maxval;
            i += 2;
        }

        for (int j = 0; j < 26; j++)
        {
            if (j + 'a' != maxval && hash[j])
            {
                while (hash[j]--)
                {
                    if (i >= n)
                    {
                        i = 1;
                    }

                    ret[i] = j + 'a';
                    i += 2;
                }
            }
        }

        for (auto x : ret)
        {
            cout << x;
        }
    }

    return 0;
}





#include <iostream>
using namespace std;

const int N = 100010;
int n;
char s[N];
char ret[N];

int main()
{
    cin >> n >> s;

    int hash[26] = { 0 };                      // 统计每个字符的频次
    int maxIndex, maxCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (maxCount < ++hash[s[i] - 'a'])
        {
            maxCount = hash[s[i] - 'a'];
            maxIndex = s[i] - 'a';
        }
    }

    if (maxCount > (n + 1) / 2)
    {
        cout << "no" << endl;
    }
    else
    {
        cout << "yes" << endl;
        int index = 0;
        
        while (maxCount--)                      // 先去摆放出现次数最多的
        {
            ret[index] = maxIndex + 'a';
            index += 2;
        }
        
        for (int i = 0; i < 26; i++)            // 处理剩下的
        {
            if (hash[i] && i != maxIndex)
            {
                while (hash[i]--)
                {
                    if (index >= n) index = 1;
                    ret[index] = i + 'a';
                    index += 2;
                }
            }
        }
        
        for (int i = 0; i < n; i++)             // 打印结果
        {
            cout << ret[i];
        }

        cout << endl;
    }
    return 0;
}