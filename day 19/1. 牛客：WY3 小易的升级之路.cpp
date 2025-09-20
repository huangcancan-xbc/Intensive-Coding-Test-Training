// 牛客：WY3 小易的升级之路
// 链接：https://www.nowcoder.com/practice/fe6c73cb899c4fe1bdd773f8d3b42c3d?tpId=122&tqId=33649&ru=/exam/oj

// 方法：模拟
#include <iostream>
using namespace std;

int n, a;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

int main()
{
    while (cin >> n >> a)
    {
        int b;
        for (int i = 0; i < n; i++)
        {
            cin >> b;

            if (b <= a)
            {
                a += b;
            }
            else
            {
                a += gcd(a, b);
            }
        }

        cout << a << endl;
    }

    return 0;
}



// 实际遇到的笔试强训有效解：

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//    long long n, x, val;
//    cin >> n >> x;
//
//    while (n--)
//    {
//        cin >> val;
//        if (x < val)
//        {
//            x = x + __gcd(val, x);
//        }
//        else
//        {
//            x += val;
//        }
//    }
//    cout << x << endl;
//
//    return 0;
//}