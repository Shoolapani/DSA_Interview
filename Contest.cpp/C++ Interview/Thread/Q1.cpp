// Deadlock
// std::lock() these are the func not the wrapper so you have to unlock these
// order of mutex lock should be same to avoid deadlock
#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std;
using namespace std::chrono;

std::mutex m1, m2;

void thread1()
{
    m1.lock();
    std::this_thread::sleep_for(chrono::seconds(1));
    m2.lock();
    cout << " Critical section of Thread 1" << endl;
    m1.unlock();
    m2.unlock();
}

// void thread2()
// {
//     m2.lock();
//     // std::this_thread::sleep_for(chrono::seconds(1));
//     m1.lock();
//     // so change lock sequence
//     // m1.lock();
//     // m2.lock();

//     cout << " Critical section of Thread 2" << endl;

//     m2.unlock();
//     m1.unlock();
// }

// void thread2()
// {
//     std::lock(m1, m2);
//     std::this_thread::sleep_for(chrono::seconds(1));
//     cout << " Critical section of Thread 2" << endl;
//     m1.unlock();
//     m2.unlock();
// }

int main()
{
    std::thread t1(thread1);
    std::thread t2(thread2);
    t1.join();
    t2.join();
    return 0;
}