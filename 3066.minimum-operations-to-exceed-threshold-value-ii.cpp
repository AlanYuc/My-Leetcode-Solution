/*
 * @lc app=leetcode.cn id=3066 lang=cpp
 * @lcpr version=30204
 *
 * [3066] 瓒呰繃闃堝�肩殑鏈�灏戞搷浣滄暟 II
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
    int minOperations(vector<int> &nums, int k)
    {
        //最终超时
        //错误记录：1、long long，需要考虑数据超范围的情况
        //2、需要考虑开始就符合条件，操作数为0的情况
        //3、中间用冒泡的方式保证数组的顺序，但时间复杂度o（n2），最终有个测试用例超时
        sort(nums.begin(), nums.end());
        vector<long long> vec;
        for (int i = 0; i < nums.size(); i++)
        {
            vec.push_back(nums[i]);
        }
        int op = 0;

        if (vec[0] >= k)
            return op;

        for (int i = 0; i < vec.size() - 1; i++)
        {
            long long temp = min(vec[i], vec[i + 1]) * 2 + max(vec[i], vec[i + 1]);
            vec[i] = 0;
            vec[i + 1] = temp;
            for (int j = i + 1; j < vec.size() - 1; j++)
            {
                if (vec[j] > vec[j + 1])
                {
                    int val = vec[j + 1];
                    vec[j + 1] = vec[j];
                    vec[j] = val;
                }
            }
            if (vec[i + 1] >= k)
            {
                return i + 1;
            }
            else
            {
                op++;
            }
        }
        return op;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,11,10,1,3]\n10\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,4,9]\n20\n
// @lcpr case=end

 */
