#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

struct Item
{
    int value;
    int weight;
};

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

void setZeroes(vector<vector<int>> &matrix)
{
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                int row = i, col = 0;
                while (col < matrix[0].size())
                {
                    if (matrix[row][col] != 0)
                    {
                        matrix[row][col] = -1;
                    }
                    ++col;
                }

                row = 0, col = j;
                while (row < matrix.size())
                {
                    if (matrix[row][col] != 0)
                    {
                        matrix[row][col] = -1;
                    }
                    ++row;
                }
            }
        }
    }

    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

void setZeroes2(vector<vector<int>> &matrix)
{
    vector<int> row(matrix.size(), 0);
    vector<int> col(matrix[0].size(), 0);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        if (row[i] == 1)
        {
            int r = i, j = 0;
            while (j < matrix[0].size())
            {
                matrix[r][j] = 0;
                ++j;
            }
        }
    }

    for (int i = 0; i < col.size(); i++)
    {
        if (col[i] == 1)
        {
            int c = i, j = 0;
            while (j < matrix.size())
            {
                matrix[j][c] = 0;
                ++j;
            }
        }
    }
}

int reversePairs1(vector<int> &nums)
{
    int ans = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (size_t j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] > 2 * nums[j])
            {
                ++ans;
            }
        }
    }

    return ans;
}

void setZeroes3(vector<vector<int>> &matrix)
{
    bool flag = false;

    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 1; j < matrix[0].size(); j++)
        {
            if (matrix[i][0] == 0)
            {
                flag = 1;
            }
            if (matrix[i][j] == 0)
            {

                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (size_t i = matrix.size() - 1; i >= 0; i--)
    {
        for (size_t j = matrix[0].size(); j >= 1; j--)
        {
            if ((matrix[i][0] == 0) || (matrix[0][j] == 0))
            {
                matrix[i][j] = 0;
            }
        }

        if (flag)
        {
            matrix[i][0] = 0;
        }
    }
}

double myPow(double x, int n)
{
    double ans = x;

    if (n == 0)
    {
        return 1;
    }

    if (n > 0)
    {
        while (--n)
        {
            ans *= x;
        }

        return ans;
    }

    long long int nn = abs(n);
    while (--nn)
    {
        ans *= ans;
    }
    return (1 / ans);
}

double myPow2(double x, int n)
{
    double ans = 1.0;

    long long int e = abs(n);
    while (e)
    {
        if (e & 1)
        {
            ans *= x;
            e = e - 1;
        }

        else
        {
            x *= x;
            e = e / 2;
        }
    }

    if (n < 0)
    {
        ans = (1.0) / ans;
    }

    return ans;
}

int majorityElement(vector<int> &nums)
{
    int count = 1, num = nums[0];
    for (size_t i = 1; i < nums.size(); i++)
    {
        if (nums[i] == num)
        {
            ++count;
        }

        else
        {
            if (count == 0)
            {
                count = 1;
                num = nums[i];
            }
            else
                --count;
        }
    }

    return num;
}

vector<int> majorityElement2(vector<int> &nums)
{
    vector<int> ans;
    int n1 = INT_MAX, n2 = INT_MIN, c1 = 0, c2 = 0;

    for (auto i : nums)
    {
        if (n1 == i)
        {
            ++c1;
        }

        else if (n2 == i)
        {
            ++c2;
        }

        else if (c1 == 0)
        {
            n1 = i;
            c1 = 1;
        }

        else if (c2 == 0)
        {
            n2 = i;
            c1 = 1;
        }

        else
        {
            --c1, --c2;
        }
    }

    int cou1{0}, cou2 = 0;

    for (auto &&i : nums)
    {
        if (i == n1)
        {
            cou1++;
        }

        else if (i == n2)
        {
            ++cou2;
        }
    }

    if (cou1 > nums.size() / 3)
    {
        ans.push_back(n1);
    }

    if (cou2 > nums.size() / 3)
    {
        ans.push_back(n2);
    }

    return ans;
}

int recurionAns(int i, int j, int m, int n)
{
    if ((i == m) && (j == n))
    {
        return 1;
    }

    if ((i > m) || (j > n))
    {
        return 0;
    }
    else
    {
        return recurionAns(i + 1, j, m, n) + recurionAns(i, j + 1, m, n);
    }
}

int dpAns(int i, int j, int m, int n, vector<vector<int>> &ds)
{
    if ((i == m) && (j == n))
    {
        return 1;
    }

    if ((i > m) || (j > n))
    {
        return 0;
    }

    if ((ds[i][j] != -1))
    {
        return ds[i][j];
    }
    else
    {
        return ds[i][j] = dpAns(i + 1, j, m, n, ds) + dpAns(i, j + 1, m, n, ds);
    }
}

int uniquePaths2(int m, int n)
{
    vector<vector<int>> ds(m + 1, vector<int>(n + 1, -1));

    if ((n == 1) && (m == 1))
    {
        return 1;
    }
    dpAns(0, 0, m - 1, n - 1, ds);

    return ds[0][0];
}

int uniquePaths(int m, int n)
{
    int path = m + n - 2;
    double ans = 1, ans2 = 1;
    int last = 1;

    (m <= n) ? (last = m) : (last = n);

    for (size_t i = 1; i < last; i++)
    {
        ans *= (path - i + 1) / (i);
    }
    ans2 = static_cast<int>(ans);
    return ans2;
}

void nextPermutation(vector<int> &nums)
{
    // next_permutation(nums.begin(), nums.end());

    int f{-1}, s{-1};

    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            f = i;
            break;
        }
    }
    if (f < 0)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    else
    {
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[f] < nums[i])
            {
                s = i;
                break;
            }
        }
        swap(nums[f], nums[s]);
        reverse(nums.begin() + f + 1, nums.end());
    }
}

int maxProfit(vector<int> &prices)
{
    int s{0}, maxdiff{0};

    for (size_t i = 0; i < prices.size(); i++)
    {
        if (prices[i] <= prices[s])
        {
            s = i;
            for (size_t j = s + 1; j < prices.size(); j++)
            {
                if (prices[j] > prices[s])
                {
                    maxdiff = max(maxdiff, prices[j] - prices[s]);
                }
            }
        }
    }
    return maxdiff;
}

int maxProfit2(vector<int> &prices)
{
    int s{0}, maxdiff{0};

    for (size_t i = 1; i < prices.size(); i++)
    {
        if (prices[i] < prices[s])
        {
            s = i;
        }
        else
        {
            maxdiff = max(maxdiff, prices[i] - prices[s]);
        }
    }
    return maxdiff;
}

void swap2(vector<vector<int>> &v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        for (size_t j = 0; j <= i; j++)
        {
            swap(v[i][j], v[j][i]);
        }
    }

    for (size_t i = 0; i < v.size(); i++)
    {
        reverse(v[i].begin(), v[i].end());
    }
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> u;

    sort(intervals.begin(), intervals.end());

    if (intervals.size() == 0)
    {
        return u;
    }

    vector<int> temp = intervals[0];

    for (auto &&it : intervals)
    {
        if (temp[1] < it[0])
        {
            u.push_back(temp);
            temp = it;
        }
        else
        {
            temp[1] = max(temp[1], it[1]);
        }
    }
    u.push_back(temp);

    return u;
}

