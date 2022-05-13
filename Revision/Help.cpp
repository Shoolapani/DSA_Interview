#include<iostream>
using namespace std;
class A{
public:
virtual void a()=0;
A(){
 cout<<"A ";
}
};
class B: public A
{
public:
B(){
 cout<<"B ";
} 
};

int main(){
A *a=new B();

return 0;
}