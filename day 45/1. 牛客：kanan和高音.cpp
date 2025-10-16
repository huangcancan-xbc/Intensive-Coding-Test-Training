// 牛客：kanan和高音
// 链接：https://ac.nowcoder.com/acm/problem/26229

// 方法：双指针/滑动窗口
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ret = 1, cur = 1;           // 当前连续片段长度

    for (int i = 1; i < n; i++)
    {
        if (v[i] - v[i - 1] <= 8)   // 当前音和前一个音差值 ≤ 8，可以唱
        {
            cur++;                  // 当前片段继续累加
        }
        else                        // 否则唱不上去
        {
            cur = 1;                // 重新开始新的片段
        }

        ret = max(ret, cur);        // 更新最大值
    }

    cout << ret << endl;

    return 0;
}




// 优化：
#include <iostream>
using namespace std;

const int N = 2e5 + 10;
int n;
int arr[N];
int ret = 1;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; )
    {
        int j = i;
        while (j + 1 < n && arr[j + 1] - arr[j] <= 8)
        {
            j++;
        }

        ret = max(ret, j - i + 1);
        i = j + 1;
    }

    cout << ret << endl;
    return 0;
}