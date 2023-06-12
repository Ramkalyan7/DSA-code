

#include <bits/stdc++.h>
using namespace std;
// better approach//

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_map<string, vector<string>> mymap;
        int n = strs.size();
        string temp;

        for (int i = 0; i < n; ++i)
        {
            temp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            mymap[strs[i]].push_back(temp);
        }

        vector<vector<string>> result;

        for (auto itr = mymap.begin(); itr != mymap.end(); ++itr)
            result.push_back(itr->second);

        return result;
    }
};

//*****************most optimal approach ***********************************//
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        vector<vector<string>> ans;

        unordered_map<string, vector<string>> container;

        for (int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            string sortedString = strSort(strs[i]);
            container[sortedString].push_back(temp);
        }

        for (auto p : container)
        {
            ans.push_back(p.second);
        }
        return ans;
    }

private:
    string strSort(string str)
    {
        int count[26] = {0};

        for (int i = 0; i < str.length(); i++)
        {
            count[str[i] - 'a']++;
        }

        string t;
        for (int i = 0; i < 26; i++)
        {
            t += string(count[i], i + 'a');
        }

        return t;
    }
};