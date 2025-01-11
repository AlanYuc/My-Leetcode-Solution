/*
 * @lc app=leetcode.cn id=343 lang=cpp
 * @lcpr version=30204
 *
 * [343] 鏁存暟鎷嗗垎
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
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[2] = 1;
        for(int i=3;i<=n;i++){
            for(int j= 1;j<= i/2;j++){
                //错误记录
                //max(dp[i]也要进行一次比较，不然只记录最后一次j的结果，前面计算的最大值会被丢掉
                dp[i] = max(dp[i] , max(j * (i-j) , j* dp[i-j]));
            }
        }
        return dp[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

 */

