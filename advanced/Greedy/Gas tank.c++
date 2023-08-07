#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/gas-tank_699834?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

// https://leetcode.com/problems/gas-station/description/

// https://www.codingninjas.com/studio/library/gas-station

int minimumStartingIndex(vector<int> &gas, vector<int> &cost, int n)
{
    // Write your code here.

    int totalGas = 0;
    int totalCost = 0;

    for (int i = 0; i < n; i++)
    {
        totalGas += gas[i];
        totalCost += cost[i];
    }

    if (totalGas < totalCost)
        return -1;

    int fuel = 0;

    int start = 0;

    for (int i = 0; i < n; i++)
    {
        fuel += gas[i];
        fuel -= cost[i];

        if (fuel < 0)
        {
            start = i + 1;
            fuel = 0;
        }
    }
    return start;
}