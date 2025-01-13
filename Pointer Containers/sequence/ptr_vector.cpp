#include<iostream>
#include<assert.h>
#include<vector>
#include<boost/ptr_container/ptr_vector.hpp>

using namespace std;
using namespace boost;

//一般ptr_container不允许支持nullptr
int main()
{
    using ptr_vec=ptr_vector<string>;
    ptr_vec vec;
    vec.push_back(new string("123"));
    vec.push_back(new string("abc"));
    assert(vec.front()=="123");
    assert(vec.back()=="abc");
    ptr_vec vec2;
    vec2.assign(vec.begin(),vec.end());
    //与普通vec的不同
    vector<string> v1(10);
    ptr_vec v2(10);
    assert(v1.size()==10);
    assert(v2.size()==0);
    return 0;
}