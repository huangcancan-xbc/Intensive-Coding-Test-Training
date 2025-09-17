// 牛客：神奇数
// 链接：https://www.nowcoder.com/questionTerminal/99fa7be28d5f4a9d9aa3c98a6a5b559a

// 方法：模拟
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// 判断一个数是否是质数
bool isPrime(int x)
{
    if (x <= 1)
    {
        return false;                               // 1及以下不是质数
    }

    for (int i = 2; i <= sqrt(x); i++)              // 从2遍历到sqrt(x)
    {
        if (x % i == 0)
        {
            return false;                           // 如果有因子则不是质数
        }
    }

    return true;
}

// 检查某个数是否为神奇数
bool check(int x)
{
    string s = to_string(x);                        // 转为字符串以便逐位处理

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < s.size(); j++)
        {
            if (i == j)
            {
                continue;                           // 两个位置必须不同
            }

            if (s[i] == '0' || s[j] == '0')
            {
                continue;                           // 前导0非法，跳过
            }

            int num = stoi(string() + s[i] + s[j]); // 拼接字符串并转数字，string() 是一个空字符串对象（等价于 ""）
            /*等价下面4行代码
            string t = "";
            t += s[i];
            t += s[j];
            int num = stoi(t);*/

            if (num >= 10 && isPrime(num))          // 要求是合法两位数，且为质数
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int ret = 0;

    for (int i = a; i <= b; i++)
    {
        if (check(i))
        {
            ret++;
        }
    }

    cout << ret << endl;
    return 0;
}




// 优解：
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int a, b;

bool isprim(int n)
{
    if (n < 2)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int check(int n)
{
    vector<int> num;
    while (n)
    {
        num.push_back(n % 10);
        n /= 10;
    }

    for (int i = 0; i < num.size(); i++)
    {
        for (int j = 0; j < num.size(); j++)
        {
            if (i != j && num[i] != 0)
            {
                if (isprim(num[i] * 10 + num[j]))
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int main()
{
    cin >> a >> b;

    int ret = 0;
    for (int i = max(a, 10); i <= b; i++)
    {
        ret += check(i);
    }

    cout << ret << endl;

    return 0;
}