#include <bits/stdc++.h>
using namespace std;

// 😉😉 Don't delete this
int singleNonDuplicate(vector<int> &nums)
{
    int start = 0, end = nums.size() - 2;

    while (start <= end)
    {
        int mid = (start + (end - start) / 2);
        if (nums[mid] == nums[mid ^ 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return nums[start];
}

double findNthRootOfM(int n, long long m)
{
    double eps = 1e-6;
    double low = 1.0, high = m;

    while ((high - low) > eps)
    {
        double mid = low + (high - low) / 2;
        if (pow(mid, n) > m)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    return low;
}

// Search in Bitonic Array!
int solveBitonic(vector<int> &A, int B)
{
    int i = 0;
    for (i = 1; i < A.size(); i++)
    {
        if (A[i] < A[i - 1])
        {
            --i;
            break;
        }
    }

    int low = 0, high = i;
    while (low <= high)
    {
        int mid = (low + (high - low) / 2);
        if (A[mid] == B)
        {
            return mid;
        }
        else if (B < A[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    low = i + 1, high = A.size() - 1;
    while (low <= high)
    {
        int mid = (low + (high - low) / 2);
        if (A[mid] == B)
        {
            return mid;
        }
        else if (B < A[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int solveBitonic2(vector<int> &A, int B)
{
    int low = 0, high = A.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (B == A[mid])
        {
            return mid;
        }

        if (A[low] <= A[mid])
        {
            if ((B >= A[low]) && (B <= A[mid]))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if ((B >= A[mid]) && (B <= A[high]))
            {
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    if (B == A[low])
    {
        return low;
    }

    return -1;
}

// Smaller or equal elements
int solveSmaller(vector<int> &A, int B)
{
    int x = upper_bound(A.begin(), A.end(), B) - A.begin();
    return x;
}

// 1, 3, 4, 4, 6
int solveSmaller2(vector<int> &A, int B)
{
    int low = 0, high = A.size() - 1;

    while (low <= high)
    {
        int mid = (low + (high - low) / 2);
        if (A[mid] <= B)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low;
}

// WoodCutting Made Easy!
// [20, 15, 10, 17] 7
// O(N * log(maxHeight))
int solveWoodCutting(vector<int> &A, int B)
{
    int ans = -1;
    int low = 0, high = 0;

    for (size_t i = 0; i < A.size(); i++)
    {
        high = max(high, A[i]);
    }

    while (low <= high)
    {
        int mid = (low + (high - low) / 2);
        long long int count = 0;
        for (size_t i = 0; i < A.size(); i++)
        {
            if (A[i] - mid > 0)
            {
                count += (A[i] - mid);
            }
        }

        if (count >= (long long int)B)
        {
            low = mid + 1;
            ans = mid;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

// Matrix Search
int searchMatrix(vector<vector<int>> &A, int B)
{
    int col = A[0].size();
    int low = 0, high = (A[0].size() * A.size()) - 1;

    while (low <= high)
    {
        int mid = (low + (high - low) / 2);
        if (A[mid / col][mid % col] == B)
        {
            return 1;
        }
        else if (A[mid / col][mid % col] < B)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return 0;
}

// Search for a Range
vector<int> searchRange1(const vector<int> &A, int B)
{
    vector<int> ans(2, -1);
    bool flagLower = 0, flagUpper = 0;

    int st = lower_bound(A.begin(), A.end(), B) - A.begin();

    if (A[st] != B)
    {
        flagLower = 1;
    }

    int en = upper_bound(A.begin(), A.end(), B) - A.begin();
    if (A[en] != B)
    {
        flagUpper = 1;
    }

    if ((flagUpper) && (flagLower))
    {
        return ans;
    }
    ans.clear();

    ans.push_back(st);

    ans.push_back(en - 1);

    return ans;
}

vector<int> searchRange(const vector<int> &A, int B)
{
    vector<int> ans(2, -1);
    int low = 0, high = A.size() - 1;
    int end = 0;

    while (low < high)
    {
        int mid = (low + (high - low) / 2);
        if (A[mid] < B)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    if (A[low] != B)
        return ans;

    ans[0] = low;

    high = A.size() - 1;
    while (low <= high)
    {
        int mid = (low + (high - low) / 2);
        if (A[mid] <= B)
        {
            if (A[mid] == B)
                end = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    ans[1] = end;
    return ans;
}

// Sorted Insert Position
int searchInsert(vector<int> &A, int B)
{
    int low = 0, high = A.size() - 1;
    int ind = A.size();

    while (low <= high)
    {
        int mid = (low + (high - low) / 2);
        if (A[mid] == B)
            return mid;
        if (A[mid] < B)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    low = 0, high = A.size() - 1;

    // Edge Case
    if (A[low] > B)
    {
        return 0;
    }

    while (low <= high)
    {
        int mid = (low + (high - low) / 2);

        if (A[mid] < B)
        {
            ind = mid + 1;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ind;
}

// Square Root of Integer
int sqrt(int A)
{
    if (A == 0 || A == 1)
        return A;

    int low = 0, high = A / 2, ans = 0;

    while (low <= high)
    {
        long long int mid = (low + (high - low) / 2);
        long long int sqr = mid * mid;
        if (sqr == A)
            return mid;

        if (sqr <= A)
        {
            low = mid + 1;
            ans = mid;
        }
        else
            high = mid - 1;
    }
    return ans;
}

// Search in Rotated Sorted Array
int search(vector<int> &A, int B)
{
    int low = 0, high = (A.size()) - 1;

    while (low <= high)
    {
        int mid = (low + (high - low) / 2);
        if (A[mid] == B)
        {
            return 1;
        }
        if (A[low] <= A[mid])
        {
            if ((B >= A[low]) && (B <= A[mid]))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if ((B >= A[mid]) && (B <= A[high]))
            {
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    return -1;
}

// 🤦‍♂️🤦‍♂️🤷‍♂️ Baar Baar Bhul Jate h
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    if (nums2.size() < nums1.size())
    {
        return findMedianSortedArrays(nums2, nums1);
    }
    int n1 = nums1.size();
    int n2 = nums2.size();
    int low = 0, high = n1;
    int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

    while (low <= high)
    {
        int cut1 = (high + low) >> 1;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        l1 = (cut1 == 0) ? (INT_MIN) : (nums1[cut1 - 1]);
        l2 = (cut2 == 0) ? (INT_MIN) : (nums2[cut2 - 1]);

        r1 = (cut1 == n1) ? (INT_MAX) : (nums1[cut1]);
        r2 = (cut2 == n2) ? (INT_MAX) : (nums2[cut2]);

        if ((l1 <= r2) && (l2 <= r1))
        {
            if ((n1 + n2) % 2 == 0)
            {
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else
            {
                return max(l1, l2);
            }
        }
        else if (l1 > r2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }

    return 0.0;
}

int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    if (m < n)
    {
        return kthElement(arr2, arr1, m, n, k);
    }

    int low = max(0, k - m), high = min(k, n);
    int l1 = INT_MIN, r1 = INT_MAX;
    int l2 = INT_MIN, r2 = INT_MAX;

    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = (k - cut1);

        l1 = (cut1 == 0) ? (INT_MIN) : (arr1[cut1 - 1]);
        l2 = (cut2 == 0) ? (INT_MIN) : (arr2[cut2 - 1]);
        r1 = (cut1 == n) ? (INT_MAX) : (arr1[cut1]);
        r2 = (cut2 == m) ? (INT_MAX) : (arr2[cut2]);

        if ((l1 <= r2) && (l2 <= r1))
        {
            return max(l1, l2);
        }

        else if (l1 > r2)
        {
            high = cut1 - 1;
        }

        else
        {
            low = cut1 + 1;
        }
    }
    return 1;
}

// Median of Array
double findMedianSortedArrays3(const vector<int> &A, const vector<int> &B)
{
    if (B.size() < A.size())
    {
        return findMedianSortedArrays3(B, A);
    }

    int n1 = A.size();
    int n2 = B.size();
    int low = 0, high = n1;
    int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
    int medianPos = (n1 + n2 + 1) / 2;

    while (low <= high)
    {
        int cut1 = (low + high) / 2;
        int cut2 = medianPos - cut1;

        l1 = (cut1 == 0) ? (INT_MIN) : (A[cut1 - 1]);
        l2 = (cut2 == 0) ? (INT_MIN) : (B[cut2 - 1]);

        r1 = (cut1 == n1) ? (INT_MAX) : (A[cut1]);
        r2 = (cut2 == n2) ? (INT_MAX) : (B[cut2]);

        if ((l1 <= r2) && (l2 <= r1))
        {
            if ((n1 + n2) % 2 == 0)
            {
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else
            {
                return max(l1, l2);
            }
        }

        else if (l1 > r2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return 0.0;
}

// Allocate Books
bool isPossible(vector<int> &A, int B, int maxPage)
{
    int student = 0, pages = 0;

    for (auto &&i : A)
    {
        if (i > maxPage)
        {
            return false;
        }

        if (pages + i > maxPage)
        {
            ++student;
            maxPage = i;
        }
        else
        {
            pages += i;
        }
    }
    if (student < B)
        return true;
    return false;
}

int books2(vector<int> &A, int B)
{
    if (B > A.size())
    {
        return -1;
    }

    int low = A[0], high = 0;
    int ans = 0;

    for (auto &&i : A)
    {
        low = min(low, i);
        high += i;
    }

    while (low <= high)
    {
        int mid = (high + low) >> 1;
        if (isPossible(A, B, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int isPossible2(vector<int> &A, int pages, int students)
{
    int cnt = 0;
    int sumAllocated = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (sumAllocated + A[i] > pages)
        {
            cnt++;
            sumAllocated = A[i];
            if (sumAllocated > pages)
                return false;
        }
        else
        {
            sumAllocated += A[i];
        }
    }
    if (cnt < students)
        return true;
    return false;
}

int books(vector<int> &A, int B)
{
    if (B > A.size())
        return -1;
    int low = A[0];
    int high = 0;
    // to find minimum value and sum of all pages
    for (int i = 0; i < A.size(); i++)
    {
        high = high + A[i];
        low = min(low, A[i]);
    }
    // binary search
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (isPossible2(A, mid, B))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

bool ifPossible(vector<int> stall, int minDis, int c)
{
    int count = 1, last = stall[0];

    for (size_t i = 1; i < stall.size(); i++)
    {
        if ((stall[i] - last) >= minDis)
        {
            ++count;
            last = stall[i];
            if (count == c)
            {
                return 1;
            }
        }
    }

    return 0;
}

bool ifPossible2(vector<int> stall, int minDis, int cows)
{
    int count = 1, pos = stall[0];
    for (size_t i = 1; i < stall.size(); i++)
    {
        if (stall[i] - pos >= minDis)
        {
            ++count;
            pos = stall[i];
        }

        if (count == cows)
        {
            return true;
        }
    }

    return 0;
}

int aggressiveCows(vector<int> stall, int cows)
{
    sort(stall.begin(), stall.end());
    int low = 1, high = stall[stall.size() - 1] - low;
    int ans = 0;

    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (ifPossible2(stall, mid, cows))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

// Matrix Median
int countSmallerThanMid(vector<int> &row, int mid)
{
    int l = 0, h = row.size() - 1;
    while (l <= h)
    {
        int md = (l + h) >> 1;
        if (row[md] <= mid)
        {
            l = md + 1;
        }
        else
        {
            h = md - 1;
        }
    }
    return l;
}

int findMedian(vector<vector<int>> &A)
{
    int low = 1;
    int high = 1e9;
    int n = A.size();
    int m = A[0].size();
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += countSmallerThanMid(A[i], mid);
        }
        if (cnt <= (n * m) / 2)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

// GFG
int findMedian2(vector<vector<int>> &m)
{
    int min = INT_MAX, max = INT_MIN;
    int r = m.size(), c = m[0].size();

    for (int i = 0; i < r; i++)
    {
        // Finding the minimum element
        if (m[i][0] < min)
            min = m[i][0];

        // Finding the maximum element
        if (m[i][c - 1] > max)
            max = m[i][c - 1];
    }

    int desired = (r * c + 1) / 2;
    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int place = 0;

        // Find count of elements smaller than mid
        for (int i = 0; i < r; ++i)
            place += upper_bound(m[i].begin(), m[i].end(), mid) - m[i].begin();
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}

// My Method Matrix Median
int smallerThenMid(vector<int> A, int val)
{
    int low = 0, high = A.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (A[mid] <= val)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int findMedian4(vector<vector<int>> &A)
{
    int low = 1, high = 1e9;
    int row = A.size(), col = A[0].size();

    // for (auto i : A)
    // {
    //     for (auto &&j : i)
    //     {
    //         low = min(low, j);
    //         high = max(high, j);
    //     }
    // }

    int desired = (row * col) / 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int count = 0;

        for (size_t i = 0; i < row; i++)
        {
            count += smallerThenMid(A[i], mid);
        }

        if (count <= desired)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low;
}

double multiply(double number, int n)
{
    double ans = 1.0;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * number;
    }
    return ans;
}

void getNthRoot(int n, int m)
{
    double low = 1;
    double high = m;
    double eps = 1e-6;

    while ((high - low) > eps)
    {
        double mid = (low + high) / 2.0;
        if (multiply(mid, n) <= m)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    cout << n << "th root of " << m << " is " << low << endl;
}

int main()
{
    vector<int> A = {1, 3, 5, 7};
    getNthRoot(2, 9);
    // cout << searchInsert(A, 2) << endl;
    // cout << floorSqrt(930675566) << endl;
    // for (auto &&i : searchRange(A, 9))
    // {
    //     cout << i << ",";
    // }
    // int t = 0;
    // cin >> t;
    // while (t--)
    // {
    //     int n = 0, c = 0;
    //     cin >> n >> c;

    //     vector<int> stall(n);
    //     for (size_t i = 0; i < n; i++)
    //     {
    //         cin >> stall[i];
    //     }

    //     sort(stall.begin(), stall.end());

    //     int low = stall[0], high = stall[n - 1] - low, res = 0;

    //     while (low <= high)
    //     {
    //         int mid = (low + high) >> 1;
    //         if (ifPossible(stall, mid, c))
    //         {
    //             res = mid;
    //             low = mid + 1;
    //         }
    //         else
    //         {
    //             high = mid - 1;
    //         }
    //     }

    //     cout << res << endl;
    // }

    return 0;
}