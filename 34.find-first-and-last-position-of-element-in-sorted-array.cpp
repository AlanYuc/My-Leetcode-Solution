// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 * @lcpr version=30204
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位�??
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
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        vector<int> ans(2,-1);

        //��������ˡ�nums[nums.size()-1] < target�����ȫ��ͨ����
        //��Ȼ����vector�Ķ��������
        //(�ѽ��)��ǰ��right = nums.size()����д����
        //����nums[mid]���п����±����
        if(nums.size() == 0 || nums[nums.size()-1] < target){
            return ans;
        }

        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                int start = mid;
                int end = mid;
                while (start >= 0 && nums[start] == nums[mid])
                {
                    start--;
                }
                start++;
                while (end < nums.size() && nums[end] == nums[mid])
                {
                    end++;
                }
                end--;
                ans.clear();
                ans.push_back(start);
                ans.push_back(end);
                return ans;
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [5,7,7,8,8,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,7,7,8,8,10]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */
