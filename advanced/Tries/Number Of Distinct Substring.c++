#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/number-of-distinct-substring_1465938?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

// https://takeuforward.org/data-structure/number-of-distinct-substrings-in-a-string-using-trie/

class Node
{
    Node *links[26];

public:
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
};

int distinctSubstring(string &word)
{
    //  Write your code here.

    Node *root = new Node();

    int count = 0;

    for (int i = 0; i < word.length(); i++)
    {
        Node *node = root;
        for (int j = i; j < word.length(); j++)
        {
            if (!node->containsKey(word[j]))
            {
                count++;
                node->put(word[j], new Node());
            }

            node = node->get(word[j]);
        }
    }

    return count;
}
