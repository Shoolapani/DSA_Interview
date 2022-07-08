#include <bits/stdc++.h>
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
    std::shared_ptr<foo> sp(new foo(10));
    cout << sp->get() << endl;
    std::shared_ptr<foo> sp2 = sp;
    cout << sp2->get() << endl;
    cout << sp2.use_count() << endl;
    
    // Refer.. count will not work
    std::shared_ptr<foo> &sp3=sp2;
    cout << sp2.use_count() << endl;
    cout << sp3.use_count() << endl;


    return 0;
}