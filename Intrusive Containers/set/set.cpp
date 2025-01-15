#include<assert.h>
#include<vector>
#include<boost/intrusive/set.hpp>
#include<boost/intrusive/unordered_set.hpp>
#include<boost/operators.hpp>
#include<boost/ptr_container/ptr_vector.hpp>
#include<boost/assign/ptr_list_of.hpp>
#include<boost/intrusive/hashtable.hpp>

using namespace std;
using namespace boost::intrusive;
using namespace boost::assign;
using namespace boost;

class point:public set_base_hook<>,less_than_comparable<point>
{
public:
    int x,y;
    using node_ptr=point*;

    point(int a):x(a),y(0){}
    point(int a,int b):x(a),y(b){}

    friend bool operator==(const point& l,const point& r)
    {return l.x==r.x&&l.y==r.y;}

    friend bool operator<(const point& l,const point& r)
    {return l.x<r.x;}
};

class point2:public unordered_set_base_hook<>
{
public:
    int x,y;

    point2(int a):x(a),y(0){}
    point2(int a,int b):x(a),y(b){}

    friend bool operator==(const point2& l,const point2& r)
    {return l.x==r.x&&l.y==r.y;}

    friend bool operator<(const point2& l,const point2& r)
    {return l.x<r.x;}

    friend size_t hash_value(const point2& p)
    {
        size_t seed=2016;
        hash_combine(seed,p.x);
        hash_combine(seed,p.y);
        return seed;
    }
};

int main()
{
    ptr_vector<point> vec=ptr_list_of<point> (0)(1)(2)(3)(4);
    using set_t=make_set<point,compare<greater<point>>>::type;  //降序的有序集合

    ptr_vector<point2> vec2=ptr_list_of<point2> (0)(1)(2)(3)(4);
    using set_t2=make_unordered_set<point2>::type;
    set_t2::bucket_type buckets[20];
    //半侵入容器需要外部额外分配辅助内存空间维护负载因子
    set_t2 s2(vec2.begin(),vec2.end(),set_t2::bucket_traits(buckets,20));
    vector<set_t2::bucket_type> buckets2(2);
    s2.rehash(set_t2::bucket_traits(&buckets2[0],2));   //重散列
    return 0;
}