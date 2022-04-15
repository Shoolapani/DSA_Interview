#include <bits/stdc++.h>
using namespace std;

// using 2 stack
class MyQueue
{
public:
    MyQueue()
    {
        size = 0;
    }

    void push(int x)
    {
        ++size;
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        --size;
        int temp = s1.top();
        s1.pop();
        return temp;
    }

    int peek()
    {
        return s1.top();
    }

    bool empty()
    {
        return (size == 0);
    }

private:
    stack<int> s1, s2;
    int size;
};

class MyQueue
{
public:
    MyQueue()
    {
        size = 0;
    }

    void push(int x)
    {
        ++size;
        iP.push(x);
    }

    int pop()
    {
        --size;
        if (oP.empty())
            while (iP.size())
                oP.push(iP.top()), iP.pop();

        int x = oP.top();
        oP.pop();
        return x;
    }

    int peek()
    {
        if (oP.empty())
        {
            while (iP.size())
                oP.push(iP.top()), iP.pop();
        }

        int temp = oP.top();
        return temp;
    }

    bool empty()
    {
        return (size == 0);
    }

private:
    stack<int> iP, oP;
    int size;
};

int main()
{
    return 0;
}