#include <bits/stdc++.h>
using namespace std;

void longestPalin(string str, int start, int end, int &mx,
                  string &ans)
{
    int flag = 1, st = start, en = end;

    while (start <= end)
    {
        if (str[start++] != str[end--])
            flag = 0;
    }

    if (flag == 1)
    {
        string res = str.substr(st, en - st + 1);
        if (mx < res.size())
        {
            ans = res;
            mx = res.size();
        }
    }
}

int longestPalSubstr(string str)
{
    // get length of input string
    int n = str.size();
 
    // table[i][j] will be false if substring
    // str[i..j] is not palindrome.
    // Else table[i][j] will be true
    bool table[n][n];
 
    memset(table, 0, sizeof(table));
 
    // All substrings of length 1
    // are palindromes
    int maxLength = 1;
 
    for (int i = 0; i < n; ++i)
        table[i][i] = true;
 
    // check for sub-string of length 2.
    int start = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (str[i] == str[i + 1]) {
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }
 
    // Check for lengths greater than 2.
    // k is length of substring
    for (int k = 3; k <= n; ++k) {
        // Fix the starting index
        for (int i = 0; i < n - k + 1; ++i) {
            // Get the ending index of substring from
            // starting index i and length k
            int j = i + k - 1;
 
            // checking for sub-string from ith index to
            // jth index iff str[i+1] to str[j-1] is a
            // palindrome
            if (table[i + 1][j - 1] && str[i] == str[j]) {
                table[i][j] = true;
 
                if (k > maxLength) {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
 
    cout << "Longest palindrome substring is: ";
 
    // return length of LPS
    return maxLength;
}

int main()
{
    string str =
        "aacabdkacaa";
    unordered_map<char, int> mp;
    int mx = 1;
    string ans = "h";
    for (int i = 0; i < str.size(); i++)
    {
        mp[str[i]] = i;
    }
    for (int i = 0; i < str.size(); i++)
    {
        longestPalin(str, i, mp[str[i]], mx, ans);
    }
    cout << ans;
    cout << "\nLength is: "
         << mx;
}
