#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std::chrono;
using namespace std;

int numSetBits(unsigned int A)
{
    int count = 0;

    while ((A))
    {
        A = A & (A - 1);
        ++count;
    }

    return count;
}

// Reverse Bits
unsigned int reverse(unsigned int A)
{
    unsigned int ans = 0;

    for (size_t i = 0; i < 32; i++)
    {
        if (A & (1 << i))
        {
            ans |= (1 << (31 - i));
        }
    }

    return ans;
}

// Single Number II
int singleNumber(const vector<int> &A)
{
    int ones = 0, twoS = 0;

    for (auto &&it : A)
    {
        ones = (ones ^ it) & (~twoS);
        twoS = (twoS ^ it) & (~ones);
    }

    return ones;
}

// Min XOR value
int findMinXor(vector<int> &A)
{
    int ans = INT_MAX;

    sort(A.begin(), A.end());
    int val = 0;

    for (size_t i = 0; i < A.size() - 1; i++)
    {
        val = A[i] ^ A[i + 1];
        ans = min(ans, val);
    }
    return ans;
}

// XOR-ing the Subarrays!
int solve(vector<int> &A)
{
    int freq = 0, ans = 0;

    for (size_t i = 0; i < A.size(); i++)
    {
        freq = (i + 1) * (A.size() - i);
        if (freq & 1)
        {
            ans ^= A[i];
        }
    }

    return ans;
}

int main()
{
    cout << reverse(3) << endl;
    return 0;
}