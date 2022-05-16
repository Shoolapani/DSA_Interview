#include <bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono;

static int oddNum = 0, evenNum = 0;

int evenSum(int st, int end)
{
    for (int i = st; i <= end; i++)
    {
        if ((i & 1) == 0)
        {
            evenNum += i;
        }
    }
    return evenNum;
}

void oddSum(int st, int end)
{
    for (int i = st; i <= end; i++)
    {
        if ((i & 1) == 1)
        {
            oddNum += i;
        }
    }
    return;
}

int main()
{
    int st = 0, end = 1000;
    auto startTime = high_resolution_clock::now();

    std::thread worker1(evenSum, st, end);
    std::thread worker2(oddSum, st, end);
    worker1.join();
    worker2.join();

    // evenSum(st, end);
    // oddSum(st, end);

    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime - startTime);

    cout << "Even no " << evenNum << endl;
    cout << "odd no " << oddNum << endl;

    return 0;
}