int findDuplicate(vector<int> &nums)
{
    int f{0}, s{0};

    do
    {
        f = nums[nums[f]];
        s = nums[s];
    } while (f != s);

    f = 0;
    while (f != s)
    {
        f = nums[f];
        s = nums[s];
    }

    return f;
}

vector<pair<int, int>> merge(vector<pair<int, int>> &arr)
{

    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<pair<int, int>> ans;

    for (int i = 0; i < n; i++)
    {
        int start = arr[i].first, end = arr[i].second;

        // since the intervals already lies
        // in the data structure present we continue
        if (!ans.empty())
        {
            if (start <= ans.back().second)
            {
                continue;
            }
        }

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j].first <= end)
            {
                end = arr[j].second;
            }
        }

        ans.push_back({start,
                       end});
    }

    return ans;
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> ans(m + n, 0);

    int i{0}, j{0}, ind{0};

    while ((i < m) && (j < n))
    {
        if (nums1[i] < nums2[j])
        {
            ans[ind] = nums1[i];
            ++ind;
        }
        else
        {
            ans[ind] = nums2[i];
            ++ind;
        }
    }

    while (i < m)
    {
        ans[ind] = nums1[i];
        ++ind, ++i;
    }

    while (j < m)
    {
        ans[ind] = nums2[j];
        ++ind, ++j;
    }

    nums1 = ans;
}

void merge5(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i{0}, j{0};

    while ((i < m) && (j < n))
    {
        if ((nums1[i] == 0) && (nums1[i - 1] > 0))
        {
            break;
        }

        if (nums1[i] <= nums2[j])
        {
            ++i;
        }
        else
        {
            swap(nums1[i], nums2[j]);
            for (size_t k = j + 1; k < n; k++)
            {
                if (nums2[k] >= nums2[k - 1])
                {
                    break;
                }
                else
                {
                    swap(nums2[k], nums2[k - 1]);
                }
            }
            ++i;
        }
    }

    while ((j < n))
    {
        nums1[i++] = nums2[j++];
    }
}

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    pair<int, int> P;
    int x{0}, y{0};
    long long int s{0}, s1{0}, s_{0}, p{0}, p1{0}, p_{0};

    s = (n * (n + 1)) / 2;
    for (auto &&i : arr)
    {
        s1 += i;
    }
    s_ = s - s1;

    p = (n * (n + 1) * (2 * n + 1)) / 6;
    for (auto &&i : arr)
    {
        p1 += (i * i);
    }
    p_ = p - p1;

    x = (s_ + (p_ / s_)) / 2;
    P.first = x;

    y = x - s_;
    P.second = y;

    return P;
}

