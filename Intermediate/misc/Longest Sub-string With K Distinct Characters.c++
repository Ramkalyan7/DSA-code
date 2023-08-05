#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/longest-sub-string-with-k-distinct-characters_920521?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

// https://www.youtube.com/watch?v=Lav6St0W_pQ

int getLengthofLongestSubstring(string s, int k)
{
    // Write your code here.
    unordered_map<int, int> m;

    int i = 0;
    int j = 0;
    int n = s.length();

    int mx = INT_MIN;

    while (j < n)
    {
        m[s[j]]++;
        if (m.size() == k)
        {
            mx = max(mx, j - i + 1);
        }
        else if (m.size() > k)
        {
            while (m.size() > k)
            {
                m[s[i]]--;
                if (m[s[i]] == 0)
                {
                    m.erase(s[i]);
                }
                i++;
            }
        }
        j++;
    }

    if (mx == INT_MIN)
        return n;

    return mx;
}