// 牛客：乒乓球筐
// 链接：https://www.nowcoder.com/questionTerminal/bb4f1a23dbb84fd7b77be1fbe9eaaf32

// 方法一：哈希表
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		int hash[26] = { 0 };
		bool flag = false;

		for (auto x : a)
		{
			hash[x - 'A']++;
		}

		for (auto x : b)
		{
			if (--hash[x - 'A'] < 0)
			{
				flag = true;
				break;
			}
		}

		if (flag)
		{
			cout << "No" << endl;
		}
		else
		{
			cout << "Yes" << endl;
		}
	}

	return 0;
}




// 方法二：排序 + 双指针
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    while (cin >> a >> b)
    {
        // 1. 将 a, b 都排序（sort），方便后续匹配
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int i = 0, j = 0;                       // i 用来遍历 a，j 用来遍历 b
        int n = a.size(), m = b.size();
        bool flag = true;

        // 2. 双指针扫描
        while (i < n && j < m)
        {
            if (a[i] < b[j])                    // 当前 a[i] 字母过小，不是 b[j]，跳过
            {
                i++;            
            }
            else if (a[i] == b[j])              // 匹配到 b[j]，同时向后移动
            {
                i++;
                j++;
            }
            else                                // a[i] > b[j]，a 中没有足够 b[j]，直接失败
            {
                flag = false;
                break;
            }
        }
        
        if (j < m)
        {
            flag = false;                       // 如果 j 没走完，说明 b 中还有字母没匹配上
        }

        if (flag)
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