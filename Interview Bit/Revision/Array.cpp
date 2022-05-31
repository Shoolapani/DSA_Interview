#include <bits/stdc++.h>
using namespace std;

int solve1(vector<int> &A, int B)
{
    int sum = 0, maxSum = 0;

    for (int i = 0; i < B; i++)
    {
        sum += A[i];
    }
    maxSum = sum;

    int i = 0, j = A.size() - 1;
    while ((B--))
    {
        sum -= A[i++];
        sum += A[j--];
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int coverPoints(vector<int> &A, vector<int> &B)
{
    int ans = 0;

    for (size_t i = 1; i < A.size(); i++)
    {
        ans += max(A[i - 1] - A[i], B[i - 1] - B[i]);
    }

    return ans;
}

int Solution(vector<int> &A, int B)
{
    
}

int main()
{
    return 0;
}