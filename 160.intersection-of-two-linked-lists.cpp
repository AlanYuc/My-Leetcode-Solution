// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=160 lang=cpp
 * @lcpr version=30204
 *
 * [160] 相交链表
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *cur = headA;
        int size_A = 0;
        while (cur)
        {
            size_A++;
            cur = cur->next;
        }

        cur = headB;
        int size_B = 0;
        while (cur)
        {
            size_B++;
            cur = cur->next;
        }

        cur = nullptr;

        ListNode *cur_A = headA;
        ListNode *cur_B = headB;
        if (size_A < size_B)
        {
            swap(cur_A, cur_B);
        }

        int startIndex_A = abs(size_A - size_B);
        while (startIndex_A--)
        {
            cur_A = cur_A->next;
        }

        while (cur_A)
        {
            if (cur_A == cur_B)
            {
                return cur_A;
            }
            cur_A = cur_A->next;
            cur_B = cur_B->next;
        }
        return NULL;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 8\n[4,1,8,4,5]\n[5,6,1,8,4,5]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 2\n[1,9,1,2,4]\n[3,2,4]\n3\n1\n
// @lcpr case=end

// @lcpr case=start
// 0\n[2,6,4]\n[1,5]\n3\n2\n
// @lcpr case=end

 */
