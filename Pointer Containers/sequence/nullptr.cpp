#include<iostream>
#include<assert.h>
#include<vector>
#include<string>
#include<boost/ptr_container/ptr_vector.hpp>

using namespace std;
using namespace boost;

class item:noncopyable
{
public:
    virtual ~item(){}
    virtual void print()=0;
};

class abstract_item:public item
{
    string name;
public:
    abstract_item(const string& str):name(str){}
    virtual ~abstract_item(){}
    virtual void print() final override
    {cout<<name<<endl;}
};

class television:public abstract_item
{
public:
    television():abstract_item("tel"){}
};

class computer:public abstract_item
{
public:
    computer():abstract_item("com"){}
};

class null_item final:public item
{virtual void print(){}};

//一般ptr_container不允许支持nullptr
int main()
{
    using ptr_vec=ptr_vector<nullable<int>>;
    ptr_vec vec;
    vec.push_back(nullptr);
    assert(vec.is_null(0));
    ptr_vector<item> v;
    v.push_back(new television);
    v.push_back(new computer);
    v.push_back(new null_item);
    for(auto& i:v)
        i.print();
    //无须空指针判断
    return 0;
}