#include <bits/stdc++.h>
using namespace std;

// Using 2 Queue;
class MyStack
{
public:
    MyStack()
    {
        size = 0;
    }

    void push(int x)
    {
        ++size;
        q2.push(x);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        dummyQ = q1;
        q1 = q2;
        q2 = dummyQ;
    }

    int pop()
    {
        --size;
        int temp = q1.front();
        q1.pop();
        return temp;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return (size == 0);
    }

private:
    queue<int> q1, q2;
    queue<int> dummyQ;
    int size;
};

class MyStack
{
public:
    MyStack()
    {
        size = 0;
    }

    void push(int x)
    {
        ++size;
        q1.push(x);
        int temp = size;
        for (size_t i = 1; i < size; i++)
        {
            q1.push(q1.front());
            q1.pop();
        }
    }

    int pop()
    {
        --size;
        int temp = q1.front();
        q1.pop();
        return temp;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return (size == 0);
    }

private:
    queue<int> q1;
    int size;
};

int main()
{

    return 0;
}