pair<int, int> missingAndRepeating2(vector<int> &arr, int n)
{
    pair<int, int> P;
    int xoR = arr[0];
    int i{0}, x{0}, y{0}, set_bit_no = 0;

    for (size_t i = 1; i < n; i++)
    {
        xoR = xoR ^ arr[i];
    }

    for (size_t i = 1; i < n; i++)
    {
        xoR = xoR ^ i;
    }

    set_bit_no = (xoR) & ~(xoR - 1);

    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] & set_bit_no)
        {
            x = x ^ arr[i];
        }
        else
        {
            y = y ^ arr[i];
        }
    }

    for (size_t i = 1; i < n; i++)
    {
        if (i & set_bit_no)
        {
            x = x ^ i;
        }
        else
        {
            y = y ^ i;
        }
    }

    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            P.second = y;
            P.first = x;
            return P;
        }
    }
    P.first = y;
    P.second = x;
    return P;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), col = matrix[0].size();
    int j = 0;

    for (size_t i = 0; i < n; i++)
    {
        if (target == matrix[i][col / 2])
        {
            return 1;
        }

        if (target < matrix[i][col / 2])
        {
            for (size_t j = 0; j < col / 2; j++)
            {
                if (target == matrix[i][j])
                {
                    return 1;
                }
            }
            return 0;
        }

        if (target > matrix[i][col / 2])
        {
            for (size_t j = col / 2; j < col; j++)
            {
                if (target == matrix[i][j])
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

bool searchMatrix2(vector<vector<int>> &matrix, int target)
{
    int i{0}, j = matrix[0].size() - 1;

    while ((i < matrix.size()) && (j > 0))
    {
        if (matrix[i][j] == target)
        {
            return 1;
        }

        if (matrix[i][j] > target)
        {
            ++i;
        }
        else
        {
            --j;
        }
    }
    return 0;
}

int longestConsecutive(vector<int> &nums)
{
    map<int, int> M;
    int size = 1, maxLen = 0;

    for (size_t i = 0; i < nums.size(); i++)
    {
        M[nums[i]]++;
    }

    for (auto it = M.begin(); it != M.end(); it++)
    {
        auto cur = ++it;
        it--;
        if (cur == M.end())
        {
            break;
        }
        if ((it->first) - (cur->first) == -1)
        {
            ++size;
        }
        else
        {
            size = 1;
        }
        maxLen = max(maxLen, size);
    }

    return maxLen;
}

int longestConsecutive2(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    int size = 1, maxSize = 1;
    unordered_set<int> s;
    for (auto &&i : nums)
    {
        s.insert(i);
    }

    for (auto &&i : nums)
    {
        if (s.find(i - 1) == s.end())
        {
            while (s.find(i + 1) != s.end())
            {
                ++size;
                ++i;
            }
            maxSize = max(maxSize, size);
            size = 1;
        }
    }

    return maxSize;
}

bool searchMatrix3(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();
    int lo = 0, hig = (matrix.size() * matrix[0].size()) - 1;
    int mid = 0;

    while (lo <= hig)
    {
        mid = lo + (hig - lo) / 2;
        if (matrix[mid / n][mid % n] == target)
        {
            return 1;
        }

        if (matrix[mid / n][mid % n] < target)
        {
            hig = mid - 1;
        }

        if (matrix[mid / n][mid % n] == target)
        {
            lo = mid + 1;
        }
    }

    return 0;
}

int lengthOfLongestSubstring2(string s)
{
    int left = 0, right = 0, size = 1;
    unordered_set<char> uSet;

    while ((left < s.size()) && (right < s.size()))
    {
        if (uSet.find(s[right]) == uSet.end())
        {
            uSet.insert(s[right]);
            size = max(size, right - left + 1);
            ++right;
        }
        else
        {
            uSet.erase(s[left]);
            ++left;
        }
    }
    return size;
}

bool xorOp(vector<int> &A, int B)
{
    if (A.size() == 0)
    {
        return 0;
    }
    int x = 0;

    for (size_t i = 0; i < A.size(); i++)
    {
        x = x ^ A[i];
    }

    if (x == B)
    {
        return 1;
    }

    return 0;
}

void subarray(vector<int> &A, vector<int> &ds, int B, int &ans, int i)
{
    if (i == A.size())
    {
        if (xorOp(ds, B))
        {
            ++ans;
        }
        // ds.clear();
        return;
    }

    ds.push_back(A[i]);
    subarray(A, ds, B, ans, i + 1);
    ds.pop_back();
    subarray(A, ds, B, ans, i + 1);
}

int subarraysXor(vector<int> &arr, int x)
{
    int ans{0};

    vector<int> ds, ds2;
    subarray(arr, ds, x, ans, 0);
    return ans;
}

int subarraysXor2(vector<int> &A, int B)
{
    int ans{0};

    vector<int> ds;
    for (size_t num = 0; num < (pow(2, A.size())); num++)
    {
        for (size_t i = 0; i < A.size(); i++)
        {
            if (num & (1 << i))
            {
                ds.push_back(A[i]);
            }
        }
        if (xorOp(ds, B))
        {
            ++ans;
        }
        ds.clear();
    }

    return ans;
}

double myPow3(double x, int n)
{
    double ans = 1.0;
    bool f = 0;
    long long int po = 1;
    (n < 0) ? (po = abs(n), f = 1) : (po = abs(n), f = 0);

    while (po != 0)
    {
        if (po & 1)
        {
            ans *= x;
            po = po - 1;
        }
        else
        {
            x *= x;
            po /= 2;
        }
    }
    if (f)
        return 1 / ans;

    return ans;
}

vector<int> majorityElement21(vector<int> &nums)
{
    int num1 = -1, num2 = 0, count1 = 0, count2 = 0, n = nums.size();

    for (auto &&i : nums)
    {
        if (num1 == i)
        {
            ++count1;
        }
        else if (num2 == i)
        {
            ++count2;
        }
        else if (count1 == 0)
        {
            count1 = 1;
            num1 = i;
        }
        else if (count2 == 0)
        {
            count2 = 1;
            num2 = i;
        }
        else
        {
            --count1;
            --count2;
        }
    }

    vector<int> ans;
    count1 = 0;
    count2 = 0;

    for (auto &&i : nums)
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

    if (count1 > nums.size() / 3)
    {
        ans.push_back(num1);
    }
    if (count2 > nums.size() / 3)
    {
        ans.push_back(num2);
    }

    return ans;
}

void path(int i, int j, int m, int n, int &ans)
{
    if ((i >= m) || (j >= n))
    {
        return;
    }
    if ((i == m - 1) && (j == n - 1))
    {
        ++ans;
        return;
    }

    path(i + 1, j, m, n, ans);
    path(i, j + 1, m, n, ans);
}

int uniquePath(int m, int n)
{
    int ans{0};
    path(0, 0, m, n, ans);
    return ans;
}

int findPath(int i, int j, int m, int n, vector<vector<int>> &arr)
{
    if ((i >= m) || (j >= n))
    {
        return 0;
    }
    if ((i == m - 1) && (j == n - 1))
    {
        return 1;
    }

    if (arr[i][j] == 0)
    {
        arr[i][j] = findPath(i + 1, j, m, n, arr) + findPath(i, j + 1, m, n, arr);
        return arr[i][j];
    }
    else
    {
        return arr[i][j];
    }
}

int uniquePaths21(int m, int n)
{
    int ans = 0;

    vector<vector<int>> arr(m, vector<int>(n, 0));
    ans = findPath(0, 0, m, n, arr);
    return arr[0][0];
}

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ans;
    unordered_map<int, int> u;

    for (auto i = 0; i < nums.size(); i++)
    {
        if (u.find(target - nums[i]) == u.end())
        {
            u.insert({nums[i], i});
        }
        else
        {
            auto it = u.find(target - nums[i]);
            ans.push_back(it->second);
            ans.push_back(i);
            return ans;
        }
    }
    return ans;
}

void reverseMerge(int begin, int mid, int end, vector<int> &ans, vector<int> &nums)
{
    int leftS = mid - begin + 1, rightS = end - mid;
    int *leftA = new int[leftS];
    int *rightA = new int[rightS];

    for (size_t i = 0; i < leftS; i++)
    {
        leftA[i] = nums[i];
    }

    for (size_t i = 0; i < rightS; i++)
    {
        rightA[i] = nums[mid + 1 + i];
    }

    auto i = 0, j = 0, k = begin;

    while ((i < leftS) && (j < rightS))
    {
        if (leftA[i] <= rightA[j])
        {
            nums[k] = leftA[i];
            i++, k++;
        }
        else
        {
            if (leftA[i] > (2 * rightA[j]))
            {
                ans[0] = ans[0] + 1;
            }
            nums[k] = rightA[j];
            j++, k++;
        }
    }

    while (i < leftS)
    {
        nums[k++] = leftA[i];
        i++;
    }
    while (j < rightS)
    {
        nums[k++] = rightA[j];
        j++;
    }
}

void reverseMergeSort(int begin, int end, vector<int> &ans, vector<int> &nums)
{
    if (begin >= end)
        return;

    auto mid = (begin + (end - begin) / 2);
    reverseMergeSort(begin, mid, ans, nums);
    reverseMergeSort(mid + 1, end, ans, nums);
    reverseMerge(begin, mid, end, ans, nums);
}

int reversePairs(vector<int> &nums)
{
    vector<int> ans(1, 0);
    reverseMergeSort(0, nums.size() - 1, ans, nums);
    return ans[0];
}

int maxLen(vector<int> &A, int n)
{
    int size = 0, sum = 0, maxSize = 0;
    for (size_t i = 0; i < n; i++)
    {
        sum = A[i];
        for (size_t j = i + 1; j < n; j++)
        {
            sum += A[j];
            if (sum == 0)
            {
                size = j - i;
                maxSize = max(size + 1, maxSize);
            }
        }
        size = 0;
        sum = 0;
    }
    return maxSize;
}

bool binarySearch(vector<int> &nums, int target, int begin)
{
    int end = nums.size() - 1;

    while (begin <= end)
    {
        auto mid = (begin + (end - begin) / 2);

        if (nums[mid] == target)
        {
            return 1;
        }

        if (target < nums[mid])
        {
            end = mid - 1;
        }

        if (target > nums[mid])
        {
            begin = mid + 1;
        }
    }

    return 0;
}

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    vector<int> vec;
    set<vector<int>> s;
    sort(nums.begin(), nums.end());
    int sum = 0;

    for (size_t i = 0; i < nums.size(); i++)
    {
        sum = nums[i];
        for (size_t j = i + 1; j < nums.size(); j++)
        {
            sum += nums[j];
            for (size_t k = j + 1; k < nums.size(); k++)
            {
                sum += nums[k];
                if (binarySearch(nums, target - sum, k + 1))
                {
                    vec.push_back(nums[i]);
                    vec.push_back(nums[j]), vec.push_back(nums[k]), vec.push_back(target - sum);
                    s.insert(vec);
                    vec.clear();
                    sum -= nums[k];
                    break;
                }
                sum -= nums[k];
            }
            sum -= nums[j];
        }
        sum = 0;
    }

    for (auto it = s.begin(); it != s.end(); it++)
    {
        ans.push_back(*it);
    }

    return ans;
}

vector<vector<int>> fourSum2(vector<int> &nums, int target)
{
    vector<int> vec;
    set<vector<int>> s;
    sort(nums.begin(), nums.end());
    int sum = 0;

    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] == nums[i + 1])
        {
            continue;
        }
        sum = nums[i];
        for (size_t j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] == nums[j + 1])
            {
                continue;
            }
            sum += nums[j];
            for (size_t k = j + 1; k < nums.size(); k++)
            {
                if (nums[k] == nums[k + 1])
                {
                    continue;
                }
                sum += nums[k];
                if (binarySearch(nums, target - sum, k + 1))
                {
                    vec.push_back(nums[i]);
                    vec.push_back(nums[j]), vec.push_back(nums[k]), vec.push_back(target - sum);
                    s.insert(vec);
                    vec.clear();
                }
                sum -= nums[k];
            }
            sum -= nums[j];
        }
        sum = 0;
    }

    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

