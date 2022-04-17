#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    MinStack()
    {
        minEle = 0;
    }

    void push(int val)
    {
        if (st.empty())
        {
            minEle = val;
        }

        else
        {
            minEle = min(st.top().second, val);
        }

        st.push({val, minEle});
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return (st.top().first);
    }

    int getMin()
    {
        return st.top().second;
    }

private:
    stack<pair<int, int>> st;
    int minEle;
};

class MinStack
{
public:
    MinStack()
    {
        while (st.empty() == false)
            st.pop();
        minEle = INT_MAX;
    }

    void push(int value)
    {
        // Because overflow;
        long long int val = value;
        if (st.empty())
        {
            minEle = val;
            st.push(val);
        }
        else
        {
            if (val < minEle)
            {
                long long int temp = (2 * (val) * (1LL));
                st.push((temp)-minEle);
                minEle = val;
            }
            else
            {
                st.push(val);
            }
        }
    }

    void pop()
    {
        // Edge Case
        if (st.empty())
        {
            return;
        }

        long long int temp = st.top();
        if (temp < minEle)
        {
            minEle = (2 * minEle) - temp;
        }
        st.pop();
    }

    int top()
    {
        // Edge Case
        if (st.empty())
        {
            return -1;
        }

        long long int temp = st.top();
        if (temp < minEle)
        {
            return minEle;
        }
        return temp;
    }

    int getMin()
    {
        return minEle;
    }

private:
    stack<long long int> st;
    long long int minEle;
};

int main()
{
    return 0;
}