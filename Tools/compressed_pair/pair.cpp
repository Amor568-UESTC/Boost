#include<boost/compressed_pair.hpp>
//#include<event2/event.h>
#include<iostream>

using std::cout;
using std::endl;

class empty1{};


//利用元编程实现比较功能
template<typename T1,typename T2> inline
boost::compressed_pair<T1,T2>
make_compressed_pair(T1 t1,T2 t2)
{
    return boost::compressed_pair<T1,T2>(t1,t2);
}

template<typename P,int Version>    //P即compressed_pair
struct _compare 
{
    bool operator()(const P& l,const P& r)
    {
        return 0;   //一个模板函数对象缺省返回false
    }
};

template<typename P>
struct _compare<P,0>    //版本0都不是空类比较两个成员
{
    bool operator()(const P& l,const P& r)
    {
        return l.first()==r.first()&&l.second()==r.second();
    }
};


template<typename P>    
struct _compare<P,1>    //版本1,T1为空类只比较T2
{
    bool operator()(const P& l,const P& r)
    {
        return l.second()==r.second();
    }
};

//...其他版本

template<typename T1,typename T2>
bool operator==(const boost::compressed_pair<T1,T2>& l,const boost::compressed_pair<T1,T2>& r)
{
    using pair_type=boost::compressed_pair<T1,T2>;
    using version=boost::details::compressed_pair_switch<T1,T2,
    boost::is_same<typename boost::remove_cv<T1>::type,
    typename boost::remove_cv<T2>::type>::value,
    boost::is_empty<T1>::value,boost::is_empty<T2>::value>;

    return _compare<pair_type,version::value>()(l,r);
}

template<typename T1,typename T2>
bool operator!=(const boost::compressed_pair<T1,T2>& l,const boost::compressed_pair<T1,T2>& r)
{
    return !(l==r);
}

int main()
{
    //std::pair<int,empty1()> p1;
    boost::compressed_pair<int,empty1> p2(10);
    //cout<<p1.first<<"  "<<p1.second<<endl;
    //cout<<p2.first()<<"  "<<p2.second()<<endl;

    cout<<sizeof(std::pair<int,empty1>)<<endl;
    cout<<sizeof(boost::compressed_pair<int,empty1>)<<endl;
    //可以看到空间利用率得到提高
    //compressed_pair适用于程序出现大量空类时
    
    auto cp1=make_compressed_pair(10,"char*");
    auto cp2=make_compressed_pair(33,"empty1");

    cout<<cp1.first()<<endl;
    cout<<cp2.second()<<endl;
    cout<<(cp1==cp2)<<endl;

    return 0;
}