vector<vector<int>> arraySub(vector<int> v)
{
    vector<int> ds;
    vector<vector<int>> ans;

    int i = 0, j = 0;

    while (i < v.size() - 1)
    {
        if (j == v.size())
        {
            ++i;
            j = i;
            ans.push_back(ds);
            ds.clear();
        }
        ds.assign(v.begin() + i, v.begin() + j + 1);
        ans.push_back(ds);
        ds.clear();
        ++j;
    }
    return ans;
}

int subarraysXor3(vector<int> &arr, int x)
{
    vector<int> ds;
    int ans = 0;
    int i = 0, j = 0;

    while (i < arr.size() - 1)
    {
        if (j == arr.size())
        {
            ++i;
            j = i;
            if (xorOp(ds, x))
            {
                ++ans;
            }
            ds.clear();
        }
        ds.assign(arr.begin() + i, arr.begin() + j + 1);
        if (xorOp(ds, x))
        {
            ++ans;
        }
        ds.clear();
        ++j;
    }
    return ans;
}

int maxLen4(vector<int> &A, int n)
{
    int sum = 0, maxLen = 0, len = 0;
    unordered_map<int, int> uMap;

    for (size_t i = 0; i < A.size(); i++)
    {
        sum += A[i];
        if (sum == 0)
        {
            maxLen = i + 1;
        }
        else if ((uMap.find(sum) == uMap.end()))
        {
            uMap.insert({sum, i});
        }
        else
        {
            len = (i - uMap.find(sum)->second) + 1;
            maxLen = max(maxLen, len);
        }
    }
    return maxLen;
}

int subarraysXor4(vector<int> &arr, int x)
{
    int count = 0, xr = 0, y = 0;
    unordered_map<int, int> u;

    for (auto &&i : arr)
    {
        xr = xr ^ i;
        if (xr == x)
        {
            ++count;
        }

        y = xr ^ x;

        if (u.find(y) != u.end())
        {
            count = count + (u[y]);
        }
        u[xr]++;
    }

    return count;
}

int lengthOfLongestSubstring(string s)
{
    if (s.size() == 0)
    {
        return 0;
    }
    int size = 1, maxSize = 1, l = 0, r = 0;

    unordered_map<char, int> u;
    while ((r < s.length()))
    {
        if (u.find(s[r]) != u.end())
        {
            l = max(u[s[r]] + 1, l);
        }
        u[s[r]] = r;

        maxSize = max(r - l + 1, maxSize);
        ++r;
    }
    return maxSize;
}

long long int mergeAns(long long *arr, int begin, int mid, int end)
{
    long long int ans = 0;
    int leftL = mid - begin + 1;
    int rightL = end - mid;

    auto *la = new int[leftL], *ra = new int[rightL];

    for (size_t i = 0; i < leftL; i++)
    {
        la[i] = arr[i];
    }

    for (size_t i = 0; i < rightL; i++)
    {
        ra[i] = *(arr + mid + 1 + i);
    }

    int i{0}, j{0}, ind = begin;

    while ((i < leftL) && (j < rightL))
    {
        if ((la[i] <= ra[j]))
        {
            arr[ind] = la[i];
            ++i;
        }
        else
        {
            arr[ind] = ra[j];
            ++j;
            ans = ans + (mid - i);
        }
        ++ind;
    }

    while ((i < leftL))
    {
        arr[ind++] = la[i++];
    }

    while ((j < rightL))
    {
        arr[ind++] = ra[j++];
    }
    return ans;
}

int merge2(long long *arr, int arr2[], int begin, int end)
{
    long long int ans = 0;

    if (begin < end)
    {
        auto mid = begin + (end - begin) / 2;
        ans += merge2(arr, arr2, begin, mid);
        ans += merge2(arr, arr2, mid + 1, end);
        ans += mergeAns(arr, begin, mid, end);
    }
    return ans;
}

long long getInversions(long long *arr, int n)
{
    long long int ans{0};
    int arr2[n];
    ans = merge2(arr, arr2, 0, n - 1);

    return ans;
}
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int count = 0;
    ListNode *temp = head, *r = nullptr;

    while (temp)
    {
        ++count;
        temp = temp->next;
    }
    temp = head;
    r = temp;
    count -= n;
    while (count--)
    {
        temp = temp->next;
    }
    temp = temp->next->next;
    return head;
}

ListNode *removeNthFromEnd(ListNode *&head, int n)
{
    int count = 0;
    ListNode *temp = head;

    while (temp)
    {
        ++count;
        temp = temp->next;
    }
    if ((n == 1) && (count == n))
    {
        return nullptr;
    }
    if (count == n)
    {
        return head->next;
    }

    --count;
    temp = head;
    count -= n;

    while (count > 0)
    {
        temp = temp->next;
        --count;
    }
    temp->next = temp->next->next;
    return head;
}

ListNode *removeNthFromEnd2(ListNode *head, int n)
{
    ListNode *newNode = new ListNode(0, head);
    ListNode *s = newNode, *f = newNode;

    for (size_t i = 0; i < n; i++)
    {
        f = f->next;
    }

    while (f->next != nullptr)
    {
        f = f->next;
        s = s->next;
    }

    s->next = s->next->next;

    return newNode->next;
}

int countHillValley(vector<int> &nums)
{
    int count = 0;

    for (int i = 1; i < nums.size() - 1; i++)
    {
        if ((nums[i] != nums[i - 1]) && (nums[i] != nums[i + 1]))
        {
            if ((nums[i] < nums[i - 1]) && (nums[i] < nums[i + 1]))
            {
                ++count;
            }
            else if ((nums[i] > nums[i - 1]) && (nums[i] > nums[i + 1]))
            {
                ++count;
            }
        }
        else
        {
            int j = i - 1, k = i + 1;
            while ((nums[j] == nums[j + 1]))
            {
                --j;
                if (j < 0)
                {
                    break;
                }
            }
            while ((nums[k] == nums[k - 1]) && (k < nums.size()))
            {
                ++k;
                if (k >= nums.size())
                {
                    break;
                }
            }

            if ((j < 0))
            {
                continue;
            }
            if (k >= nums.size())
            {
                continue;
            }

            if ((nums[i] < nums[j]) && (nums[i] < nums[k]))
            {
                ++count;
            }
            else if ((nums[i] > nums[j]) && (nums[i] > nums[k]))
            {
                ++count;
            }
            i = k - 1;
        }
    }

    return count;
}

