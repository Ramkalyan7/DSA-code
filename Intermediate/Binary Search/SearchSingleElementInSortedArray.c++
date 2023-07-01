#include <bits/stdc++.h>
using namespace std;

// leetcode link : https://leetcode.com/problems/single-element-in-a-sorted-array/
// solution link : https://takeuforward.org/data-structure/search-single-element-in-a-sorted-array/

// video solution : https://www.youtube.com/watch?v=PzszoiY5XMQ&t=430s

class Solution
{
public:
    int findSingleElement(vector<int> &arr)
    {
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) >> 1;

            if (arr[mid] == arr[mid ^ 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return arr[low];
    }
};

int main()
{
    Solution obj;
    vector<int> v{1, 1, 2, 3, 3, 4, 4, 8, 8};

    int elem = obj.findSingleElement(v);
    cout << "The single occurring element is " << elem << endl;
}