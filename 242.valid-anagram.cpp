// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=242 lang=cpp
 * @lcpr version=30204
 *
 * [242] 有效的字母异位词
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
    bool isAnagram(string s, string t)
    {
        vector<int> vec(26);
        for (int i = 0; i < s.size(); i++)
        {
            vec[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            vec[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (vec[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "anagram"\n"nagaram"\n
// @lcpr case=end

// @lcpr case=start
// "rat"\n"car"\n
// @lcpr case=end

 */
