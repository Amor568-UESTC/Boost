#include<iostream>
#include<string>
#include<vector>
#include<boost/ptr_container/ptr_vector.hpp>

using namespace std;
using namespace boost;

int main()
{
    using ptr_vec=ptr_vector<string>;
    ptr_vec vec;
    auto_ptr<string> ap(new string("123"));
    vec.push_back(ap);  //容纳自动指针，auto_ptr失去管理权
    vec.push_back(new string("xyz"));
    vec.push_back(new string("abc"));
    ptr_vec::auto_type p=vec.release(vec.begin());
    //将“123”释放给p,p可以当普通指针使用
    string *sp=p.release(); //再释放
    ptr_vec vec2;
    //vec2.transfer(vec2.end(),vec);
    //vec2得到vec的所有权
    auto pos=vec.insert(vec.begin(),new string("123"));
    ++pos;
    pos=vec.erase(pos);
    vec2=vec.clone();   //仅克隆
    
}