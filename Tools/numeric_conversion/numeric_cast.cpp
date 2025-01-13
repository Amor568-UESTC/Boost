#include<iostream>
#include<boost/numeric/conversion/cast.hpp>

using namespace std;
using namespace boost;

int main()
{
    short s=numeric_limits<short>::max();
    int i=numeric_cast<int>(s);  //未越界可以正常转换
    //char c=static_cast<char>(s);    //会发生奇怪的错误
    char c=numeric_cast<char>(s);   //越界发生异常提醒
    cout<<(int)c<<endl;
    return 0;
}