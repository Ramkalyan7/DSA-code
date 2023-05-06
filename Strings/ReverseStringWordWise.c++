#include <iostream>
#include <vector>
using namespace std;

/***************************approach 1 :*****************************/

string reverseWords1(string input)
{
    vector<string> v;
    int n = input.length();
    int index = 0;
    string temp = "";
    for (int i = 0; i < n; i++)
    {

        if (input[i] == ' ')
        {
            if (temp.length() > 0)
                v.push_back(temp);
            temp = "";
        }
        else
        {
            temp.push_back(input[i]);
        }
    }
    if (temp.length() > 0)
        v.push_back(temp);

    string ans = "";
    for (int i = v.size() - 1; i >= 0; i--)
    {

        ans.append(v[i]);
        if (i != 0)
            ans.append(" ");
    }
    return ans;
}

/*********************************approach2********************************************/
string reverseWords2(string input)
{
    int i = 0;
    string ans;
    int n = input.length();
    while (i < n)
    {
        while (i < n && input[i] == ' ')
            i++;
        int j = i + 1;
        if (i >= n)
            return ans;
        while (j < n && input[j] != ' ')
            j++;
        string temp = input.substr(i, j - i);
        if (ans.length() == 0)
            ans = temp;
        else
            ans = temp + " " + ans;
        i = j + 1;
    }
    return ans;
}

int main()
{
    string s;
    getline(cin, s);
    string ans = reverseWords2(s);
    cout << ans << endl;
}