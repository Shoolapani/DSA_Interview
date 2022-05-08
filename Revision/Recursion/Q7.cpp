// Permutation with Spaces
// Make a binary tree with take like this op and ip;

#include <bits/stdc++.h>
using namespace std;

void diffString(string ip, string op, vector<string> &vec)
{
    if (ip.empty())
    {
        vec.push_back(op);
        return;
    }

    // Yha Dikkat hua tha please
    string op1 = op, op2 = op;
    op1 += ip[0];
    diffString(ip.substr(1), op1, vec);
    op2 += " ";
    op2 += ip[0];
    diffString(ip.substr(1), op2, vec);
    return;
}

vector<string> permutation(string S)
{
    string op = "";
    op += S[0];
    vector<string> ans;
    diffString(S.substr(1), op, ans);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    for (auto &&i : permutation("ABC"))
    {
        cout << i << " ";
    }

    return 0;
}