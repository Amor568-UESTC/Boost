#include<boost/iterator/iterator_facade.hpp>
#include<iostream>
#include<vector>

using namespace boost;
using namespace std;

//完成vector的单向迭代器
template<typename T>
class vs_iterator:
    public iterator_facade<vs_iterator<T>,T,single_pass_traversal_tag>
{
private:
    vector<T>& v;
    size_t cur_pos;
public:
    using super_type=iterator_facade<vs_iterator<T>,T,single_pass_traversal_tag>;
    using this_type=vs_iterator;
    typedef typename super_type::reference reference;

    vs_iterator(vector<T>& _v,size_t pos=0):v(_v),cur_pos(pos){}
    vs_iterator(const this_type& other):v(other.v),cur_pos(other.cur_pos){}
    void operator=(const this_type& other)
    {
        this->v=other.v;
        this->cur_pos=other.cur_pos;
    }
private:
    friend class boost::iterator_core_access;
    reference dereference() const {return v[cur_pos];}
    void increment() {++cur_pos;}
    bool equal(const this_type& other) const {return this->cur_pos==other.cur_pos;}
};

//step_iterator见书上...

int main()
{
    vector<int> v={1,2,3,4,5};
    vs_iterator<int> vsi(v),vsi_end(v,v.size());
    *vsi=9;
    copy(vsi,vsi_end,ostream_iterator<int>(cout,","));
    return 0;
}