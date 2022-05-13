#include <iostream>
using namespace std;
class Base
{
public:
    Base()
    {
        cout << "Base constructor is called"
             << "\n";
    }
    ~Base()
    {
        cout << "Base class object is destroyed"
             << "\n";
    }
};
class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived class constructor is called"
             << "\n";
    }
    ~Derived()
    {
        cout << "Derived class object is destroyed"
             << "\n";
    }
};
int main()
{
    Base *b = new Derived();
    delete b;
    return 0;
}