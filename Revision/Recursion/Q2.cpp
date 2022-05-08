// Sort an stack

#include <bits/stdc++.h>
using namespace std;

void rightPlace(stack<int> &s, int value)
{
    if (s.empty())
    {
        s.push(value);
        return;
    }

    int x = s.top();
    
    if (x >= value)
    {
        s.push(value);
        return;
    }
    s.pop();
    rightPlace(s, value);
    s.push(x);
    return;
}

void sortStack(stack<int> &s)
{
    if (s.size() == 1)
    {
        return;
    }
    int x = s.top();
    s.pop();
    sortStack(s);
    rightPlace(s, x);
    return;
}

int main()
{
    stack<int> s;
    for (size_t i = 0; i < 4; i++)
    {
        s.push(i);
    }
    s.push(-1);
    s.push(-1);
    s.push(-1);
    s.push(-12);
    s.push(12);
    s.push(12);
    sortStack(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}