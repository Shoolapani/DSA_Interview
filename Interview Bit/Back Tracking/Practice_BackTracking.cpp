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

// 39. Combination Sum
void findCombinationSum(vector<int> nums, vector<int> &ds, vector<vector<int>> &ans, int index, int target)
{
	if (index == nums.size())
	{
		if (target == 0)
		{
			ans.push_back(ds);
		}
		return;
	}

	if ((nums[index] <= target))
	{
		ds.push_back(nums[index]);
		findCombinationSum(nums, ds, ans, index, target - nums[index]);
		ds.pop_back();
	}
	findCombinationSum(nums, ds, ans, index + 1, target);
	return;
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
	vector<vector<int>> ans;
	vector<int> ds;
	sort(candidates.begin(), candidates.end());
	findCombinationSum(candidates, ds, ans, 0, target);
	return ans;
}

// 40. Combination Sum II
void findCombinationSum2(vector<int> nums, vector<int> &ds, vector<vector<int>> &ans, int index, int target)
{
	if (index == nums.size())
	{
		if (target == 0)
		{
			ans.push_back(ds);
		}
		return;
	}

	if (target == 0)
	{
		ans.push_back(ds);
		return;
	}

	for (int i = index; i < nums.size(); i++)
	{
		if (target < nums[i])
		{
			return;
		}

		if ((i != index) and (nums[i] == nums[i - 1]))
		{
			continue;
		}

		ds.push_back(nums[i]);
		findCombinationSum2(nums, ds, ans, i + 1, target - nums[i]);
		ds.pop_back();
	}

	return;
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
	vector<vector<int>> ans;
	vector<int> ds;
	sort(candidates.begin(), candidates.end());
	findCombinationSum2(candidates, ds, ans, 0, target);
	return ans;
}

// 131. Palindrome Partitioning
bool isPalindrome(string s, int st, int end)
{
	if (st > end)
	{
		return false;
	}

	if (st == end)
	{
		return true;
	}

	while (st < end)
	{
		if (s[st] != s[end])
		{
			return false;
		}
		st++;
		end--;
	}

	return true;
}

void findPartition(string s, vector<string> &ds, vector<vector<string>> &ans, int index)
{
	if (index == s.length())
	{
		ans.push_back(ds);
		return;
	}

	for (int i = index; i < s.length(); i++)
	{
		if (isPalindrome(s, index, i))
		{
			ds.push_back(s.substr(index, i - index + 1));
			findPartition(s, ds, ans, i + 1);
			ds.pop_back();
		}
	}

	return;
}

vector<vector<string>> partition(string s)
{
	vector<vector<string>> ans;
	vector<string> ds;
	findPartition(s, ds, ans, 0);
	return ans;
}

// 60. Permutation Sequence
string getPermutation(int n, int k)
{
}

// 1 1 2 5 6 7 10
// 1239. Maximum Length of a Concatenated String with Unique Characters
// int maxLength(vector<string> &arr)
// {
// }

int main()
{
	vector<int> A = {2, 5, 2, 1, 2};
	// cout << minWindow("ADOBECODEBANC", "ABC") << endl
	// cout << floorSqrt(930675566) << endl;
	// for (auto &&i : subsetSums(A))
	// {
	// 	cout << i << ",";
	// }

	for (auto &&i : partition("aab"))
	{
		for (auto &&j : i)
		{
			cout << j << ",";
		}
		cout << endl;
	}

	return 0;
}