void deleteNode(ListNode *node)
{
    node->val = node->next->val;
    node->next = node->next->next;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    string s1 = "", s2 = "";
    ListNode *d1 = l1, *d2 = l2;
    int n1 = 0, n2 = 0, sum = 0, dn = 0;
    ListNode *newNode = new ListNode(), *head = newNode;
    while (d1)
    {
        s1 += to_string(d1->val);
        d1 = d1->next;
    }
    while (d2)
    {
        s2 += to_string(d2->val);
        d2 = d2->next;
    }
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    n1 = stoi(s1);
    n2 = stoi(s2);
    sum = n1 + n2;

    if (sum == 0)
    {
        newNode->next = new ListNode();
    }
    while (sum > 0)
    {
        dn = sum % 10;
        sum = sum / 10;
        newNode->next = new ListNode(dn);
        newNode = newNode->next;
    }

    return head->next;
}

ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2)
{
    ListNode *d1 = l1, *d2 = l2;
    int n1 = 0, n2 = 0, sum = 0, dn = 0;
    ListNode *newNode = new ListNode(), *head = newNode;

    while (d1)
    {
        n1 += (d1->val * (pow(10, dn)));
        d1 = d1->next;
        ++dn;
    }
    dn = 0;
    while (d2)
    {
        n2 += (d2->val * (pow(10, dn++)));
        d2 = d2->next;
    }

    sum = n1 + n2;

    if (sum == 0)
    {
        newNode->next = new ListNode();
    }
    while (sum > 0)
    {
        dn = sum % 10;
        sum = sum / 10;
        newNode->next = new ListNode(dn);
        newNode = newNode->next;
    }
    return head->next;
}

ListNode *addTwoNumbers21(ListNode *l1, ListNode *l2)
{
    int sum = 0, carry = 0;
    ListNode *newNode = new ListNode(), *head = newNode;

    while ((l1 != nullptr) || (l2 != nullptr) || (carry))
    {
        sum = 0;
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;
        carry = sum / 10;
        newNode->next = new ListNode(sum % 10);
        newNode = newNode->next;
    }

    return head->next;
}

bool hasCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    if (head == nullptr)
    {
        return 0;
    }

    if (head->next != nullptr)
    {
        while ((fast) && (fast->next))
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return 1;
            }
        }
    }
    return 0;
}

bool hasCycle2(ListNode *head)
{
    unordered_set<ListNode *> nodeSet;
    while ((nodeSet.find(head) == nodeSet.end()) && (head))
    {
        nodeSet.insert(head);
        head = head->next;
    }

    if (head == nullptr)
    {
        return false;
    }
    return true;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    unordered_set<ListNode *> nodeSet;
    while (headA)
    {
        nodeSet.insert(headA);
        headA = headA->next;
    }

    while ((nodeSet.find(headB) == nodeSet.end()) && (headB))
    {
        headB = headB->next;
    }
    if (headB == nullptr)
    {
        return nullptr;
    }
    return headB;
}

ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB)
{
    ListNode *h1 = headA, *h2 = headB;

    while ((h1) || (h2))
    {
        if ((h1 == h2) && (h1 != nullptr) && (h2 != nullptr))
        {
            return h1;
        }

        if (h1 == nullptr)
        {
            h1 = headB;
            continue;
        }
        if (h2 == nullptr)
        {
            h2 = headA;
            continue;
        }
        h1 = h1->next;
        h2 = h2->next;
    }

    return nullptr;
}

ListNode *getIntersectionNode3(ListNode *headA, ListNode *headB)
{
    ListNode *h1 = headA, *h2 = headB;
    if (h1 == NULL || h2 == NULL)
    {
        return NULL;
    }

    while (h1 != h2)
    {
        h1 = (h1 == NULL) ? (headB) : (headA->next);
        h2 = (h2 == NULL) ? (headA) : (headB->next);
    }
    return h1;
}

bool isPalindrome(ListNode *head)
{
    ListNode *s = head, *f = head, *d = s, *prev = nullptr;
    int count = 1;
    while ((f) && (f->next))
    {
        ++count;
        d = s;
        s = s->next;
        f = f->next->next;
    }

    // for single node
    if (count)
    {
        return true;
    }

    // Even ke liye
    if (f == nullptr)
    {
        d->next = nullptr;
    }

    // For odd no of node
    else if (f->next == nullptr)
    {
        d->next = nullptr;
        d = s;
        s = s->next;
    }

    f = s->next;
    while (f)
    {
        s->next = prev;
        prev = s;
        s = f;
        f = f->next;
    }
    s->next = prev;
    prev = head;

    while (s && prev)
    {
        if (s->val != prev->val)
        {
            return false;
        }
        s = s->next;
        prev = prev->next;
    }

    return true;
}

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

// } Driver Code Ends

/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

/*  Function which returns the  root of
    the flattened linked list. */
Node *merge(Node *left, Node *right)
{
    Node *temp = new Node(0), *res = temp;

    while (left && right)
    {
        if (left->data <= right->data)
        {
            temp->bottom = left;
            left = left->bottom;
            temp = temp->bottom;
        }
        else
        {
            temp->bottom = right;
            right = right->bottom;
            temp = temp->bottom;
        }
    }

    if (left)
    {
        temp->bottom = left;
    }
    else
    {
        temp->bottom = right;
    }

    return res->bottom;
}

Node *flatten(Node *root)
{
    if (root == NULL || root->next == nullptr)
    {
        return root;
    }

    Node *right = flatten(root->next);
    return merge(root, right);
}

ListNode *detectCycle(ListNode *head)
{
    unordered_set<ListNode *> nodeSet;

    while ((nodeSet.find(head) == nodeSet.end()) && (head != nullptr))
    {
        nodeSet.insert(head);
        head = head->next;
    }

    return head;
}

