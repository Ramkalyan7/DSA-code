#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/search-in-a-row-wise-and-column-wise-sorted-matrix_839811?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=1

// https://leetcode.com/problems/search-a-2d-matrix/description/

// https://takeuforward.org/data-structure/search-in-a-sorted-2d-matrix/

// https://www.youtube.com/watch?v=ZYpYur0znng

// better approach :

pair<int, int> search(vector<vector<int>> matrix, int x)
{
    // Write your code here.
    pair<int, int> ans = {-1, -1};

    int n = matrix.size();
    int m = matrix[0].size();

    int j = m - 1;
    int i = 0;

    while (i < n && j >= 0)
    {
        if (x == matrix[i][j])
        {
            ans = {i, j};
            return ans;
        }
        if (x > matrix[i][j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    return ans;
}

// optimise approach

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        if (matrix.size() == 0)
            return false;

        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0;
        int high = (n * m) - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (matrix[mid / m][mid % m] == target)
            {
                return true;
            }
            else if (matrix[mid / m][mid % m] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;
    }
};