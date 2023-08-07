#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/975286?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

// https://takeuforward.org/data-structure/fractional-knapsack-problem-greedy-approach/

bool comp(pair<int, int> a, pair<int, int> b)

{

    double r1 = (double)a.second / a.first;

    double r2 = (double)b.second / b.first;

    return r1 > r2;
}

double maximumValue(vector<pair<int, int>> &items, int n, int w)

{

    sort(items.begin(), items.end(), comp);

    double res = 0;

    for (int i = 0; i < n; i++)

    {

        if (items[i].first <= w)

        {

            res = res + items[i].second;

            w = w - items[i].first;
        }

        else

        {

            res = res + (items[i].second * ((double)w / items[i].first));

            break;
        }
    }

    return res;
}
