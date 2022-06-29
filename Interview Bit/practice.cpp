#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

int solve4(vector<int> &a, int B)
{
    int ans = 0, sum = 0, n1 = a.size();
    for (size_t i = 0; i < B; i++)
    {
        sum += a[i];
    }
    ans = max(ans, sum);
    sum = 0;
    int k = B;
    for (size_t i = n1 - 1; i >= 0; i--)
    {
        if (k < 0)
        {
            break;
        }
        --k;
        sum += a[i];
    }
    ans = max(ans, sum);
    sum = 0;
    int t = B - 1;

    while (t > 0)
    {
        for (size_t i = 0; i < t; i++)
        {
            sum += a[i];
        }
        int k = B - t;
        for (size_t i = n1 - 1; i >= 0; i--)
        {
            if (k < 0)
            {
                break;
            }
            --k;
            sum += a[i];
        }
        ans = max(ans, sum);
        sum = 0;
        --t;
    }
    return ans;
}

int fun(vector<int> &A, int B)
{
    int n = A.size();
    int suff[n + 1];
    suff[n] = 0;
    suff[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suff[i] = A[i] + suff[i + 1];
    int prefSum = 0;
    int ans = suff[n - B];
    for (int i = 0; i < B; i++)
    {
        prefSum = prefSum + A[i];
        int suffSum = suff[n - B + (i + 1)];
        ans = max(ans, prefSum + suffSum);
    }
    return ans;
}

int solve2(vector<int> &A, int B)
{
    return fun(A, B);
}

int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        ans ^= nums[i];
    }
    return ans;
}

vector<string> summaryRanges(vector<int> &nums)
{
    vector<string> ans;
    string temp = "";

    for (size_t i = 0; i < nums.size(); i++)
    {
        int j = i;
        temp = "";
        while ((j + 1 < nums.size()) && (nums[j + 1] == nums[j] + 1))
        {
            ++j;
        }

        if (j > i)
        {
            temp += to_string(nums[i]);
            temp += "->";
            temp += to_string(nums[j]);
        }
        else
        {
            temp += to_string(nums[i]);
        }
        ans.push_back(temp);
        i = j;
    }

    return ans;
}

vector<string> summaryRanges2(vector<int> &arr)
{
    int n = arr.size(); // extracting size of the array
    vector<string> ans; // declaring answer array to store our answer

    string temp = ""; // temproray string that stores all possible answer

    for (int i = 0; i < n; i++) // start traversing from the array
    {
        int j = i; // declare anthor pointer that will move

        // run that pointer until our range is not break
        while (j + 1 < n && arr[j + 1] == arr[j] + 1)
        {
            j++;
        }

        // if j > i, that means we got our range more than one element
        if (j > i)
        {
            temp += to_string(arr[i]); // first store starting point
            temp += "->";              // then store arrow, as question wants it
            temp += to_string(arr[j]); // and lastly store the end point
        }
        else // we got only one element as range
        {
            temp += to_string(arr[i]); // then store that element in temp
        }

        ans.push_back(temp); // push one possible answer string to our answer
        temp = "";           // again reintiliaze temp for new possible answers
        i = j;               // and move i to j for a fresh start
    }

    return ans; // and at last finally return the answer array
}

int merge(vector<int> &nums, int begin, int mid, int end)
{
    int count = 0;
    vector<int> ans;

    int i = begin, j = mid;
    while ((i < mid) && (j <= end))
    {
        if (nums[i] > nums[j])
        {
            ans.push_back(nums[j++]);
        }
        else
        {
            if (nums[i] == nums[j])
            {
                ++count;
            }
            ans.push_back(nums[i++]);
        }
    }

    while ((i < mid))
    {
        ans.push_back(nums[i++]);
    }
    while ((j <= end))
    {
        ans.push_back(nums[j++]);
    }

    for (size_t k = 0; k < ans.size(); k++)
    {
        nums[k + begin] = ans[k];
    }

    return count;
}

int mergeSort(vector<int> &nums, int begin, int end)
{
    int mid = (end + (end - begin) / 2);
    int ans = 0;
    if (begin < end)
    {
        ans += mergeSort(nums, begin, mid);
        ans += mergeSort(nums, mid + 1, end);
        ans += merge(nums, begin, mid + 1, end);
    }
    return ans;
}

int numIdenticalPairs(vector<int> &nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}

vector<int> rotateArray(vector<int> &A, int B)
{

    while (B >= A.size())
    {
        B = B % A.size();
    }

    vector<int> ret;
    for (int i = B + 1; i < A.size(); i++)
    {
        ret.push_back(A[i]);
    }

    for (int i = 0; i < B; i++)
    {
        ret.push_back(A[i]);
    }

    return ret;
}

