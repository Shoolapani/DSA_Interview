#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100;

class Stack
{
public:
    Stack()
    {
        topElement = -1;
        memset(arr, -1, MAX_SIZE);
    }

    void push(int num)
    {
        if (topElement > MAX_SIZE)
        {
            return;
        }
        ++topElement;
        arr[topElement] = num;
    }

    void pop()
    {
        if (topElement < 0)
        {
            return;
        }
        arr[topElement] = -1;
        --topElement;
    }

    int top()
    {
        return arr[topElement];
    }

    int size()
    {
        return topElement + 1;
    }

private:
    int arr[MAX_SIZE];
    int topElement;
};

int main()
{
    return 0;
}