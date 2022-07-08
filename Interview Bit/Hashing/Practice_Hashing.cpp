#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std::chrono;
using namespace std;

// Colorful Number
int colorful(int A)
{
    string s = to_string(A);
    unordered_set<long long int> uSet;

    for (size_t i = 0; i < s.length(); i++)
    {
        if (uSet.find(s[i] - '0') != uSet.end())
        {
            return 0;
        }

        uSet.insert(s[i] - '0');
        long long int temp = s[i] - '0';

        for (size_t j = i + 1; j < s.length(); j++)
        {
            temp *= (s[j] - '0');
            if (uSet.find(temp) != uSet.end())
            {
                return 0;
            }
            uSet.insert(temp);
        }
    }

    return 1;
}

int colorful2(int A)
{

    string a = to_string(A);
    int len = a.length();

    unordered_map<long long, bool> Hash;

    for (int i = 0; i < len; i++)
    {
        long long mul = 1;
        for (int j = i; j < len; j++)
        {
            mul *= (long long)(a[j] - '0');
            if (Hash.find(mul) != Hash.end())
                return 0;

            Hash[mul] = true;
        }
    }

    return 1;
}

// Check Palindrome!
int solve(string A)
{
    unordered_map<char, int> uMap;

    for (size_t i = 0; i < A.length(); i++)
    {
        uMap[A[i]]++;
    }
    bool flag = false;

    if (A.length() & 1)
    {
        flag = true;
    }

    for (auto it = uMap.begin(); it != uMap.end(); it++)
    {
        if (it->second & 1)
        {
            if (flag)
            {
                flag = 0;
                continue;
            }
            return 0;
        }
    }
    return 1;
}

// Anagrams
vector<vector<int>> anagrams(const vector<string> &A)
{
    vector<vector<int>> ans;
    vector<int> noPair;
    unordered_map<string, int> uMap;

    for (size_t i = 0; i < A.size(); i++)
    {
        string temp = A[i];
        sort(temp.begin(), temp.end());

        if (uMap.find(temp) != uMap.end())
        {
            vector<int> ds;
            ds.emplace_back(uMap[temp]);
            ds.emplace_back(i);
            ans.push_back(ds);
        }
        else
        {
            uMap[temp] = i;
        }
    }

    for (auto it = uMap.begin(); it != uMap.end(); it++)
    {
        if (it->second & 1)
        {
        }
    }
    return ans;
}

int main()
{
    return 0;
}