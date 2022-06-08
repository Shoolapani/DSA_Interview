#include <bits/stdc++.h>
using namespace std;

// Number of 1 Bits
// Machine Dependent and slow also 😒😒
int hammingWeight(uint32_t n)
{
    int count = 0;
    for (int i = 32 - 1; i >= 0; i--)
    {
        if ((n >> i) & 1)
        {
            ++count;
        }
    }
    return count;
}

// Best Code
int hammingWeight2(uint32_t n)
{
    int count = 0;
    cout << n << "\t";

    while (n != 0)
    {
        n = n & (n - 1);
        cout << n << "\t";
        ++count;
    }

    return count;
}

unsigned int reverseBits(unsigned int n)
{
    unsigned int rev = 0;
    // cout << n << "\t";

    // traversing bits of 'n' from the right
    while (n > 0)
    {
        // bitwise left shift
        // 'rev' by 1
        rev <<= 1;
        // cout << "rev " << rev << "\n";
        // cout << "n " << n << "\t";

        // if current bit is '1'
        if (n & 1 == 1)
            rev ^= 1;

        // bitwise right shift
        // 'n' by 1
        n >>= 1;
    }

    // required number
    return rev;
}

unsigned int reverseBits2(unsigned int n)
{
    unsigned int rev = 0;
    bool flag = 0;
    int j = 0;

    for (int i = 32 - 1; i >= 0; i--)
    {

        if ((n >> i) & 1)
        {
            int setMask = (1 << j);
            rev |= setMask;
        }
        ++j;
    }

    return rev;
}

int singleNumber(const vector<int> &A)
{
    int ones = 0, twos = 0;

    for (auto &&it : A)
    {
        ones = (ones ^ it) & (~twos);
        twos = (twos ^ it) & (~ones);
    }

    return ones;
}

// Min XOR value
// O(NlogN)
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

// Count Total Set Bits
// O(N)
const long int mod = 1000000007;

int largestPowerOf2InRange(int A)
{
    int power = 0;

    while ((1 << power) <= A)
    {
        ++power;
    }

    return power - 1;
}

int solveSet(int A)
{
    if (A == 0)
    {
        return 0;
    }
    long long int ans = 0;
    long long int x = largestPowerOf2InRange(A);

    long long int bitsUpto2RaiseX = x * (1 << (x - 1));
    long long int msbFrom2 = A - (1 << x) + 1;
    long long int rest = A - (1 << x);

    ans = bitsUpto2RaiseX + msbFrom2 + (solveSet(rest));
    return ans % mod;
}

int solve(int A)
{
    int x = 1;
    while (x <= A)
    {
        x <<= 1;
    }
    x--;
    return (x ^ A);
}

int main()
{
    // cout << hammingWeight2(15) << endl;
    // cout << reverseBits(18) << endl;
    // cout << reverseBits2(3) << endl;
    // int a = 0;
    // int A = 5;
    // // cout << ~a << endl;

    // int h = 0;
    // for (h = 32 - 1; h >= 0; h--)
    // {
    //     if ((A >> h) & 1)
    //     {
    //         break;
    //     }
    // }
    // // ++h;

    // for (size_t i = 0; i <= h; i++)
    // {
    //     if (!(A & (1 << i)))
    //     {
    //         a |= (1 << i);
    //     }
    // }

    cout << solve(11) << endl;

    return 0;
}