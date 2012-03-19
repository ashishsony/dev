#include<iostream>
#include<stdexcept>
using namespace std;
template <typename T>
class Array
{
    public:
        Array(unsigned int i=10);
        Array(const Array<T>&);
        ~Array();
        Array<T>& operator=(const Array<T>&);
        const T&  operator[](unsigned int) const throw(out_of_range);
        T&        operator[](unsigned int) throw(out_of_range);
        unsigned size() const;
    private:
    size_t SIZE;//order dependency
    T* t_;      //order dependency
};
template<typename T> Array<T>::Array(unsigned i):SIZE(i),t_(new T[SIZE])
{
}
template<typename T> Array<T>::Array(const Array<T>& ar):SIZE(ar.SIZE),t_(new T[ar.SIZE])
{
    int i=0;
    while(i<SIZE)
    {
        t_[i]=ar.t_[i];
        ++i;
    }
}
template<typename T> Arrat<T>::~Array()
{
    delete[] t_;
}
template<typename T> unsigned Array<T>::size()const
{
    return SIZE;
}
template<typename T> const T& Array<T>::operator[](unsigned i)const throw(out_of_range)
{
    if(i>=SIZE)
        throw out_of_range("out of range:const T& Array<T>::operator[]");
    return t_[i];
}
template<typename T> T& Array<T>::operator[](unsigned i)throw(out_of_range)
{
    if(i>=SIZE)
        throw out_of_range("out of range:T& Array<T>::operator[]");
    return t_[i];
}
int main()
{
}
