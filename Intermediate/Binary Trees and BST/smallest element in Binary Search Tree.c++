#include <bits/stdc++.h>
using namespace std;

/*
https://takeuforward.org/data-structure/kth-largest-smallest-element-in-binary-search-tree/
https://www.codingninjas.com/studio/problems/920441?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0
https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
*/

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
public:
    TreeNode *kthsmallestHelper(TreeNode *root, int &k)
    {

        if (root == NULL)
            return NULL;

        TreeNode *left = kthsmallestHelper(root->left, k);
        if (left != NULL)
            return left;
        k--;
        if (k == 0)
            return root;

        return kthsmallestHelper(root->right, k);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        return kthsmallestHelper(root, k)->val;
    }
};