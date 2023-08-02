#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/@probabilitycodingisfunis1
// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
// https://www.codingninjas.com/studio/problems/sorted-linked-list-to-balanced-bst_842564?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube

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

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

TreeNode<int> *func(vector<int> v, int l, int r)
{

    if (l > r)
        return NULL;
    int mid = l + ((r - l) / 2);

    TreeNode<int> *temp = new TreeNode<int>(v[mid]);
    temp->left = func(v, l, mid - 1);
    temp->right = func(v, mid + 1, r);
    return temp;
}

TreeNode<int> *sortedListToBST(Node<int> *head)
{
    // Write your code here.
    vector<int> v;
    if (head == NULL)
        return NULL;
    while (head)
    {
        v.push_back(head->data);
        head = head->next;
    }

    return func(v, 0, v.size() - 1);
}
