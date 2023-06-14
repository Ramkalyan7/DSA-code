#include <bits/stdc++.h>
using namespace std;

// question link : https://leetcode.com/problems/maximum-sum-circular-subarray/description/

// video solution link : https://www.youtube.com/watch?v=Q1TYVUEr-wY

// article solution link : https://www.geeksforgeeks.org/maximum-contiguous-circular-sum/

/*********************************************/
/*
Approach
There are 2 possibility of The maximum subarray sum in circular array

Maximum subarray sum in non circular array
If max subarray sum in non circular array then we can simply apply Kadane's Algorithm and we will calculate the max_sum_subarray
Example A=[-3,-5,3,5,7,3,5,-9] ans= 23
2.Maximum subarray sum in circular array.

If max subarray sum in circular array then we will calculate the minimum sum of subarray and Subtract it from total_sum of array.
Example A=[11,1,-17,2,-15,9,13]
circular.png

Here we will remove {17,2,-15} from our total sum that will give us max subarray sum because max sum include some prefix and suffix part:-
Ans= max(prefix+suffix)
Ans= max(total sum - subarray)
Ans=total sum + max(-subarray)
Ans= total sum - min(subarray)
Corner case -When all the element in the array are negative then our answer will be max_sum_subarray because if when all the element are negative at that time our total_sum - minsum_subary=0
and it will return 0 means empty subarray thats why we will return max sum of subarray

At last we will return
max(subarray sum in non circular array,Maximum subarray sum in circular array)

Complexity
Time complexity:O(N)
Space complexity:O(1)
*/
/************************************************************/

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {

        int n = nums.size();
        int temp_maxSum = 0;
        int temp_minSum = 0;
        int maxSum = INT_MIN;
        int minSum = INT_MAX;

        int arrSum = 0;

        for (int i = 0; i < n; i++)
        {
            arrSum += nums[i];

            temp_maxSum += nums[i];
            if (temp_maxSum > maxSum)
            {
                maxSum = temp_maxSum;
            }
            if (temp_maxSum < 0)
            {
                temp_maxSum = 0;
            }

            temp_minSum += nums[i];
            if (temp_minSum < minSum)
            {
                minSum = temp_minSum;
            }
            if (temp_minSum > 0)
            {
                temp_minSum = 0;
            }
        }

        if (arrSum == minSum)
        {
            return maxSum;
        }

        return max(maxSum, (arrSum - minSum));
    }
};