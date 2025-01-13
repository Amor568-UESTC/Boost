#include<iostream>
#include<string>
#include<assert.h>
#include<boost/ptr_container/ptr_map.hpp>
#include<boost/ptr_container/ptr_unordered_map.hpp>
#include<map>
#include<unordered_map>

using namespace std;
using namespace boost;

int main()
{
    using ptr_map_t=ptr_map<int,string>;
    ptr_map_t m;
    int a=1;
    m.insert(a,new string("one"));
    m.insert(10,auto_ptr<string>(new string("ten")));
    assert(m.size()==2);
    assert(m[10]=="ten");
    ptr_map<int,nullable<string>> n;    //允许空指针
    n.insert(a,new string("tenten"));
    n.insert(10,auto_ptr<string>(new string("tenten")));
    assert(n.at(10)=="tenten");
    return 0;
}