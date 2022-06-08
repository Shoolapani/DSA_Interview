#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std::chrono;
using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

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

vector<vector<long long int>> multiply(vector<vector<long long int>> v, vector<vector<long long int>> v2)
{
    vector<vector<long long int>> ds(2, vector<long long int>(2, 0));
    int mod = pow(2, 10) + 7;
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            int ans = 0;
            for (size_t k = 0; k < 2; k++)
            {
                ans += (((v[i][k] % mod) * (v2[k][j] % mod)) % mod);
            }
            ds[i][j] = ans;
        }
    }
    return ds;
}

int solveFibonacci(int A)
{
    if (A <= 2)
    {
        return 1;
    }

    vector<vector<long long int>> v(2, vector<long long int>(2, 0)), v2, ans(2, vector<long long int>(2, 0));
    v = {{1, 1}, {1, 0}};
    v2 = v;
    ans = {{1, 0}, {0, 1}};
    --A;
    while (A)
    {
        if (A % 2 == 0)
        {
            v = multiply(v, v);
            A /= 2;
        }
        else
        {
            ans = multiply(ans, v);
            A -= 1;
        }
    }

    return ans[0][0];
}

vector<vector<long long int>> multiply1(vector<vector<long long int>> v1, vector<vector<long long int>> v2)
{
    int mod = pow(10, 9) + 7;
    vector<vector<long long int>> temp(2, vector<long long int>(2));
    temp[0][0] = ((v1[0][0] * v2[0][0]) % mod + (v1[0][1] * v2[1][0]) % mod) % mod;
    temp[0][1] = ((v1[0][0] * v2[0][1]) % mod + (v1[0][1] * v2[1][1]) % mod) % mod;
    temp[1][0] = ((v1[1][0] * v2[0][0]) % mod + (v1[1][1] * v2[1][0]) % mod) % mod;
    temp[1][1] = ((v1[1][0] * v2[0][1]) % mod + (v1[1][1] * v2[1][1]) % mod) % mod;
    return temp;
}
vector<vector<long long int>> helper(vector<vector<long long int>> &v, int n)
{
    if (n == 1)
        return v;
    vector<vector<long long int>> temp = helper(v, n / 2);
    vector<vector<long long int>> ans = multiply(temp, temp);
    if (n & 1)
        return multiply(ans, v);
    return ans;
}
int solve(int A)
{
    int n = A;
    vector<vector<long long int>> v = {{1, 1}, {1, 0}};
    vector<vector<long long int>> ans = helper(v, A);
    return ans[0][1];
}

void arrange2(vector<int> &A)
{
    vector<int> a1 = A;

    for (size_t i = 0; i < A.size(); i++)
    {
        A[i] = a1[a1[i]];
    }
}

void arrange(vector<int> &A)
{
    int n = A.size();

    for (size_t i = 0; i < A.size(); i++)
    {
        A[i] = (A[i] + ((A[A[i]] % n) * (n)));
    }

    for (size_t i = 0; i < A.size(); i++)
    {
        A[i] /= n;
    }
}

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
{
    vector<Interval> ans;
    bool flag = 1;
    for (auto &&it : intervals)
    {
        if (it.end < newInterval.start)
        {
            ans.push_back(it);
        }
        else if (it.start > newInterval.end)
        {
            if (flag)
            {
                ans.push_back(newInterval);
            }
            flag = 0;
            ans.push_back(it);
        }
        else
        {
            newInterval.start = min(newInterval.start, it.start);
            newInterval.end = max(newInterval.end, it.end);
        }
    }
    if (flag)
    {
        ans.push_back(newInterval);
    }

    return ans;
}

void mergeSort(vector<int> &A, int begin, int mid, int end)
{
    vector<int> ans;
    int i = begin, j = mid;
    string s1 = "", s2 = "";

    while ((i < mid) && (j <= end))
    {
        s1 = "", s2 = "";
        s1 += to_string(A[i]), s2 += to_string(A[j]);
        s2 += to_string(A[i]), s1 += to_string(A[j]);
        if (s1 >= s2)
        {
            ans.push_back(A[i]);
            ++i;
        }
        else
        {
            ans.push_back(A[j]);
            ++j;
        }
    }

    while ((i < mid))
    {
        ans.push_back(A[i]);
        ++i;
    }

    while (j <= end)
    {
        ans.push_back(A[j]);
        ++j;
    }

    for (size_t i = 0; i < ans.size(); i++)
    {
        A[begin + i] = ans[i];
    }

    return;
}

void merge(vector<int> &A, int begin, int end)
{
    if (begin < end)
    {
        int mid = (begin + (end - begin) / 2);
        merge(A, begin, mid);
        merge(A, mid + 1, end);
        mergeSort(A, begin, mid + 1, end);
    }
    return;
}

string largestNumber(const vector<int> &A)
{
    vector<int> k = A;
    string ans = "";
    merge(k, 0, A.size() - 1);
    for (auto &&i : k)
    {
        ans += to_string(i);
    }
    int i = 0;
    bool flag = true;
    for (i = 0; i < ans.length(); i++)
    {
        if (ans[i] != '0')
        {
            flag = 0;
        }
    }
    if (flag)
    {
        ans = "0";
    }
    return ans;
}
// 1, 1, 0, 0, 1, 1
int solveLight(vector<int> &A, int B)
{
    int a = 0, c = 0, i = 0;
    int ans = 0;
    int n = A.size();
    bool flag = 1;

    while ((i < A.size()))
    {
        a = max(0, i - B + 1);
        c = min(n - 1, i + B - 1);
        flag = 1;
        while (c >= a)
        {
            if (A[c])
            {
                flag = false;
                ++ans;
                i = c + B;
                break;
            }
            --c;
        }
        if (flag)
        {
            return -1;
        }
    }
    return ans;
}

