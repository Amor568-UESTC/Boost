#include<iostream>
#include<boost/assign.hpp>
#include<vector>

using namespace std;
using namespace boost::assign;

int main()
{
    vector<int> v1,v2;
    v1+=1,2,3;
    push_back(v2)()(10),20,30;
    return 0;
}