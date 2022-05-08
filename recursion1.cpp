#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &vec, int &item)
{
    if ((vec.size() == 0) || (vec[vec.size() - 1] <= item))
    {
        vec.push_back(item);
        return;
    }

    int last = vec[vec.size() - 1];
    vec.pop_back();
    insert(vec, item);
    vec.push_back(last);
    return;
}

void sort2(vector<int> &vec)
{
    if (vec.size() <= 1)
    {
        return;
    }

    int last = vec[vec.size() - 1];
    vec.pop_back();
    sort2(vec);
    insert(vec, last);
    return;
}

// Sort a Stack
void insertStack(stack<int> &s, int item)
{
    if ((s.size() == 0) || (s.top() <= item))
    {
        s.push(item);
        return;
    }

    int last = s.top();
    s.pop();
    insertStack(s, item);
    return;
}

void sort(stack<int> &s)
{
    if (s.size() <= 1)
    {
        return;
    }
    int last = s.top();
    s.pop();
    sort(s);
    insertStack(s, last);
    return;
}

// Delete a mid of stack
void midDelete(stack<int> &s, int mid)
{
    if (mid == 1)
    {
        s.pop();
        return;
    }
    int last = s.top();
    s.pop();
    midDelete(s, mid - 1);
    s.push(last);
}

void deleteMid(stack<int> &s)
{
    int mid = s.size() / 2 + 1;
    bool flag = 0;
    (s.size() & 1) ? (flag = 0) : (flag = 1);
    midDelete(s, mid);
}

// Reverse a Stack in O(1)
void insert(stack<int> &s, int temp)
{
    if (s.size() == 0)
    {
        s.push(temp);
        return;
    }
    int last = s.top();
    s.pop();
    insert(s, temp);
    s.push(last);
}

void reverse(stack<int> &s)
{
    if (s.size() == 1)
    {
        return;
    }
    int last = s.top();
    s.pop();
    reverse(s);
    insert(s, last);
    return;
}

int kthGrammar(int n, int k)
{
    if ((n == 1) && (k == 1))
    {
        return 0;
    }
    int mid = (pow(2, n - 1)) / 2;
    if (k <= mid)
    {
        return kthGrammar(n - 1, k);
    }
    else
    {
        return !kthGrammar(n - 1, k - mid);
    }
}

void toh(int n, int from, int to, int aux)
{
    if (n == 0)
    {
        return;
    }
    toh(n - 1, from, aux, to);
    cout << "Moving rod " << n << " from " << from << " to " << to << " using " << aux << endl;
    toh(n - 1, aux, to, from);
    return;
}

void subsets(string ip, string op = "")
{
    if (ip.empty())
    {
        cout << op << ",";
        return;
    }
    string op1 = op + ip[0];
    string op2 = op;
    ip.erase(ip.begin() + 0);
    subsets(ip, op1);
    subsets(ip, op2);
    return;
}

void permuString(string s, int ind, vector<string> &ans)
{
    if (ind >= s.size())
    {
        ans.push_back(s);
        return;
    }
    string temp = "";
    for (size_t i = 0; i < s.size(); i++)
    {
        if (i == ind)
        {
            char c = ' ';
            temp += c;
        }
        temp += s[i];
    }
    s = temp;
    permuString(s, ind + 2, ans);

    temp = "";
    for (size_t i = 0; i < s.size(); i++)
    {
        if (i == ind)
        {
            continue;
        }
        temp += s[i];
    }
    s = temp;
    permuString(s, ind + 1, ans);
    return;
}

void perMString(string s, string op, vector<string> &ans)
{
    if (s.empty())
    {
        ans.push_back(op);
        return;
    }
    string op1 = op;
    string op2 = op;

    op1.push_back(' ');
    op1.push_back(s[0]);
    op2.push_back(s[0]);
    s.erase(s.begin() + 0);
    perMString(s, op1, ans);
    perMString(s, op2, ans);
    return;
}

vector<string> permutation(string S)
{
    vector<string> ans;
    // permuString(S, 1, ans);
    string op = "";
    op.push_back(S[0]);
    S.erase(S.begin() + 0);
    perMString(S, op, ans);
    return ans;
}

