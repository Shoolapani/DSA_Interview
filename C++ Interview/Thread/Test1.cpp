#include <iostream>
int main(int argc, char **argv)
{
    const int &r1 = 100;
    int v = 200;
    int &r2 = v;
    // int &r3 = 200;
    return 0;
}