#include <bits/stdc++.h>
using namespace std;

// there are two approaches for this question's solution
// both the approaches are important

// https://www.codingninjas.com/studio/problems/k-th-largest-sum-contiguous-subarray_920398?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

// approach 1 :

/*
    Time Complexity: O(N ^ 2 * log(K)
    Space Complexity: O(K)

    where ‘N’ is the length of the given array/list.
    And 'K' is the given number.
*/

#include <queue>

int getKthLargest(vector<int> &arr, int k)
{
    int n = arr.size();

    //	To store the subarray sums.
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++)
    {
        //	To store the current subarray sum.
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];

            minHeap.push(sum);
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
    }

    //	Top-most element is the k-th largest subarray sum.
    return minHeap.top();
}

// aproach 2 from chatgpt..

/*

Certainly! I'll explain each line of the C++ code and the underlying logic step by step.

```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
```

Here, we include necessary header files and declare the namespace for convenience.

```cpp
int kthLargestSumSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> prefixSum(n + 1);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + arr[i];
    }
```

This is the function `kthLargestSumSubarray` which takes the array `arr` and the integer `k` as parameters.

- `n` stores the length of the array.
- `prefixSum` is a vector that will hold the prefix sum of elements in `arr`.

We calculate the prefix sum array to efficiently compute the sum of any subarray using the difference between two prefix sums. The loop iterates over the elements of `arr` and calculates the prefix sum at each index.

```cpp
    vector<int> subarraySums;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            subarraySums.push_back(prefixSum[j] - prefixSum[i]);
        }
    }
```

`subarraySums` is a vector that will store all possible subarray sums.

- The outer loop (`i` loop) iterates over the starting index of the subarray.
- The inner loop (`j` loop) iterates over the ending index of the subarray.
- We calculate the sum of the subarray from index `i` to index `j-1` using the prefix sum array and store it in `subarraySums`.

```cpp
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < k; ++i) {
        minHeap.push(subarraySums[i]);
    }
```

`minHeap` is a priority queue (min-heap) used to store the K largest subarray sums.

- We push the first K subarray sums from `subarraySums` into the min-heap. This initializes the heap with the smallest K subarray sums.

```cpp
    for (int i = k; i < subarraySums.size(); ++i) {
        if (subarraySums[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(subarraySums[i]);
        }
    }
```

This loop iterates through the remaining subarray sums (starting from index K) and updates the min-heap.

- If the current subarray sum is greater than the smallest element (top) of the min-heap, we remove the smallest element and insert the current subarray sum into the heap.

```cpp
    return minHeap.top();
}
```

After iterating through all subarray sums, the K-th largest sum will be at the top of the min-heap. We return this value from the function.

```cpp
int main() {
    vector<int> arr = {10, -10, 20, -40};
    int k = 3;
    cout << kthLargestSumSubarray(arr, k) << endl;  // Output will be 10

    return 0;
}
```

In the `main` function, we create an array `arr` and specify the value of `k`. We call the `kthLargestSumSubarray` function with these inputs and print the result.

The logic of the solution revolves around generating all possible subarray sums using prefix sums, maintaining a min-heap to track the K largest sums, and updating the heap as necessary. The final result is the K-th largest sum from the min-heap.

*/