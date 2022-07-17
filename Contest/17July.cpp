#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std::chrono;
using namespace std;

// 6120. Maximum iber of Pairs in Array
// Solved
vector<int> iberOfPairs(vector<int> &is)
{
    unordered_map<int, int> uMap;
    vector<int> ans;
    int pair = 0, size = 0;

    if (is.size() == 0)
    {
        return ans;
    }

    for (auto &&i : is)
    {
        uMap[i]++;
    }

    for (auto it = uMap.begin(); it != uMap.end(); it++)
    {
        if ((it->second) & 1)
        {
            if ((it->second) >= 3)
            {
                pair += ((it->second) - 1) / 2;
                size += (it->second) % 2;
            }
            else
            {
                size += (it->second);
            }
        }
        else
        {
            pair += (it->second) / 2;
        }
    }

    ans.push_back(pair);
    ans.push_back(size);
    return ans;
}

// 6164. Max Sum of a Pair With Equal Sum of Digits
int totalSum(int i)
{
    int sum = 0;

    while (i != 0)
    {
        sum += (i % 10);
        i = i / 10;
    }

    return sum;
}

int maximumSum(vector<int> &nums)
{
    unordered_map<long int, long int> uMap;
    int ans = -1;

    for (auto i = 0; i < nums.size(); i++)
    {
        int sum = totalSum(nums[i]);

        if (uMap.find(sum) != uMap.end())
        {
            ans = max(ans, nums[i] + nums[uMap[sum]]);
            if (nums[uMap[sum]] < nums[i])
            {
                uMap[sum] = i;
            }
        }
        else
        {
            uMap[sum] = i;
        }
    }

    return ans;
}

// 6121. Query Kth Smallest Trimmed Number
vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
{
    vector<int> ans;
    set<int> order;

    

    return ans;
}

int main()
{
    vector<int> A = {279, 169, 463, 252, 94, 455, 423, 315, 288, 64, 494, 337, 409, 283, 283, 477, 248, 8, 89, 166, 188, 186, 128};
    cout << maximumSum(A) << endl;
    // for (auto &&i : iberOfPairs(A))
    // {
    //     cout << i << "\t";
    // }

    return 0;
}