/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30204
 *
 * [20] 有效的括�?
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
    bool isValid(string s)
    {
        if (s.size() % 2 == 1)
            return false;
        stack<char> myStack;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                myStack.push(')');
            }
            else if (s[i] == '[')
            {
                myStack.push(']');
            }
            else if (s[i] == '{')
            {
                myStack.push('}');
            }
            else if (myStack.empty() || s[i] != myStack.top())
            {
                return false;
            }
            else
            {
                myStack.pop();
            }
        }
        return myStack.empty();
    }
};
// @lc code=end

/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

// @lcpr case=start
// "([])"\n
// @lcpr case=end

 */