vector<int> spiralOrder(const vector<vector<int>> &A)
{
    int top = 0, bottom = A.size() - 1, right = A[0].size() - 1, left = 0;
    int dir = 0;
    vector<int> ans;
    int i = 0;
    while ((top <= bottom) && (left <= right))
    {
        if (dir == 0)
        {
            for (i = left; i <= right; i++)
            {
                ans.push_back(A[top][i]);
            }
            ++top;
        }
        else if (dir == 1)
        {
            for (i = top; i <= bottom; i++)
            {
                ans.push_back(A[i][right]);
            }
            --right;
        }
        else if (dir == 2)
        {
            for (i = right; i >= left; i--)
            {
                ans.push_back(A[bottom][i]);
            }
            --bottom;
        }
        else if (dir == 3)
        {
            for (i = bottom; i >= top; i--)
            {
                ans.push_back(A[i][left]);
            }
            left++;
        }
        dir = (dir + 1) % 4;
    }
    return ans;
}

int multiply(int arr[], int num, int resSize)
{
    int carry = 0;

    for (size_t i = 0; i < resSize; i++)
    {
        int prod = (arr[i] * num) + carry;
        arr[i] = prod % 10;
        carry = prod / 10;
    }

    while (carry)
    {
        arr[resSize] = carry % 10;
        carry = carry / 10;
        ++resSize;
    }
    return resSize;
}

string solve(int A)
{
    string res = "";
    int arr[1500];
    arr[0] = 1;
    int resSize = 1;

    for (int i = 2; i <= A; i++)
    {
        resSize = multiply(arr, i, resSize);
    }

    for (int i = resSize - 1; i >= 0; i--)
    {
        res += to_string(arr[i]);
    }

    return res;
}

#define MAX 500

int multiply(int x, int res[], int res_size);

// This function finds factorial of large numbers
// and prints them
void factorial(int n)
{
    int res[MAX];

    // Initialize result
    res[0] = 1;
    int res_size = 1;

    // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
    for (int x = 2; x <= n; x++)
        res_size = multiply(x, res, res_size);

    cout << "Factorial of given number is \n";
    for (int i = res_size - 1; i >= 0; i--)
        cout << res[i];
}

int multiply(int x, int res[], int res_size)
{
    int carry = 0; // Initialize carry

    // One by one multiply n with individual digits of res[]
    for (int i = 0; i < res_size; i++)
    {
        int prod = res[i] * x + carry;

        // Store last digit of 'prod' in res[]
        res[i] = prod % 10;

        // Put rest in carry
        carry = prod / 10;
    }

    // Put carry in res and increase result size
    while (carry)
    {
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }
    return res_size;
}

int maxSubArray(const vector<int> &A)
{
    int sum = 0, maxSum = A[0];
    for (auto &&i : A)
    {
        if (sum < 0)
        {
            sum = 0;
        }
        sum += i;
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

// Minimum Lights to Activate
int solveM(vector<int> &A, int b)
{
    int ans = 0, n = A.size();
    bool flag = false;
    int i = 0;
    while (i < A.size())
    {
        int a = max(0, i - b + 1);
        int c = min(n - 1, i + b - 1);
        while (c >= a)
        {
            if (A[c])
            {
                flag = true;
                i = c + b;
                ++ans;
                break;
            }
            --c;
        }
        if (!flag)
        {
            return -1;
        }
        flag = false;
    }
    return ans;
}

vector<int> plusOne1(vector<int> &a)
{
    vector<int> ans;
    int i = 0;
    if ((a.size() == 1) && (a[0] == 0))
    {
        ans.push_back(1);
        return ans;
    }
    for (i = 0; i < a.size(); i++)
    {
        if (a[i] != 0)
        {
            break;
        }
    }
    string s = "";
    int temp = 0;
    for (i; i < a.size(); i++)
    {
        s += to_string(a[i]);
    }
    s = to_string(stoi(s) + 1);

    for (int k = 0; k < s.length(); k++)
    {
        ans.push_back(s[k] - '0');
    }

    return ans;
}

vector<int> plusOne(vector<int> &a)
{
    vector<int> ans;
    int i = 0;
    if ((a.size() == 1) && (a[0] == 0))
    {
        ans.push_back(1);
        return ans;
    }
    for (i = 0; i < a.size(); i++)
    {
        if (a[i] != 0)
        {
            break;
        }
    }
    int carry = 1;
    int sum = 0;
    for (int k = a.size() - 1; k >= i; k--)
    {
        sum = a[k] + carry;
        carry = sum / 10;
        ans.push_back(sum % 10);
    }

    while (carry)
    {
        ans.push_back(carry % 10);
        carry = carry / 10;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

// Maximum Sum Triplet
int solveMax(vector<int> &a)
{
    // Please be careful here
    vector<int> rightMost(a.size() + 1);
    set<int> leftMost;
    rightMost[a.size()] = INT_MIN;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        rightMost[i] = max(rightMost[i + 1], a[i]);
    }

    leftMost.insert(INT_MIN);
    int ans = 0;
    for (size_t i = 0; i < a.size(); i++)
    {
        auto it = leftMost.lower_bound(a[i]);
        --it;
        if (rightMost[i + 1] > a[i])
        {
            ans = max(ans, ((*it) + a[i] + rightMost[i]));
        }
        leftMost.insert(a[i]);
    }
    return ans;
}

int getLowValue(set<int> &lowValue, int &n)
{
    auto it = lowValue.lower_bound(n);

    // Since 'lower_bound' returns the first
    // iterator greater than 'n', thus we
    // have to decrement the pointer for
    // getting the minimum value
    --it;

    return (*it);
}

// Function to calculate maximum triplet sum
int maxTripletSum(int arr[], int n)
{
    // Initialize suffix-array
    int maxSuffArr[n + 1];

    // Set the last element
    maxSuffArr[n] = 0;

    // Calculate suffix-array containing maximum
    // value for index i, i+1, i+2, ... n-1 in
    // arr[i]
    for (int i = n - 1; i >= 0; --i)
        maxSuffArr[i] = max(maxSuffArr[i + 1], arr[i]);

    int ans = 0;

    // Initialize set container
    set<int> lowValue;

    // Insert minimum value for first comparison
    // in the set
    lowValue.insert(INT_MIN);

    for (int i = 0; i < n - 1; ++i)
    {
        if (maxSuffArr[i + 1] > arr[i])
        {
            ans = max(ans, getLowValue(lowValue,
                                       arr[i]) +
                               arr[i] + maxSuffArr[i + 1]);

            // Insert arr[i] in set<> for further
            // processing
            lowValue.insert(arr[i]);
        }
    }
    return ans;
}

// brute force
int maxArr2(vector<int> &A)
{
    int ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i + 1; j < A.size(); j++)
        {
            int temp = abs(A[i] - (A[j]));
            temp += abs(i - j);
            ans = max(ans, temp);
        }
    }
    return ans;
}

// Memory exceed
int maxArr1(vector<int> &A)
{
    map<pair<int, int>, int> Map;
    int ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i + 1; j < A.size(); j++)
        {
            if ((Map.find({i, j}) == Map.end()) && (Map.find({j, i}) == Map.end()))
            {
                int temp = abs(A[i] - (A[j]));
                temp += abs(i - j);
                ans = max(ans, temp);
                Map.insert({{i, j}, temp});
            }
        }
    }
    return ans;
}

