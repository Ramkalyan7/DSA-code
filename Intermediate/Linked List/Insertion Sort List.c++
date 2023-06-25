#include <bits/stdc++.h>
using namespace std;

// LC : https://leetcode.com/problems/insertion-sort-list/description/

// YT : https://www.youtube.com/watch?v=gwW8U4exaYs

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *dummy = new ListNode(0);
        while (head)
        {
            ListNode *temp = dummy;
            ListNode *headNext = head->next;
            while (temp->next && temp->next->val < head->val)
            {
                temp = temp->next;
            }

            head->next = temp->next;
            temp->next = head;
            head = headNext;
        }
        return dummy->next;
    }
};