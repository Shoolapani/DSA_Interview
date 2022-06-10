#include <bits/stdc++.h>
using namespace std;

// 151. Reverse Words in a String
string reverseWords(string s)
{
    string ans = "", temp = "";
    bool flag = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if ((s[i] == ' '))
        {
            if (flag)
            {
                flag = 0;
                reverse(temp.begin(), temp.end());
                ans += temp;
                ans += " ";
                temp.clear();
            }
        }
        else
        {
            temp += s[i];
            flag = 1;
        }
    }

    if (flag)
    {
        flag = 0;
        reverse(temp.begin(), temp.end());
        ans += temp;
        temp.clear();
    }
    if (ans[ans.length() - 1] == ' ')
    {
        ans.pop_back();
    }

    return ans;
}

string longestCommonPrefix(vector<string> &ar)
{
    int n = ar.size();
    // If size is 0, return empty string
    if (n == 0)
        return "";

    if (n == 1)
        return ar[0];

    // Sort the given array
    sort(ar.begin(), ar.end());
    // Find the minimum length from
    // first and last string
    int en = min(ar[0].size(),
                 ar[n - 1].size());

    // Now the common prefix in first and
    // last string is the longest common prefix
    string first = ar[0], last = ar[n - 1];
    int i = 0;
    while (i < en && first[i] == last[i])
        i++;

    string pre = first.substr(0, i);
    return pre;
}

int romanToInt(string s)
{
    unordered_map<char, int> uMap = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int ans = 0;

    for (size_t i = 0; i < s.length(); i++)
    {
        if (((uMap[s[i]]) < uMap[s[i + 1]]))
        {
            ans -= uMap[s[i]];
            ans += uMap[s[i + 1]];
            ++i;
        }
        else
        {
            ans += uMap[s[i]];
        }
    }

    return ans;
}

int main()
{
    // cout << reverseWords("lets go to 'new york'") << endl;
    cout << romanToInt("MCMXCIV") << endl;
    return 0;
}