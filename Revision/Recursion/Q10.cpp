// Print N-bit binary numbers having more 1s than 0s
#include <bits/stdc++.h>
using namespace std;

void binary(string op, int n, int oneC, int zeroC, vector<string> &ans)
{
    if (op.size() == n)
    {
        ans.push_back(op);
        return;
    }

    if (oneC >= zeroC)
    {
        op.push_back('1');
        binary(op, n, oneC + 1, zeroC, ans);
        op.pop_back();
        if (oneC >= zeroC+1)
        {
            op.push_back('0');
            binary(op, n, oneC, zeroC + 1, ans);
        }
    }
    return;
}

vector<string> NBitBinary(int N)
{
    vector<string> ans;
    string op = "1";
    binary(op, N, 1, 0, ans);
    return ans;
}

int main()
{
    for (auto &&i : NBitBinary(4))
    {
        cout << i << " ";
    }
    return 0;
}