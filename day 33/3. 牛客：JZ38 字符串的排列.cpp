// 牛客：JZ38 字符串的排列
// 链接：https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=13&tqId=11180&ru=/exam/oj

// 方法：递归 + DFS + 回溯 + 剪枝
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @return string字符串vector
     */

    string s;
    vector<string> ret;
    bool vis[15] = { 0 };
    string path;
    int n;
    vector<string> Permutation(string str)
    {
        // write code here
        n = str.size();
        sort(str.begin(), str.end());

        s = str;
        dfs(0);

        return ret;
    }

    void dfs(int pos)
    {
        if (n == pos)
        {
            ret.push_back(path);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if (i > 0 && s[i] == s[i - 1] && !vis[i - 1])
                {
                    continue;
                }

                path.push_back(s[i]);
                vis[i] = true;

                dfs(pos + 1);

                vis[i] = false;
                path.pop_back();
            }
        }
    }
};