#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std;

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
    vector<int> rightMost;
    int ele = INT_MIN;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        ele = max(ele, a[i]);
        rightMost.push_back(ele);
    }

    for (size_t i = 0; i < a.size(); i++)
    {
        
    }
}

int main()
{
    vector<int> A = {2, 5, 6, 8, 6, 1, 2, 4, 5};
    for (auto &&i : plusOne(A))
    {
        cout << i << " ";
    }

    // cout << solve(4) << endl;
    // factorial(4);
    return 0;
}