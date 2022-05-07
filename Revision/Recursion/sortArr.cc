#include <bits/stdc++.h>
using namespace std;

void rightPlace(vector<int> &arr, int value)
{
    if (arr.empty())
    {
        arr.push_back(value);
        return;
    }
    int x = arr.back();
    if (x <= value)
    {
        arr.push_back(value);
        return;
    }
    arr.pop_back();
    rightPlace(arr, value);
    arr.push_back(x);
    return;
}

void sortArr(vector<int> &arr)
{
    if (arr.size() == 1)
    {
        return;
    }
    int x = arr.back();
    arr.pop_back();
    sortArr(arr);
    rightPlace(arr, x);
    return;
}

int main()
{
    vector<int> arr = {1, 1, 1, 1, 1, 5};
    sortArr(arr);
    for (auto &&i : arr)
    {
        cout << i << " ";
    }

    return 0;
}