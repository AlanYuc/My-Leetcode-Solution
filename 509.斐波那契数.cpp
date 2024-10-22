/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 鏂愭尝閭ｅ鏁?
 */

// @lc code=start
class Solution
{
public:
    int fib(int n)
    {
        // 这里n=0的时候，dp[1] = 1;这一句会报错，下标越界了
        //  vector<int> dp(n + 1);
        //  dp[0] = 0;
        //  dp[1] = 1;
        //  if (n <= 1)
        //      return dp[n];
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
