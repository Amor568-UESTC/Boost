#include<boost/range.hpp>
#include<boost/range/counting_range.hpp>
#include<boost/range/istream_range.hpp>
#include<boost/range/irange.hpp>
#include<boost/range/join.hpp>
#include<vector>
#include<algorithm>
#include<boost/range/algorithm.hpp>
#include<boost/range/algorithm_ext.hpp>
#include<iostream>

using namespace std;
using namespace boost;

//ranges已经纳入Cpp20标准库中！

int main()
{
    vector<int> v{8,1,16,3,7,3,42};
    //sort(boost::begin(v),boost::end(v));
    //copy(v.begin(),v.end(),ostream_iterator<int>(cout,","));
    boost::erase(v,boost::remove<return_found_end>(v,3));
    //boost::copy(v,ostream_iterator<int>(cout,","));

    //int a[10];
    //auto r3=make_iterator_range(a,1,-1);    //有点像py了嗷
    //cout<<r3.size();

    //boost::copy(istream_range<int>(cin),ostream_iterator<int>(cout,","));

    vector<int> b;
    boost::copy(boost::irange(0,10),std::back_inserter(b));
    auto r1=make_iterator_range(b.begin(),b.begin()+3);
    auto r2=make_iterator_range(b.begin()+5,b.end());
    auto r3=boost::join(r1,r2);
    boost::copy(r3,ostream_iterator<int>(cout,","));
    return 0;
}