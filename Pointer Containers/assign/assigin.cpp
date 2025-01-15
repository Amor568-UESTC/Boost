#include<iostream>
#include<algorithm>
#include<boost/assign.hpp>
#include<boost/assign/ptr_list_inserter.hpp>
#include<boost/assign/ptr_map_inserter.hpp>
#include<boost/assign/ptr_list_of.hpp>
#include<boost/ptr_container/ptr_vector.hpp>
#include<boost/ptr_container/ptr_deque.hpp>
#include<vector>

using namespace std;
using namespace boost;
using namespace boost::assign;

int main()
{
    vector<int> v1,v2;
    v1+=1,2,3;
    push_back(v2)()(10),20,30;
    ptr_vector<int> v=ptr_list_of<int>()(1)(2);
    //stl中的不变算法和部分修改算法可以用于指针容器中
    ptr_deque<int> dq;
    ptr_push_back(dq)(1)(2)(10)(10)(9);
    transform(dq.begin(),dq.end(),dq.begin(),[](int x){return x+3;});

    return 0;
}