int maxArr(vector<int> &A)
{
    int max1 = INT_MIN, min1 = INT_MAX;
    int max2 = INT_MIN, min2 = INT_MAX;

    for (int i = 0; i < A.size(); i++)
    {
        max1 = max(max1, A[i] + i);
        min1 = min(min1, A[i] + i);
        max2 = max(max2, A[i] - i);
        min2 = min(min2, A[i] - i);
    }
    return max(max1 - min1, max2 - min2);
}

// Pick from both sides!
int solvePick(vector<int> &A, int B)
{
    int sum = 0, maxSum = 0;
    for (size_t i = 0; i < B; i++)
    {
        sum += A[i];
    }
    int inc = A.size() - 1, exc = B - 1;
    maxSum = sum;
    while ((exc >= 0) && (inc >= 0))
    {
        sum += A[inc--];
        sum -= A[exc--];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

bool comparator(Interval n1, Interval n2)
{
    return n1.start < n2.start;
}

// Not Working
// vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
// {
//     vector<Interval> ans;
//     // bool flag = 1;
//     // for (auto &&it : intervals)
//     // {
//     //     if (it.end >= newInterval.start)
//     //     {
//     //         it.start=min(it.start,newInterval.start);
//     //         it.end = max(it.end, newInterval.end);
//     //         flag = 0;
//     //         break;
//     //     }
//     // }
//     // if (flag)
//     // {
//     intervals.push_back(newInterval);
//     // }

//     sort(intervals.begin(), intervals.end(), comparator);
//     Interval temp;
//     temp.start = intervals[0].start;
//     temp.end = intervals[0].end;
//     ans.push_back(temp);
//     for (long long int i = 1; i < intervals.size(); i++)
//     {
//         if (ans.back().end < intervals[i].end)
//         {
//             ans.push_back(intervals[i]);
//         }
//         else
//         {
//             ans.back().end = max(ans.back().end, intervals[i].end);
//         }
//     }

//     return ans;
// }

vector<Interval> insert2(vector<Interval> &intervals, Interval newInterval)
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
            ans.push_back(it);
            flag = 0;
        }
        else
        {
            newInterval.start = min(it.start, newInterval.start);
            newInterval.end = max(it.end, newInterval.end);
        }
    }
    if (flag)
    {
        ans.push_back(newInterval);
    }

    return ans;
}

