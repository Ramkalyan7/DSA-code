#include <bits/stdc++.h>
using namespace std;

// LC : https://leetcode.com/problems/linked-list-cycle-ii/submissions/978624722/
// SL : https://takeuforward.org/data-structure/detect-and-remove-loop-in-a-linked-list/
// YT : https://www.youtube.com/watch?v=VxOFflTXlXo

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

Node *floydDetectLoop(Node *head)
{

    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {

        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;

        if (slow == fast)
        {
            return slow;
        }
    }

    return NULL;
}

Node *getStartingNode(Node *head)
{

    if (head == NULL)
        return NULL;

    Node *intersection = floydDetectLoop(head);

    if (intersection == NULL)
        return NULL;

    Node *slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

Node *removeLoop(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *startOfLoop = getStartingNode(head);

    if (startOfLoop == NULL)
        return head;

    Node *temp = startOfLoop;

    while (temp->next != startOfLoop)
    {
        temp = temp->next;
    }

    temp->next = NULL;
    return head;
}