#include <bits/stdc++.h>
using namespace std;

void sums(vector<int> arr, int ind, vector<int> &ds, vector<int> &ans)
{
    if (ind == arr.size())
    {
        int sum = 0;
        sum = accumulate(ds.begin(), ds.end(), sum);
        ans.push_back(sum);
        return;
    }

    ds.push_back(arr[ind]);
    sums(arr, ind + 1, ds, ans);
    ds.pop_back();
    sums(arr, ind + 1, ds, ans);
    return;
}

vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> ans;
    vector<int> ds;
    sums(arr, 0, ds, ans);
    reverse(ans.begin(), ans.end());
    return ans;
}

void subsetNoDup(vector<int> arr, int ind, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);

    for (size_t i = ind; i < arr.size(); i++)
    {
        if ((i != ind) && (arr[i] == arr[i - 1]))
        {
            continue;
        }
        ds.push_back(arr[i]);
        subsetNoDup(arr, i + 1, ds, ans);
        ds.pop_back();
    }
    return;
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> ds;
    subsetNoDup(nums, 0, ds, ans);
    return ans;
}

void sum(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &ds, int target, int ind)
{
    if (ind == candidates.size())
    {
        if ((target == 0))
        {
            ans.push_back(ds);
        }
        return;
    }

    if ((target == 0))
    {
        ans.push_back(ds);
        return;
    }

    if (target >= candidates[ind])
    {
        ds.push_back(candidates[ind]);
        sum(candidates, ans, ds, target - candidates[ind], ind);
        ds.pop_back();
    }
    //  agar target-candidates[ind] then agar target=0 hua then candidates[ind] wala ds mai store nahi hoga
    sum(candidates, ans, ds, target, ind + 1);
    return;
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sum(candidates, ans, ds, target, 0);
    return ans;
}

void sum2(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &ds, int target, int ind)
{
    if ((target == 0))
    {
        ans.push_back(ds);
        return;
    }

    for (size_t i = ind; i < candidates.size(); i++)
    {
        if ((i != ind) && (candidates[i] == candidates[i - 1]))
        {
            continue;
        }
        if (target >= candidates[i])
        {
            ds.push_back(candidates[i]);
            sum(candidates, ans, ds, target - candidates[i], i + 1);
            ds.pop_back();
        }
        sum(candidates, ans, ds, target, i + 1);
    }
    return;
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> ds;
    sum2(candidates, ans, ds, target, 0);
    return ans;
}

int main()
{
    vector<int> arr = {2, 3, 6, 7};
    // for (auto &&i : combinationSum(arr, arr.size()))
    // {
    //     cout << i << " ";
    // }
    for (auto &&i : combinationSum2(arr, 7))
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}