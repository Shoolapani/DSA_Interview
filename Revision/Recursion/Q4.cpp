// Reverse an stack
#include <bits/stdc++.h>
using namespace std;

void atStarting(stack<int> &s, int x)
{
    if (s.size() == 0)
    {
        s.push(x);
        return;
    }
    int t = s.top();
    s.pop();
    atStarting(s, x);
    s.push(t);
    return;
}

void reverseStack(stack<int> &s)
{
    if (s.size() == 1)
    {
        return;
    }

    int x = s.top();
    s.pop();
    reverseStack(s);
    atStarting(s, x);
    return;
}

int main()
{
    stack<int> s, s1;
    for (size_t i = 1; i < 10; i++)
    {
        s.push(i);
    }
    s1 = s;
    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;

    reverseStack(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}