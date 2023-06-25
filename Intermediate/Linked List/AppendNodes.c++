#include <bits/stdc++.h>
using namespace std;

// CS : https://www.codingninjas.com/codestudio/problems/append-nodes_763407?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

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

Node *addNodes(Node *head, int n, int m)
{
    // Write your code here.
    Node *dummyNode = new Node(-1);
    dummyNode->next = head;
    Node *p = dummyNode;
    while (p != NULL)
    {
        int i = m;
        int j = n;
        int sum = 0;
        while (i > 0 && p != NULL)
        {
            p = p->next;
            i--;
        }
        if (p == NULL)
            return head;

        while (j > 0 && p != NULL)
        {
            if (p->next)
                p = p->next;
            else
            {
                // sum+=p->data;
                Node *temp = new Node(sum);
                p->next = temp;
                return head;
            }
            sum += p->data;
            j--;
        }
        Node *temp = new Node(sum);
        temp->next = p->next;
        p->next = temp;
        p = temp;
    }
}