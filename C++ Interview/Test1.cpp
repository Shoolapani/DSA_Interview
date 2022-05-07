#include <bits/stdc++.h>
using namespace std;

class base
{
private:
    int value;

public:
    base(int x)
    {
        value = x;
    }
    virtual void fun()
    {
    }
};

class derived
{
private:
    int a;

public:
    derived(int x, int y) : a{0}
    {
        base b(a + 10);
        b.fun(); // calls derived::fun()
    }
    void fun()
    {
        cout << "fun inside derived class" << endl;
    }
};

class ClassA
{
public:
    ClassA(int ii = 0) : i(ii) {}
    void show() { cout << "i = " << i << endl; }

private:
    int i;
};

class ClassB
{
public:
    ClassB(int xx) : x(xx) {}
    operator ClassA() const { return ClassA(x); }

private:
    int x;
};

void g(ClassA a)
{
    a.show();
}

class BaseClass
{
    int arr[10];
};

class DerivedBaseClass1 : virtual public BaseClass
{
};

class DerivedBaseClass2 : virtual public BaseClass
{
};

class DerivedClass : public DerivedBaseClass1, public DerivedBaseClass2
{
};

class A
{
public:
    virtual void print()
    {
        cout << " Inside A::";
    }
};

class B : public A
{
public:
    void print()
    {
        cout << " Inside B";
    }
};

class C : public B
{
};

int main()
{
    // ClassB b(10);
    // g(b);
    // g(20);
    // getchar();
    // cout << sizeof(DerivedClass);

    C c;

    c.print();

    return 0;
}

// int main()
// {
//     // derived d(10, 22);

//     return 0;
// }