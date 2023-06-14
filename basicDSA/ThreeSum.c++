#include <bits/stdc++.h>
using namespace std;

// leetcode and codestudio

// solution and explanation  can be found at take you forward
// https://takeuforward.org/data-structure/3-sum-find-triplets-that-add-up-to-a-zero/

/*Intuition: Can we do something better?
I think yes! In our intuitive approach, we were considering all possible triplets. But do we really need to do that? I say we fixed two pointers i and j and came out with a combination of [-1,1,1] which doesn’t satisfy our condition. However, we still check for the next combination of say [-1,1,2] which is worthless. (Assuming the k pointer was pointing to 2).

Approach:
We could make use of the fact that we just need to return the triplets and thus could possibly sort the array. This would help us use a modified two-pointer approach to this problem.

Eg) Input :  [-1,0,1,2,-1,-4]

After sorting, our array is : [-4,-1,-1,0,1,2]

Notice, that we are fixing the i pointer and then applying the traditional 2 pointer approach to check whether the sum of three numbers equals zero. If the sum is less than zero, it indicates our sum is probably too less and we need to increment our j pointer to get a larger sum. On the other hand, if our sum is more than zero, it indicates our sum is probably too large and we need to decrement the k pointer to reduce the sum and bring it closer to zero.*/

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> temp;
    int i, j, k;
    for (i = 0; i < nums.size() - 2; i++)
    {
        for (j = i + 1; j < nums.size() - 1; j++)
        {
            for (k = j + 1; k < nums.size(); k++)
            {
                temp.clear();
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                }
                if (temp.size() != 0)
                    ans.push_back(temp);
            }
        }
    }

    return ans;
}