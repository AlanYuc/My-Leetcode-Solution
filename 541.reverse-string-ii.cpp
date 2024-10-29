/*
 * @lc app=leetcode.cn id=541 lang=cpp
 * @lcpr version=30204
 *
 * [541] 反转字符�? II
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
    void myReverse(string &s, int startIndex, int endIndex)
    {
        for (int i = startIndex, j = endIndex; i < j; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }

    string reverseStr(string s, int k)
    {
        int len = s.size();
        for (int i = 0; i < len; i += (2 * k))
        {
            if (i + k <= len)
            {
                myReverse(s, i, i + k - 1);
                continue;
            }
            myReverse(s, i, len - 1);
        }
        return s;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abcdefg"\n2\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n2\n
// @lcpr case=end

 */
