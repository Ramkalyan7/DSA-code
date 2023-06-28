#include <bits/stdc++.h>
using namespace std;

// LC : https://leetcode.com/problems/diameter-of-binary-tree/
// soln : https://takeuforward.org/data-structure/calculate-the-diameter-of-a-binary-tree/
// CS : https://bit.ly/3I3O1uD
// YT : https://www.youtube.com/watch?v=Rezetez59Nk&embeds_referring_euri=https%3A%2F%2Ftakeuforward.org%2Fdata-structure%2Fcalculate-the-diameter-of-a-binary-tree%2F&feature=emb_imp_woyt

// code :

#include <bits/stdc++.h>

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
};

int diameterOfBinaryTreeHelper(TreeNode<int> *root, int &maxi)
{
    if (root == NULL)
        return 0;

    int lh = diameterOfBinaryTreeHelper(root->left, maxi);
    int rh = diameterOfBinaryTreeHelper(root->right, maxi);

    maxi = max(maxi, lh + rh);

    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    // Write Your Code Here.
    int maxi = INT_MIN;

    diameterOfBinaryTreeHelper(root, maxi);
    return maxi;
}
