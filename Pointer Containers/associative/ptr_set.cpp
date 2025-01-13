#include<iostream>
#include<assert.h>
#include<boost/ptr_container/ptr_set.hpp>
#include<boost/ptr_container/ptr_unordered_set.hpp>

using namespace std;
using namespace boost;

int main()
{
    using ptr_set_t=ptr_set<string>; 
    ptr_set_t s;
    assert(s.insert(new string("123")).second);
    assert(s.insert(new string("abc")).second);
    auto ap=s.release();
}