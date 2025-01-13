#include<iostream>
#include<boost/polymorphic_cast.hpp>

using namespace std;
using namespace boost;

struct base1
{
    virtual ~base1(){};
};

struct base2
{
    virtual ~base2(){};
};

struct derived:public base1,public base2
{
    virtual ~derived(){};
};

struct derived2:public base1
{
    virtual ~derived2(){};
};

int main()
{
    //int i=100;
    //cout<<static_cast<double>(i)<<endl;
    //cout<<*reinterpret_cast<double*>(&i)<<endl;
    base1* p=new derived;
    derived* pd=dynamic_cast<derived*>(p);
    base2* pb2=dynamic_cast<base2*>(p);
    string* ps=dynamic_cast<string*>(p);    //会失败变成空指针
    //cout<<ps<<endl;   //输出为0即nullptr


    return 0;
}