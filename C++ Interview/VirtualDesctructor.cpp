#include <bits/stdc++.h>
using namespace std;

// Compiler will not make Destructor as Virtual for us as a result Derived Destructor is not called.
// As we make Desctructor Virtual Derived Destructor is called.
// And size also increase as virtual ptr is stored.

class Base
{
public:
    Base()
    {
        cout << "Base" << endl;
    }
    // ~Base()
    // {
    //     cout << "Base Des" << endl;
    // }
    virtual ~Base()
    {
        cout << "Base Des" << endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived" << endl;
    }
    ~Derived()
    {
        cout << "Derived Des" << endl;
    }
};

int main()
{
    Base *b = new Derived();
    delete b;

    cout << "Size " << sizeof(Base) << endl;
    cout << "Size Derived " << sizeof(Derived) << endl;

    return 0;
}