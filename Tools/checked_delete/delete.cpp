#include<iostream>
#include<boost/checked_delete.hpp>
#include<boost/static_assert.hpp>

using namespace std;
using namespace boost;

class demo_class;

void do_delete(demo_class* p)
{delete p;}

//利用写自己的checked_delete
template<class Pointer> inline
void my_checked_delete(Pointer P)
{
    BOOST_STATIC_ASSERT(is_pointer<Pointer>::value);
    using T=typename remove_pointer<Pointer>::type;
    BOOST_STATIC_ASSERT(is_object<T>::value);
    BOOST_STATIC_ASSERT(!is_array<T>::value);
    BOOST_STATIC_ASSERT(sizeof(T)>0);
    delete p;
}

// class demo_class
// {
// public:
//     ~demo_class(){cout<<"dtor exec."<<endl;}
// };

int main()
{
    // auto p1=new demo_class;
    // checked_delete(p1);
    // auto p2=new demo_class[10];
    // checked_array_delete(p2);

    auto p=(demo_class*)(1996);
    //do_delete(p);             //普通delete会产生警告但不会错误，这会导致运行时的错误
    //checked_delete(p);        //对于不完整类型checked_delete会在编译时发生错误

    auto q=new int[2][2];
    my_checked_delete(q);
    return 0;
}