vector<Interval> merge(vector<Interval> &A)
{
    sort(A.begin(), A.end(), comparator);
    vector<Interval> ans;
    ans.push_back(A[0]);
    for (auto &&it : A)
    {
        if (ans.back().end >= it.start)
        {
            ans.back().end = max(ans.back().end, it.end);
            // ans.back().start = min(ans.back().start, it.start);
        }
        else if (ans.back().end < it.start)
        {
            ans.push_back(it);
        }
    }
    return ans;
}

// Naive approach
int perfectPeak2(vector<int> &A)
{
    stack<int> s;
    s.push(A[0]);
    for (size_t i = 1; i < A.size() - 1; i++)
    {
        if (A[i] > s.top())
        {
            while (!s.empty())
            {
                if (A[i] > s.top())
                {
                    s.pop();
                }
                else
                {
                    break;
                }
            }

            if (s.empty())
            {
                int j = i + 1;
                while ((j < A.size()) && (A[i] < A[j]))
                {
                    ++j;
                }
                if ((j >= A.size()))
                {
                    return 1;
                }
            }
        }
        s.push(A[i]);
    }
    return 0;
}

// O(N)
int perfectPeak(vector<int> &A)
{
    int largest = A[0];
    for (int i = 1; i < A.size() - 1; i++)
    {
        if (A[i] > largest)
        {
            largest = A[i];
            int j = i + 1;
            while ((j < A.size()))
            {
                if (A[j] <= largest)
                    break;
                ++j;
            }
            if ((j == A.size()))
            {
                return 1;
            }
        }
    }
    return 0;
}

long long nCr(int n, int r)
{
    if (r > (n - r))
    {
        r = n - r;
    }
    long long int res = 1;
    for (size_t i = 0; i < r; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

vector<int> getRow(int A)
{
    vector<int> ans;
    ans.push_back(1);

    if (A == 0)
    {
        return ans;
    }

    for (size_t i = 1; i < A + 1; i++)
    {
        ans.push_back(nCr(A, i));
    }

    return ans;
}

vector<vector<int>> generateMatrix(int A)
{
    vector<vector<int>> ans(A, vector<int>(A, 0));
    int left = 0, right = A - 1, top = 0, down = A - 1;
    int temp = 1, dir = 0;
    while (((left <= right) && (top <= down)) && (temp <= pow(A, 2)))
    {
        if (dir == 0)
        {
            for (int i = left; i <= right; i++)
            {
                ans[top][i] = temp;
                ++temp;
            }
            ++top;
        }
        else if (dir == 1)
        {
            for (int i = top; i <= down; i++)
            {
                ans[i][right] = temp;
                ++temp;
            }
            --right;
        }
        else if (dir == 2)
        {
            for (int i = right; i >= left; i--)
            {
                ans[down][i] = temp;
                ++temp;
            }
            --down;
        }
        else if (dir == 3)
        {
            for (int i = down; i >= top; i--)
            {
                ans[i][left] = temp;
                ++temp;
            }
            ++left;
        }
        dir = (dir + 1) % 4;
    }
    return ans;
}

vector<vector<int>> solvePascal(int A)
{
    vector<vector<int>> ds;

    if (A == 0)
    {
        vector<int> ans;
        ans.push_back(1);
        ds.push_back(ans);
        return ds;
    }
    while (A--)
    {
        vector<int> ans;
        ans.push_back(1);
        for (size_t i = 1; i < A + 1; i++)
        {
            ans.push_back(nCr(A, i));
        }
        ds.push_back(ans);
        ans.clear();
    }
    reverse(ds.begin(), ds.end());
    return ds;
}

vector<int> solveArr(vector<int> &A)
{
    vector<int> ans;
    vector<int> negative, positive;
    for (auto &&i : A)
    {
        if (i < 0)
        {
            negative.push_back(i);
        }
        else
        {
            positive.push_back(i);
        }
    }
    int i = negative.size() - 1, j = 0;
    while ((i >= 0) && (j < positive.size()))
    {
        if (abs(negative[i]) <= positive[j])
        {
            ans.push_back(abs(negative[i]) * abs(negative[i]));
            --i;
        }
        else
        {
            ans.push_back(positive[j] * positive[j]);
            ++j;
        }
    }
    while ((i >= 0))
    {
        ans.push_back(abs(negative[i]) * abs(negative[i]));
        --i;
    }
    while ((j < positive.size()))
    {
        ans.push_back(positive[j] * positive[j]);
        ++j;
    }
    return ans;
}

// Memory Limit exceed
// string largestNumber(const vector<int> &A)
// {
//     vector<int> ans;
//     for (auto &&i : A)
//     {
//         if (i >= 10)
//         {
//             int temp = i;
//             while (temp >= 0)
//             {
//                 ans.push_back(temp % 10);
//                 temp /= 10;
//             }
//         }
//     }
//     sort(ans.begin(), ans.end(), greater<int>());
//     string s;
//     for (auto &&i : ans)
//     {
//         s += to_string(i);
//     }
//     return s;
// }

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

bool myCompare(string a, string b)
{
    string ab = a.append(b);
    string ba = b.append(a);
    return ab.compare(ba) > 0 ? 1 : 0;
}

string largestNumber2(const vector<int> &A)
{
    vector<string> arr(A.size());
    int count = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == 0)
            count++;
        arr[i] = to_string(A[i]);
    }
    if (count == A.size())
        return "0";
    sort(arr.begin(), arr.end(), myCompare);
    string ans = arr[0];
    for (int i = 1; i < arr.size(); i++)
        ans = ans + arr[i];
    return ans;
}

