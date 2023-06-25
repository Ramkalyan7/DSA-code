#include <bits/stdc++.h>
using namespace std;

// CD link :https://www.codingninjas.com/codestudio/problems/binary-strings-with-no-consecutive-1s_893001?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

void generateStringHelper(string &temp, vector<string> &ans, int &k)
{

    if (k == 0)
    {

        ans.push_back(temp);
        return;
    }
    temp.push_back('0');
    k--;
    generateStringHelper(temp, ans, k);
    if (temp.length() > 0)
        temp.pop_back();
    k++;
    if (temp[temp.length() - 1] != '1')
    {
        temp.push_back('1');
        k--;
        generateStringHelper(temp, ans, k);
        if (temp.length() > 0)
            temp.pop_back();
        k++;
    }
}

vector<string> generateString(int k)
{
    // Write your code here.

    string temp = "";
    vector<string> ans;
    generateStringHelper(temp, ans, k);

    return ans;
}
