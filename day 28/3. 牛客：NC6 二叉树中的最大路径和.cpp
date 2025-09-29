// 牛客：NC6 二叉树中的最大路径和
// 链接：https://www.nowcoder.com/practice/da785ea0f64b442488c125b441a4ba4a?tpId=196&tqId=37050&ru=/exam/oj

// 方法：递归/DFS/树形DP/后序遍历

//把问题拆解成一个更容易处理的子问题：对于某个节点 root，我们如何计算一条“经过该节点的最大路径和”？
//定义 int dfs(TreeNode* root)表示从当前节点 root 出发，向下走一条路径（只能往左子树或右子树走一边），能获得的最大路径和。
//同时我们在遍历的过程中，尝试更新 以该节点为“中间点”向左、向右扩展的路径和，也就是：
//最大路径 = 左子树最大贡献 + 右子树最大贡献 + 当前节点值
//这个值可能会是全局最大路径和，我们就尝试更新一个 ret。


/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return int整型
     */
    int ret = INT_MIN;                      // 全局最大路径和，初始为最小整数
    int maxPathSum(TreeNode* root)
    {
        // write code here
        dfs(root);
        return ret;
    }

    int dfs(TreeNode* root)                 // 后序遍历：返回以当前节点为起点的“单边”最大路径和
    {
        if (root == nullptr)
        {
            return 0;                       // 空节点返回0
        }

        // 左右子树分别递归，负数不贡献，取0
        int l = max(0, dfs(root->left));    // 左子树最大贡献
        int r = max(0, dfs(root->right));   // 右子树最大贡献

        ret = max(ret, root->val + l + r);  // 更新全局最大路径和（当前节点+左右两边）
        return root->val + max(l, r);       // 返回“单边”最大路径（只能往左或右，不能同时返回）
    }
};