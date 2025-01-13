/*
 * @lc app=leetcode.cn id=2270 lang=cpp
 * @lcpr version=30204
 *
 * [2270] 分割数组的方案数
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
    int waysToSplitArray(vector<int> &nums)
    {
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        long long left = 0;
        long long right = sum;
        int total = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            left += nums[i];
            right -= nums[i];
            if (left >= right)
            {
                total++;
            }
        }
        return total;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [10,4,-8,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,1,0]\n
// @lcpr case=end

 */