ListNode *detectCycle2(ListNode *head)
{
    ListNode *fast = head, *slow = head;

    while (fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            fast = head;
            break;
        }
    }

    while (fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

ListNode *reverseKGroup(ListNode *&head, int k, int flag = 0)
{
    ListNode *currptr = head, *prevPtr = nullptr, *nextPtr = nullptr;
    int count = 0;

    if (flag < k)
    {
        while ((currptr != nullptr) && (count < k))
        {
            nextPtr = currptr->next;
            currptr->next = prevPtr;
            prevPtr = currptr;
            currptr = nextPtr;
            ++count;
        }
        k -= count;
        flag += count;
        if (nextPtr != nullptr)
        {
            head->next = reverseKGroup(nextPtr, k, flag);
        }
        return prevPtr;
    }

    return currptr;
}

int removeDuplicates(vector<int> &nums)
{
    int num = nums[0], ind = 1;

    for (size_t i = 1; i < nums.size(); i++)
    {
        if (nums[i] != num)
        {
            num = nums[i];
            swap(nums[i], nums[ind++]);
        }
    }

    return ind;
}

ListNode *rotateRight(ListNode *head, int k)
{
    ListNode *prev = head, *last = head, *temp = head;

    int len = 0;

    if ((last == NULL) || (last->next == NULL))
    {
        return last;
    }

    while (temp)
    {
        temp = temp->next;
        ++len;
    }
    temp = head;

    if (k % len == 0)
    {
        return head;
    }

    if (k > len)
    {
        k = k % len;

        while (k > 0)
        {
            while (last->next != nullptr)
            {
                prev = last;
                last = last->next;
            }
            prev->next = nullptr;
            last->next = temp;
            temp = last;
            --k;
        }
    }
    else
    {
        while (k > 0)
        {
            while (last->next != nullptr)
            {
                prev = last;
                last = last->next;
            }
            prev->next = nullptr;
            last->next = temp;
            temp = last;
            --k;
        }
    }
    return temp;
}

// Better
ListNode *rotateRight2(ListNode *head, int k)
{
    ListNode *temp = head;

    int len = 1;

    if ((temp == NULL) || (temp->next == NULL) || (k == 0))
    {
        return head;
    }

    while (temp->next != nullptr)
    {
        temp = temp->next;
        ++len;
    }
    temp->next = head;
    k = k % len;
    k = len - k;

    while (k--)
    {
        temp = temp->next;
    }
    head = temp->next;
    temp->next = nullptr;
    return head;
}

vector<vector<int>> threeSum2(vector<int> &nums)
{
    vector<vector<int>> ans;
    unordered_map<int, int> hash;
    vector<int> vec;
    set<vector<int>> uSet;

    for (size_t i = 0; i < nums.size(); i++)
    {
        hash[nums[i]]++;
    }

    for (size_t i = 0; i < nums.size(); i++)
    {
        hash[nums[i]]--;
        for (size_t j = i + 1; j < nums.size(); j++)
        {
            hash[nums[j]]--;
            int a = -1 * (nums[i] + nums[j]);
            if ((hash.find(a) != hash.end()) && (hash.find(a)->second > 0))
            {
                vec.push_back(nums[i]);
                vec.push_back(nums[j]);
                vec.push_back(a);
                sort(vec.begin(), vec.end());
                uSet.insert(vec);
                vec.clear();
            }
            hash[nums[j]]++;
        }
        hash[nums[i]]++;
    }
    ans.assign(uSet.begin(), uSet.end());
    return ans;
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int ind = 0, left = 1, right = nums.size() - 1;

    for (ind = 0; ind < (int)(nums.size()) - 2; ind++)
    {
        if ((ind == 0) || (ind > 0 && nums[ind] != nums[ind - 1]))
        {
            left = ind + 1, right = (int)(nums.size()) - 1;
            int a = 0 - (nums[ind]);
            while (left < right)
            {
                if (nums[left] + nums[right] == a)
                {
                    vector<int> vec;
                    vec.push_back(nums[ind]);
                    vec.push_back(nums[left]);
                    vec.push_back(nums[right]);
                    ans.push_back(vec);

                    while (left < right && (nums[left] == nums[left + 1]))
                        left++;
                    while (left < right && (nums[right] == nums[right - 1]))
                        right--;

                    left++, right--;
                }
                else if (nums[left] + nums[right] < a)
                {
                    ++left;
                }
                else
                {
                    right--;
                }
            }
        }
    }
    return ans;
}

int maxMeetings(int start[], int end[], int n)
{
    int count = 1;
    vector<vector<int>> vec(n, vector<int>(2));

    for (size_t i = 0; i < n; i++)
    {
        vec[i][0] = end[i];
        vec[i][1] = start[i];
    }
    sort(vec.begin(), vec.end());
    int last = vec[0][0];

    for (size_t i = 1; i < n; i++)
    {
        if (vec[i][1] > last)
        {
            ++count;
            last = vec[i][0];
        }
    }

    return count;
}

vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
{
    vector<vector<int>> vec;
    vector<int> dummy;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    for (size_t i = 0; i < nums1.size(); i++)
    {
        if ((i == 0) || (i > 0 && nums1[i] != nums1[i - 1]))
        {
            if (binary_search(nums2.begin(), nums2.end(), nums1[i]) == false)
            {
                dummy.push_back(nums1[i]);
            }
        }
    }
    vec.push_back(dummy);
    dummy.clear();

    for (size_t i = 0; i < nums2.size(); i++)
    {
        if ((i == 0) || (i > 0 && nums2[i] != nums2[i - 1]))
        {
            if (binary_search(nums1.begin(), nums1.end(), nums2[i]) == false)
            {
                dummy.push_back(nums2[i]);
            }
        }
    }
    vec.push_back(dummy);
    return vec;
}

int minDeletion(vector<int> &nums)
{
    int ind = 0, siz = 1;
    vector<int> dummy;

    if ((nums.size() == 1))
    {
        return 1;
    }
    for (size_t i = 0; i < nums.size() - 1; i++)
    {
        if (((ind & 1) == 0) && (nums[i] == nums[i + 1]))
        {
            // ++ind;
            continue;
        }
        else
        {
            ++ind;
            dummy.push_back(nums[i]);
        }
    }

    if (nums[nums.size() - 2] != nums[nums.size() - 1])
    {
        dummy.push_back(nums[nums.size() - 1]);
    }

    if ((dummy.size() & 1) == 1)
    {
        dummy.pop_back();
    }

    siz = nums.size() - dummy.size();
    nums = dummy;
    return siz;
}

// Comparator function
bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second)
    {
        return true;
    }
    else if (p1.second == p2.second)
    {
        if (p2.first > p1.first)
        {
            return 1;
        }
    }
    return 0;
}

int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    n = ((n + 1) * (n) / 2);

    int sum = 0;
    sum = accumulate(nums.begin(), nums.end(), sum);

    return n - sum;
}

bool remove(vector<int> &vec, int a, int d)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (vec[i] < a)
        {
            vec[i] = d;
            return 1;
        }
    }
    return 0;
}

int findPlatform(int arr[], int dep[], int n)
{
    vector<int> vec;
    sort(arr, arr + n);
    sort(dep, dep + n);

    int count = 1;
    vec.push_back(dep[0]);

    for (size_t i = 1; i < n; i++)
    {
        if (arr[i] > vec[vec.size() - 1])
        {
            vec[vec.size() - 1] = dep[i];
        }
        else
        {
            if (remove(vec, arr[i], dep[i]) == 0)
            {
                ++count;
                vec.push_back(dep[i]);
            }
        }
    }

    return count;
}

// More Optimized Way
int findPlatform2(int arr[], int dep[], int n)
{
    int arrInd = 1, depInd = 0, platCount = 1, maxCount = 1;
    sort(arr, arr + n);
    sort(dep, dep + n);

    while ((arrInd < n) && (depInd < n))
    {
        if (arr[arrInd] > dep[depInd])
        {
            ++depInd;
            --platCount;
        }
        else if (arr[arrInd] <= dep[depInd])
        {
            ++platCount;
            ++arrInd;
        }
        maxCount = max(maxCount, platCount);
    }

    return maxCount;
}

bool comparatorJob(Job j1, Job j2)
{
    if (j1.profit > j2.profit)
    {
        return true;
    }
    return false;
}

