#include <bits/stdc++.h>
#include <string.h>
using namespace std;

double square(double n, double st, double end)
{
    double mid = (st + end) / 2;
    double midMult = mid * mid;

    if ((midMult == n) || (abs(midMult - n) < 0.0001))
    {
        return mid;
    }
    else if (midMult < n)
    {
        return square(n, mid, end);
    }
    else
    {
        return square(n, st, mid);
    }
}

void sqrtFind(double n)
{
    double i = 1;
    double ans = 1.0;
    bool flag = true;
    while (flag)
    {
        if (i * i == n)
        {
            ans = i;
            cout << ans << endl;
            flag = false;
        }
        else if (i * i > n)
        {
            ans = square(n, i - 1, i);
            ans = round(ans);
            cout << ans << endl;
            flag = false;
        }
        ++i;
    }
}

int main()
{
    sqrtFind(10);
    sqrtFind(7);
    sqrtFind(25);
    sqrtFind(40);
    sqrtFind(1);
    sqrtFind(23);
    sqrtFind(24);
    return 0;
}