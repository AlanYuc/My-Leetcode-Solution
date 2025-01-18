/*
 * @lc app=leetcode.cn id=518 lang=cpp
 * @lcpr version=30204
 *
 * [518] 闆堕挶鍏戞崲 II
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
    int change(int amount, vector<int> &coins)
    {
        //本题注意事项
        //中间有样例4681，会出现正值溢出（两个数相加超出int范围）
        //解决方法，

        // 完全背包
        //vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));
        vector<vector<unsigned int>> dp(coins.size(), vector<unsigned int>(amount + 1, 0));

        // 初始化列
        for (int i = 0; i < coins.size(); i++)
        {
            dp[i][0] = 1;
        }

        // 初始化行
        for (int j = coins[0]; j <= amount; j++)
        {
            // dp[0][j] = dp[0][j - coins[0]] + coins[0];
            if (j % coins[0] == 0)
            {
                dp[0][j] = 1;
            }
        }

        // 公式推导
        for (int i = 1; i < coins.size(); i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                if (j < coins[i])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
                }
            }
        }
        return dp[coins.size() - 1][amount];
    }
};
// @lc code=end

/*
// @lcpr case=start
// 5\n[1, 2, 5]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[2]\n
// @lcpr case=end

// @lcpr case=start
// 10\n[10]\n
// @lcpr case=end

 */
