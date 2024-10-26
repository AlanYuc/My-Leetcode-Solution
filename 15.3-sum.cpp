/*
 * @lc app=leetcode.cn id=15 lang=cpp
 * @lcpr version=30204
 *
 * [15] 涓夋暟涔嬪拰
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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            // 排序后第一个数大于0，则不存在三数之和为0的组合
            if (nums[i] > 0)
            {
                return ans;
            }

            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0)
                {
                    right--;
                }
                else if (sum < 0)
                {
                    left++;
                }
                else
                {
                    vector<int> path = {nums[i], nums[left], nums[right]};
                    ans.push_back(path);
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    left++;
                    right--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [-1,0,1,2,-1,-4]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n
// @lcpr case=end

 */
