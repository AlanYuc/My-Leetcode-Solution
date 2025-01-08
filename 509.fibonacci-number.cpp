/*
 * @lc app=leetcode.cn id=509 lang=cpp
 * @lcpr version=30204
 *
 * [509] 斐波那契�?
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */

