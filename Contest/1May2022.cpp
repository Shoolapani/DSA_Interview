#include <bits/stdc++.h>
using namespace std;

string removeDigit(string number, char digit)
{
    string t = "", t2 = "";
    int ind = number.find(digit);
    int n1 = 0, t1 = 0;
    n1 = stoi(number);
    int a1 = max(n1, t1);
    string ans = "";

    t += number.substr(0, ind);
    t += number.substr(ind + 1);
    t1 = stoi(t);
    a1 = t1;
    ans = to_string(a1);

    for (size_t i = 0; i < number.size(); i++)
    {
        bool flag = 1;
        t2 += t;
        for (size_t j = i + 1; j < number.size(); j++)
        {
            if ((digit == number[i]) && (flag))
            {
                flag = 0;
                continue;
            }
            t2 += number[i];
        }
        n1 = stoi(t2);
        a1 = max(a1, n1);
        ans = to_string(a1);
        t += number[i];
        t2 = "";
    }

    return ans;
}

int main()
{
    string number = "1231";
    char digit = '1';
    cout << removeDigit(number, digit) << endl;
    return 0;
}