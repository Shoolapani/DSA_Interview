// Delete Middle Element of Stack
#include <bits/stdc++.h>
using namespace std;

void deleteMiddle(stack<int> &s, int k, int i)
{
    if (i == k)
    {
        s.pop();
        return;
    }
    int x = s.top();
    s.pop();
    deleteMiddle(s, k, ++i);
    s.push(x);
    return;
}

int main()
{
    stack<int> s, s1;
    for (size_t i = 0; i < 7; i++)
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
    int k = ((s.size() / 2) + 1);
    deleteMiddle(s, k, 1);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}