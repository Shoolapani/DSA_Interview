// Join and Detach
#include <bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono;

void run(int count)
{
    while (--count)
    {
        cout << " OM NAMAH SIVAY " << count << endl;
    }
    this_thread::sleep_for(chrono::seconds(2));
    cout << " Finished At last" << endl;
}

int main()
{
    thread t1(run, 10);
    cout << "main " << endl;
    t1.detach();
    // if (t1.joinable())
    // {
    //     t1.detach();
    // }
    // t1.join();
    // if (t1.joinable())
    // {
    //     t1.join();
    // }
    cout << " Main At last" << endl;
    // this_thread::sleep_for(chrono::seconds(5));
    return 0;
}