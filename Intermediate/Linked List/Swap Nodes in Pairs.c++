#include <bits/stdc++.h>
using namespace std;

// LC : https://leetcode.com/problems/swap-nodes-in-pairs/

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *pairsSwap(Node *head)
{
    //  Write your code here.
    if (head == NULL || head->next == NULL)
        return head;

    Node *Prev = NULL;
    Node *Cur = head;
    Node *Next = head->next;
    head = head->next;

    while (Cur != NULL && Next != NULL)
    {
        if (Prev)
            Prev->next = Next;
        Cur->next = Next->next;
        Next->next = Cur;
        Prev = Cur;
        Cur = Cur->next;
        if (Cur)
            Next = Cur->next;
    }
    return head;
}