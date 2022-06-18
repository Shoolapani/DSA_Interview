#include <bits/stdc++.h>
using namespace std;

// Search in Bitonic Array!
int peak(vector<int> &A)
{
	int low = 0, high = A.size() - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (A[0] > A[1])
		{
			return 0;
		}
		if (A[high - 1] < A[high])
		{
			return high;
		}
		if ((A[mid] > A[mid - 1]) && (A[mid] > A[mid + 1]))
		{
			return mid;
		}
		else if ((A[mid] > A[mid - 1]) || (A[mid] < A[mid + 1]))
		{
			low = mid + 1;
		}
		else if (A[mid] < A[mid - 1] || A[mid] > A[mid + 1])
		{
			high = mid - 1;
		}
	}

	return -1;
}

int solveBitonic(vector<int> &A, int B)
{
	int low = 0, high = peak(A);
	int low1 = high, high1 = A.size() - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (A[mid] == B)
		{
			return mid;
		}
		else if (A[mid] > B)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	while (low1 <= high1)
	{
		int mid = (low1 + high1) / 2;
		if (A[mid] == B)
		{
			return mid;
		}
		else if (A[mid] < B)
		{
			high1 = mid - 1;
		}
		else
		{
			low1 = mid + 1;
		}
	}
	return -1;
}

int searchInsert(vector<int> &A, int B)
{
	int low = 0, high = A.size() - 1;

	while (low <= high)
	{
		int mid = (low + (high - low) / 2);
		if (A[mid] == B)
		{
			return mid;
		}

		if (A[mid] <= B)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	low = 0, high = A.size() - 1;
	int ans = 0;
	while (low <= high)
	{
		int mid = (low + (high - low) / 2);
		if (A[mid] > B)
		{
			high = mid - 1;
		}
		else
		{
			ans = mid;
			low = mid + 1;
		}
	}
	return ans;
}

int main()
{
	return 0;
}