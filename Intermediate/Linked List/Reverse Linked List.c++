#include <bits/stdc++.h>
using namespace std;

// YT :https://www.youtube.com/watch?v=iRtLEoL-r-g

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    // Write your code here
    LinkedListNode<int> *p = NULL;
    LinkedListNode<int> *q = head;
    LinkedListNode<int> *r = NULL;
    while (q != NULL)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    return p;
}