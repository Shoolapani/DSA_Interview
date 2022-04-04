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

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    // sort2(v);
    // for (auto &&i : v)
    // {
    //     cout << i << " ";
    // }

    stack<int> s;

    for (auto &&i : v)
    {
        s.push(i);
    }

    reverse(s);
    while (s.empty() == false)
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}