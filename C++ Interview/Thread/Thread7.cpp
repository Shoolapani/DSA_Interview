#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;
using namespace std::chrono;

/**
 * NO Deadlock
 *
 * std::lock(m1,m2)  std::lock(m1,m2);
 *
 * std::lock(m1,m2)  std::lock(m2,m1);
 *
 * std::lock(m1,m2,m3,m4)  std::lock(m2,m1),std::lock(m3,m4);
 *
 *
 *  Deadlock poss..
 * std::lock(m1,m2)  std::lock(m3,m4);
 * std::lock(m3,m4)  std::lock(m2,m1);
 *
 */

std::mutex m1, m2;
void task_a()
{
    while (1)
    {
        m1.lock();
        m2.lock();
        cout << "A" << endl;
        m1.unlock();
        m2.unlock();
    }
}

void task_b()
{
    while (1)
    {
        m2.lock();
        m1.lock();
        cout << "B" << endl;
        m2.unlock();
        m1.unlock();
    }
}

int main()
{
    std::thread t1(task_a);
    std::thread t2(task_b);
    t1.join();
    t2.join();
    return 0;
}