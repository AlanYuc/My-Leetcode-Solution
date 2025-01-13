/*
 * @lc app=leetcode.cn id=118 lang=cpp
 * @lcpr version=30204
 *
 * [118] 鏉ㄨ緣涓夎
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
    vector<vector<int>> generate(int numRows)
    {
        //注意数组创建的格式，以下生成的是空的二维数组
        //后面可以用push_back将一维数组添加进去
        vector<vector<int>> ans;

        //题解中的不同点（用resize构建二维数组）：
        //二维数组的创建使用vector<vector<int>> ans(numRows);
        //先创建一个有numRows行的二维数组，
        //然后用resize重新设置每行大小，再直接赋值，不用push_back
        //ret[i].resize(i + 1);

        for (int i = 0; i < numRows; i++)
        {
            vector<int> row(i + 1);
            row[0] = 1;
            row[i] = 1;
            ans.push_back(row);
        }

        for (int i = 2; i < numRows; i++)
        {
            for (int j = 1; j < i; j++)
            {
                ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
