// 牛客：MT2 棋子翻转
// 链接：https://www.nowcoder.com/practice/a8c89dc768c84ec29cbf9ca065e3f6b4?tpId=128&tqId=33769&ru=/exam/oj

// 方法：暴力模拟
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param A int整型vector<vector<>>
     * @param f int整型vector<vector<>>
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > flipChess(vector<vector<int> >& A, vector<vector<int> >& f) {
        // write code here

        int dx[4] = { 0,0,1,-1 };
        int dy[4] = { 1,-1,0,0 };

        for (int i = 0; i < f.size(); i++)
        {
            int a = f[i][0] - 1, b = f[i][1] - 1;
            for (int k = 0; k < 4; k++)
            {
                int x = a + dx[k], y = b + dy[k];
                if (x >= 0 && x < 4 && y >= 0 && y < 4)
                {
                    A[x][y] = (A[x][y] + 1) % 2;
                }
            }
        }

        return A;
    }
};




// 位运算优化：
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param A int整型vector<vector<>>
     * @param f int整型vector<vector<>>
     * @return int整型vector<vector<>>
     */

    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    vector<vector<int> > flipChess(vector<vector<int> >& A, vector<vector<int> >& f) {
        // write code here
        for (auto& v : f)
        {
            int a = v[0] - 1, b = v[1] - 1;
            for (int i = 0; i < 4; i++)
            {
                int x = a + dx[i], y = b + dy[i];
                if (x >= 0 && x < 4 && y >= 0 && y < 4)
                {
                    A[x][y] ^= 1;
                }
            }
        }

        return A;
    }
};