#include <bits/stdc++.h>
using namespace std;

// LC : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// SL :
// YT : https://www.youtube.com/watch?v=Lhu3MsXZy-Q

/*

Approach :


using slow and fast pointers



*/

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *removeKthNode(Node *head, int K)
{
    // Write your code here.
    Node *temp = new Node();
    temp->next = head;
    Node *fast = temp;
    Node *slow = temp;

    for (int i = 1; i <= K; i++)
    {
        fast = fast->next;
    }

    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return temp->next;
}
