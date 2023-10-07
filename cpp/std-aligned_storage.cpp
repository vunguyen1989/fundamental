/*
 You can use std::aligned_storage whenever you wish to decouple memory allocation from object creation.

 You claim:

 Also it is usable only with POD types.

 But this is not true. There is nothing preventing std::aligned_storage from being used with non-POD types.

 The example on cppreference provides a legitimate use case:

 template<class T, std::size_t N>
 class static_vector
 {
     // properly aligned uninitialized storage for N T's
     //     typename std::aligned_storage<sizeof(T), alignof(T)>::type data[N];
     //         std::size_t m_size = 0;
     //         ...
     //         The idea here is that once the static_vector is constructed, memory is immediately allocated for N objects of type T, but no objects of type T are created yet.
     //
     //         You cannot do that with a simple T data[N]; array member, because this would immediately run T's constructor for each element, or wouldn't even compile if T is not default-constructible.
 */
#include <iostream>
#include <type_traits>
#include <string>
 
template<class T, std::size_t N>
class static_vector
{
    // properly aligned uninitialized storage for N T's
    typename std::aligned_storage<sizeof(T), alignof(T)>::type data[N];
    std::size_t m_size = 0;
 
public:
    // Create an object in aligned storage
    template<typename ...Args> void emplace_back(Args&&... args) 
    {
        if( m_size >= N ) // possible error handling
            throw std::bad_alloc{};
 
        // construct value in memory of aligned storage
        // using inplace operator new
        new(&data[m_size]) T(std::forward<Args>(args)...);
        ++m_size;
    }
 
    // Access an object in aligned storage
    const T& operator[](std::size_t pos) const 
    {
        // note: needs std::launder as of C++17
        return *reinterpret_cast<const T*>(&data[pos]);
    }
 
    // Delete objects from aligned storage
    ~static_vector() 
    {
        std::cout << "Destructor" << std::endl;
        for(std::size_t pos = 0; pos < m_size; ++pos) {
            std::cout << "pos = " << pos << std::endl;
            // note: needs std::launder as of C++17
            reinterpret_cast<T*>(&data[pos])->~T();
        }
    }
};
 
int main()
{
    static_vector<std::string, 10> v1;
    v1.emplace_back(5, '*');
    v1.emplace_back(10, '*');
    std::cout << v1[0] << '\n' << v1[1] << '\n';
}
