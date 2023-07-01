#include <bits/stdc++.h>
using namespace std;

/*
https://www.youtube.com/watch?v=SXKAD2svfmI

https://www.codingninjas.com/studio/problems/_893049?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

https://github.com/striver79/FreeKaTreeSeries/blob/main/inorderSuccCpp


*/

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

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    // Write your code here.
    pair<int, int> ans;

    int successor = -1;
    BinaryTreeNode<int> *cur = root;
    while (cur != NULL)
    {
        if (cur->data <= key)
        {
            cur = cur->right;
        }
        else
        {
            successor = cur->data;
            cur = cur->left;
        }
    }
    int predecessor = -1;
    cur = root;
    while (cur != NULL)
    {
        if (cur->data >= key)
        {
            cur = cur->left;
        }
        else
        {
            predecessor = cur->data;
            cur = cur->right;
        }
    }
    ans = {predecessor, successor};
    return ans;
}
