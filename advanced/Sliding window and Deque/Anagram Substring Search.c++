#include <bits/stdc++.h>
using namespace std;

// https://takeuforward.org/data-structure/anagram-substring-search/

// https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

// https://www.codingninjas.com/studio/problems/anagram-substring-search_873350?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=1

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int n = s.length();

        int m = p.length();

        vector<int> ans;

        if (m > n)
            return ans;

        vector<int> v1(26, 0);
        vector<int> v2(26, 0);

        for (int i = 0; i < m; i++)
        {
            v1[s[i] - 'a']++;
            v2[p[i] - 'a']++;
        }

        if (v1 == v2)
        {
            ans.push_back(0);
        }

        for (int i = m; i < n; i++)
        {
            v1[s[i - m] - 'a']--;
            v1[s[i] - 'a']++;

            if (v1 == v2)
            {
                ans.push_back(i - m + 1);
            }
        }

        return ans;
    }
};