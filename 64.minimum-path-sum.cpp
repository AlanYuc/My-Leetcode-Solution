/*
 * @lc app=leetcode.cn id=64 lang=cpp
 * @lcpr version=30204
 *
 * [64] æœ€å°è·¯å¾„å’Œ
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // ³õÊ¼»¯
        int row = 0;
        for (int i = 0; i < m; i++)
        {
            row += grid[i][0];
            dp[i][0] = row;
        }

        int col = 0;
        for (int j = 0; j < n; j++)
        {
            col += grid[0][j];
            dp[0][j] = col;
        }

        // ±éÀú
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,3,1],[1,5,1],[4,2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[4,5,6]]\n
// @lcpr case=end

 */