int solve(int A, vector<int> &B)
{
    vector<int> prefix, suffix;
    int ans = 0;
    int sum = 0, currSum = 0;

    for (auto &&i : B)
    {
        sum += i;
    }
    if (sum % 3 != 0)
    {
        return 0;
    }
    sum = sum / 3;

    for (size_t i = 0; i < B.size(); i++)
    {
        currSum += B[i];
        if (currSum == sum)
        {
            prefix.push_back(i);
        }
    }

    currSum = 0;
    for (int i = B.size() - 1; i >= 0; i--)
    {
        currSum += B[i];
        if (currSum == sum)
        {
            suffix.push_back(i);
        }
    }

    for (size_t i = 0; i < prefix.size(); i++)
    {
        int x = 0;
        bool flag = 0;
        for (size_t j = 0; j < suffix.size(); j++)
        {
            for (size_t k = prefix[i] + 1; k < suffix[j]; k++)
            {
                x += B[k];
                flag = 1;
            }
            if ((x == sum) && (flag))
            {
                ++ans;
            }
        }
    }
    return ans;
}

vector<int> subUnsort(vector<int> &A)
{
    int i = 0, right = A.size() - 2;
    vector<int> ans(2, 0);

    for (i = 1; i < A.size(); i++)
    {
        if (A[i] < A[i - 1])
        {
            --i;
            break;
        }
    }

    if (i == A.size())
    {
        ans.clear();
        ans.push_back(-1);
        return ans;
    }

    for (right; right >= 0; right--)
    {
        if (A[right] > A[right + 1])
        {
            ++right;
            break;
        }
    }

    int maxEle = 0, minEle = INT_MAX;
    for (size_t j = i; j <= right; j++)
    {
        minEle = min(minEle, A[j]);
        maxEle = max(maxEle, A[j]);
    }

    int t_i = i - 1, t_right = right + 1;

    while (t_i >= 0)
    {
        if (A[t_i] > minEle)
        {
            --t_i;
        }
        else
        {
            break;
        }
    }

    while (t_right < A.size())
    {
        if (A[t_right] < maxEle)
        {
            ++t_right;
        }
        else
        {
            break;
        }
    }
    ans[0] = t_i + 1;
    ans[1] = t_right - 1;

    return ans;
}

vector<int> flip(string A)
{
    vector<int> ans, arr(A.size(), 0);
    bool flag = 1;

    for (size_t i = 0; i < A.size(); i++)
    {
        if (A[i] == '1')
        {
            arr[i] = -1;
        }
        else
        {
            flag = 0;
            arr[i] = 1;
        }
    }

    if (flag)
    {
        return ans;
    }
    ans.resize(2);

    int sum = 0, currSum = 0;
    int left = 0, right = 0;

    for (size_t i = 0; i < A.size(); i++)
    {
        currSum += arr[i];
        if (currSum < 0)
        {
            left = i + 1;
            currSum = 0;
        }

        if (currSum > sum)
        {
            sum = currSum;
            right = i;
            ans[0] = left + 1;
            ans[1] = right + 1;
        }
        +right;
    }

    return ans;
}

int trailingZeroes(int A)
{
    int count = 0;

    while (A / 5 > 0)
    {
        count += (A / 5);
        A /= 5;
    }

    return count;
}

// O(N! * N) -> O(N^2) -> O(nlog n)
const long int mod = 1000003;

int findRank(string A)
{
    int rank = 0;
    vector<long long int> fact(26, 1);
    vector<int> s;

    // fact
    for (size_t i = 1; i < 26; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
    }

    for (auto &&i : A)
    {
        s.push_back(i - 'a');
    }

    sort(s.begin(), s.end());
    for (size_t i = 0; i < A.length(); i++)
    {
        int x = lower_bound(s.begin(), s.end(), (A[i] - 'a')) - s.begin();
        s.erase(s.begin() + x, s.begin() + x + 1);
        int ans1 = (fact[A.length() - 1 - i] * (x)) % mod;
        rank = (rank + ans1) % mod;
    }

    return (rank + 1) % mod;
}

int gcd(int a, int b)
{
    return (b == 0) ? (a) : gcd(b, (a % b));
}

int cpFact(int A, int B)
{
    int i = 1, m = 0;
    for (i = 1; i <= A; i++)
    {
        if ((A % i == 0) && (__gcd(i, B) == 1))
        {
            m = max(i, m);
        }
    }
    return m;
}

int cpFact(int x, int y)
{
    while (gcd(x, y) != 1)
    {
        x = x / gcd(x, y);
    }
    return x;
}

int main()
{
    // cout << convertToTitle(943566) << endl;
    cout << cpFact(30, 12) << endl;
    // vector<int> A = {4, 0, 2, 1, 3};
    // arrange(A);
    // for (auto &&i : A)
    // {
    //     cout << i << ",";
    // }
    return 0;
}