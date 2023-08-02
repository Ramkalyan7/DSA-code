#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/893106?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

// https://www.youtube.com/watch?v=nGNoTdav5bQ&t=499s

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void func(BinaryTreeNode<int> *root, BinaryTreeNode<int> *&prev, BinaryTreeNode<int> *&head)
{
    if (root == NULL)
        return;

    func(root->left, prev, head);

    if (prev == NULL)
        head = root;

    else
    {
        root->left = prev;
        prev->right = root;
    }

    prev = root;

    func(root->right, prev, head);
}

BinaryTreeNode<int> *BTtoDLL(BinaryTreeNode<int> *root)
{
    // Write your code here

    BinaryTreeNode<int> *prev = NULL, *head = NULL;

    func(root, prev, head);

    return head;
}