void rotate(vector<vector<int>> &A)
{
    for (size_t i = 0; i < A.size(); i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            swap(A[i][j], A[j][i]);
        }
    }

    for (size_t i = 0; i < A.size(); i++)
    {
        reverse(A[i].begin(), A[i].end());
    }

    return;
}

vector<int> nextPermutation(vector<int> &A)
{
    vector<int> ans = A;
    int i = 0, j = 0;
    for (i = A.size() - 2; i >= 0; i--)
    {
        if (A[i] < A[i + 1])
        {
            break;
        }
    }

    if (i < 0)
    {
        sort(ans.begin(), ans.end());
        return ans;
    }

    for (j = A.size() - 1; j >= 0; j--)
    {
        if (A[j] > A[i])
        {
            break;
        }
    }
    swap(A[j], A[i]);
    reverse(A.begin() + i + 1, A.end());
    ans = A;

    return ans;
}

// TLE
vector<int> findPerm2(string A, int B)
{
    vector<int> ans;
    for (size_t i = 1; i <= B; i++)
    {
        ans.push_back(i);
    }
    do
    {
        int j = 1;
        for (size_t i = 0; i < A.length(); i++)
        {
            if (A[i] == 'I')
            {
                if (ans[j] < ans[j - 1])
                {
                    continue;
                }
                ++j;
            }
            else
            {
                if (ans[j] > ans[j - 1])
                {
                    continue;
                }
                ++j;
            }
        }
        if (j == ans.size())
            break;

    } while (next_permutation(ans.begin(), ans.end()));
    return ans;
}

vector<int> findPerm(const string A, int B)
{
    vector<int> ans;
    int start = 1, end = B;
    int i = 0;
    int n = A.size();
    for (i = 0; i < n; i++)
    {
        if ((A[i] == 'I'))
        {
            ans.push_back(start);
            ++start;
        }
        else
        {
            ans.push_back(end);
            --end;
        }
    }
    for (; i <= n; i++)
    {
        ans.push_back(end);
        --end;
    }

    return ans;
}

// Min Steps in Infinite Grid
// ans=max(abs(X),abs(Y))
// dist. diagonal + remaining dist.
// diagonal =min(X,Y)
// remaining dist=max(x,y)-min(x-y);
int coverPoints(vector<int> &A, vector<int> &B)
{
    int ans = 0;
    for (size_t i = 1; i < A.size(); i++)
    {
        int x = abs(A[i - 1] - A[i]), y = abs(B[i - 1] - B[i]);
        ans += max(x, y);
    }
    return ans;
}

// Wave Array
vector<int> wave(vector<int> &A)
{
    vector<int> ans;
    sort(A.begin(), A.end());

    for (size_t i = 1; i < A.size(); i++)
    {

        swap(A[i], A[i - 1]);
        ++i;
    }
    ans = A;

    return ans;
}

bool comparatorNew(pair<int, char> one, pair<int, char> two)
{
    if (one.first == two.first)
    {
        // we want departure
        return one.second > two.second;
    }
    return one.first < two.first;
}

// Hotel Bookings Possible
bool hotel(vector<int> &arrive, vector<int> &depart, int K)
{
    vector<pair<int, char>> ans;
    int curr = 0;
    int maxcount = 0;
    for (size_t i = 0; i < arrive.size(); i++)
    {
        ans.push_back({arrive[i], 'a'});
        ans.push_back({depart[i], 'd'});
    }

    sort(ans.begin(), ans.end(), comparatorNew);
    for (size_t i = 0; i < ans.size(); i++)
    {
        if (ans[i].second == 'a')
        {
            ++curr;
            maxcount = max(maxcount, curr);
        }
        else
        {
            --curr;
        }
    }

    return K >= maxcount;
}

bool hotel2(vector<int> &arrive, vector<int> &depart, int K)
{
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());

    for (int i = 0; i < arrive.size(); i++)
    {
        if (i + K < arrive.size() && arrive[i + K] < depart[i])
        {
            return 0;
        }
    }
    return 1;
}

// Max Distance
bool comparatorNew2(pair<int, int> one, pair<int, int> two)
{
    if (one.first == two.first)
    {
        // we want departure
        return one.second < two.second;
    }
    return one.first < two.first;
}

