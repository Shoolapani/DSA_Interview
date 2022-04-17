#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
public:
    StockSpanner()
    {
        res = 1;
    }

    int next(int price)
    {
        while ((!st.empty()) && (st.top().first >= price))
        {
            res += st.top().second;
            st.pop();
        }

        st.push({price, res});
        return res;
    }

private:
    stack<pair<int, int>> st;
    int res;
};

vector<int> calculateSpan(int price[], int n)
{
    stack<int> s;
    vector<int> ans(n);

    ans[0] = 1;
    s.push(0);

    for (size_t i = 1; i < n; i++)
    {
        while ((!s.empty()) && (price[s.top()] <= price[i]))
        {
            s.pop();
        }
        ans[i] = (s.empty()) ? (i + 1) : (i - s.top());
        s.push(i);
    }
    return ans;
}

void calculateSpan(int price[], int n, int S[])
{
    stack<int> s;
    s.push(0);

    vector<int> ans;
    ans.push_back(1);

    for (int i = 1; i < n; i++)
    {
        while ((!s.empty()) && (price[i] >= price[s.top()]))
        {
            s.pop();
        }

        if (s.empty())
        {
            ans.push_back(i + 1);
        }

        else
        {
            ans.push_back(i - s.top());
        }
        s.push(i);
    }

    return;
}

int main()
{
    return 0;
}