// Permute a string by changing case
#include <bits/stdc++.h>
using namespace std;

void casePermut(string s, string op, vector<string> &vec, int ind = 0)
{
    if (ind == s.size())
    {
        vec.push_back(op);
        return;
    }

    if (isalpha(s[ind]))
    {
        s[ind] ^= (1 << 5);
        op += s[ind];
        casePermut(s, op, vec, ind + 1);
        s[ind] ^= (1 << 5);
        op.pop_back();
        op += s[ind];
    }
    else 
    {
        op += s[ind];
    }
    casePermut(s, op, vec, ind + 1);
    return;
}

// Function to generate permutations
vector<string> letterCasePermutation(string s)
{
    string op = "";
    vector<string> ans;
    casePermut(s, op, ans);
    return ans;
}

int main()
{
    for (auto &&i : letterCasePermutation("a1b2"))
    {
        cout << i << " ";
    }
    return 0;
}