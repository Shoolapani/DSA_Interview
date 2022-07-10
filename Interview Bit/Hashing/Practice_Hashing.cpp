#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std::chrono;
using namespace std;

// Colorful Number
int colorful(int A)
{
	string s = to_string(A);
	unordered_set<long long int> uSet;

	for (size_t i = 0; i < s.length(); i++)
	{
		if (uSet.find(s[i] - '0') != uSet.end())
		{
			return 0;
		}

		uSet.insert(s[i] - '0');
		long long int temp = s[i] - '0';

		for (size_t j = i + 1; j < s.length(); j++)
		{
			temp *= (s[j] - '0');
			if (uSet.find(temp) != uSet.end())
			{
				return 0;
			}
			uSet.insert(temp);
		}
	}

	return 1;
}

int colorful2(int A)
{

	string a = to_string(A);
	int len = a.length();

	unordered_map<long long, bool> Hash;

	for (int i = 0; i < len; i++)
	{
		long long mul = 1;
		for (int j = i; j < len; j++)
		{
			mul *= (long long)(a[j] - '0');
			if (Hash.find(mul) != Hash.end())
				return 0;

			Hash[mul] = true;
		}
	}

	return 1;
}

// Check Palindrome!
int solve(string A)
{
	unordered_map<char, int> uMap;

	for (size_t i = 0; i < A.length(); i++)
	{
		uMap[A[i]]++;
	}
	bool flag = false;

	if (A.length() & 1)
	{
		flag = true;
	}

	for (auto it = uMap.begin(); it != uMap.end(); it++)
	{
		if (it->second & 1)
		{
			if (flag)
			{
				flag = 0;
				continue;
			}
			return 0;
		}
	}
	return 1;
}

// Anagrams
vector<vector<int>> anagrams(const vector<string> &A)
{
	vector<vector<int>> ans;
	vector<int> group;
	vector<string> sorted(A.size());
	unordered_map<string, vector<int>> uMap;

	for (size_t i = 0; i < A.size(); i++)
	{
		string temp = A[i];
		sort(temp.begin(), temp.end());
		sorted[i] = temp;

		if (uMap.find(temp) != uMap.end())
		{
			group = uMap[sorted[i]];
			group.emplace_back(i + 1);
			uMap[sorted[i]] = group;
		}
		else
		{
			group.clear();
			group.push_back(i + 1);
			uMap[sorted[i]] = group;
		}
	}

	for (size_t i = 0; i < A.size(); i++)
	{
		if (uMap.find(sorted[i]) != uMap.end())
		{
			ans.push_back(uMap[sorted[i]]);
			uMap.erase(sorted[i]);
		}
	}

	return ans;
}

// Pairs With Given Xor
// O(N^2)
int solvePairs1(vector<int> &A, int B)
{
	unordered_map<int, int> uMap;

	for (size_t i = 0; i < A.size(); i++)
	{
		for (size_t j = i + 1; j < A.size(); j++)
		{
			if ((A[i] ^ A[j]) == B)
			{
				if (uMap.find(A[i]) == uMap.end())
				{
					uMap[A[i]] == A[j];
				}
			}
		}
	}

	return uMap.size();
}

// O(N)
int solvePairs2(vector<int> &A, int B)
{
	unordered_set<int> uSet;
	int ans = 0;

	for (size_t i = 0; i < A.size(); i++)
	{
		if (uSet.find(A[i]) != uSet.end())
		{
			++ans;
		}
		else
		{
			uSet.insert(A[i] ^ B);
		}
	}

	return ans;
}

// Subarray with B odd numbers
int solve(vector<int> &A, int B)
{
}

int solve(vector<int> &A, int B)
{
	int n = A.size();
	int count = 0;
	int prefix[n + 1];
	memset(prefix, 0, sizeof(prefix));
	int odd = 0;
	// traverse in the array
	for (int i = 0; i < n; i++)
	{

		prefix[odd]++;
		// if array element is odd
		if (A[i] & 1)
			odd++;

		// when number of odd elements>=M
		if (odd >= B)
			count += prefix[odd - B];
	}
	return count;
}

// First Repeating element
int solve(vector<int> &A)
{
	unordered_map<int, int> uMap;
	int ans = INT_MAX;

	for (auto i = 0; i < A.size(); i++)
	{
		if (uMap.find(A[i]) != uMap.end())
		{
			ans = min(ans, uMap[A[i]]);
		}
		else
		{
			uMap[A[i]] = i;
		}
	}

	if (ans == INT_MAX)
	{
		return -1;
	}
	return A[ans];
}

// Longest Subarray Length
//  A = [0, 1, 1, 0, 0, 1]
//
int solve(vector<int> &A)
{
	int ans = 1;
	int i = 0, j = 0;
	int countZero = 0, countOne = 0;

	while ((i < A.size()) and (j < A.size()))
	{
		if (A[j] == 0)
		{
			++countZero;
		}
		else
		{
			++countOne;
		}

		while ((countOne > countZero + 1) and (i < A.size()))
		{
			if (A[i] == 0)
			{
				--countZero;
			}
			else
			{
				--countOne;
			}
			++i;
		}

		if (countOne == countZero + 1)
		{
			ans = max(ans, j - i + 1);
		}
		++j;
	}

	return ans;
}

int solve(vector<int> &A)
{
	map<int, int> m;
	int sum = 0, maxlen = 0;
	for (int i = 0; i < A.size(); i++)
	{
		sum += (A[i] == 0) ? -1 : 1;
		if (sum == 1)
			maxlen = max(maxlen, i + 1);
		else if (m.find(sum) == m.end())
			m[sum] = i;
		if (m.find(sum - 1) != m.end())
		{
			maxlen = max(maxlen, i - m[sum - 1]);
		}
	}
	return maxlen;
}

int main()
{
	return 0;
}
