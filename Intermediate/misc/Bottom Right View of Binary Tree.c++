// C++ program to print
// bottom right view of BT
#include <bits/stdc++.h>
using namespace std;

// A binary Tree node
struct Node
{
    int data;
    Node *left, *right;
};

// create and returns a new node
Node *newNode(int val)
{
    Node *temp = new Node();
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// fun to print bottom right view of a BT
void bottomRightView(Node *root)
{
    // Base case
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            root = q.front();
            q.pop();
            // traverse all right nodes and push leftnodes
            // (if any) into the queue for the next level
            // traverse
            while (root->right)
            {
                if (root->left)
                    q.push(root->left);
                root = root->right;
            }
            // if last node has any left node
            if (root->left)
                q.push(root->left);
        }
        // print the data
        cout << root->data << " ";
    }
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->left->right = newNode(6);

    bottomRightView(root);

    return 0;
}
// This code is contributed by Modem Upendra.
