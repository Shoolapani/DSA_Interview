#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    if (intervals.size() == 0)
    {
        return ans;
    }
    sort(intervals.begin(), intervals.end());
    vector<int> ds = intervals[0];
    for (auto &&it : intervals)
    {
        if (it[0] <= ds[1])
        {
            ds[1] = max(ds[1], it[1]);
        }
        else
        {
            ans.push_back(ds);
            ds = it;
        }
    }
    ans.push_back(ds);
    return ans;
}

double myPow(double x, int n)
{
    double ans = 1.0;
    long long int nn;
    if (n < 0)
    {
        nn = (-1) * (n);
    }

    while (nn)
    {
        if (nn % 2)
        {
            ans = ans * x;
            nn -= 1;
        }
        else
        {
            x = x * x;
            nn = nn / 2;
        }
    }
    if (n < 0)
    {
        ans = (double)(1.0) / (double)(ans);
    }
    return ans;
}

// int reversePairs(vector<int> &nums)
// {
// }

int mergeAll(long long *arr, int begin, int mid, int end)
{
    int total = 0;

    return total;
}

int merge(long long *arr, int begin, int end)
{
    int cnt = 0;
    if (begin < end)
    {
        int mid = (begin + (end - begin) / 2);
        cnt += merge(arr, begin, mid);
        cnt += merge(arr, mid + 1, begin);
        cnt += mergeAll(arr, begin, mid, end);
    }
    return cnt;
}

long long getInversions(long long *arr, int n)
{
    long long int ans{0};
    ans = merge(arr, 0, n - 1);

    return ans;
}

int main()
{
    return 0;
}