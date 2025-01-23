/*
 * @lc app=leetcode.cn id=278 lang=cpp
 * @lcpr version=30204
 *
 * [278] 绗竴涓敊璇殑鐗堟湰
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
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int left = 1;
        int right = n;
        // while (left < right)
        // {
        //     int mid = left + (right - left) / 2;
        //     if (isBadVersion(mid))
        //     {
        //         right = mid - 1;
        //     }
        //     else
        //     {
        //         left = mid + 1;
        //     }
        // }
        // if (!isBadVersion(left))
        // {
        //     return left + 1;
        // }
        // else
        // {
        //     return left;
        // }

        //优化一次，全部默认左闭右闭的空间
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 5\n4\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */
