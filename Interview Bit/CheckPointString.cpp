#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std::chrono;
using namespace std;

int numRange(vector<int> &A, int B, int C)
{
    int i = 0, j = 0, sum = 0, count = 0;
    while (i < A.size())
    {
        sum += A[j];
        if ((sum >= B) && (sum <= C))
        {
            ++count;
            ++j;
        }
        else if (sum < B)
        {
            ++j;
        }
        else if (sum > C)
        {
            ++i;
            sum = 0;
            j = i;
        }

        if (j == A.size())
        {
            ++i;
            sum = 0;
            j = i;
        }
    }
    return count;
}

int main()
{
    vector<int> A = {10, 5, 1, 0, 2};
    cout << numRange(A, 6, 10) << endl;
    return 0;
}