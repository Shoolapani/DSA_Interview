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

int divide(int dividend, int divisor)
{
    if ((dividend == INT_MIN) && (divisor == -1))
    {
        return INT_MAX;
    }

    int a = abs(dividend), b = abs(divisor);
    int res = 0;

    while ((a - b) >= 0)
    {
        int x = 0;
        while ((a - (b << x << 1)) >= 0)
        {
            ++x;
        }
        res += (1 << x);
        a -= (b << x);
    }

    return (dividend > 0) == (divisor > 0) ? (res) : (-res);
}

int divide2(int A, int B)
{
    if (A == INT_MIN && B == -1)
        return INT_MAX;
    int a = abs(A), b = abs(B), res = 0, x = 0;
    while (a - b >= 0)
    {
        for (x = 0; a - (b << x << 1) >= 0; x++)
            ;
        res += 1 << x;
        a -= b << x;
    }
    return (A > 0) == (B > 0) ? res : -res;
}

int swapBits(int x, int p1, int p2, int n)
{
    unsigned int a = (x >> p1) & ((1U << n) - 1);
    bitset<8> bit_a(a);
    cout << "a: " << bit_a << endl;
    unsigned int b = (x >> p2) & ((1U << n) - 1);
    bitset<8> bit_b(b);
    cout << "b: " << bit_b << endl;
    unsigned int c = a ^ b;
    bitset<8> bit_c(c);
    cout << "c: " << bit_c << endl;
    c = (c << p1) | (c << p2);
    bitset<8> bit_d(c);
    cout << "c: " << bit_d << endl;
    int ans = x ^ c;
    return ans;
}

// Swap Bits
int solveBits(int A, int B, int C)
{
    // unsigned int a = (A >> B) & ((1U << 1) - 1);
    // bitset<8> bit_a(a);
    // cout << "a: " << bit_a << endl;
    // unsigned int b = (A >> C) & ((1U << 1) - 1);
    // bitset<8> bit_b(b);
    // cout << "b: " << bit_b << endl;
    // unsigned int c = a ^ b;
    // bitset<8> bit_c(c);
    // cout << "c: " << bit_c << endl;
    // c = (c << B) | (c << C);
    // bitset<8> bit_d(c);
    // cout << "c: " << bit_d << endl;
    bitset<8> bit_a(A);
    // cout << "a: " << bit_a << endl;
    // int flag1 = 0, flag2 = 0;
    if (A & (1 << B))
    {
        flag1 = 1;
    }

    if (A & (1 << C))
    {
        flag2 = 1;
    }

    if (flag1 && flag2)
    {
        return A;
    }

    unsigned int ans = A | (flag1 << B);
    // bitset<8> bit_as(ans);
    // cout << "ans: " << bit_as << endl;
    ans = A | (flag2 << C);

    return ans;
}

// XOR-ing the Subarrays!
int solve(vector<int> &A)
{
    int res = 0;

    for (size_t i = 0; i < A.size(); i++)
    {
        int freq = (i + 1) * (A.size() - i);

        if (freq & 1)
        {
            res = res ^ A[i];
        }
    }

    return res;
}

bool findPair(vector<int> &A, int B)
{
    sort(A.begin(), A.end());
    int i = 0, j = 1;

    while (i <= j)
    {
        if ((i != j) && ((A[j] - A[i] == B) || (A[i] - A[j] == B)))
        {
            return 1;
        }

        if ((A[j] - A[i]) <= B)
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

    // cout << solve(11) << endl;
    int x = 47, P1 = 1,
        P2 = 5,
        N = 3;
    // cout << swapBits(x, P1, P2, N) << endl;
    cout << solveBits(8, 1, 3) << endl;

    return 0;
}