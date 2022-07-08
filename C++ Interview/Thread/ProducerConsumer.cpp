// Producer Consumer Prob..
// only mutex will there so that proper synchronization will be there.....

#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std;
using namespace std::chrono;

std::mutex m1;
std::condition_variable cv;
deque<long long int> buffer;
const unsigned int maxBufferSize = 1000000;

void producer(long long int val)
{
    while ((val--))
    {
        std::unique_lock<mutex> ul(m1);
        cv.wait(ul, []()
                { return buffer.size() < maxBufferSize; });
        buffer.push_back(val);
        cout << "Produced: " << val << endl;
        ul.unlock();
        cv.notify_one();
    }
}

void consumer()
{
    while ((true))
    {
        std::unique_lock<mutex> ul(m1);
        cv.wait(ul, []()
                { return buffer.size() > 0; });
        cout << "Consumed: " << buffer.front() << endl;
        buffer.pop_front();
        ul.unlock();
        cv.notify_one();
    }
}

int main()
{
    std::thread w1(producer, 100);
    std::thread w2(consumer);
    w1.join();
    w2.join();
    return 0;
}