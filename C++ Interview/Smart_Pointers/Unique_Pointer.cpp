// topic unique pointer
#include <bits/stdc++.h>
#include <memory>
using namespace std;

class foo
{
public:
    foo(int x = 0) : var{x} { var = x; }
    int get()
    {
        return var;
    }
    ~foo()
    {
        cout << "Foo Dest..." << endl;
    }

private:
    int var;
};

int main()
{
    // normal
    // foo *f = new foo(10);
    // cout << f->get() << endl;
    // delete f;

    // unique pointer manages object
    std::unique_ptr<foo> uP(new foo(10));
    cout << uP->get() << endl;

    std::unique_ptr<foo> uP1;

    // This wil fail as the ownerShip it is unique;
    //  uP1 = uP;
    uP1 = std::move(uP);
    // uP==nullptr;
    cout << uP1->get() << endl;
    // cout << uP->get() << endl;
    return 0;
}