bool addProfit(vector<int> &maxD, int d)
{
    for (size_t i = d; i >= 1; i--)
    {
        if (maxD[i] == -1)
        {
            maxD[i] = d;
            return 1;
        }
    }
    return 0;
}

vector<int> JobScheduling(Job arr[], int n)
{
    vector<int> ans(2);
    sort(arr, arr + n, comparatorJob);
    int profit = 0, noJob = 0, size = 0;

    for (size_t i = 0; i < n; i++)
    {
        if (arr[i].dead > size)
        {
            size = arr[i].dead;
        }
    }
    vector<int> maxD(size + 1, -1);

    for (size_t i = 0; i < n; i++)
    {
        if (addProfit(maxD, arr[i].dead))
        {
            ++noJob;
            profit += arr[i].profit;
        }
    }

    ans[0] = noJob;
    ans[1] = profit;

    return ans;
}

bool compt(Item l1, Item l2)
{
    double res = ((double)l1.value / (double)l1.weight), res2 = (double)l2.value / (double)l2.weight;
    if (res > res2)
    {
        return 1;
    }
    return 0;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, compt);

    double ans = 0.0, ratio = 0.0;
    double weight = 0.0;

    for (size_t i = 0; i < n; i++)
    {
        if (weight + arr[i].weight < W)
        {
            weight += arr[i].weight;
            ans += arr[i].value;
        }
        else
        {
            weight = W - weight;
            ratio = (double)arr[i].value / (double)arr[i].weight;
            ans += (weight * ratio);
            break;
        }
    }

    return ans;
}

int findMinimumCoins(int amount)
{
    vector<int> vec = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int ind = vec.size() - 1, count = 0;

    while ((amount > 0) && (ind >= 0))
    {
        if (amount >= vec[ind])
        {
            while ((amount - vec[ind]) >= 0)
            {
                ++count;
                amount = amount - vec[ind];
            }
        }
        ind--;
    }

    return count;
}

double midValue(double num, int n)
{
    double res = 1.0;
    for (size_t i = 1; i < n; i++)
    {
        res *= num;
    }
    return res;
}

