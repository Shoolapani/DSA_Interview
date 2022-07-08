// it saves the states of function
// object works as functions
#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std;
using namespace std::chrono;

class mul
{
    int val;

public:
    mul(int v) : val{v}
    {
    }
    int operator()(int val)
    {
        return this->val * val;
    }
};

class foo
{
    int val;

public:
    foo(int v = 0) : val{v}
    {
    }

    foo &operator=(const foo &f) { this->val = f.val; }
};

int main()
{
    mul m(2);
    cout << m(4) << endl;
    cout << m(45) << endl;
    foo f(2), f1, f2;
    f1 = f2 = f;

    cout << () << endl;
    return 0;
}