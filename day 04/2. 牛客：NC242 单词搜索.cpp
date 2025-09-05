// 牛客：NC242 单词搜索
// 链接：https://www.nowcoder.com/practice/987f2981769048abaf6180ed63266bb2?tpId=196&tqId=39583&ru=/exam/oj

// 方法：搜索

// 优解：DFS + 回溯
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param board string字符串vector
     * @param word string字符串
     * @return bool布尔型
     */

    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    bool vis[110][110] = { 0 };
    int n, m;

    bool dfs(vector<string>& board, int i, int j, string& word, int index)
    {
        if (index == word.size() - 1)
        {
            return true;
        }

        vis[i][j] = true;

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == word[index + 1] && !vis[x][y])
            {
                if (dfs(board, x, y, word, index + 1))
                {
                    return true;
                }
            }
        }

        vis[i][j] = false;
        return false;
    }

    bool exist(vector<string>& board, string word)
    {
        // write code here
        n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (dfs(board, i, j, word, 0))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};




// BFS + 状态压缩
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param board string字符串vector
     * @param word string字符串
     * @return bool布尔型
     */

    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };

    struct Node
    {
        int x, y;                                       // 当前坐标
        int idx;                                        // 已匹配到 word 的第几位
        bool vis[110][110];                             // 当前路径访问标记（每条路径独立）
    };

    bool exist(vector<string>& board, string word)
    {
        // write code here
        int n = board.size();
        int m = board[0].size();

        queue<Node> q;

        // 将所有起点字符加入队列
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {
                    Node start;
                    start.x = i;
                    start.y = j;
                    start.idx = 0;
                    memset(start.vis, false, sizeof(start.vis));
                    start.vis[i][j] = true;
                    q.push(start);
                }
            }
        }

        // 开始BFS
        while (!q.empty())
        {
            Node cur = q.front();
            q.pop();

            if (cur.idx == word.size() - 1)
            {
                return true;                             // 如果已经匹配到最后一个字符
            }

            // 向四个方向扩展
            for (int i = 0; i < 4; i++)
            {
                int a = cur.x + dx[i], b = cur.y + dy[i];

                if (a >= 0 && a < n && b >= 0 && b < m && !cur.vis[a][b] && board[a][b] == word[cur.idx + 1])
                {
                    Node next = cur;                    // 拷贝当前状态
                    next.x = a;
                    next.y = b;
                    next.idx++;                         // 匹配下一位
                    next.vis[a][b] = true;              // 标记为已访问
                    q.push(next);                       // 入队
                }
            }
        }

        return false;                                   // 所有路径都无法匹配
    }
};