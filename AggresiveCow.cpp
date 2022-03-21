#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    int t = 0;
    cin>>t;
    while (t--)
    {
        int n = 0, c = 0;
        cin >> n >> c;

        vector<int> stall(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> stall[i];
        }

        sort(stall.begin(), stall.end());

        int low = stall[0], high = stall[n - 1] - low, res = 0;

        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (ifPossible(stall, mid, c))
            {
                res = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        cout << res << endl;
    }

    return 0;
}