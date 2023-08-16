#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/maximum-xor_3119012?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

// https://takeuforward.org/data-structure/maximum-xor-of-two-numbers-in-an-array/

class Node
{
    Node *links[2];

public:
    bool containsKey(int num)
    {
        return links[num] != NULL;
    }

    void put(int num, Node *node)
    {
        links[num] = node;
    }

    Node *get(int num)
    {
        return links[num];
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void Insert(int num)
    {
        Node *node = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }

            node = node->get(bit);
        }
    }

    int getMax(int num)
    {
        Node *node = root;
        int maxi = 0;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            int n = (1 - bit);

            if (node->containsKey(n))
            {
                maxi = maxi | (1 << i);
                node = node->get(n);
            }
            else
            {
                node = node->get(bit);
            }
        }

        return maxi;
    }
};

int maximumXor(vector<int> A)
{
    // Write your code here.

    Trie trie;

    for (int i = 0; i < A.size(); i++)
    {
        trie.Insert(A[i]);
    }

    int maxi = 0;

    for (int i = 0; i < A.size(); i++)
    {
        maxi = max(maxi, trie.getMax(A[i]));
    }

    return maxi;
}