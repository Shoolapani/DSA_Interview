// Count number of bits to be flipped
// to convert A into B
#include <iostream>
using namespace std;

// Function that count set bits
int countSetBits(int n)
{
    int count = 0;
    // while (n > 0)
    // {
    //     count++;
    //     int b = n - 1;
    //     n &= (n - 1);
    // }

    for (int i = 31; i >= 0; i--)
    {
        if ((n >> i) & 1)
        {
            ++count;
        }
    }

    return count;
}

// Function that return count of
// flipped number
int FlippedCount(int a, int b)
{
    // Return count of set bits in
    // a XOR b
    return countSetBits(a ^ b);
}

// Driver code
int main()
{
    int a = 10;
    int b = 20;
    cout << FlippedCount(2, 4) << endl;
    return 0;
}
