#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std::chrono;
using namespace std;

// Total Moves For Bishop!
int solveBishop(int A, int B)
{
    int i = A, j = B;
    int count = 0, sum = 0;

    while ((i >= 1) && (j >= 1))
    {
        ++count;
        --i, --j;
    }
    count -= 1;
    sum += count;
    count = 0;
    i = A, j = B;

    while ((i <= 8) && (j >= 1))
    {
        ++count;
        ++i, --j;
    }
    count -= 1;

    sum += count;
    count = 0;
    i = A, j = B;

    while ((i >= 1) && (j <= 8))
    {
        ++count;
        --i, ++j;
    }
    count -= 1;
    sum += count;
    count = 0;
    i = A, j = B;

    while ((i <= 8) && (j <= 8))
    {
        ++count;
        ++i, ++j;
    }
    count -= 1;

    sum += count;
    count = 0;

    return sum;
}

int solveBishop2(int A, int B)
{
    int count = 0, sum = 0;
    int i = A, j = B;
    // TL
    sum += min(A - 1, B - 1);
    // TR
    sum += min((A - 1), 8 - (B));
    // BL
    sum += min(8 - A, (B - 1));
    // BR
    sum += min(8 - (A), 8 - (B));

    return sum;
}

// Step by Step
int solveStep(int A)
{
    int sum = 0, ind = 0;
    A = abs(A);

    while (sum < A)
    {
        ++ind;
        sum += ind;
    }

    while ((sum - A) % 2 != 0)
    {
        ++ind;
        sum += ind;
    }

    return ind;
}

// Power Of Two Integers
int isPower(int n)
{
    float p;
    if (n <= 1)
        return 1;
    for (size_t i = 2; i <= sqrt(n); i++)
    {
        p = log2(n) / log2(i);
        if ((ceil(p) == floor(p)) && p > 1)
            return true;
    }

    return 0;
}

// FizzBuzz
vector<string> fizzBuzz(int A)
{
    vector<string> ans;
    for (int i = 1; i <= A; i++)
    {
        if ((i % 3 == 0) && (i % 5 == 0))
        {
            ans.push_back("FizzBuzz");
        }
        else if ((i % 3 == 0))
        {
            ans.push_back("Fizz");
        }
        else if ((i % 5 == 0))
        {
            ans.push_back("Buzz");
        }
        else
        {
            ans.push_back(to_string(i));
        }
    }
    return ans;
}

// Excel Column Title
char intToAlphabet(int i)
{
    return static_cast<char>('A' - 1 + i);
}

string convertToTitle(int A)
{
    string ans;

    while (A)
    {
        int t = A % 26;
        if (t == 0)
        {
            ans = "Z" + ans;
            A /= 26;
            A -= 1;
        }
        else
        {
            char c = 'A' + t - 1;
            A /= 26;
            ans = c + ans;
        }
    }

    return ans;
}

// Find Nth Fibonacci
int solveFibonacci1(int A)
{
    int a = 0, b = 1, ans = 0;

    for (long long int i = 2; i <= A + 1; i++)
    {
        ans = a + b;
        b = a;
        a = ans;
    }

    return a;
}

int solveFibonacci(int A)
{
    if (A <= 2)
    {
        return 1;
    }

    vector<vector<int>> v(2, vector<int>(2, 0));
    v = {{1, 1}, {1, 0}};

    return v[0][0];
}

int main()
{
    // cout << convertToTitle(943566) << endl;
    cout << solveFibonacci(9 + 1) << endl;
    // BAQTZ
    return 0;
}