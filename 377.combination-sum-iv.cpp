/*
 * @lc app=leetcode.cn id=377 lang=cpp
 * @lcpr version=30204
 *
 * [377] 缁勫悎鎬诲拰 鈪?
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

        //初始化是1，但没有明确的意义，只是确保后续可以迭代
        dp[0] = 1;

        //题目要求是求所有组合，所以对遍历顺序有要求
        //先遍历背包容量再遍历物品--求所有排列组合
        //先遍历物品再遍历背包容量--只求组合（不要求顺序）
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
