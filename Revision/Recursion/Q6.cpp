// Tower of Hanoi
#include <bits/stdc++.h>
using namespace std;

void toh(int n, int from, int to, int aux)
{
    if (n == 0)
    {
        return;
    }
    toh(n - 1, from, aux, to);
    cout << "Moving rod " << n << " from " << from << " to " << to << " using " << aux << endl;
    toh(n - 1, aux, to, from);
    return;
}

int main()
{
    toh(3, 1, 3, 2);
    return 0;
}