void casePermutation(string s, string op, vector<string> &ans, int ind = 0)
{
    if (ind == s.size())
    {
        ans.push_back(op);
        return;
    }

    if (isalpha(s[ind]))
    {
        s[ind] ^= (1 << 5);
        op += s[ind];
        s[ind] ^= (1 << 5);
        casePermutation(s, op, ans, ind + 1);
        op.pop_back();
        op += s[ind];
    }
    else if (isalnum(s[ind]))
    {
        op += s[ind];
    }

    casePermutation(s, op, ans, ind + 1);
    return;
}

vector<string> letterCasePermutation(string s)
{
    vector<string> ans;
    string op = "";
    casePermutation(s, op, ans, 0);
    return ans;
}

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
    else if ((open < close))
    {
        op.push_back('(');
        balancedParenthesis(op, open - 1, close, ans);
        op.pop_back();
        op.push_back(')');
        balancedParenthesis(op, open, close - 1, ans);
    }
    else if (open >= close)
    {
        op.push_back('(');
        balancedParenthesis(op, open - 1, close, ans);
        op.pop_back();
    }
}

vector<string> generateParenthesis(int A)
{
    vector<string> ans;
    string op = "";
    op.push_back('(');
    balancedParenthesis(op, A - 1, A, ans);
    return ans;
}

bool isOneMoreThenZero(string op)
{
    if (op.size() == 1)
    {
        return true;
    }
    int count{0};
    for (size_t i = 0; i < op.size(); i++)
    {
        if (op[i] == '1')
        {
            ++count;
        }
        else
        {
            --count;
        }
    }
    if (count < 0)
    {
        return false;
    }
    return isOneMoreThenZero(op.substr(1));
}

void bitBinary2(string op, int size, vector<string> &ans)
{
    if (op.size() == size)
    {
        if (isOneMoreThenZero(op))
        {
            ans.push_back(op);
        }
        return;
    }
    op.push_back('1');
    bitBinary2(op, size, ans);
    op.pop_back();
    op.push_back('0');
    bitBinary2(op, size, ans);
    return;
}

vector<string> NBitBinary2(int N)
{
    vector<string> ans;
    string op = "";
    op.push_back('1');
    bitBinary2(op, N, ans);
    return ans;
}

void bitBinary(string op, int oneC, int zeroC, int size, vector<string> &ans)
{
    if (size == 0)
    {
        ans.push_back(op);
        return;
    }

    op.push_back('1');
    bitBinary(op, oneC + 1, zeroC, size - 1, ans);
    op.pop_back();
    if (oneC > zeroC)
    {
        op.push_back('0');
        bitBinary(op, oneC, zeroC + 1, size - 1, ans);
    }
    return;
}

vector<string> NBitBinary(int N)
{
    vector<string> ans;
    string op = "";
    op.push_back('1');
    bitBinary(op, 1, 0, N - 1, ans);
    return ans;
}

void posSafe(int ind, int k, vector<int> &ds, int &ans)
{
    if (ds.size() == 1)
    {
        ans = ds[0];
        return;
    }
    ind = (ind + k) % ds.size();
    ds.erase(ds.begin() + ind);
    posSafe(ind, k, ds, ans);
    return;
}

int safePos2(int n, int k)
{
    vector<int> ds(n);
    for (size_t i = 0; i < ds.size(); i++)
    {
        ds[i] = i + 1;
    }
    int ans = -1;
    posSafe(0, k - 1, ds, ans);
    return ans;
}

int possafe(int n, int k)
{
    if (n == 1)
    {
        return 0;
    }
    else
    {
        return (possafe(n - 1, k) + k) % n;
    }
}

int safePos(int n, int k)
{
    return possafe(n, k) + 1;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    cout << safePos(14, 2);
    // subsets("abc");
    // sort2(v);
    // for (auto &&i : NBitBinary(3))
    // {
    //     cout << i << " ";
    // }

    // stack<int> s;

    // for (auto &&i : v)
    // {
    //     s.push(i);
    // }

    // reverse(s);
    // while (s.empty() == false)
    // {
    //     cout << s.top() << " ";
    //     s.pop();
    // }

    return 0;
}