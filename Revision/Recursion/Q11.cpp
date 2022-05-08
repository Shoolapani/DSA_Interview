// Find the Safe Position

#include <bits/stdc++.h>
using namespace std;

void posFind(int index, int k, vector<int> ans, int &temp)
{
    if (ans.size() == 1)
    {
        temp = ans[0];
        return;
    }

    index = (index + k) % ans.size();
    ans.erase(ans.begin() + index);
    posFind(index, k,ans,temp);
    return;
}



int safePos(int n, int k)
{
    vector<int> ans;
    for (size_t i = 1; i <= n; i++)
    {
        ans.push_back(i);
    }
    int temp = 0;
    posFind(0, k-1, ans, temp);
    return temp;
}

int main()
{
    cout << safePos(14, 2) << endl;
    return 0;
}