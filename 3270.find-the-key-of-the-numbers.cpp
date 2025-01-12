/*
 * @lc app=leetcode.cn id=3270 lang=cpp
 * @lcpr version=30204
 *
 * [3270] 姹傚嚭鏁板瓧绛旀
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
    // int minKey(int num1, int num2, int num3)
    // {
    //     int min1 = num1 < num2 ? num1 : num2;
    //     int min2 = min1 < num3 ? min1 : num3;
    //     return min2;
    // }

    // int generateKey(int num1, int num2, int num3)
    // {
    //     vector<vector<int>> ans(3, vector<int>(4));
    //     for (int i = 3; i >= 0; i--)
    //     {
    //         ans[0][i] = num1 % 10;
    //         num1 /= 10;

    //         ans[1][i] = num2 % 10;
    //         num2 /= 10;

    //         ans[2][i] = num3 % 10;
    //         num3 /= 10;
    //     }

    //     int key = 0;
    //     for (int i = 0; i < 4; i++)
    //     {
    //         key = key * 10 + minKey(ans[0][i], ans[1][i], ans[2][i]);
    //     }
    //     return key;
    // }

    // 继续优化
    int generateKey(int num1, int num2, int num3)
    {
        int key = 0;
        int p = 1;
        while (num1 && num2 && num3)
        {
            // 注意min函数的用法，{}可以进行多值比较
            key += p * (min({num1 % 10, num2 % 10, num3 % 10}));
            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
            p *= 10;
        }
        return key;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 1\n10\n1000\n
// @lcpr case=end

// @lcpr case=start
// 987\n879\n798\n
// @lcpr case=end

// @lcpr case=start
// 1\n2\n3\n
// @lcpr case=end

 */
