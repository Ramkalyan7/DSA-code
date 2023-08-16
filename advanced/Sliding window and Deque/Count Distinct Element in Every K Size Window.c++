#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/count-distinct-element-in-every-k-size-window_920336?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

// https://www.youtube.com/watch?v=j48e8ac7r20

vector<int> countDistinctElements(vector<int> &arr, int k)
{
    // Write your code here

    vector<int> ans;

    unordered_map<int, int> mp;

    int n = arr.size();

    if (n == 0)
        return ans;

    for (int i = 0; i < k; i++)
    {
        mp[arr[i]]++;
    }

    ans.push_back(mp.size());

    for (int i = k; i < n; i++)
    {
        mp[arr[i - k]]--;

        if (mp[arr[i - k]] == 0)
        {
            mp.erase(arr[i - k]);
        }

        mp[arr[i]]++;

        ans.push_back(mp.size());
    }

    return ans;
}
