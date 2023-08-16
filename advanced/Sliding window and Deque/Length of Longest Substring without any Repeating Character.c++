#include <bits/stdc++.h>
using namespace std;

// https://takeuforward.org/data-structure/length-of-longest-substring-without-any-repeating-character/

// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// https://www.codingninjas.com/studio/problems/longest-unique-substring_630418?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube

int uniqueSubstrings(string s)
{
    vector<int> mp(256, -1);

    int n = s.length();

    int len = 0;

    int left = 0;
    int right = 0;

    while (right < n)
    {
        if (mp[s[right] != -1])
        {
            left = max(left, mp[s[right]] + 1);
        }

        mp[s[right]] = right;

        len = max(len, right - left + 1);

        right++;
    }

    return len;
}