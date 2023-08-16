#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/letter-combinations-of-a-phone-number_983623?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

// https://www.youtube.com/watch?v=tWnHbSHwNmA

void letterCombinationsHelper(vector<string> &ans, string mapping[], string digits, int index, string output)
{
    if (index >= digits.length())
    {
        ans.push_back(output);
        return;
    }

    int number = digits[index] - '0';
    string value = mapping[number];

    for (int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        letterCombinationsHelper(ans, mapping, digits, index + 1, output);
        output.pop_back();
    }
}

vector<string> combinations(string digits)
{

    vector<string> ans;

    if (digits.length() == 0)
    {
        return ans;
    }

    string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    int index = 0;
    string output = "";

    letterCombinationsHelper(ans, mapping, digits, index, output);

    return ans;
}
