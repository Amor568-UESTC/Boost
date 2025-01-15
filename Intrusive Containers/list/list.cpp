#include<assert.h>
#include<boost/intrusive/list.hpp>
#include<boost/ptr_container/ptr_vector.hpp>
#include<boost/assign/ptr_list_of.hpp>

using namespace std;
using namespace boost::intrusive;
using namespace boost::assign;
using namespace boost;

class point:public list_base_hook<>
{
public:
    int x,y;
    using node_ptr=point*;
    node_ptr next;

    point(int a):x(a),y(0),next(nullptr){}
    point(int a,int b):x(a),y(b),next(nullptr){}
    node_ptr get_next(){return next;}
    void set_next(node_ptr p){next=p;}

    friend bool operator==(const point& l,const point& r)
    {return l.x==r.x&&l.y==r.y;}
    friend bool operator<(const point& l,const point& r)
    {return l.x<r.x;}
};

int main()
{
    ptr_vector<point> vec=ptr_list_of<point> (0)(1)(2)(3)(4);
    using list_t=make_list<point>::type;
    list_t lt;
    lt.push_back(vec[2]);
    lt.push_front(vec[3]);
    //以及各种不同于stl的特别用法
    return 0;
}