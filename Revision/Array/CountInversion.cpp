#include <bits/stdc++.h>
using namespace std;

long long int merge(long long *arr, int n, long long int begin, long long int mid, long long int end)
{
    long long int i = begin, j = mid, k = begin, ans = 0;
    long long int temp[n];
    while ((i <= mid - 1) && (j <= end))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            ans += (mid - i);
        }
    }

    while (i <= mid - 1)
    {
        temp[k++] = arr[i++];
    }

    while (j <= end)
    {
        temp[k++] = arr[j++];
    }

    for (size_t i = begin; i <= end; i++)
    {
        arr[i] = temp[i];
    }

    return ans;
}

long long int mergeSort(long long *arr, int n, long long int begin, long long int end)
{
    long long int cnt = 0;
    if (begin < end)
    {
        long long int mid = (begin + (end - begin) / 2);
        cnt += mergeSort(arr, n, begin, mid);
        cnt += mergeSort(arr, n, mid + 1, end);
        cnt += merge(arr, n, begin, mid + 1, end);
    }
    return cnt;
}

long long getInversions(long long *arr, int n)
{
    return mergeSort(arr, n, 0, n - 1);
}

int main()
{
    return 0;
}