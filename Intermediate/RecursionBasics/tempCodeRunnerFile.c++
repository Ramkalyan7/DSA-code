#include <bits/stdc++.h>
using namespace std;

void generateStringHelper(string &temp, vector<string> &ans, int &k, char c)
{

    if (k == 0)
    {
        ans.push_back(temp);
        temp.clear();
        return;
    }
    temp.push_back(c);
    k--;
    generateStringHelper(temp, ans, k, '0');

    k++;
    if (temp[temp.length() - 1] != '1')
    {
        temp.push_back(c);
        k--;
        generateStringHelper(temp, ans, k, '1');
        k++;
    }
}

vector<string> generateString(int k)
{
    // Write your code here.

    string temp = "";
    vector<string> ans;
    generateStringHelper(temp, ans, k, '0');
    temp = "";
    generateStringHelper(temp, ans, k, '1');

    return ans;
}

int main()
{
    vector<string> ans = generateString(3);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}