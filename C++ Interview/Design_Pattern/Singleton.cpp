#include <bits/stdc++.h>
using namespace std;

class SingleTon
{
public:
    ~SingleTon()
    {
        if (instanceSingleTon != nullptr)
        {
            cout << "Des....." << endl;
            delete instanceSingleTon;
            instanceSingleTon = nullptr;
        }
    }
    // SingleTon(const SingleTon &) = delete;
    // SingleTon &operator=(SingleTon const &) = delete;
    void set(int val);
    void get()
    {
        cout << this->val << endl;
    }
    static SingleTon *getInstance()
    {
        if (instanceSingleTon == nullptr)
        {
            instanceSingleTon = new (std::nothrow) SingleTon();
        }
        return instanceSingleTon;
    }

private:
    static SingleTon *instanceSingleTon;
    SingleTon() : val(0){};
    int val;
};

SingleTon *SingleTon::instanceSingleTon = nullptr;

void SingleTon::set(int val)
{
    this->val = val;
}


int main()
{
    SingleTon *singleTon = SingleTon::getInstance();
    SingleTon *singleTon2 = singleTon;
    singleTon->set(20);
    // singleTon->get();
    singleTon2->set(50);
    singleTon2->get();
    singleTon->get();


    int a = 2;
    int &b = a;
    cout << a << " " << b << endl;

    return 0;
}