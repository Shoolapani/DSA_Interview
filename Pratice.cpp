#include <bits/stdc++.h>
using namespace std;

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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    
}

int main()
{
    long long int arr[] = {2, 5, 1, 3, 4};
    cout << getInversions(arr, sizeof(arr) / sizeof(arr[0])) << endl;

    // cout << longestConsecutive(3, 7) << endl;

    vector<int> vec = {4, 2, 2, 6, 4};

    // cout << lengthOfLongestSubstring("abcaabcd") << endl;
    // cout << subarraysXor4(vec, 6) << endl;

    // for (auto &&i : twoSum(vec, 9))
    // {
    //     cout << i << " ";
    // }

    // vector<vector<int>> v(4, vector<int>(2));

    // v = {{1}};
    // cout << searchMatrix(v, 1) << endl;

    // for (auto &&i : arraySub(vec))
    // {
    //     for (auto &&j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    // long long int arr[] = {52244275, 123047899, 493394237, 922363607, 378906890, 188674257, 222477309, 902683641, 860884025, 339100162};

    return 0;
}