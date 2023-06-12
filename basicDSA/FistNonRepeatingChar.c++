#include <bits/stdc++.h>
using namespace std;
char firstNonRepeatingCharacter(string s)
{

    // Write your code here
    int hash[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        hash[s[i] - 'a']++;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (hash[s[i] - 'a'] == 1)
        {
            return s[i];
        }
    }

    return s[0];
}
