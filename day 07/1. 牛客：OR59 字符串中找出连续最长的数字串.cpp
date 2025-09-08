// 牛客：OR59 字符串中找出连续最长的数字串
// 链接：https://www.nowcoder.com/practice/bd891093881d4ddf9e56e7cc8416562d?tpId=182&tqId=34785&ru=/exam/oj

// 方法、优解：模拟、双指针
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int len = 1, begin = 0;
    for (int i = 0, j = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            j = i;
            while (j < s.size() && s[j] >= '0' && s[j] <= '9')
            {
                j++;
            }

            if (j - i >= len)
            {
                len = j - i;
                begin = i;
            }

            i = j;
        }
    }

    cout << s.substr(begin, len) << endl;
    return 0;
}



#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int maxLen = 0, maxStart = 0;                   // 最长数字串长度，最长数字串起始位置
    int i = 0;

    while (i < s.length())
    {
        if (isdigit(s[i]))                          // 判断是否为数字字符
        {
            int start = i;
            while (i < s.length() && isdigit(s[i]))
            {
                ++i;
            }

            int len = i - start;
            if (len > maxLen)                       // 更新最大长度与位置
            {
                maxLen = len;
                maxStart = start;
            }
        }
        else
        {
            ++i;                                    // 跳过非数字字符
        }
    }

    cout << s.substr(maxStart, maxLen) << endl;     // 提取最长数字串
    return 0;
}




// 方法二：多段拆分
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    for (char& c : s)
    {
        if (!isdigit(c)) c = ' ';  // 非数字字符替换为空格
    }

    istringstream ss(s);
    string word, maxStr;

    while (ss >> word)
    {
        if (word.length() > maxStr.length())
        {
            maxStr = word;
        }
    }

    cout << maxStr << endl;
    return 0;
}