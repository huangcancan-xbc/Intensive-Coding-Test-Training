// 牛客：MT7 字符编码
// 链接：https://www.nowcoder.com/practice/c471efdbd33a4a979539a91170c9f1cb?tpId=128&tqId=33774&ru=/exam/oj

// 方法：哈夫曼编码
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        int ret = 0;
        unordered_map<char, int> hash;
        priority_queue<int, vector<int>, greater<int>> heap;
        for (auto x : s)
        {
            hash[x]++;
        }

        for (auto [a, b] : hash)
        {
            heap.push(b);
        }

        while (heap.size() > 1)
        {
            int t1 = heap.top(); heap.pop();
            int t2 = heap.top(); heap.pop();
            ret += (t1 + t2);
            heap.push(t1 + t2);
        }

        cout << ret << endl;
    }

    return 0;
}



// 优化：
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        // 1. 先统计每个字符的频次
        int hash[300] = { 0 };
        for (auto ch : s)
        {
            hash[ch]++;
        }

        // 2. 把所有的频次放入堆里面
        priority_queue<int, vector<int>, greater<int>> heap;
        for (int i = 0; i < 300; i++)
        {
            if (hash[i]) heap.push(hash[i]);
        }

        // 3. 哈夫曼编码
        int ret = 0;
        while (heap.size() > 1)
        {
            int t1 = heap.top(); heap.pop();
            int t2 = heap.top(); heap.pop();
            ret += t1 + t2;
            heap.push(t1 + t2);
        }

        cout << ret << endl;
    }

    return 0;
}