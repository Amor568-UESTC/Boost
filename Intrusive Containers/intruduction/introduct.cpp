#include<iostream>
#include<boost/intrusive/slist.hpp>
#include<boost/core/noncopyable.hpp>


using namespace std;
using namespace boost;
using namespace boost::intrusive;

//侵入式容器的特点？
class point:noncopyable
{
public:
    int x,y;
    using node_ptr=point*;
    node_ptr next;

    point(int a,int b):x(a),y(b),next(nullptr){}
    node_ptr get_next(){return next;}
    void set_next(node_ptr p){next=p;}
};

//基类挂钩
class pnt1:public slist_base_hook<>
{
public:
    int x,y;
    pnt1(int a=0,int b=0):x(a),y(b){}
};


//成员挂钩
class pnt2
{
public:
    int x,y;
    pnt2(int a=0,int b=0):x(a),y(b){}
    slist_member_hook<> m_hook;
};

int main()
{
    slist<pnt1,cache_last<1>> s1;
    slist<pnt2,member_hook<pnt2,slist_member_hook<>,&pnt2::m_hook>> s2;
    //挂钩是实现的核心概念，侵入式修改自己的类
    return 0;
}