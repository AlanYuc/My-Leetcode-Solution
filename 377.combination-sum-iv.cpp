/*
 * @lc app=leetcode.cn id=377 lang=cpp
 * @lcpr version=30204
 *
 * [377] 组合总和 �?
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
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<unsigned int> dp(target + 1);

        dp[0] = 1;
        
        // for (int i = 1; i <= target; i++)
        // {
        //     if (i % nums[0] == 0)
        //         dp[i] = 1;
        // }

        for (int i = 0; i <= target; i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i >= nums[j])
                    dp[i] += dp[i - nums[j]];
            }
        }

        return dp[target];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n4\n
// @lcpr case=end

// @lcpr case=start
// [9]\n3\n
// @lcpr case=end

 */
