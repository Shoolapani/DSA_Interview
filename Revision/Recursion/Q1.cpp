#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    virtual void funct() // V.Table
    {
        cout << "funct1"; // Funct
    }
    virtual void funct4() // V.Table
    {
        cout << "funct4"; // Funct 4
    }
};

class Derived1 : public Base
{
public:
    void funct() // Funct
    {
        cout << "funct2";
    }
};

class Derived2 : public Base
{
public:
    void funct() // Funct
    {
        cout << "funct5";
    }
};

void exm(Base &temp)
{
    temp.funct();
}

int main()
{
    Derived2 d;

    Base *b = &d;
    b->funct4();
    cout << endl;
    b->funct();
    cout << endl;
    exm(d);

    return 0;
}