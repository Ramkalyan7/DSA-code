#include <bits/stdc++.h>
using namespace std;
int minElementsToRemove(vector<int> &arr)
{
    // Write your code here.

    int ans = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == arr[i + 1])
        {
            ans++;
        }
    }

    return ans;
}