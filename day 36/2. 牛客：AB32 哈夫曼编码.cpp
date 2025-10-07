// 牛客：AB32 哈夫曼编码
// 链接：https://www.nowcoder.com/practice/4c0419eb07c840ca8402e4f2a52cfd49?tpId=308&tqId=40489&ru=/exam/oj

// 时间长了，有点忘了哈夫曼编码的原理了，题目也不太友好，没有进行说明。
// 关于哈夫曼编码的介绍（B站）：https://www.bilibili.com/video/BV1qu411F7Zs/?share_source=copy_web&vd_source=872e5e3ccf44874c39edaf42e30ab0de

// 方法：优先队列 + 哈夫曼编码
// 计算编码后字符串的最短长度其实也就是计算带权路径长度，但是计算带权路径长度需要计算叶子节点到根节点的路径长度，比较麻烦
// 因此，可以使用另外一种方法：累加每个节点的值（除去根节点不计入）就是编码后字符串的最短长度。

// 所以：在哈夫曼树的构造过程中，把每次合并两个最小节点的权值之和累加起来（不包括最后的根节点权值），得到的就是带权路径长度，也就是最短编码长度。
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long LL;
int n;

int main()
{
    cin >> n;
    priority_queue<LL, vector<LL>, greater<LL>> heap;
    while (n--)
    {
        LL x;
        cin >> x;
        heap.push(x);
    }

    // 构建最优二叉树 / 构建哈夫曼树
    LL ret = 0;
    while (heap.size() > 1)
    {
        LL t1 = heap.top(); heap.pop();
        LL t2 = heap.top(); heap.pop();
        heap.push(t1 + t2);
        ret += t1 + t2;
    }

    cout << ret << endl;

    return 0;
}