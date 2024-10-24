/*
 * @lc app=leetcode.cn id=202 lang=cpp
 * @lcpr version=30204
 *
 * [202] 快乐�?
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
    int getSum(int val)
    {
        int sum = 0;
        while (val)
        {
            int temp = val % 10;
            sum += temp * temp;
            val /= 10;
        }
        return sum;
    }
    bool isHappy(int n)
    {
        int sum = 0;
        unordered_map<int, int> myMap;
        while (n)
        {
            int sum = getSum(n);
            if (sum == 1)
            {
                return true;
            }
            if (myMap[sum] > 0)
            {
                return false;
            }
            myMap[sum]++;
            n = sum;
        }
        return false;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 19\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

 */
