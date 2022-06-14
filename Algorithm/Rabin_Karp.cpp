#include <bits/stdc++.h>
using namespace std;

#define d 256

void search(string pat, string str, int q)
{
	int m = pat.size();
	int n = str.size();
	int p = 0, t = 0;
	int h = 1;

	for (size_t i = 0; i < m - 1; i++)
	{
		h = (h * d) % q;
	}

	for (size_t i = 0; i < m; i++)
	{
		p = ((d * p) + pat[i]) % q;
		t = ((d * t) + str[i]) % q;
	}

	for (size_t i = 0; i <= n - m; i++)
	{
		if (p == t)
		{
			int j;
			for (j = 0; j < m; j++)
			{
				if (str[i + j] != pat[j])
				{
					break;
				}
			}

			if (j == m)
			{
				cout << "Pattern found at index " << i << endl;
			}
		}

		if (i < n - m)
		{
			t = (d * (t - str[i] * h) + str[i + m]) % q;

			if (t < 0)
			{
				t = (t + q);
			}
		}
	}
}

int main()
{
	string txt = "GEEKS FOR GEEKS";
	string pat = "GEEKS";
	int q = INT_MAX;

	// Function Call
	search(pat, txt, q);
	return 0;
}