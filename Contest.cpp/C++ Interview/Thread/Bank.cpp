#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std;
using namespace std::chrono;

std::mutex m1;
std::condition_variable cv;

class accDetails
{
public:
    accDetails() : balance(0) {}
    void addBalance(unsigned int money)
    {
        std::lock_guard<mutex> lg(m1);
        balance += money;
        cout << "Current Balance is Rs: " << balance << endl;
        cv.notify_one();
    }

    void withdrawBalance(unsigned int money)
    {
        std::unique_lock<mutex> ul(m1);
        int val = balance;
        cv.wait(
            ul, []
            { return () ? (1) : (0); });
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

private:
    unsigned int balance;
};

int main()
{
    accDetails a;
    std::thread t1(&accDetails::addBalance, &a, 20);
    std::thread t2(&accDetails::withdrawBalance, &a, 20);
    t1.join();
    t2.join();
    return 0;
}