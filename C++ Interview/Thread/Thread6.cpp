// 5 ways to create thread
#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std;
using namespace std::chrono;

std::mutex m;

// 1. using function pointer
// 2. using lamda funct.
auto fun = [](int x)
{while(--x){cout<<x<<endl;} };

// 3. using Function object;
class Base
{
public:
    void operator()(int x)
    {
        std::lock_guard<mutex> lg(m);
        while (x--)
        {
            cout << x << endl;
        }
    }
};

// 4. using non-static member function
class Base2
{
public:
    void funct(int x)
    {
        std::lock_guard<mutex> lg(m);
        while (x--)
        {
            cout << x << endl;
        }
    }
    // 5. using non-static member function
    static void funct2(int x)
    {
        std::lock_guard<mutex> lg(m);
        while (x--)
        {
            cout << x << endl;
        }
    }
};

int main()
{
    // std::thread t1([](int x)
    //                {while(--x){cout<<x<<endl;} },
    //                10);
    // t1.join();
    // std::thread t2(Base(), 10);
    Base2 b;
    std::thread t3(&Base2::funct, &b, 10);
    std::thread t4(&Base2::funct2, 10);
    // t2.join();
    t3.join();
    t4.join();
    return 0;
}