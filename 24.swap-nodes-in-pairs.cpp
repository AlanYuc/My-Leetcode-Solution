/*
 * @lc app=leetcode.cn id=24 lang=cpp
 * @lcpr version=30204
 *
 * [24] 两两交换链表中的节点
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    pair<ListNode *, ListNode *> myReverse(ListNode *head, ListNode *tail)
    {
        ListNode *pre = tail->next;
        ListNode *cur = head;
        while (pre != tail)
        {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return {tail, head};
    }

    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummyNode = new ListNode();
        dummyNode->next = head;
        ListNode *pre = dummyNode;
        int k = 2;
        while (head)
        {
            ListNode *tail = pre;
            int i = k;
            while (i--)
            {
                tail = tail->next;
                if (!tail)
                {
                    return dummyNode->next;
                }
            }
            ListNode *next = tail->next;
            pair<ListNode *, ListNode *> result = myReverse(head, tail);
            head = result.first;
            tail = result.second;
            tail->next = next;
            pre->next = head;
            pre = tail;
            head = tail->next;
        }
        return dummyNode->next;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
