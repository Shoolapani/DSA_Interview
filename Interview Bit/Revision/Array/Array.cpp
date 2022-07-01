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

// int Solution(vector<int> &A, int B)
// {
// }

int repeatedNumber(const vector<int> &A)
{
    int num1 = 0, num2 = 0, count1 = 0, count2 = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        if (num1 == A[i])
        {
            ++count1;
        }
        else if (num2 == A[i])
        {
            ++count2;
        }
        else if (count1 <= 0)
        {
            num1 = A[i];
            count1 = 1;
        }
        else if (count2 <= 0)
        {
            num2 = A[i];
            count2 = 1;
        }
        else
        {
            --count1;
            --count2;
        }
    }

    count1 = 0, count2 = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        if (num1 == A[i])
        {
            ++count1;
        }
        if (num2 == A[i])
        {
            ++count2;
        }
    }

    if (count1 > A.size() / 3)
    {
        return num1;
    }

    if (count2 > A.size() / 3)
    {
        return num2;
    }

    return -1;
}

vector<int> repeatedNumber2(const vector<int> &A)
{
    int x = 0, y = 0, xORy = 0;
    vector<int> ans;
    for (auto &&i : A)
    {
        xORy ^= i;
    }

    for (size_t i = 1; i <= A.size(); i++)
    {
        xORy ^= i;
    }

    int set_bit = xORy & ~(xORy - 1);

    for (auto &&i : A)
    {
        if (i & set_bit)
        {
            x ^= i;
        }
        else
        {
            y ^= i;
        }
    }

    for (size_t i = 1; i <= A.size(); i++)
    {
        if (i & set_bit)
        {
            x ^= i;
        }
        else
        {
            y ^= i;
        }
    }

    bool flag = false;
    for (auto &&i : A)
    {
        if (i == x)
        {
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        ans.push_back(x);
        ans.push_back(y);
    }
    else
    {
        ans.push_back(y);
        ans.push_back(x);
    }

    return ans;
}

int firstMissingPositive(vector<int> &A)
{
    for (size_t i = 0; i < A.size(); i++)
    {
        if ((A[i] > 0) && (A[i] <= A.size()))
        {
            if (A[i] != A[A[i] - 1])
            {
                swap(A[i], A[A[i] - 1]);
                --i;
            }
        }
    }

    for (size_t i = 0; i < A.size(); i++)
    {
        if (i + 1 != A[i])
        {
            return i + 1;
        }
    }

    return A.size() + 1;
}

// Maximum Sum Square SubMatrix
int solve(vector<vector<int>> &A, int B)
{
    vector<vector<int>> ds(A.size());
    int maxSum = INT_MIN;

    for (size_t i = 0; i < A.size(); i++)
    {
        int sum = 0, ind = 0;
        for (size_t j = 0; j < A.size(); j++)
        {
            sum += A[i][j];
            if ((j - ind + 1) == B)
            {
                ds[i].push_back(sum);
                sum -= A[i][ind];
                ++ind;
            }
        }
    }

    for (size_t i = 0; i < ds[0].size(); i++)
    {
        int sum = 0, ind = 0;
        for (size_t j = 0; j < ds.size(); j++)
        {
            sum += ds[j][i];
            if ((j - ind + 1) == B)
            {
                cout << sum << endl;
                maxSum = max(maxSum, sum);
                sum -= ds[ind][i];
                ++ind;
            }
        }
    }
    cout << endl;
    return maxSum;
}

int main()
{
    vector<vector<int>> A(5, vector<int>(5, 0));
    A = {{1, 1, 1, 1, 1}, {2, 2, 2, 2, 2}, {3, 8, 6, 7, 3}, {4, 4, 4, 4, 4}, {5, 5, 5, 5, 5}};
    cout << solve(A, 3) << endl;
    return 0;
}