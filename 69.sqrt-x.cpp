/*
 * @lc app=leetcode.cn id=69 lang=cpp
 * @lcpr version=30204
 *
 * [69] x 鐨勫钩鏂规牴
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
    int mySqrt(int x)
    {
        // 二分查找
        int left = 0, right = x;
        int temp = -1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            // 注意这里int类型的数值相乘可能会超出范围，因此使用long long类型
            if ((long long)mid * mid <= x)
            {
                temp = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return temp;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 8\n
// @lcpr case=end

 */