// O(nlogn)
int maximumGap21(const vector<int> &A)
{
    int maxGap = 0;
    vector<pair<int, int>> ds;
    for (size_t i = 0; i < A.size(); i++)
    {
        ds.push_back({A[i], i});
    }

    sort(ds.begin(), ds.end(), comparatorNew2);
    int minInd = ds[0].second;
    for (size_t i = 1; i < ds.size(); i++)
    {
        if ((ds[i].first >= ds[i - 1].first))
        {
            minInd = min(minInd, ds[i].second);
            int temp = ds[i].second - minInd;
            maxGap = max(maxGap, temp);
        }
    }

    return maxGap;
}

// O(n)
int maximumGap2(const vector<int> &A)
{
    int maxGap = 0;
    int maxEle = A[A.size() - 1];

    vector<int> ds;
    ds.push_back(maxEle);

    for (size_t i = A.size() - 2; i >= 0; i--)
    {
        maxEle = max(A[i], maxEle);
        ds.push_back(maxEle);
    }

    int i = 0, j = 0;
    while ((i < A.size()) && (j < A.size()))
    {
        if (A[i] <= ds[j])
        {
            maxGap = max(maxGap, j - i);
            ++j;
        }
        else
        {
            ++i;
        }
    }

    return maxGap;
}

