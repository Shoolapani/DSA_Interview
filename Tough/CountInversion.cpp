#include <bits/stdc++.h>
using namespace std;

long long int merge(long long *arr, long long int begin, long long int mid, long long int end)
{
    long long int cnt = 0, i = begin, j = mid;
    vector<long long int> temp;

    while ((i < mid) && (j <= end))
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
            // IMP
            cnt += (mid - i);
        }
    }

    while ((i < mid))
    {
        temp.push_back(arr[i++]);
    }
    while ((j <= end))
    {
        temp.push_back(arr[j++]);
    }

    // +begin right subtree mai dikkat ata h isliye
    for (long long int k = 0; k < temp.size(); k++)
    {
        arr[k + begin] = temp[k];
    }

    return cnt;
}

long long int mergeSort(long long *arr, long long int begin, long long int end)
{
    long long int cnt = 0;
    if (begin < end)
    {
        long long int mid = (begin + (end - begin) / 2);
        cnt += mergeSort(arr, begin, mid);
        cnt += mergeSort(arr, mid + 1, end);
        cnt += merge(arr, begin, mid + 1, end);
    }
    return cnt;
}

long long getInversions(long long *arr, int n)
{
    return mergeSort(arr, 0, n - 1);
}

int main()
{
    long long int arr[] = {5, 3, 2, 1, 4};
    int n = 5;
    int temp[n];
    int ans = getInversions(arr, n);
    cout << "The total inversions are " << ans << endl;
    return 0;
}