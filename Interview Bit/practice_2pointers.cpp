#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &A)
{
    int low = 0, mid = 0, high = A.size() - 1;

    while (mid <= high)
    {
        switch (A[mid])
        {
        case 0:
            swap(A[mid++], A[low++]);
            break;

        case 1:
            mid++;
            break;

        case 2:
            swap(A[high--], A[mid]);
            break;
        }
    }
    return;
}

bool isPresent(vector<int> &nums, int k, int low, int high)
{
    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (k == nums[mid])
        {
            return 1;
        }
        else if (nums[low] < k)
        {
            mid = low + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return 0;
}

int findPairs(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int l = 0, r = 0;
    int count = 0;

    for (size_t i = 0; i < nums.size() - 1; i++)
    {
        if (isPresent(nums, nums[i] + k, i + 1, nums.size()))
        {
            ++count;
        }
    }

    return count;
}

int main()
{
    vector<int> nums = {3, 1, 4, 1, 5};
    cout << findPairs(nums, 2);
    return 0;
}