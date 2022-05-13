#include <bits/stdc++.h>
using namespace std;

// O(4 ^(M*N)) O(n*n)
void find(vector<vector<int>> &m, int i, int j, int n, vector<string> &ans, vector<vector<int>> &vis, string s)
{
    if ((i == n - 1) && (j == n - 1))
    {
        ans.push_back(s);
        return;
    }

    // Downward
    if ((i + 1 < n) && (!vis[i + 1][j]) && (m[i + 1][j] == 1))
    {
        vis[i][j] = 1;
        find(m, i + 1, j, n, ans, vis, s + "D");
        vis[i][j] = 0;
    }

    // Right ward
    if ((j + 1 < n) && (!vis[i][j + 1]) && (m[i][j + 1] == 1))
    {
        vis[i][j] = 1;
        find(m, i, j + 1, n, ans, vis, s + "R");
        vis[i][j] = 0;
    }

    // Left ward
    if ((j - 1 >= 0) && (!vis[i][j - 1]) && (m[i][j - 1] == 1))
    {
        vis[i][j] = 1;
        find(m, i, j - 1, n, ans, vis, s + "L");
        vis[i][j] = 0;
    }

    // Upward
    if ((i - 1 >= 0) && (!vis[i - 1][j]) && (m[i - 1][j] == 1))
    {
        vis[i][j] = 1;
        find(m, i - 1, j, n, ans, vis, s + "U");
        vis[i][j] = 0;
    }
    return;
}

vector<string> findPath2(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    vis[0][0] = 1;

    // Please see this is imp.
    if (m[0][0])
        find(m, 0, 0, n, ans, vis, "");

    if (ans.empty())
    {
        ans.push_back("-1");
    }
    return ans;
}

void find2(vector<vector<int>> &m, vector<int> di, vector<int> dj, int i, int j, int n, vector<string> &ans, vector<vector<int>> &vis, string s)
{
    if ((i == n - 1) && (j == n - 1))
    {
        ans.push_back(s);
        return;
    }

    string dir = "DLRU";
    for (size_t ind = 0; ind < 4; ind++)
    {
        int nexti = i + di[ind];
        int nextj = j + dj[ind];

        if (((nexti >= 0) & (nextj >= 0) && (nexti < n) && (nextj < n)) && (!vis[nexti][nextj]) && (m[nexti][nextj] == 1))
        {
            vis[i][j] = 1;
            find2(m, di, dj, nexti, nextj, n, ans, vis, s+dir[ind]);
            vis[i][j] = 0;
        }
    }
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
 
    // DLRU
    vector<int> di{1, 0, 0, -1};
    vector<int> dj{0, -1, 1, 0};

    // Please see this is imp.
    if (m[0][0]==1)
    {
        find2(m, di, dj, 0, 0, n, ans, vis, "");
    }

    if (ans.empty())
    {
        ans.push_back("-1");
    }
    return ans;
}

int main()
{
    vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    for (auto &&j : findPath(m, m.size()))
    {
        cout << j << " ";
    }
    return 0;
}