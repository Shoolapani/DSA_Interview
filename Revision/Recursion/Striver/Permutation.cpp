// 60. Permutation Sequence
#include <bits/stdc++.h>
using namespace std;

// Naive approach
string getPermutation2(int n, int k)
{
    string s = "";
    for (size_t i = 1; i <= n; i++)
    {
        s += to_string(i);
    }
    do
    {
        --k;
        if (k == 0)
        {
            break;
        }
    } while (next_permutation(s.begin(), s.end()));

    return s;
}

void findPermutation(string &s, int k)
{
    int m = 0, i = 0;
    while (--k)
    {
        for (m = s.length() - 2; m >= 0; m--)
        {
            char t1 = s[m], t2 = s[m + 1];
            int n1 = t1 - '0';
            int n2 = t2 - '0';
            if (n1 < n2)
            {
                break;
            }
        }
        if (m < 0)
        {
            reverse(s.begin(), s.end());
        }
        else
        {
            for (i = s.length() - 1; i >= 0; i--)
            {
                char t1 = s[m], t2 = s[i];
                int n1 = t1 - '0';
                int n2 = t2 - '0';
                if (t2 > t1)
                {
                    break;
                }
            }
            swap(s[i], s[m]);
            reverse(s.begin() + m + 1, s.end());
        }
    }
}

string getPermutation(int n, int k)
{
    string s = "";
    for (size_t i = 1; i <= n; i++)
    {
        s += to_string(i);
    }
    findPermutation(s, k);
    return s;
}

int main()
{
    cout << getPermutation(3, 3) << endl;

    return 0;
}