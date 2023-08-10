#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/next-greater-number_980529?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

// https://www.geeksforgeeks.org/find-next-greater-number-set-digits/

string nextGreater(string arr)
{
    // Write your code here.

    int n = arr.length();

    if (n == 1)
        return arr;

    // Start from the right most digit and find the first
    // digit that is
    // smaller than the digit next to it.
    int i = -1;
    for (i = n - 1; i > 0; i--)
    {
        if (arr[i] > arr[i - 1])
            break;
    }

    if (i == 0 || i == -1)
    {
        return "-1";
    }

    // If there is a possibility of a next greater element

    // Find the smallest digit on right side of (i-1)'th
    // digit that is
    // greater than number[i-1]
    for (int j = n - 1; j >= i; j--)
    {
        if (arr[i - 1] < arr[j])
        {
            // Swap the found smallest digit i.e. arr[j]
            // with arr[i-1]
            swap(arr[i - 1], arr[j]);
            break;
        }
    }

    // Reverse the digits after (i-1) because the digits
    // after (i-1) are in decreasing order and thus we will
    // get the smallest element possible from these digits
    reverse(arr.begin() + i, arr.end());

    // If i is 0 that means elements are in decreasing order
    // Therefore, no greater element possible then we just
    // return the lowest possible
    // order/element formed from these digits by just
    // reversing the vector

    return arr;
}