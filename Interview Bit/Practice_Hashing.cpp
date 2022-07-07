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



int main()
{
    return 0;
}