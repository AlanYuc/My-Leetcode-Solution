/*
 * @lc app=leetcode.cn id=9 lang=cpp
 * @lcpr version=30204
 *
 * [9] 回文�?
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
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        stack<int> myStack;
        int len = 0;
        int temp = x;
        while (temp > 0)
        {
            len++;
            temp /= 10;
        }
        temp = x;
        for (int i = 0; i < len / 2; i++)
        {
            myStack.push(temp % 10);
            temp /= 10;
        }
        if (len % 2 == 1)
            temp /= 10;
        for (int i = 0; i < len / 2; i++)
        {
            if (temp % 10 != myStack.top())
                return false;
            temp /= 10;
            myStack.pop();
        }
        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 121\n
// @lcpr case=end

// @lcpr case=start
// -121\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

 */
