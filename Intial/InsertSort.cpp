#include <bits/stdc++.h>
using namespace std;

void sort(int arr[], int n)
{
    for (size_t i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            int j = i;
            while ((arr[j] < arr[j-1]) && (j >= 1))
            {
                swap(arr[j], arr[j-1]);
                --j;
            }
        }
    }
}

int main()
{
    int arr[] = {12, 13, 2, 1, 24, 56, 0};
    sort(arr, 7);

    for (size_t i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}