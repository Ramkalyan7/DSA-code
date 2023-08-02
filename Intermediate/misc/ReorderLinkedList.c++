#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/rearrange-linked-list_764146?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=1

// https://leetcode.com/problems/reorder-list/description/

// https://takeuforward.org/data-structure/reorder-list/

// https://www.youtube.com/watch?v=mD7L5l2NmGU

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

Node<int> *reverseLL(Node<int> *head)
{

    Node<int> *p = NULL;
    Node<int> *q = head;
    Node<int> *n = head->next;
    while (q != NULL)
    {
        n = q->next;
        q->next = p;
        p = q;
        q = n;
    }
    return p;
}

Node<int> *rearrangeList(Node<int> *head)
{
    // Write your code here.

    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node<int> *slow = head;
    Node<int> *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node<int> *first = head;

    Node<int> *second = reverseLL(slow->next);

    slow->next = NULL;
    while (second)
    {
        Node<int> *t1 = first->next;
        Node<int> *t2 = second->next;
        first->next = second;
        second->next = t1;
        first = t1;
        second = t2;
    }

    return head;
}