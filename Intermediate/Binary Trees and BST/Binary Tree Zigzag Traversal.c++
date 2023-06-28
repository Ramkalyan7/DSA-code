#include <bits/stdc++.h>
using namespace std;

// LC : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
// CS : https://www.codingninjas.com/studio/problems/1062662?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0
// sol : https://takeuforward.org/data-structure/zig-zag-traversal-of-binary-tree/#

// code :

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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<BinaryTreeNode<int> *> q;
    bool leftToRight = true;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        vector<int> row(n);
        for (int i = 0; i < n; i++)
        {
            BinaryTreeNode<int> *temp = q.front();
            q.pop();
            int curIndex = leftToRight ? i : n - i - 1;
            row[curIndex] = temp->data;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        leftToRight = !leftToRight;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(row[i]);
        }
    }

    return ans;
}
