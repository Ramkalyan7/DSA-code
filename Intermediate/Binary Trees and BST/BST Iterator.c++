#include <bits/stdc++.h>
using namespace std;

/*
https://www.youtube.com/watch?v=D2jMcmxU4bs

https://leetcode.com/problems/binary-search-tree-iterator/description/

https://www.codingninjas.com/studio/problems/bst-iterator_1112601?leftPanelTab=0



*/

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

class BSTiterator
{
private:
    stack<TreeNode<int> *> st;

public:
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        st.push(root);
        pushAllLeft(root->left);
    }

    int next()
    {
        // write your code here
        TreeNode<int> *temp = st.top();
        st.pop();
        pushAllLeft(temp->right);
        return temp->data;
    }

    bool hasNext()
    {
        // write your code here
        return !st.empty();
    }

    void pushAllLeft(TreeNode<int> *node)
    {
        while (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
    }
};

/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/