#include<iostream>
#include<boost/utility/addressof.hpp>
#include<memory>

using namespace boost;
using namespace std;

class dont_do_this
{
public:
    int x,y;
    auto operator&() 
    {return &y;}
};

//重载操作符&会导致一些问题

int main()
{
    dont_do_this ddt;
    cout<<"&ddt = "<<&ddt<<endl;
    cout<<"addressof(ddt) is "<<std::addressof(ddt)<<endl;
    cout<<"addressof(ddt) is "<<boost::addressof(ddt)<<endl;
    if((size_t)&ddt==(size_t)boost::addressof(ddt))
        cout<<"111"<<endl;
    else cout<<"000"<<endl;
    return 0;
}