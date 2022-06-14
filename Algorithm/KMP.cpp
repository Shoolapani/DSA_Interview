#include <bits/stdc++.h>
using namespace std;

vector<int> computeTemporaryArray(string pat)
{
    int index = 0, i = 1;
    vector<int> lps(pat.length(), 0);

    while (i < pat.length())
    {
        if (pat[i] == pat[index])
        {
            lps[i] = index + 1;
            ++i, ++index;
        }
        else
        {
            if (index != 0)
            {
                index = lps[index - 1];
            }
            else
            {
                lps[i] = 0;
                ++i;
            }
        }
    }
    return lps;
}

bool KMP(string text, string pat)
{
    int i = 0, j = 0;
    vector<int> lps = computeTemporaryArray(pat);

    while ((i < text.length()) && (j < pat.length()))
    {
        if (text[i] == pat[j])
        {
            ++i, ++j;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                ++i;
            }
        }

        if (j == pat.length())
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    cout << KMP("Mahadev", "maha") << endl;
    return 0;
}