#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std::chrono;
using namespace std;

// Zigzag Conversion
// O(N)
string convert(string s, int numRows)
{
    if (numRows == 1)
    {
        return s;
    }
    string ans = "";
    int val = (numRows - 1) * 2;

    for (size_t row = 0; row < numRows; row++)
    {
        for (size_t i = row; i < s.length(); i += val)
        {
            ans += s[i];
            if ((row > 0) && (row < numRows - 1) && ((i + val - (2 * row)) < s.length()))
            {
                ans += s[i + val - (2 * row)];
            }
        }
    }

    return ans;
}

int main()
{
    return 0;
}