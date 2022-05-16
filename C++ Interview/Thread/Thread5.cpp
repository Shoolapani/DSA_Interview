// Condition  Variable -- 11/18

#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std;
using namespace std::chrono;

std::condition_variable cv;
std::mutex m;

long balance = 0;

void addMoney(int money)
{
    std::lock_guard<mutex> lg(m);
    balance += money;
    cout << "Current Balance is Rs: " << balance << endl;
    cv.notify_one();
}

void withdrawMoney(int money)
{
    std::unique_lock<mutex> ul(m);
    cv.wait(ul, []
            { return (balance != 0) ? true : false; });

    if (balance >= money)
    {
        balance -= money;
        cout << "Amount deducted is Rs: " << money << endl;
    }
    else
    {
        cout << "Amount cannot be deducted " << endl;
    }
    cout << "Current Balance is Rs: " << balance << endl;
}

int main()
{
    std::thread t1(withdrawMoney, 600);
    std::thread t2(addMoney, 700);
    t1.join();
    t2.join();
    return 0;
}