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


int main()
{
    cout << reverse(3) << endl;
    return 0;
}