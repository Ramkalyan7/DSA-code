#include <bits/stdc++.h>
using namespace std;

// leetcode link : https://leetcode.com/problems/single-element-in-a-sorted-array/
// solution link : https://takeuforward.org/data-structure/search-single-element-in-a-sorted-array/

// video solution : https://www.youtube.com/watch?v=PzszoiY5XMQ&t=430s

class Solution
{
public:
    int findSingleElement(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 2;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (mid % 2 == 0)
            {
                if (nums[mid] != nums[mid + 1])
                    // Checking whether we are in right half

                    high = mid - 1; // Shrinking the right half
                else
                    low = mid + 1; // Shrinking the left half
            }
            else
            {

                // Checking whether we are in right half
                if (nums[mid] == nums[mid + 1])
                    high = mid - 1; // Shrinking the right half
                else
                    low = mid + 1; // Shrinking the left half
            }
        }

        return nums[low];
    }
};

int main()
{
    Solution obj;
    vector<int> v{1, 1, 2, 3, 3, 4, 4, 8, 8};

    int elem = obj.findSingleElement(v);
    cout << "The single occurring element is " << elem << endl;
}