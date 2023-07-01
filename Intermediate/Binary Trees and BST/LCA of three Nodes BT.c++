#include <bits/stdc++.h>
using namespace std;

/*
https://www.youtube.com/watch?v=zldZe-O7evs

https://www.codingninjas.com/studio/problems/lca-of-three-nodes_794944?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

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
};

BinaryTreeNode<int> *lcaOfThreeNodes(BinaryTreeNode<int> *root, int node1, int node2, int node3)
{
    // Write your code here.

    if (root == NULL)
        return NULL;

    if (root->data == node1 || root->data == node2 || root->data == node3)
    {
        return root;
    }

    BinaryTreeNode<int> *left = lcaOfThreeNodes(root->left, node1, node2, node3);
    BinaryTreeNode<int> *right = lcaOfThreeNodes(root->right, node1, node2, node3);

    if (left != NULL && right != NULL)
    {
        return root;
    }

    if (left == NULL)
        return right;

    if (right == NULL)
        return left;
}