void setZeroes(vector<vector<int>> &A)
{
    vector<int> row(A.size(), 0), col(A[0].size(), 0);
    for (size_t i = 0; i < A.size(); i++)
    {
        for (size_t j = 0; j < A[i].size(); j++)
        {
            if (A[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (size_t i = 0; i < A.size(); i++)
    {
        for (size_t j = 0; j < A[i].size(); j++)
        {
            if ((row[i] == 1) || (col[j] == 1))
            {
                A[i][j] = 0;
            }
        }
    }
}

// First Missing Integer
int firstMissingPositive2(vector<int> &A)
{
    set<int> s(A.begin(), A.end());
    int ans = 1;
    while (s.find(ans) != s.end())
    {
        ++ans;
    }
    return ans;
}

int firstMissingPositive(vector<int> &A)
{
    int ans = 0, sum = 0;
    for (int i = 0; i < A.size(); i++)
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

vector<int> repeatedNumber1(const vector<int> &A)
{
    vector<int> ds;
    int xy = 0;
    int x = 0, y = 0;
    for (size_t i = 1; i <= A.size(); i++)
    {
        xy ^= i;
    }

    for (size_t i = 0; i < A.size(); i++)
    {
        xy ^= A[i];
    }

    int set_bit_no = xy & ~(xy - 1);

    for (size_t i = 0; i < A.size(); i++)
    {
        if (set_bit_no & A[i])
        {
            x ^= A[i];
        }
        else
        {
            x ^= A[i];
        }
    }

    for (size_t i = 1; i <= A.size(); i++)
    {
        if (set_bit_no & i)
        {
            x ^= i;
        }
        else
        {
            x ^= i;
        }
    }

    int xCount = 0;
    for (auto &&i : A)
    {
        if (i == x)
        {
            ++xCount;
        }
    }
    if (xCount > 0)
    {
        vector<int> ans;
        ans.push_back(x);
        ans.push_back(y);
        return ans;
    }
    vector<int> ans;
    ans.push_back(y);
    ans.push_back(x);
    return ans;
}

vector<vector<int>> diagonal(vector<vector<int>> &A)
{
    vector<vector<int>> ans;
    int row = 0, col = 0;
    bool flag = true;
    int n1 = A.size();

    vector<int> ds1;
    ds1.push_back(A[row][col]);
    ans.push_back(ds1);
    col += 1;

    while ((row < n1) && (col < n1))
    {
        vector<int> ds;
        int r = row, c = col;
        while ((r < n1) && (c >= 0))
        {
            ds.push_back(A[r][c]);
            --c;
            ++r;
        }
        ++col;
        ans.push_back(ds);
    }
    row = 1;
    col = n1 - 1;
    while ((row < n1) && (col < n1))
    {
        vector<int> ds;
        int r = row, c = col;
        while ((r < n1) && (c >= 0))
        {
            ds.push_back(A[r][c]);
            --c;
            ++r;
        }
        ++row;
        ans.push_back(ds);
    }

    return ans;
}

vector<vector<int>> diagonal2(vector<vector<int>> &A)
{
    vector<vector<int>> s;
    // int i=0;
    vector<int> v;
    int r = A.size();
    int c = A[0].size();
    if (c == 0 or r == 0)
        return s;

    int i;
    int j = 0;

    for (i = 0; i < c; i++)
    {
        v.clear();
        int p = i, q = j;
        while (p >= 0 and q <= (r - 1))
        {
            v.push_back(A[q][p]);
            p--;
            q++;
        }
        s.push_back(v);
    }

    i = c - 1;
    for (j = 1; j < r; j++)
    {
        v.clear();
        int p = i, q = j;
        while (p >= 0 and q <= (r - 1))
        {
            v.push_back(A[q][p]);
            p--;
            q++;
        }
        s.push_back(v);
    }
    return s;
}

// Maximum Sum Square SubMatrix
// O(N^2)
int solveSum(vector<vector<int>> &A, int B)
{
    vector<vector<int>> ans(A.size());
    int maxSum = INT_MIN;
    for (size_t i = 0; i < A.size(); i++)
    {
        int l = 0, sum = 0;
        for (size_t j = 0; j < A.size(); j++)
        {
            sum += A[i][j];
            if (j - l + 1 == B)
            {
                ans[i].push_back(sum);
                sum -= A[i][l];
                ++l;
            }
        }
    }

    for (size_t i = 0; i < ans.size(); i++)
    {
        int l = 0, sum = 0;
        for (size_t j = 0; j < ans.size(); j++)
        {
            sum += ans[j][i];
            if (j - l + 1 == B)
            {
                maxSum = max(maxSum, sum);
                sum -= A[l][i];
                ++l;
            }
        }
    }

    return maxSum;
}

// Balance Array
// O(N^2)
int solveBalance1(vector<int> &A)
{
    int count = 0;
    int sumE = 0, sumO = 0;

    for (size_t i = 0; i < A.size() - 1; i++)
    {
        if ((i) % 2 == 0)
        {
            sumE += A[i];
        }
        else
        {
            sumO += A[i];
        }
    }
    if (sumE == sumO)
    {
        ++count;
    }

    int ind = 0;
    for (size_t i = 0; i < A.size() - 1; i++)
    {
        sumE = 0, sumO = 0;
        if (i != 0)
        {
            for (size_t k = 0; k < ind; k++)
            {
                if ((k) % 2 == 0)
                {
                    sumE += A[k];
                }
                else
                {
                    sumO += A[k];
                }
            }
        }

        for (size_t j = ind + 1; j < A.size(); j++)
        {
            if ((j - 1) % 2 == 0)
            {
                sumE += A[j];
            }
            else
            {
                sumO += A[j];
            }
        }
        ++ind;
        if (sumE == sumO)
        {
            ++count;
        }
    }
    return count;
}

// O(N)
int solveBalance2(vector<int> &A)
{
    int count = 0;
    int sumE = 0, sumO = 0;
    int currE = 0, currO = 0;

    for (size_t i = 0; i < A.size(); i++)
    {
        if ((i) % 2 == 0)
        {
            sumE += A[i];
        }
        else
        {
            sumO += A[i];
        }
    }

    for (size_t i = 0; i < A.size(); i++)
    {
        if ((i) % 2 == 0)
        {
            sumE -= A[i];
            if (i != 0)
            {
                currO += A[i - 1];
            }
        }
        else
        {
            sumO -= A[i];
            if (i != 0)
            {
                currE += A[i - 1];
            }
        }

        if ((sumE + currO) == (sumO + currE))
        {
            ++count;
        }
    }

    return count;
}

int repeatedNumber2(const vector<int> &A)
{
    int slow = 0, fast = 0;

    do
    {
        slow = A[slow];
        fast = A[A[fast]];
    } while (A[slow] != A[fast]);

    fast = 0;
    while (A[slow] != A[fast])
    {
        slow = A[slow];
        fast = A[fast];
    }

    return A[slow];
}

int maximumGap(const vector<int> &A)
{
    if (A.size() < 2)
    {
        return 0;
    }
    // sort(A.begin(), A.end());
    int ans = 0;
    for (size_t i = 1; i < A.size(); i++)
    {
        ans = max(ans, A[i] - A[i - 1]);
    }
    return ans;
}

// N/3 Repeat Number
int repeatedNumber(const vector<int> &A)
{
    int num1 = 0, num2 = 0;
    int count1 = 0, count2 = 0;

    for (auto &&i : A)
    {
        if (i == num1)
        {
            ++count1;
        }
        else if (i == num2)
        {
            ++count2;
        }
        else if (count1 <= 0)
        {
            num1 = i;
            count1 = 1;
        }
        else if (count2 <= 0)
        {
            num2 = i;
            count2 = 1;
        }
        else
        {
            --count1;
            --count2;
        }
    }

    count1 = 0, count2 = 0;
    for (auto &&i : A)
    {
        if (i == num1)
        {
            ++count1;
        }
        if (i == num2)
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

int isPrime(int A)
{
    if (A <= 1)
    {
        return 0;
    }

    for (size_t i = 2; i < A; i++)
    {
        if ((A % i) == 0)
        {
            return 0;
        }
    }
    return 1;
}

// Partitions
int solvePartitions(int A, vector<int> &B)
{
    vector<int> prefix, suffix;
    int sum = 0, count = 0, currSum = 0;

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
            currSum = 0;
        }
    }

    currSum = 0;
    for (int i = B.size() - 1; i >= 0; i--)
    {
        currSum += B[i];
        if (currSum == sum)
        {
            suffix.push_back(i);
            currSum = 0;
        }
    }

    for (size_t i = 0; i < prefix.size(); i++)
    {
        for (size_t j = 0; j < suffix.size(); j++)
        {
            int x = 0, n = 0;
            for (size_t k = prefix[i] + 1; k < suffix[j]; k++)
            {
                x += B[k];
                n = 1;
            }
            if ((x == sum) && (n))
            {
                ++count;
            }
        }
    }

    return count;
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
    int currSum = 0, maxSum = 0, left = 0, right = 0;

    for (size_t i = 0; i < A.size(); i++)
    {
        currSum += arr[i];
        if (currSum < 0)
        {
            currSum = 0;
            left = i + 1;
        }
        if (currSum > maxSum)
        {
            maxSum = currSum;
            right = i;
            ans[0] = left + 1;
            ans[1] = right + 1;
        }
    }

    return ans;
}

string findDigitsInBinary1(int A)
{
    string s = "";
    for (size_t i = 0; i < 31; i++)
    {
        if (A & (1 << i))
        {
            s += '1';
        }
        else
        {
            s += '0';
        }
    }
    reverse(s.begin(), s.end());
    int i = 0;
    for (i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            break;
        }
    }
    if (i == s.length())
    {
        s = "";
        s += '0';
    }
    else
    {
        s = s.substr(i);
    }
    return s;
}

string findDigitsInBinary(int A)
{
    string s = "";

    for (int i = 31; i >= 0; i--)
    {
        if ((A >> i) & 1)
        {
            s += '1';
        }
        else
        {
            s += '0';
        }
    }

    int i = 0;
    for (i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            break;
        }
    }
    if (i == s.length())
    {
        s = "";
        s += '0';
    }
    else
    {
        s = s.substr(i);
    }

    return s;
}

// Maximum Unsorted Sub array
vector<int> subUnsort(vector<int> &A)
{
    vector<int> ans(2, 0);
    int i = 0, right = 0;

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

    for (right = A.size() - 2; right >= 0; right--)
    {
        if (A[right] > A[right + 1])
        {
            right++;
            break;
        }
    }

    int minEle = INT_MAX, maxEle = 0;

    for (size_t k = i; k <= right; k++)
    {
        minEle = min(minEle, A[k]);
        maxEle = max(maxEle, A[k]);
    }

    int t_i = i - 1, t_right = right + 1;
    while (t_i >= 0)
    {
        // Equal to wala mat lena
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

vector<vector<int>> prettyPrint(int A)
{
    vector<vector<int>> ans((2 * A) - 1, vector<int>((2 * A) - 1, A));
    int left = 1, right = (2 * A) - 3;
    int top = 1, bottom = (2 * A) - 3;
    int ele = A - 1;

    while ((left <= right) && (top <= bottom))
    {
        for (size_t i = left; i <= right; i++)
        {
            ans[top][i] = ele;
        }
        ++top;

        for (size_t i = top; i <= bottom; i++)
        {
            ans[i][right] = ele;
        }
        --right;

        for (int i = right; i >= left; i--)
        {
            ans[bottom][i] = ele;
        }
        --bottom;

        for (int i = bottom; i >= top; i--)
        {
            ans[i][left] = ele;
        }
        ++left;

        --ele;
    }
    return ans;
}

// Rain Water Trapped
int trap(const vector<int> &A)
{
    vector<int> postFix(A.size(), 0);
    int ans = 0;
    int temp = A[A.size() - 1];

    for (int i = A.size() - 1; i >= 0; i--)
    {
        temp = max(A[i], temp);
        postFix[i] = temp;
    }

    temp = A[0];
    for (size_t i = 1; i < A.size() - 1; i++)
    {
        int tempDiff = min(temp, postFix[i]) - A[i];
        if (tempDiff > 0)
        {
            ans += tempDiff;
        }
        temp = max(temp, A[i]);
    }

    return ans;
}

int main()
{
    vector<int> A = {1, 3, 2, 4, 5};
    // cout << findDigitsInBinary(6) << endl;
    // for (auto &&i : subUnsort(A))
    // {
    //     cout << i << ",";
    // }
    // cout << endl;
    // for (auto &&i : d)
    // {
    //     cout << i << ",";
    // }
    // cout << endl;

    for (auto &&i : prettyPrint(3))
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    // vector<Interval> v = {{{1, 1}, {2, 3}, {3, 8}, {4, 7}, {5, 6}, {6, 6}}};
    // for (auto &&i : merge(v))
    // {
    //     cout << i.start << " " << i.end << endl;
    // }
    // The expected return value:
    // (1, 10)
    // Your function returned the following:
    // (1, 10) (1, 10) (2, 9) (3, 8) (4, 7) (5, 6) (6, 6)
    // cout << solve(4) << endl;
    // factorial(4);
    return 0;
}