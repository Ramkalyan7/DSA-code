#include <bits/stdc++.h>
using namespace std;

// solution link : https://takeuforward.org/data-structure/longest-consecutive-sequence-in-an-array/

// question link leetcode : https://leetcode.com/problems/longest-consecutive-sequence/submissions/822431429/

/*
Approach: We will first push all elements in the HashSet. Then we will run a for loop and check for any number(x) if it is the starting number of the consecutive sequence by checking if the HashSet contains (x-1) or not. If ‘x’ is the starting number of the consecutive sequence we will keep searching for the numbers y = x+1, x+2, x+3, ….. And stop at the first ‘y’ which is not present in the HashSet. Using this we can calculate the length of the longest consecutive subsequence.
*/

int lengthOfLongestConsecutiveSequence(vector<int> &nums, int n)
{
    // Write your code here.

    unordered_set<int> hashSet;
    for (int num : nums)
    {
        hashSet.insert(num);
    }
    int longestStreak = 0;

    for (int num : nums)
    {
        if (!hashSet.count(num - 1))
        {
            int currentNum = num;
            int currentStreak = 1;
            while (hashSet.count(currentNum + 1))
            {
                currentStreak += 1;
                currentNum += 1;
            }

            longestStreak = max(currentStreak, longestStreak);
        }
    }

    return longestStreak;
}

/*

    Time Complexity: O(N ^ 2)
    Space Complexity: O(N ^ 2)

    Where N is the size of array.

*/
