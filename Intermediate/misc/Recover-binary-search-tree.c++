#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/recover-binary-search-tree/

// https://www.codingninjas.com/studio/problems/fix-bst_873137?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

// https://www.youtube.com/watch?v=ZWGW7FminDM

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{

private:
    TreeNode *first;
    TreeNode *middle;
    TreeNode *last;
    TreeNode *prev;

public:
    void Inorder(TreeNode *root)
    {
        if (root == NULL)
            return;

        Inorder(root->left);

        if (prev != NULL && (prev->val > root->val))
        {
            if (first == NULL)
            {
                first = prev;
                middle = root;
            }
            else
            {
                last = root;
            }
        }

        prev = root;

        Inorder(root->right);
    }

    void recoverTree(TreeNode *root)
    {

        if (root == NULL)
            return;

        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);

        Inorder(root);

        if (first && last)
            swap(first->val, last->val);
        else
            swap(first->val, middle->val);

        return;
    }
};