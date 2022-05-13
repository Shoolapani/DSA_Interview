#include <bits/stdc++.h>
using namespace std;

// O(N*3) O(N*3)
bool isSafe(vector<string> &board, int row, int column, int n)
{
    int dumRow = row, dupCol = column;
    while ((row >= 0) && (column >= 0))
    {
        if (board[row][column] == 'Q')
        {
            return false;
        }
        row--;
        --column;
    }
    row = dumRow;
    column = dupCol;

    while (column >= 0)
    {
        if (board[row][column] == 'Q')
        {
            return false;
        }
        --column;
    }
    row = dumRow;
    column = dupCol;

    while ((row < n) && (column >= 0))
    {
        if (board[row][column] == 'Q')
        {
            return false;
        }
        row++;
        --column;
    }

    return true;
}

void solve(vector<vector<string>> &ans, vector<string> &board, int ind, int n)
{
    if ((ind == n))
    {
        ans.push_back(board);
        return;
    }

    for (size_t i = 0; i < board.size(); i++)
    {
        if (isSafe(board, i, ind, n))
        {
            board[i][ind] = 'Q';
            solve(ans, board, ind + 1, n);
            board[i][ind] = '.';
        }
    }
    return;
}

vector<vector<string>> solveNQueens2(int n)
{
    string s(n, '.');
    vector<vector<string>> ans;
    vector<string> board(n, s);
    solve(ans, board, 0, n);
    return ans;
}

// We reduce the search time complexity
// O(N*2) O(N)
void solve2(vector<vector<string>> &ans, vector<string> &board, int ind, int n, vector<bool> &leftRow, vector<bool> &lowerDiagonal, vector<bool> &upperDiagonal)
{
    if ((ind == n))
    {
        ans.push_back(board);
        return;
    }

    for (size_t i = 0; i < board.size(); i++)
    {
        if ((!leftRow[i]) && (!lowerDiagonal[i + ind]) && (!upperDiagonal[n - 1 + ind - i]))
        {
            board[i][ind] = 'Q';
            leftRow[i] = true;
            lowerDiagonal[i + ind] = true;
            upperDiagonal[n - 1 + ind - i] = true;
            solve2(ans, board, ind + 1, n, leftRow, lowerDiagonal, upperDiagonal);
            board[i][ind] = '.';
            leftRow[i] = false;
            lowerDiagonal[i + ind] = false;
            upperDiagonal[n - 1 + ind - i] = false;
        }
    }
    return;
}

vector<vector<string>> solveNQueens(int n)
{
    string s(n, '.');
    vector<vector<string>> ans;
    vector<string> board(n, s);
    vector<bool> leftRow(n, 0);
    vector<bool> lowerDiagonal(2 * n - 1, 0);
    vector<bool> upperDiagonal(2 * n - 1, 0);
    solve2(ans, board, 0, n, leftRow, lowerDiagonal, upperDiagonal);
    return ans;
}

int main()
{
    for (auto &&i : solveNQueens(4))
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}