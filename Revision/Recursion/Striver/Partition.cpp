// 131. Palindrome Partitioning
#include <bits/stdc++.h>
using namespace std;

bool isPlanindrome(string s, int start, int end)
{

    while (start < end)
    {
        if (s[start] != s[end])
        {
            return 0;
        }
        ++start, --end;
    }

    return 1;
}

void find(string s, vector<string> &ds, vector<vector<string>> &ans, int ind)
{
    if (ind >= s.length())
    {
        ans.push_back(ds);
        return;
    }

    for (size_t i = ind; i < s.length(); i++)
    {
        if (isPlanindrome(s, ind, i))
        {
            ds.push_back(s.substr(ind, i - ind + 1));
            find(s, ds, ans, i + 1);
            ds.pop_back();
        }
    }
    return;
}

vector<vector<string>> partition(string s)
{
    vector<string> ds;
    vector<vector<string>> ans;
    find(s, ds, ans, 0);
    return ans;
}



int main()
{
    for (auto &&i : partition("aabb"))
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}