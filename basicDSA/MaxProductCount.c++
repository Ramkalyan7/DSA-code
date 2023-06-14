#include <bits/stdc++.h>
using namespace std;

// question link code studio  : https://www.codingninjas.com/codestudio/problems/max-product-count_763416?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

// for solution look into editorial of code studio
/*

Hash Map
In this problem, If we observe closely then we have to only take care of one pair of products. Let’s take an example, where ‘ARR’ = [1,2,3,4,6,8,12,24]. There are a total of 4 distinct pairs with product 24 in the given array i.e (1,24), (2,12), (3,8), (4,6). The total number of quadruples that can be formed with these 4 pairs is 6 as given below:



        (1, 24) = (2,12)

        (1, 24) = (3, 8)

        (1, 24) = (4, 6)

        (2,12) = (3, 8)

        (2,12) = (4, 6)

        (3, 8) = (4, 6)



So, we can find the highest number of quadruples by finding the product pair with max frequency and then calculate the frequency.



The steps are as follows:



We create a Map that stores the product as key and frequency as value.
We will find all the pairs by using two nested loops in which the outer loop will pick the first element and the inner loop pick the second element of the pair and store their product and frequency in the map.
Iterate through the map and find the product with maximum frequency and store in ‘maxProd’ and frequency in ‘FREQ’ and there will be ('FREQ')C2 combinations that will be the total quadruples.
Time Complexity
O(N ^ 2),  where ‘N’ is the size of the array.



Since we are iterating for each element in the array in (O(N)) time, and the inner loop for each element will be iterated in O(N) time, i.e. a nested loop. Thus the overall time complexity will be O(N ^ 2).

Space Complexity
O(N ^ 2), where ‘N’ is the size of the array.



Since we are storing products of all pairs of the array in the map, and the total number of pairs in the array of N Integers can be NC2 = (N * (N - 1)) / 2. Thus total space complexity will be O(N ^ 2).

*/

#include <unordered_map>

vector<long long> maxProductCount(vector<int> &arr, int n)
{

    // To store the product of two number as Key and value as the total number of occurrence.
    unordered_map<long long, int> map;

    // To find all pair product and store it to Map with there frequencies.
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long a = arr[i];
            long long b = arr[j];
            long long pairProduct = a * b;
            map[pairProduct]++;
        }
    }

    // To store max product pair.
    long long maxProd = 0;

    // To store frequency of max product.
    int freq = 0;

    // Traverse the Map.
    for (auto prods : map)
    {
        if (prods.second >= freq)
        {
            // If frequency is same as previous max frequency then choose the one with minimum product.
            if (prods.second == freq)
            {
                maxProd = min(maxProd, prods.first);
            }
            else
            {
                maxProd = prods.first;
            }
            freq = prods.second;
        }
    }

    // Vector to store the values of max product and Quadruples.
    vector<long long> result;

    // If there is no pair having frequency count > 1.
    if (map.find(maxProd) == map.end() || map[maxProd] == 1)
    {
        // Returning the array containing max product and number of Quadruples.
        result.push_back(0);
        result.push_back(0);
        return result;
    }
    else
    {
        // Calculating total Quadruples as all Combination a pair can have with given frequency.
        long long allCombinations = ((freq * (freq - 1))) / 2;
        result.push_back(maxProd);
        result.push_back(allCombinations);
        // Returning the pair of max product and number of Quadruples.
        return result;
    }
}