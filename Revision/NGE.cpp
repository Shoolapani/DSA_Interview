// A Stack based C++ program to find next
// greater element for all array elements.
#include <bits/stdc++.h>
using namespace std;

/* prints element and NGE pair for all
elements of arr[] of size n */
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans(nums1.size());
    stack<int> s;
    for (int i = nums1.size() - 1; i >= 0; i--)
    {
        while ((!s.empty()) && (nums1[i] <= s.top()))
        {
            s.pop();
        }

        ans[i] = (s.empty() ? (-1) : (s.top()));
        s.push(nums1[i]);
    }
    return ans;
}

/* Driver code */
int main()
{
    int arr[] = {11, 3, 21, 3, 4, 41};
    int n = sizeof(arr) / sizeof(arr[0]);
    // printNGE(arr, n);
    return 0;
}
