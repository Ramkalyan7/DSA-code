#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/job-sequencing-problem_1169460?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=1

// https://takeuforward.org/data-structure/job-sequencing-problem/

bool comparator(vector<int> a, vector<int> b)
{
    int x = a[2];
    int y = b[2];

    return x > y;
}

vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here

    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), comparator);

    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        maxi = max(jobs[i][1], maxi);
    }

    int arr[maxi + 1];

    for (int i = 0; i <= maxi; i++)
    {
        arr[i] = -1;
    }

    int profit = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i][1]; j > 0; j--)
        {
            if (arr[j] == -1)
            {
                arr[j] = jobs[i][0];
                profit += jobs[i][2];
                count++;
                break;
            }
        }
    }

    vector<int> ans;
    ans.push_back(count);
    ans.push_back(profit);

    return ans;
}