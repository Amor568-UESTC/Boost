#include<iostream>
#include<boost/numeric/conversion/bounds.hpp>

using namespace std;
using namespace boost::numeric;

int main()
{
    //cout<<"MIN_SHORT:"<<numeric_limits<short>::min()<<endl;
    //cout<<"MIN_FLOAT:"<<numeric_limits<float>::min()<<endl;
    cout<<bounds<float>::lowest()<<endl;
    cout<<bounds<float>::highest()<<endl;
    return 0;
}

//C++11新加了lowest表示下界,感觉差不多呵呵