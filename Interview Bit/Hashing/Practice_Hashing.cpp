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

int solve1(vector<int> &A, int B)
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
int solveLongest(vector<int> &A)
{
	int ans = 1;
	int sum = 0, j = 0;
	unordered_map<int, int> uMap;

	while ((j < A.size()))
	{
		sum += ((A[j] == 0) ? (-1) : (1));
		if (sum == 1)
		{
			ans = j + 1;
		}
		else if (uMap.find(sum) == uMap.end())
		{
			uMap[sum] = j;
		}

		if (uMap.find(sum - 1) != uMap.end())
		{
			ans = max(ans, j - uMap[sum - 1]);
		}
		++j;
	}

	return ans;
}

// Largest subarray with 0 sum
// A[] = {15,-2,2,-8,1,7,10,23}
//  15-2+2-8
//
int maxLen(vector<int> &A, int n)
{
	unordered_map<int, int> uMap;
	int len = 0;
	long long int sum = 0;

	for (int i = 0; i < A.size(); i++)
	{
		sum += A[i];
		if (sum == 0)
		{
			len = i + 1;
		}
		else if (uMap.find(sum) != uMap.end())
		{
			len = max(len, i - uMap[sum]);
		}
		else if (uMap.find(sum) == uMap.end())
		{
			uMap[sum] = i;
		}
	}

	return len;
}

vector<int> lszero(vector<int> &A)
{
	unordered_map<int, int> uMap;
	int len = 0, st = 0, end = 0;
	vector<int> ans;
	long long int sum = 0;
	bool flag = false;

	for (int i = 0; i < A.size(); i++)
	{
		sum += A[i];
		if (sum == 0)
		{
			len = i + 1;
			end = i;
			flag = true;
		}
		else if (uMap.find(sum) != uMap.end())
		{
			if (len < (i - uMap[sum]))
			{
				len = i - uMap[sum];
				end = i;
				st = uMap[sum];
				flag = false;
			}
		}
		else if (uMap.find(sum) == uMap.end())
		{
			uMap[sum] = i;
		}
	}

	int start = st + 1;
	if (flag)
	{
		start = 0;
	}

	for (size_t i = start; i <= end; i++)
	{
		ans.push_back(A[i]);
	}

	return ans;
}

// [".",".","4",".",".",".","6","3","."],
// [".",".",".",".",".",".",".",".","."],
// ["5",".",".",".",".",".",".","9","."],
// [".",".",".","5","6",".",".",".","."],
// ["4",".","3",".",".",".",".",".","1"],
// [".",".",".","7",".",".",".",".","."],
// [".",".",".","5",".",".",".",".","."]
// [".",".",".",".",".",".",".",".","."],
// [".",".",".",".",".",".",".",".","."]

// Failed
// bool isValidSudoku(vector<vector<char>> &board)
// {
// 	set<int> horizontal, vertical;

// 	for (size_t i = 0; i < board.size(); i++)
// 	{
// 		if ((board[i][0] != '.') and (!vertical.empty()) and (vertical.find(board[i][0]) != vertical.end()))
// 		{
// 			return 0;
// 		}
// 		else if (board[i][0] != '.')
// 		{
// 			vertical.insert(board[i][0]);
// 			for (size_t j = 0; j < 9; j++)
// 			{
// 				if ((board[i][j] != '.') and (!horizontal.empty()) and (horizontal.find(board[i][j]) != horizontal.end()))
// 				{
// 					return 0;
// 				}
// 				else if ((board[i][j] != '.'))
// 				{
// 					horizontal.insert(board[i][j]);
// 				}
// 			}
// 			horizontal.clear();
// 		}
// 	}

// 	horizontal.clear();
// 	vertical.clear();

// 	for (size_t i = 0; i < board.size(); i++)
// 	{
// 		for (size_t j = 0; j < 9; j++)
// 		{
// 			if ((board[j][i] != '.') and (!horizontal.empty()) and (horizontal.find(board[j][i]) != horizontal.end()))
// 			{
// 				return 0;
// 			}
// 			else if ((board[j][i] != '.'))
// 			{
// 				horizontal.insert(board[j][i]);
// 			}
// 		}
// 		horizontal.clear();
// 	}

