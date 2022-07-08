#include <bits/stdc++.h>
#include <unordered_map>
#include <string>
#include <thread>
using namespace std;

static bool flag = false;

void print()
{
    cout << "This thread id is " << this_thread::get_id() << endl;
    while (!flag)
    {
        cout << "Printing" << endl;
        this_thread::sleep_for(2s);
    }
}

void funct2()
{
    cout << " Shri Hari" << endl;
}

// void forecast(map<string, int> &uMap)
// {
//     while (!flag)
//     {
//         for (auto &it : uMap)
//         {
//             it.second++;
//             cout << "City"
//                  << " -----> "
//                  << " Temp..!" << endl;
//             cout << it.first << " -----> " << it.second << endl;
//         }
//         // this_thread::sleep_for(2s);
//     }
// }

int main()
{
    std::map<string, int> uMap  {
        {"Purnia", 12}, {"Bhopal", 15}, {"Delhi", 19}};
    // thread bgWorker(forecast, uMap);
    thread printLine(print);
    cin.get();
    flag = true;
    // bgWorker.join();
    // cout << "This thread id is " << this_thread::get_id() << endl;
    // // th2.join();
    printLine.join();
    // cout << "This thread id is " << this_thread::get_id() << endl;

    return 0;
}