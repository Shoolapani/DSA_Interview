#include <bits/stdc++.h>
using namespace std;

typedef struct test2
{
    int arr[90];
    int l;
} re;

typedef struct test1
{
    int arr[90];
    int l;
} re1;

re f[20];
re1 f1[20];

void read(test2 *n1, test1 *n2)
{
    if (strcmp(((char *)n1->arr), "Mahadev") == 0)
    {
        
        cout << n2->arr << " Krishna" << endl;
    }
    else
    {
        cout << "zero";
    }
}

void w()
{

    memcpy(f[0].arr, "Mahadev", 20);
    memcpy(f[1].arr, "Mahadev1", 20);
    memcpy(f[2].arr, "Mahadev2", 20);

    memcpy(f1[0].arr, "Mahadev1", 20);
    memcpy(f1[1].arr, "Mahadev11", 20);
    memcpy(f1[2].arr, "Mahadev21", 20);

    return;
}

int main()
{

    w();
    read(f, f1);
    return 0;
}