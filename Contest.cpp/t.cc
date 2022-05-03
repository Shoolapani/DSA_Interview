#include <bits/stdc++.h>
using namespace std;

class Emp
{
public:
    Emp()
        : sal{0.0}
    {
    }

    void promotion()
    {
        cout << "Base" << endl;
    }
    virtual void raisedSalary()
    {
        cout << "Increased Salary is now" << sal * 1.20 << endl;
    }

    void setSalary()
    {
        double x;
        cout << "Enter the Salary" << endl;
        cin >> x;
        sal = x;
    }

protected:
    double sal;
};

class Engineer : public Emp
{
public:
    void raisedSalary()
    {
        cout << "Increased Salary is now " << (double)sal << endl;
    }
};

int main()
{
    Emp *a;
    Engineer b;
    a = &b;

    a->setSalary();
    a->raisedSalary();

    return 0;
}