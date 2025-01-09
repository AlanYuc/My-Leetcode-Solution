/*
 * @lc app=leetcode.cn id=69 lang=cpp
 * @lcpr version=30204
 *
 * [69] x 的平方根
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
    int mySqrt(int x)
    {
        // ���ֲ���
        int left = 0, right = x;
        int temp = -1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            // ע������int���͵���ֵ��˿��ܻᳬ����Χ�����ʹ��long long����
            if ((long long)mid * mid <= x)
            {
                temp = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return temp;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 8\n
// @lcpr case=end

 */
