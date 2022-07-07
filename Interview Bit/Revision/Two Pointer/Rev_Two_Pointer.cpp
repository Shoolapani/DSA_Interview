#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std::chrono;
using namespace std;

// Pair With Given Difference
int solvePair(vector<int> &A, int B)
{
	sort(A.begin(), A.end());
	int i = 0, j = 1;

	while ((i < A.size()) && (j < A.size()))
	{
		if ((i != j) and ((A[j] - A[i] == B) or (A[i] - A[j] == B)))
		{
			return 1;
		}
		else if (A[j] - A[i] <= B)
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

int threeSumClosest(vector<int> &A, int B)
{
	int i = 0, low = 0, high = 0;
	long long int sum = 0, bestSum = INT_MAX;
	sort(A.begin(), A.end());

	while (i < A.size() - 2)
	{
		if ((i == 0) or ((i > 0) and A[i] != A[i - 1]))
		{
			low = i + 1, high = A.size() - 1;

			while (low < high)
			{
				sum = A[low] + A[i];
				sum += A[high];
				if (sum == B)
				{
					return sum;
				}
				else if (abs(B - sum) < abs(B - bestSum))
				{
					bestSum = sum;
				}
				else if (sum <= B)
				{
					++low;
				}
				else
				{
					--high;
				}
			}
		}
		++i;
	}

	return bestSum;
}

int threeSumClosest1(vector<int> &num, int target)
{
	sort(num.begin(), num.end());
	long long bestSum = 1000000000, sum = 0;
	// Fix the smallest number in the three integers
	for (int i = 0; i < num.size() - 2; i++)
	{
		// Now num[i] is the smallest number in the three integers in the solution
		int ptr1 = i + 1, ptr2 = num.size() - 1;
		while (ptr1 < ptr2)
		{
			sum = num[i] + num[ptr1] + num[ptr2];
			if (abs(target - sum) < abs(target - bestSum))
			{
				bestSum = sum;
			}
			if (sum > target)
			{
				ptr2--;
			}
			else
			{
				ptr1++;
			}
		}
	}
	return bestSum;
}

int diffPossible(vector<int> &A, int B)
{
	int i = 0, j = 0;

	while ((i < A.size()) and (j < A.size()))
	{
		if ((i != j) and ((A[i] - A[j] == B) or (A[j] - A[i] == B)))
		{
			return 1;
		}
		else if (A[j] - A[i] <= B)
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
int solve(vector<int> &A, int B)
{
	int len = 0;
	int i = 0, j = 0, countZero = 0;

	while ((i < A.size()) and (j < A.size()))
	{
		if (!A[j])
		{
			++countZero;
			while ((countZero > B) and (i < A.size()))
			{
				if (!A[i])
				{
					--countZero;
				}
				++i;
			}
		}
		len = max(len, i - j + 1);
		++j;
	}

	return len;
}

// Counting Subarrays!
int solveCounting(vector<int> &A, int B)
{
	int i = 0, j = 0;
	int num = 0;
	long long int sum = 0;

	while ((i < A.size()) and (j < A.size()))
	{
		sum += A[j];
		while ((sum >= B) and ((i < A.size())))
		{
			sum -= A[i];
			i++;
		}
		num += (j - i + 1);
		++j;
	}

	return num;
}

// Subarrays with distinct integers!
int findDistinct(vector<int> &A, int target)
{
	int i = 0, j = 0;
	int num = 0;
	unordered_map<int, int> uMap;

	while ((i < A.size()) and (j < A.size()))
	{
		uMap[A[j]]++;
		while ((uMap.size() > target) and (i < A.size()))
		{
			uMap[A[i]]--;
			if (uMap[A[i]] == 0)
			{
				uMap.erase(A[i]);
			}
			++i;
		}
		num += (j - i + 1);
		++j;
	}

	return num;
}

int solve1(vector<int> &A, int B)
{
	if (B == 0)
	{
		return 0;
	}
	return findDistinct(A, B) - findDistinct(A, B - 1);
}

// Remove Duplicates from Sorted Array
int removeDuplicates(vector<int> &A)
{
	int ind = 0, i = 0, j = 0;

	while ((i < A.size()) and (j < A.size()))
	{
		if (A[i] == A[j])
		{
			++j;
		}
		else if (A[i] != A[j])
		{

			A[ind++] = A[i];
			i = j;
			j++;
		}
	}

	A[ind] = A[j - 1];

	return ind;
}

// Remove Element from Array
int removeElement(vector<int> &A, int B)
{
	int ind = 0, i = 0;

	while (i < A.size())
	{
		if (A[i] == B)
		{
			i++;
			continue;
		}
		A[ind++] = A[i++];
	}

	return ind;
}

// Remove Duplicates from Sorted Array II
int removeDuplicates(vector<int> &A)
{
}

int main()
{
	vector<int> A = {1, 1, 2, 2, 3, 3};
	cout << removeDuplicates(A) << endl;

	for (auto &&i : A)
	{
		cout << i << ",";
	}

	return 0;
}