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
        int temp = nums[i] + k;
        if (isPresent(nums, temp, i + 1, nums.size() - 1))
        {
            ++count;
        }
    }

    return count;
}

int BS(vector<int> arr, int X, int low, int N)
{
    int high = N - 1;
    int ans = N;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= X)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ans;
}

int countPairsWithDiffK(vector<int> arr, int N, int k)
{
    int count = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < N; ++i)
    {
        int X = BS(arr, arr[i] + k, i + 1, N);
        if (X != N)
        {
            int Y = BS(arr, arr[i] + k + 1, i + 1, N);
            count += Y - X;
        }
    }

    return count;
}

// Remove Duplicates from Sorted Array
int removeDuplicates(vector<int> &A)
{
    int j = 0;
    if ((A.size() == 0) || (A.size() == 1))
    {
        return A.size();
    }
    for (size_t i = 0; i < A.size() - 1; i++)
    {
        if (A[i] != A[i + 1])
        {
            A[j++] = A[i];
        }
    }

    A[j++] = A[A.size() - 1];
    return j;
}

int removeElement(vector<int> &A, int B)
{
    int i = 0, j = 0;
    while ((i < A.size()) && (j < A.size()))
    {
        if (A[j] != B)
        {
            A[i++] = A[j];
        }
        ++j;
    }
    return i;
}

int main()
{
    vector<int> nums = {3, 1, 4, 1, 5};
    cout << countPairsWithDiffK(nums, 5, 2);
    return 0;
}