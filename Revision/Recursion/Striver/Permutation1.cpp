// 46. Permutations
#include <bits/stdc++.h>
using namespace std;

// O(N ! * N)   O(N)+O(N)
void helper(vector<int> nums, vector<vector<int>> &ans, vector<int> &ds, unordered_map<int, int> &Map)
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }

    for (size_t i = 0; i < nums.size(); i++)
    {
        if (Map.find(nums[i]) == Map.end())
        {
            Map[nums[i]] = i;
            ds.push_back(nums[i]);
            helper(nums, ans, ds, Map);
            Map.erase(nums[i]);
            ds.pop_back();
        }
    }
    return;
}

vector<vector<int>> permute2(vector<int> &nums)
{
    vector<vector<int>> ans;
    unordered_map<int, int> Map;
    vector<int> ds;
    helper(nums, ans, ds, Map);
    return ans;
}

// Best Method
// O(N! *N) O(1)
// swap method
void helper(vector<int> &nums, vector<vector<int>> &ans, int ind)
{
    if (ind == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (size_t i = ind; i < nums.size(); i++)
    {
        swap(nums[ind], nums[i]);
        helper(nums, ans, ind + 1);
        swap(nums[ind], nums[i]);
    }
    return;
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    unordered_map<int, int> Map;
    helper(nums, ans, 0);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    for (auto &&i : permute(nums))
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}