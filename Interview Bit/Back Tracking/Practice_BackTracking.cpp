#include <bits/stdc++.h>
using namespace std;

// Subset Sums
void findSum(vector<int> arr, vector<int> &total, vector<int> &ans, int index = 0)
{
	if (index == arr.size())
	{
		int sum = 0;
		for (auto &&it : total)
		{
			sum += it;
		}

		ans.push_back(sum);
		return;
	}

	total.push_back(arr[index]);
	findSum(arr, total, ans, index + 1);
	total.pop_back();
	findSum(arr, total, ans, index + 1);
	return;
}

vector<int> subsetSums(vector<int> arr)
{
	vector<int> total, ans;
	findSum(arr, total, ans);
	return ans;
}

// 90. Subsets II
void findSubset(vector<int> nums, vector<int> &ds, vector<vector<int>> &ans, int index)
{
	ans.push_back(ds);
	for (int i = index; i < nums.size(); i++)
	{
		if ((i != index) and (nums[i] == nums[i - 1]))
		{
			continue;
		}
		else
		{
			ds.push_back(nums[i]);
			findSubset(nums, ds, ans, i + 1);
			ds.pop_back();
		}
	}
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
	vector<vector<int>> ans;
	vector<int> ds;
	sort(nums.begin(), nums.end());
	findSubset(nums, ds, ans, 0);
	return ans;
}

// 1239. Maximum Length of a Concatenated String with Unique Characters
// int maxLength(vector<string> &arr)
// {
// }

int main()
{
	vector<int> A = {1, 2, 2};
	// cout << minWindow("ADOBECODEBANC", "ABC") << endl
	// cout << floorSqrt(930675566) << endl;
	// for (auto &&i : subsetSums(A))
	// {
	// 	cout << i << ",";
	// }

	for (auto &&i : subsetsWithDup(A))
	{
		for (auto &&j : i)
		{
			cout << j << ",";
		}
		cout << endl;
	}

	return 0;
}