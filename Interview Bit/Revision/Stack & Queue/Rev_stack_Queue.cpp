#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std::chrono;
using namespace std;

// Balanced Parantheses!
int solveBalanced(string A)
{
    stack<char> st;

    for (auto i = 0; i < A.length(); i++)
    {
        if ((A[i] == '('))
        {
            st.push(A[i]);
        }
        else
        {
            if (st.empty())
            {
                return 0;
            }
            while ((!st.empty()) and (i < A.length()) and (st.top() == '(') and (A[i] == ')'))
            {
                st.pop();
                ++i;
            }
            --i;
        }
    }

    if (st.empty())
    {
        return 1;
    }
    return 0;
}

// Simplify Directory Path
string simplifyPath(string A)
{
    string path = "";
    stringstream str(A);
    string temp = "";
    vector<string> res;
    char token = '/';

    while (getline(str, temp, token))
    {
        if ((temp == ".") or (temp.empty()))
        {
            continue;
        }
        else if ((temp == "..") and (!res.empty()))
        {
            res.pop_back();
        }
        else if (temp != "..")
        {
            res.push_back(temp);
        }
    }

    if ((res.empty()))
    {
        path = "/";
        return path;
    }

    for (auto &&it : res)
    {
        path += "/" + it;
    }

    return path;
}

// Redundant Braces
int braces(string A)
{
    stack<char> st;

    for (auto i = 0; i < A.length(); i++)
    {
        if ((A[i] != ')'))
        {
            if (!isalpha(A[i]))
            {
                st.push(A[i]);
            }
        }
        else
        {
            if ((A[i] == ')'))
            {
                if ((!st.empty()) and (st.top() == '('))
                {
                    return 1;
                }

                while (((!st.empty()) and (st.top() != '(')))
                {
                    st.pop();
                }
                st.pop();
            }
        }
    }

    return 0;
}

// MAXSPPROD
#define ll long long int
//  A = [1, 4, 3, 4]
//       0  1  2  3
//  left= 0, 0,1,0
int maxSpecialProduct(vector<int> &A)
{
    stack<ll> l, r;
    int n = A.size();
    vector<ll> left(n, 0), right(n, 0);
    ll ans = 0;

    for (ll i = 0; i < A.size(); i++)
    {
        while ((!l.empty()) and (A[l.top()] <= A[i]))
        {
            l.pop();
        }

        if ((!l.empty()))
        {
            left[i] = l.top();
        }
        l.push(i);
    }

    for (ll i = A.size() - 1; i >= 0; i--)
    {
        while ((!r.empty()) and (A[r.top()] <= A[i]))
        {
            r.pop();
        }

        if ((!r.empty()))
        {
            right[i] = r.top();
        }
        r.push(i);
    }

    for (ll i = 0; i < A.size(); i++)
    {
        ans = max(ans, left[i] * right[i]);
    }

    return ans % 1000000007;
}

// Nearest Smaller Element
//     A = [4, 5, 2, 10, 8]
//         -1, 4,
vector<int> prevSmaller(vector<int> &A)
{
    stack<int> l, r;
    int n = A.size();
    vector<int> left(n, -1);

    for (int i = 0; i < A.size(); i++)
    {
        while ((!l.empty()) and (A[l.top()] >= A[i]))
        {
            l.pop();
        }

        if ((!l.empty()))
        {
            left[i] = A[l.top()];
        }
        l.push(i);
    }

    return left;
}

// First non-repeating character in a stream of characters
// doubt
//  A = "abadbc"
//      ab
//
string solveRepeating(string A)
{
    string ans = "";
    queue<char> dq;
    unordered_map<char, int> uMap;

    for (size_t i = 0; i < A.size(); i++)
    {
        dq.push(A[i]);
        uMap[A[i]]++;
        while ((!dq.empty()) and ((uMap[dq.front()] > 1)))
        {
            dq.pop();
        }

        if (!dq.empty())
        {
            ans += dq.front();
        }
        else
        {
            ans += "#";
        }
    }

    return ans;
}

// Largest Rectangle in Histogram
int largestRectangleArea(vector<int> &A)
{
}

int main()
{
    string s = "/../";
    // cout << solveBalanced(s) << endl;
    cout << simplifyPath(s) << endl;
    return 0;
}