double findNthRootOfM(int n, long long m)
{
    double low = 1, high = m;
    double eps = 1e-6;

    while ((high - low) > (eps))
    {
        double mid = high + low / 2.0;
        double res = 1.0;
        for (size_t i = 1; i < n; i++)
        {
            res *= mid;
        }
        if (res > m)
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

int singleNonDuplicate(vector<int> &nums)
{
    int low = 0, high = nums.size() - 2;

    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (nums[mid] == nums[mid ^ 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return nums[low];
}

int search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (nums[mid] == target)
        {
            return mid;
        }

        if ((nums[low] <= nums[mid]))
        {
            if ((nums[low] <= target) && (nums[mid] >= target))
                high = mid - 1;
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (((nums[high] >= target) && (nums[mid] <= target)))
                low = mid + 1;
            else
            {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int countLessmid(vector<int> matrix, int mid)
{
    int low = 0, high = matrix.size() - 1;

    while (low <= high)
    {
        int mid = low + high >> 1;
        if (matrix[mid] <= mid)
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

int findMedian(vector<vector<int>> &matrix)
{
    int low = INT_MAX, high = 0, c = matrix[0].size();

    for (size_t i = 0; i < matrix.size(); i++)
    {
        if (matrix[i][0] < low)
        {
            low = matrix[i][0];
        }
        if (matrix[i][c] > high)
        {
            high = matrix[i][c - 1];
        }
    }

    int desired = (matrix.size() * c + 1) >> 1;
    while (low < high)
    {
        int mid = low + (mid - low) >> 1;
        int place = 0;

        for (size_t i = 0; i < matrix.size(); i++)
        {
            place += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        if (place < desired)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

double findMedianSortedArrays2(vector<int> &nums1, vector<int> &nums2)
{
    double ans = 0.0;

    int n1 = 0, n2 = 0,
        flag = (nums1.size() + nums2.size()) >> 1, count = 0, l1 = 0, l2 = 0;

    while ((n1 < nums1.size()) && (n2 < nums2.size()))
    {
        if (nums1[n1] <= nums2[n2])
        {
            if ((count == flag))
            {
                l1 = nums1[n1];
            }
            if ((count == flag - 1))
            {
                l2 = nums1[n1];
            }
            ++count;
            ++n1;
        }
        else
        {
            if ((count == flag))
            {
                l1 = nums2[n2];
            }
            if ((count == flag - 1))
            {
                l2 = nums2[n2];
            }
            ++count;
            ++n2;
        }
    }

    while ((n1 < nums1.size()))
    {
        if ((count == flag))
        {
            l1 = nums1[n1];
        }
        if ((count == flag - 1))
        {
            l2 = nums1[n1];
        }
        ++count;
        ++n1;
    }

    while ((n2 < nums2.size()))
    {
        if ((count == flag))
        {
            l1 = nums2[n2];
        }
        if ((count == flag - 1))
        {
            l2 = nums2[n2];
        }
        ++count;
        ++n2;
    }

    if (((nums1.size() + nums2.size()) & 1) == 0)
    {
        ans = (double)(l1 + l2) / 2;
        return ans;
    }
    ans = (l1);
    return ans;
}

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
    int low = 0, high = n;

    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = k - cut1;

        if (cut2 > m)
        {
            low = cut1 + 1;
            continue;
        }

        if (cut2 < 0)
        {
            high = cut1 - 1;
            continue;
        }

        int l1 = (cut1 == 0) ? (INT_MIN) : (arr1[cut1 - 1]);
        int l2 = (cut2 == 0) ? (INT_MIN) : (arr2[cut2 - 1]);

        int r1 = (cut1 == n) ? (INT_MAX) : (arr1[cut1]);
        int r2 = (cut2 == m) ? (INT_MAX) : (arr2[cut2]);

        if ((l1 <= r2) && (l2 <= r1))
        {
            return max(l1, l2);
        }

        if (l1 > r2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return 0;
}

int kthElement2(int arr1[], int arr2[], int n, int m, int k)
{
    if (m < n)
    {
        return kthElement(arr2, arr1, m, n, k);
    }
    int low = max(0, k - m), high = min(k, n);

    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = k - cut1;

        int l1 = (cut1 == 0) ? (INT_MIN) : (arr1[cut1 - 1]);
        int l2 = (cut2 == 0) ? (INT_MIN) : (arr2[cut2 - 1]);

        int r1 = (cut1 == n) ? (INT_MAX) : (arr1[cut1]);
        int r2 = (cut2 == m) ? (INT_MAX) : (arr2[cut2]);

        if ((l1 <= r2) && (l2 <= r1))
        {
            return max(l1, l2);
        }

        if (l1 > r2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return 0;
}

bool noOfStudents(vector<int> &A, int mid, int B)
{
    int ans = 0, sum = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        if (sum + A[i] > mid)
        {
            ++ans;
            sum = A[i];
            if (sum > mid)
                return 0;
        }
        else
            sum += A[i];
    }

    if (ans < B)
    {
        return 1;
    }
    return 0;
}

int books(vector<int> &A, int B)
{
    if (B > A.size())
    {
        return -1;
    }

    int low = A[0], high = 0, ans = -1;
    for (size_t i = 0; i < A.size(); i++)
    {
        high += A[i];
        low = min(low, A[i]);
    }

    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (noOfStudents(A, mid, B))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

void sumComb(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &ds, int target, int ind)
{
    if (ind == candidates.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }

    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    for (size_t i = ind; i < candidates.size(); i++)
    {
        if (target < candidates[i])
        {
            return;
        }
        if ((i != ind) && (candidates[i] == candidates[i - 1]))
        {
            continue;
        }
        ds.push_back(candidates[i]);
        sumComb(candidates, ans, ds, target - candidates[i], i);
        ds.pop_back();
    }
    return;
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> ds;
    sumComb(candidates, ans, ds, target, 0);
    return ans;
}

void sumComb2(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &ds, int target, int ind)
{
    if (ind == candidates.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }

    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    for (size_t i = ind; i < candidates.size(); i++)
    {
        if (target < candidates[i])
        {
            return;
        }
        if ((i != 0) && (candidates[i] == candidates[i - 1]))
        {
            continue;
        }
        ds.push_back(candidates[i]);
        sumComb(candidates, ans, ds, target - candidates[i], i + 1);
        ds.pop_back();
    }
    return;
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> ds;
    sumComb2(candidates, ans, ds, target, 0);
    return ans;
}

bool isPalindrome(string s, int start, int end)
{
    int i = start, j = end;

    while (i <= j)
    {
        if (s[i++] != s[j--])
        {
            return false;
        }
    }
    return true;
}

void func(string s, int ind, vector<vector<string>> &ans, vector<string> &str)
{
    if (ind == s.length())
    {
        ans.push_back(str);
        return;
    }

    for (size_t i = ind; i < s.length(); i++)
    {
        if (isPalindrome(s, ind, i))
        {
            str.push_back(s.substr(ind, i - ind + 1));
            func(s, i + 1, ans, str);
            str.pop_back();
        }
    }

    return;
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> str;
    func(s, 0, ans, str);
    return ans;
}

// converting to minutes
int getTime(string time)
{
    return (stoi(time.substr(0, 2)) * 60) + (stoi(time.substr(3)));
}

int convertTime(string current, string correct)
{
    int diff = getTime(correct) - getTime(current), op[] = {60, 15, 5, 1}, ans = 0;
    for (auto &&i : op)
    {
        ans += diff / i;
        diff %= i;
    }
    return ans;
}

// vector<vector<int>> findWinners(vector<vector<int>> &matches)
// {
//     set<int> all, loser, l2;
//     vector<int> a0, a1;
//     for (auto &&i : matches)
//     {
//         all.insert({i[0], i[1]});
//         if (loser.find(i[1]) == loser.end())
//         {
//             loser.insert(i[1]);
//         }
//         else
//         {
//             l2.insert(i[1]);
//         }
//     }
//     set_difference(all.begin(), all.end(), loser.begin(), loser.end(), back_inserter(a0));
//     set_difference(loser.begin(), loser.end(), l2.begin(), l2.end(), back_inserter(a1));

//     return {a0, a1};
// }

int largestInteger(int num)
{
    stack<int> s;
    vector<int> v;

    while (num > 0)
    {
        s.push(num % 10);
        num /= 10;
    }

    while (!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }

    for (size_t i = 0; i < v.size(); i++)
    {
        int m = 0, Odd = INT_MIN;
        for (size_t j = i + 1; j < v.size(); j++)
        {
            if ((v[i] % 2 == 0) && (v[j] % 2 == 0))
            {
                if (v[j] >= v[m])
                {
                    m = j;
                }
            }

            if ((v[i] % 2 != 0) && (v[j] % 2 != 0))
            {
                if (v[j] >= v[m])
                {
                    m = j;
                }
            }
        }
        swap(v[i], v[m]);
        m = i;
    }

    int ans = 0, ind = v.size() - 1;
    for (size_t i = 0; i < v.size(); i++)
    {
        ans += (pow(10, i) * (v[ind]));
        --ind;
    }
    return ans;
}

bool isValid(string s)
{
    stack<char> st;
    for (size_t i = 0; i < s.length(); i++)
    {
        if ((!st.empty()))
        {
            if ((s[i] == ')') && (st.top() == '(') || ((s[i] == '}') && (st.top() == '{')) || ((s[i] == ']') && (st.top() == '[')))
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        else
        {
            st.push(s[i]);
        }
    }
    return (st.empty());
}

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    stack<int> s;
    unordered_map<int, int> uMap;
    vector<int> ans;
    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        while ((!s.empty()) && (s.top() < nums2[i]))
        {
            s.pop();
        }
        if (s.empty())
        {
            uMap.insert({nums2[i], -1});
        }
        else
        {
            uMap.insert({nums2[i], s.top()});
        }
        s.push(nums2[i]);
    }

    for (auto &&i : nums1)
    {
        if (uMap.count(i))
        {
            ans.push_back(uMap[i]);
        }
    }
    return ans;
}

vector<int> Solution::prevSmaller(vector<int> &A)
{
}

int main()
{
    // cout << getInversions(arr, sizeof(arr) / sizeof(arr[0])) << endl;
    vector<int> vec = {1, 3, 4}, vec1 = {2};
    // int arr[3] = {900, 1100, 1235};
    // int dep[3] = {1000, 1200, 1240};
    // cout << findPlatform(arr, dep, 3) << endl;

    // int arr1[] = {1, 10, 10, 25, 40, 54, 79}, arr2[] = {15, 24, 27, 32, 33, 39, 48, 68, 82, 88, 90};

    // int arr1[] = {2, 3, 6, 7, 9}, arr2[] = {1, 4, 8, 10, 11};
    // cout << kthElement(arr1, arr2, 7, 11, 15) << endl;
    cout << largestInteger(1234) << endl;

    // cout << findMedianSortedArrays(vec, vec1) << endl;
    // Job jobs[] = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15}};
    // int n = sizeof(jobs) / sizeof(jobs[0]);
    // Item values[] = {{100, 20}, {120, 30}, {60, 10}};
    // cout << fractionalKnapsack(50, values, 3) << endl;

    // for (auto &&i :)
    // {
    //     cout << i << " ";
    // }

    // vector<vector<int>> v(4, vector<int>(2));

    // v = {{1}};
    // cout << searchMatrix(v, 1) << endl;

    // for (auto &&i : threeSum(vec))
    // {
    //     for (auto &&j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    // long long int arr[] = {52244275, 123047899, 493394237, 922363607, 378906890, 188674257, 222477309, 902683641, 860884025, 339100162};

    // int sum = 807, b = 0;
    // cout << 7 % 10 << endl;
    // while (sum > 0)
    // {
    //     b = sum % 10;
    //     cout << b << " ";
    //     sum = sum / 10;
    // }

    // pair  vector
    // vector<pair<int, int>> v = {{7, 1}, {6, 0}, {0, 1}, {3, 2}};
    // sort(v.begin(), v.end(), comp);
    // int a;
    return 0;
}