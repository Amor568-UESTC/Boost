#include<iostream>
#include<boost/iterator/iterator_adaptor.hpp>
#include<boost/iterator/iterator_facade.hpp>
#include<boost/type_traits.hpp>
#include<boost/static_assert.hpp>
#include<vector>

using namespace std;
using namespace boost;

//adaptor为facade子类，用法类似
template<typename P>
class array_iter:
    public iterator_adaptor<array_iter<P>,P>
{
    BOOST_STATIC_ASSERT(boost::is_pointer<P>::value);
public:
    typedef typename array_iter::iterator_adaptor_ super_type;
    array_iter(P x):super_type(x){}
};


template<typename I>
class delta_iterator:
    public iterator_adaptor<
        delta_iterator<I>,I,
        typename iterator_traits<I>::value_type,
        single_pass_traversal_tag,
        typename iterator_traits<I>::value_type const>
{
private:
    friend class boost::iterator_core_access;
    using this_type=delta_iterator;
    typedef typename this_type::iterator_adaptor_ super_type;
    typedef typename super_type::value_type m_value;    //不知道这个value_type是哪里的？
public:
    explicit delta_iterator(const I& iter):super_type(iter),m_value(0){}
private:
    using super_type::base;
    using super_type::base_reference;

    typename super_type::reference dereference() const {return m_value+*base();}
    void increment()
    {
        m_value+=*base();
        ++base_reference();
    }
};

int main()
{
    // int a[10]={1,2,3};
    // array_iter<int*> start(a),finish(a+10);
    // start++;
    // copy(start,finish,ostream_iterator<int>(cout,","));
    // cout<<endl;
    vector<int> a={1,2,3};  //存储delta值，实际为{1,3,6}
    typedef delta_iterator<decltype(a.cbegin())> delta_iter;
    delta_iter start(a.begin()),finish(a.end());
    copy(start,finish,ostream_iterator<int>(cout,","));
    return 0;
}