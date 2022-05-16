// Try lock for std::try_lock();
// is diff from mutex.try_lock();
#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;
using namespace std::chrono;

int x = 0, y = 0;
std::mutex m1, m2;

void doSomeThings(int seconds)
{
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void incrementXY(int &num, mutex &m1, const char *desc)
{
    for (size_t i = 0; i < 5; i++)
    {
        m1.lock();
        ++num;
        cout << desc << num << endl;
        m1.unlock();
        doSomeThings(2);
    }
}

void consumeXorY()
{
    int count = 5;
    int XplusY = 0;
    while (--count)
    {
        int lockResult = std::try_lock(m1, m2);
        if (lockResult == -1)
        {
            XplusY += x + y;
            x = 0;
            y = 0;
            cout << " x + y " << XplusY << endl;
        }
        // imp steps
        m1.unlock();
        m2.unlock();
    }
}


int main()
{
    std::thread t1(incrementXY, std::ref(x), std::ref(m1), " X ");
    std::thread t2(incrementXY, std::ref(y), std::ref(m2), " Y ");
    std::thread t3(consumeXorY);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}