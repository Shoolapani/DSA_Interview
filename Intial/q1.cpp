/*
Find size of the longest subarray which forms a peak. A peak is strictly increasing at first then decreasing.

Example 1:
arr = {3, 1, 4, 1, 5, 9, 6,5,3}
ans = 4

Example 2:
arr = {2,2,2}
ans = 0

Example 3:
arr = {0,1,2,3}
ans = 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPeak(vector<int> &vec)
    {
        int maxCount = -1, count = 0;
        bool flag = false;
        for (size_t i = 1; i < vec.size(); i++)
        {
            // arr = {3, 1, 4, 1, 5, 9, 6,5,3}
            if (flag)
            {
                if (vec[i] > vec[i - 1])
                {
                    ++count;
                    continue;
                }
                else if (vec[i] < vec[i - 1])
                {
                    ++count;
                }

                if ((i != vec.size() - 1) && (vec[i + 1] < vec[i]))
                {
                    continue;
                }
                flag = false;
                maxCount = max(maxCount, count);
            }
            else if (vec[i] > vec[i - 1])
            {
                count = 0;
                ++count;
                flag = true;
            }
        }
        // if (flag)
        // {
        //     return 0;
        // }
        return maxCount + 1;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {3, 1,2};

    cout << sol.longestPeak(v);

    return 0;
}