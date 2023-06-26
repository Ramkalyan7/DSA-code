#include <bits/stdc++.h>
using namespace std;

// LC : https://leetcode.com/problems/odd-even-linked-list/description/

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
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *oddDummy = new ListNode();
        ListNode *oddPtr = oddDummy;
        ListNode *evenDummy = new ListNode();
        ListNode *evenPtr = evenDummy;
        ListNode *p = head;
        int index = 0;
        while (p != NULL)
        {
            if (index % 2 == 0)
            {
                evenPtr->next = p;
                p = p->next;
                evenPtr = evenPtr->next;
                evenPtr->next = NULL;
            }
            else
            {
                oddPtr->next = p;
                p = p->next;
                oddPtr = oddPtr->next;
                oddPtr->next = NULL;
            }
            index++;
        }
        evenPtr->next = oddDummy->next;
        return evenDummy->next;
    }
};