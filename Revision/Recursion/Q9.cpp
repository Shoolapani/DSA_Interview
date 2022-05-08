// generateParenthesis interviewBit
#include <bits/stdc++.h>
using namespace std;

void balancedParenthesis(string op, int open, int close, vector<string> &ans)
{
    if ((open == 0) && (close == 0))
    {
        ans.push_back(op);
        return;
    }

    if (open == 0)
    {
        op.push_back(')');
        balancedParenthesis(op, open, close - 1, ans);
    }

    else if (open < close)
    {
        op.push_back('(');
        balancedParenthesis(op, open - 1, close, ans);
        op.pop_back();
        op.push_back(')');
        balancedParenthesis(op, open, close - 1, ans);
    }
    else
    {
        op.push_back('(');
        balancedParenthesis(op, open - 1, close, ans);
    }
    return;
}

vector<string> generateParenthesis(int A)
{
    vector<string> ans;
    string op = "(";
    balancedParenthesis(op, A - 1, A, ans);
    return ans;
}

int main()
{
    for (auto &&i : generateParenthesis(3))
    {
        cout << i << " ";
    }
    return 0;
}