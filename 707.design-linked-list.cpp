/*
 * @lc app=leetcode.cn id=707 lang=cpp
 * @lcpr version=30204
 *
 * [707] 设计链表
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
class MyLinkedList
{
public:
    struct LinkNode
    {
        int val;
        LinkNode *next;
        LinkNode() : val(0), next(nullptr) {}
        LinkNode(int x) : val(x), next(nullptr) {}
    };

    MyLinkedList()
    {
        m_size = 0;
        dummyNode = new LinkNode();
    }

    int get(int index)
    {
        if (index < 0 || index >= m_size)
            return -1;
        LinkNode *cur = dummyNode->next;
        while (index--)
        {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val)
    {
        LinkNode *newNode = new LinkNode(val);
        newNode->next = dummyNode->next;
        dummyNode->next = newNode;
        m_size++;
    }

    void addAtTail(int val)
    {
        LinkNode *newNode = new LinkNode(val);
        LinkNode *cur = dummyNode;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = newNode;
        m_size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index > m_size)
            return;
        if (index < 0)
            index = 0;
        LinkNode *cur = dummyNode;
        LinkNode *newNode = new LinkNode(val);
        while (index--)
        {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        m_size++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= m_size)
            return;
        LinkNode *cur = dummyNode;
        while (index--)
        {
            cur = cur->next;
        }
        LinkNode *temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        temp = nullptr;
        m_size--;
        return;
    }

private:
    int m_size;
    LinkNode *dummyNode;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
