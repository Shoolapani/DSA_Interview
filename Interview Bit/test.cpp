// C++ program to get total
// xor of all subarray xors
#include <bits/stdc++.h>
using namespace std;

// Returns XOR of all subarray xors
int getTotalXorOfSubarrayXors(int arr[],
							  int N)
{
	// initialize result by 0
	// as (a XOR 0 = a)
	int res = 0;

	// loop over all elements once
	for (int i = 0; i < N; i++)
	{
		// get the frequency of
		// current element
		int freq = (i + 1) * (N - i);

		// Uncomment below line to print
		// the frequency of arr[i]
		cout << arr[i] << " " << freq << endl;

		// if frequency is odd, then
		// include it in the result
		if (freq % 2 == 1)
			res = res ^ arr[i];
	}

	// return the result
	return res;
}

// Driver Code
int main()
{
	int arr[] = {3, 5, 2, 4, 6};
	int N = sizeof(arr) / sizeof(arr[0]);

	cout << getTotalXorOfSubarrayXors(arr, N);
	return 0;
}
