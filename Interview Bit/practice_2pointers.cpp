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

vector<vector<int>> threeSum(vector<int> &nums)
{
	vector<vector<int>> ans;
	sort(nums.begin(), nums.end());

	for (int i = 0; i < (int)nums.size() - 2; i++)
	{
		if ((i == 0) || ((i > 0) && (nums[i] != nums[i - 1])))
		{
			int startInd = i + 1, endInd = (int)(nums.size()) - 1;
			int val = 0 - (nums[i]);
			while ((startInd < endInd))
			{
				if (nums[startInd] + nums[endInd] == val)
				{
					vector<int> temp;
					temp.push_back(nums[i]);
					temp.push_back(nums[startInd]);
					temp.push_back(nums[endInd]);
					ans.push_back(temp);
					while ((startInd < endInd) && (nums[startInd] == nums[startInd + 1]))
					{
						++startInd;
					}

					while ((startInd < endInd) && (nums[endInd] == nums[endInd - 1]))
					{
						--endInd;
					}
					--endInd;
					++startInd;
				}
				else if (nums[startInd] + nums[endInd] < val)
				{
					++startInd;
				}
				else
				{
					--endInd;
				}
			}
		}
	}
	return ans;
}

vector<vector<int>> threeSum2(vector<int> &nums)
{
	vector<vector<int>> ans;
	sort(nums.begin(), nums.end());
	int ind = 0, left = 1, right = nums.size() - 1;

	for (ind = 0; ind < (int)(nums.size()) - 2; ind++)
	{
		if ((ind == 0) || (ind > 0 && nums[ind] != nums[ind - 1]))
		{
			left = ind + 1, right = (int)(nums.size()) - 1;
			int a = 0 - (nums[ind]);
			while (left < right)
			{
				if (nums[left] + nums[right] == a)
				{
					vector<int> vec;
					vec.push_back(nums[ind]);
					vec.push_back(nums[left]);
					vec.push_back(nums[right]);
					ans.push_back(vec);

					while (left < right && (nums[left] == nums[left + 1]))
						left++;
					while (left < right && (nums[right] == nums[right - 1]))
						right--;

					left++, right--;
				}
				else if (nums[left] + nums[right] < a)
				{
					++left;
				}
				else
				{
					right--;
				}
			}
		}
	}
	return ans;
}

// Subarrays with distinct integers!
// O(N)
int atMost(vector<int> &nums, int k)
{
	int i = 0, j = 0, ans = 0;
	unordered_map<int, int> uMap;

	while ((j < nums.size()))
	{
		uMap[nums[j]]++;

		while (uMap.size() > k)
		{
			// it->second = (it->second)--;
			uMap[nums[i]]--;
			auto it = uMap.find(nums[i]);
			if (it->second == 0)
			{
				uMap.erase(nums[i]);
			}
			++i;
		}
		ans += (j - i + 1);
		++j;
	}
	return ans;
}

int subarraysWithKDistinct(vector<int> &nums, int k)
{
	return atMost(nums, k) - atMost(nums, k - 1);
}

//  Intersection of Two Arrays
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	vector<int> ans;
	int i = 0, j = 0;

	while ((i < nums1.size()) && (j < nums2.size()))
	{
		if (nums1[i] == nums2[j])
		{
			ans.push_back(nums1[i]);
			++j;
			++i;
		}
		else if (nums1[i] < nums2[j])
		{
			++i;
		}
		else
		{
			++j;
		}

		while ((i > 0) && (i < nums1.size()) && (nums1[i] == nums1[i - 1]))
		{
			++i;
		}
		while ((j > 0) && (j < nums2.size()) && (nums2[j] == nums2[j - 1]))
		{
			++j;
		}
	}
	return ans;
}

// Merge Two Sorted Lists II
void merge(vector<int> &A, vector<int> &B)
{
	vector<int> ds;
	int i = 0, j = 0;

	while ((i < A.size()) && (j < B.size()))
	{
		if (A[i] <= B[j])
		{
			ds.push_back(A[i++]);
		}
		else
		{
			ds.push_back(B[j++]);
		}
	}

	while (j < B.size())
	{
		ds.push_back(B[j]);
		++j;
	}

	while (i < A.size())
	{
		ds.push_back(A[i]);
		++i;
	}
	A = ds;
	return;
}

// Diffk
int diffPossible(vector<int> &A, int B)
{
	int i = 0, j = 1;

	while ((j < A.size()))
	{
		if ((abs(A[i] - A[j]) == B) && (i != j))
		{
			return 1;
		}
		if ((abs(A[i] - A[j]) <= B))
		{
			++j;
		}
		else
		{
			++i;
		}
	}
	return 0;
}

// Maximum Ones After Modification
// O(N^2)
// TLE
int solveOnes(vector<int> &A, int B)
{
	int i = 0, j = 0, len = 0;
	while ((i < A.size()) && (j < A.size()))
	{
		if (A[j])
		{
			++j;
		}
		else
		{
			int temp = B;
			while ((temp > 0) && (j < A.size()))
			{
				if (A[j] == 0)
				{
					temp--;
				}
				++j;
			}

			while ((j < A.size()))
			{
				if (A[j])
				{
					++j;
				}
				else
				{
					break;
				}
			}
			len = max(len, j - i);
			i++;
			j = i;
		}
	}

	return len;
}

// O(N)
int solveOnes2(vector<int> &A, int B)
{
	int i = 0, j = 0, len = 0, countZero = 0;
	while ((i < A.size()) && (j < A.size()))
	{
		if (A[j] == 0)
		{
			++countZero;
			while (countZero > B)
			{
				if (A[i] == 0)
				{
					--countZero;
				}
				++i;
			}
		}
		len = max(len, j - i + 1);
		++j;
	}
	return len;
}

// Remove Duplicates from Sorted Array II
int removeDuplicates2(vector<int> &A)
{
	int i = 0, j = A[0], countDup = 1;

	for (int k = 2; k < A.size(); k++)
	{
		if ((i == 0) || (i == 1) || (A[k] != A[i - 2]))
		{
			A[i++] = A[k];
		}
	}

	return i;
}

int main()
{
	vector<int> nums = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1}, nums2 = {1, 1, 1, 2, 2, 2};
	cout << removeDuplicates2(nums2) << endl;

	for (auto &&i : nums2)
	{
		cout << i << " ";
	}

	return 0;
}