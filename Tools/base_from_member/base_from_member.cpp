#include<iostream>
#include<boost/utility/base_from_member.hpp>
#include<complex>

using namespace std;
using namespace boost;

class base
{
public:
    base(complex<int> c)
    {
        cout<<"base ctor"<<endl;
        cout<<c<<endl;
    }
};

class derived:public base
{
    complex<int> c;
public:
    derived(int a,int b):c(a,b),base(c)
    {
        cout<<"derived ctor"<<endl;
        cout<<c<<endl;
    }
};

class derived1:private base_from_member<complex<int>>,public base
{
    using pbase_type=base_from_member<complex<int>>;
public:
    derived1(int a,int b):pbase_type(a,b),base(member)  //成员变量名被命名为member
    {cout<<member<<endl;}
};

int main()
{
    //derived d(10,20);
    derived1 d1(10,20);
    return 0;
}