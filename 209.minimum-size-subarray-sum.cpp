/*
 * @lc app=leetcode.cn id=209 lang=cpp
 * @lcpr version=30204
 *
 * [209] 闀垮害鏈�灏忕殑瀛愭暟缁?
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
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int ans = INT32_MAX;
        int start = 0;  // 滑动窗口起始位置
        int sublen = 0; // 滑动窗口内子数组长度
        int sum = 0;    // 滑动窗口内子数组和
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            while (sum >= target)
            {
                sublen = i - start + 1;
                ans = ans < sublen ? ans : sublen;
                sum -= nums[start++];
            }
        }
        if (ans == INT32_MAX)
            return 0;
        else
            return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 7\n[2,3,1,2,4,3]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[1,4,4]\n
// @lcpr case=end

// @lcpr case=start
// 11\n[1,1,1,1,1,1,1,1]\n
// @lcpr case=end

 */
