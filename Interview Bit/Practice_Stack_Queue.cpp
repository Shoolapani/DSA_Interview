#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std::chrono;
using namespace std;

// 225. Implement Stack using Queues
class MyStack
{
public:
    MyStack()
    {
    }

    void push(int x)
    {
        int size = q.size();
        q.push(x);
        for (size_t i = 0; i < size; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int val = q.front();
        q.pop();
        return val;
    }

    int top()
    {
        int val = q.front();
        return val;
    }

    bool empty()
    {
        return q.empty();
    }

private:
    queue<int> q;
};

// Implement Queue using Stacks
class MyQueue
{
public:
    MyQueue()
    {
    }

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        int size = s1.size();
        stack<int> s2;
        for (size_t i = 1; i < size; i++)
        {
            s2.push(s1.top());
            s1.pop();
        }

        int val = s1.top();
        s1.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }

        return val;
    }

    int peek()
    {
        stack<int> s2;
        int size = s1.size();
        s2 = s1;
        for (size_t i = 1; i < size; i++)
        {
            s2.pop();
        }

        int val = s2.top();
        return val;
    }

    bool empty()
    {
        return s1.empty();
    }

private:
    stack<int> s1;
};

// Valid Parentheses
bool isValid(string s)
{
    stack<char> s1;

    for (size_t i = 0; i < s.length(); i++)
    {
        if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
        {
            s1.push(s[i]);
        }
        else
        {
            if (s1.empty() or (s1.top() == '(' and s[i] != ')') or (s1.top() == '{' and s[i] != '}') or (s1.top() == '[' and s[i] != ']'))
            {
                return 0;
            }
            s1.pop();
        }
    }
    return s1.empty();
}

// Next Greater Element I
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> uMap;
    stack<int> st;
    vector<int> ans;
    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        while ((!st.empty()) && (nums2[i] > st.top()))
        {
            st.pop();
        }

        if (st.empty())
        {
            uMap[nums2[i]] = -1;
        }
        else
        {
            uMap[nums2[i]] = st.top();
        }
        st.push(nums2[i]);
    }

    for (auto &&i : nums1)
    {
        if (uMap.count(i))
        {
            ans.push_back(uMap[i]);
        }
    }

    return ans;
}

class MinStack
{
public:
    MinStack()
    {
        minVal = INT_MAX;
    }

    void push(int val)
    {
        if (st.empty())
        {
            minVal = val;
        }
        else
        {
            minVal = min(val, st.top().second);
        }
        st.push({val, minVal});
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }

private:
    stack<pair<int, int>> st;
    int minVal;
};

class MinStack2
{
public:
    MinStack2()
    {
        while (st.empty() == false)
            st.pop();
        minVal = INT_MAX;
    }

    void push(int val)
    {
        long long int ele = val;
        if (st.empty())
        {
            minVal = val;
            st.push(val);
        }
        else
        {
            if (val < minVal)
            {
                ele = (2 * val) - minVal;
                minVal = val;
            }
            st.push(ele);
        }
    }

    void pop()
    {
        if (st.top() < minVal)
        {
            minVal = (2 * minVal) - (st.top());
        }
        st.pop();
    }

    int top()
    {
        if (st.top() < minVal)
        {
            return minVal;
        }
        return st.top();
    }

    int getMin()
    {
        return minVal;
    }

private:
    stack<int> st;
    long long int minVal;
};

int main()
{
    string s = "(]";
    cout << isValid(s) << endl;
    return 0;
}