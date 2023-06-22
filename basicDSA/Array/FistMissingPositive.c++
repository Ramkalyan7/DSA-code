#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &arr)
    {

        int n = arr.size();

        for (int i = 0; i < n; i++)
        {

            if (arr[i] > 0)
            {
                int CI = arr[i] - 1;

                while (arr[i] > 0 && arr[i] < n && arr[i] != arr[CI])
                {
                    swap(arr[i], arr[CI]);
                    CI = arr[i] - 1;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] != i + 1)
            {
                return i + 1;
            }
        }

        return n + 1;
    }
};