#include <bits/stdc++.h>
using namespace std;


vector<int> twoSum2(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    vector<int> ans;
    unordered_map<int, int> uMap;

    for (int i = 0; i < nums.size(); i++)
    {
        if (uMap.find(target - nums[i]) != uMap.end())
        {
            ans.insert(ans.end(), {i, uMap[target - nums[i]]});
            return ans;
        }
        uMap[nums[i]] = i;
    }

    return ans;
}

vector<int> twoSum(vector<int> &nums, int target)
{
    // This is imp
    vector<int> nums2;
    sort(nums2.begin(), nums2.end());
    int low = 0, high = nums.size() - 1;
    vector<int> ans;
    int n1{0}, n2{0};
    while (low < high)
    {
        if (nums2[low] + nums2[high] == target)
        {
            n1 = nums2[low];
            n2 = nums2[high];
            break;
        }
        if (nums2[low] + nums2[high] > target)
        {
            --high;
        }
        else if (nums2[low] + nums2[high] < target)
        {
            ++low;
        }
    }

    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] == n1)
        {
            ans.push_back(i);
        }
        if (nums[i] == n2)
        {
            ans.push_back(i);
        }
    }

    return ans;
}

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    set<vector<int>> sv;
    sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (size_t j = i + 1; j < nums.size(); j++)
        {
            for (size_t k = j + 1; k < nums.size(); k++)
            {
                int a = (long long)target - ((long long)nums[i] + (long long)nums[j] + (long long)nums[k]);
                if (binary_search(nums.begin() + k + 1, nums.end(), a))
                {
                    vector<int> temp;
                    temp.insert(temp.end(), {nums[i], nums[j], nums[k], a});
                    sort(temp.begin(), temp.end());
                    sv.insert(temp);
                    temp.clear();
                }
            }
        }
    }
    vector<vector<int>> ans(sv.begin(), sv.end());
    return ans;
}

void permutation(string s, string str, vector<int> &v, vector<string> &ans)
{
    if (s.length() == str.length())
    {
        ans.push_back(str);
        return;
    }

    for (size_t i = 0; i < v.size(); i++)
    {
        if (!v[i])
        {
            v[i] = 1;
            str += s[i];
            permutation(s, str, v, ans);
            v[i] = 0;
            str.pop_back();
        }
    }
    return;
}

vector<string> find_permutation(string s)
{
    vector<string> ans;
    vector<int> v(s.length(), 0);
    permutation(s, "", v, ans);
    return ans;
}

bool isPowerOfTwo(int n)
{
    if ((n == 0))
    {
        return 1;
    }
    if (!n & (n - 1))
    {
        return 1;
    }
    return 0;
}



int main()
{
    cout << isPowerOfTwo(0);
    return 0;
}