// 	// 3 by 3
// 	unordered_map<int, pair<int, int>> uMap;
// 	for (size_t i = 0; i < board.size(); i++)
//
// 		for (size_t j = 0; j < 9; j++)
// 		{
// 			if ((board[i][j] != '.') and (uMap.find(board[i][j]) != uMap.end()))
// 			{
// 				if ((uMap[board[i][j]].first == (i / 3)) and (uMap[board[i][j]].second == (j / 3)))
// 				{
// 					return 0;
// 				}
// 			}
// 			else if ((board[i][j] != '.'))
// 			{
// 				uMap.insert({board[i][j], {i / 3, j / 3}});
// 			}
// 		}
// 	}

// 	return 1;
// }

// O(N*2) O(N)
bool isValidSudoku(vector<vector<char>> &board)
{
	unordered_set<string> seen;

	for (size_t i = 0; i < board.size(); i++)
	{
		for (size_t j = 0; j < 9; j++)
		{
			if (board[i][j] != '.')
			{
				// For char if it is in the row so I will add R + char + row_Number
				string row = "R" + string(board[i][j], 1) + to_string(i);

				// For a char  it is in the column so I will add C + char + column_Number
				string col = "C" + string(board[i][j], 1) + to_string(j);

				// For char if it is in the 3 * 3 box so I will add R + char+ box_Number
				string box = "B" + string(board[i][j], 1) + to_string(((i / 3) * 3)) + to_string((j / 3));

				// if row or col or box string is found then it is not a valid Sudoku
				if ((seen.find(row) != seen.end()) or (seen.find(col) != seen.end()) or (seen.find(box) != seen.end()))
				{
					return false;
				}
				else
				{
					seen.insert(row);
					seen.insert(col);
					seen.insert(box);
				}
			}
		}
	}

	return true;
}

// Window String
string minWindow(string A, string B)
{
	if (A.length() < B.length())
	{
		return "";
	}

	unordered_map<int, int> uMap;
	int len = INT_MAX, ptr1 = 0, ptr2 = 0, startInd = 0, count = B.length();

	for (auto &&i : B)
	{
		uMap[i]++;
	}

	while (ptr2 < A.length())
	{
		if (uMap[A[ptr2++]]-- > 0)
		{
			--count;
		}

		while ((count == 0) and (ptr1 < A.length()))
		{
			if (ptr2 - ptr1 < len)
			{
				len = ptr2 - ptr1, startInd = ptr1;
			}

			if (uMap[A[ptr1++]]++ == 0)
			{
				++count;
			}
		}
	}

	return len == INT_MAX ? "" : A.substr(startInd, len);
}

// Longest Substring Without Repeating Characters
int lengthOfLongestSubstring(string s)
{
	if (s.empty())
	{
		return 0;
	}

	int ptr1 = 0, len = 1, ptr2 = 0;
	unordered_set<char> seen;

	while ((ptr1 < s.length()) and (ptr2 < s.length()))
	{
		if (seen.find(s[ptr2]) == seen.end())
		{
			seen.insert(s[ptr2++]);
		}
		else
		{
			while ((seen.find(s[ptr2]) != seen.end()) and (ptr1 < s.length()))
			{
				seen.erase(s[ptr1++]);
			}
		}
		len = max(len, ptr2 - ptr1);
	}

	return len;
}

// Fraction
// O(N)
string fractionToDecimal(int numerator, int denominator)
{
	string result = "";
	if (numerator == 0)
	{
		return "0";
	}

	if (denominator == 0)
	{
		return "";
	}

	if ((numerator < 0) ^ (denominator < 0))
	{
		result += "-";
	}

	long num = abs(numerator), den = abs(denominator);
	long res = num / den;
	result += to_string(res);

	long rem = (num % den) * 10;

	if (rem == 0)
	{
		return result;
	}

	unordered_map<long, int> uMap;
	result += ".";

	while (rem != 0)
	{
		if (uMap.find(rem) != uMap.end())
		{
			int beg = uMap[rem];
			string part1 = result.substr(0, beg);
			string part2 = result.substr(beg, result.length() - beg);
			result = part1 + "(" + part2 + ")";
			return result;
		}
		uMap[rem] = result.length();
		res = rem / den;
		result += to_string(res);
		rem = (rem % den) * 10;
	}

	return result;
}


int main()
{
	vector<int> A = {1, 2, -3, 3};
	// cout << minWindow("ADOBECODEBANC", "ABC") << endl
	cout << fractionToDecimal(2, 3) << endl;
	// cout << floorSqrt(930675566) << endl;
	// for (auto &&i : lszero(A))
	// {
	// 	cout << i << ",";
	// }

	return 0;
}
