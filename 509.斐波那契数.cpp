/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契�?
 */

// @lc code=start
class Solution
{
public:
    int fib(int n)
    {
        // ����n=0��ʱ��dp[1] = 1;��һ��ᱨ���±�Խ����
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
