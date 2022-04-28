#include <bits/stdc++.h>
#define LL long long int
using namespace std;

int merge(vector<int> &nums, int begin, int mid, int end)
{
    int total = 0;
    int i = begin, j = mid;
    vector<int> temp;

    for (i = begin; i <= mid; i++)
    {
        while ((j <= end) && (nums[i] > ((LL)2 * nums[j])))
        {
            ++j;
        }
        total += (j - mid);
    }

    i = begin, j = mid;
    while ((i <= mid - 1) && (j <= end))
    {
        if (nums[i] <= nums[j])
        {
            temp.push_back(nums[i++]);
        }
        else
        {
            temp.push_back(nums[j++]);
        }
    }

    while ((i < mid))
    {
        temp.push_back(nums[i++]);
    }

    while ((j <= end))
    {
        temp.push_back(nums[j++]);
    }

    for (size_t k = 0; k < temp.size(); k++)
    {
        nums[k + begin] = temp[k];
    }
    return total;
}

int mergeSort(vector<int> &nums, int begin, int end)
{
    int cnt = 0;
    if (begin < end)
    {
        int mid = (begin + (end - begin) / 2);
        cnt += mergeSort(nums, begin, mid);
        cnt += mergeSort(nums, mid + 1, end);
        cnt += merge(nums, begin, mid + 1, end);
    }
    return cnt;
}

int reversePairs(vector<int> &nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}

int main()
{
    vector<int> arr{1, 3, 2, 3, 1};
    cout << "The Total Reverse Pairs are " << reversePairs(arr);
    int a;
    return 0;
}