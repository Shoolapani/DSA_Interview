// Basic waraper to show smart pointer working
#include <bits/stdc++.h>

class MyInt
{
public:
    MyInt(int *p = nullptr) : data(nullptr)
    {
        data = p;
    }
    ~MyInt() { delete data; }
    int &operator*()
    {
        return *data;
    }

private:
    int *data;
};

int main()
{
    int *p = new int(10);
    MyInt myInt = MyInt(p);
    std::cout << *myInt << std::endl;
    return 0;
}