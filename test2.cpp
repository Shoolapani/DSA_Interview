#include <bits/stdc++.h>
using namespace std;

// int Merge(vector<int> &nums, int low, int mid, int high)
// {
//     int total = 0;
//     int j = mid + 1;
//     for (int i = low; i <= mid; i++)
//     {
//         while (j <= high && nums[i] > 2 * nums[j])
//         {
//             j++;
//         }
//         total += (j - (mid + 1));
//     }

//     vector<int> t;
//     int left = low, right = mid + 1;

//     while (left <= mid && right <= high)
//     {
//         if (nums[left] <= nums[right])
//         {
//             t.push_back(nums[left++]);
//         }
//         else
//         {
//             t.push_back(nums[right++]);
//         }
//     }

//     while (left <= mid)
//     {
//         t.push_back(nums[left++]);
//     }
//     while (right <= high)
//     {
//         t.push_back(nums[right++]);
//     }

//     for (int i = low; i <= high; i++)
//     {
//         nums[i] = t[i - low];
//     }
//     return total;
// }

// int MergeSort(vector<int> &nums, int low, int high)
// {
//     if (low >= high)
//         return 0;
//     int mid = (low + (high - low) / 2);
//     int inv = MergeSort(nums, low, mid);
//     inv += MergeSort(nums, mid + 1, high);
//     inv += Merge(nums, low, mid, high);
//     return inv;
// }

// int reversePairs(vector<int> &arr)
// {
//     return MergeSort(arr, 0, arr.size() - 1);
// }

int mergeArr(vector<int> &nums, int begin, int mid, int end)
{
    int right = mid + 1, total = 0;

    for (size_t i = begin; i <= mid; i++)
    {
        while ((right <= end) && (nums[i] > 2 * nums[right]))
        {
            ++right;
        }
        total += (right - (mid + 1));
    }

    vector<int> ans;
    right = mid + 1;
    int i = begin;

    while ((i <= mid) && (right <= end))
    {
        if (nums[i] <= nums[right])
        {
            ans.push_back(nums[i++]);
        }
        else
        {
            ans.push_back(nums[right++]);
        }
    }

    while (i <= mid)
    {
        ans.push_back(nums[i++]);
    }

    while (right <= end)
    {
        ans.push_back(nums[right++]);
    }

    for (size_t j = begin; j <= end; j++)
    {
        nums[j] = ans[j - begin];
    }
    return total;
}

int mergeSort(vector<int> &nums, int begin, int end)
{
    int cnt{0};

    if (begin < end)
    {
        int mid = (begin + (end - begin) / 2);
        cnt += mergeSort(nums, begin, mid);
        cnt += mergeSort(nums, mid + 1, end);
        cnt += mergeArr(nums, begin, mid, end);
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
    cout << "The Total Reverse Pairs are " << reversePairs(arr) << endl;
    for (auto &&i : arr)
    {
        cout << i << " ";
    }
}