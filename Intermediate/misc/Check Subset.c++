#include <bits/stdc++.h>
using namespace std;

/*

https://www.codingninjas.com/studio/problems/check-subset_762948?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0



*/

bool checkSubset(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    // Write your code here.

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr1[i]]++;
    }

    for (int i = 0; i < m; i++)
    {
        if (mp[arr2[i]] == 0)
        {
            return false;
        }
        else
        {
            mp[arr2[i]]--;
        }
    }
    return true;
}