#include <bits/stdc++.h>
#define LL long long int
using namespace std;

int merge(vector<int> &nums, int begin, int mid, int end)
{
    int cnt = 0;int i = begin, j = mid;
    for (i = begin; i < mid; i++)
    {
        while ((j <= end) && ((LL)nums[i] > (2 * nums[j])))
        {
            ++j;
        }
        cnt += (j - mid);
    }

    i = begin, j = mid;
    vector<int> ans;

    while ((i < mid) && (j <= end))
    {
        if (nums[i] <= nums[j])
        {
            ans.push_back(nums[i++]);
        }
        else
        {
            ans.push_back(nums[j++]);
        }
    }

    while ((i < mid))
    {
        ans.push_back(nums[i++]);
    }

    while (j <= end)
    {
        ans.push_back(nums[j++]);
    }

    for (size_t i = 0; i < ans.size(); i++)
    {
        nums[i + begin] = ans[i];
    }

    return cnt;
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
    return 0;
}