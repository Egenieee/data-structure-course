//
//  dynamicArray.hpp
//  Assignment1
//
//  Created by 이진희 on 2021/04/17.
//

#ifndef dynamicArray_hpp
#define dynamicArray_hpp

#include <iostream>
#include <algorithm>
#define MIN(X,Y) ((X)<(Y) ? (X) : (Y))

template <typename T> class dynamic_array {
    T* data;
    size_t n;
public:
    dynamic_array() : data(nullptr), n(0) {}
    dynamic_array(size_t _n) : n(_n) {
        data = new T[n];
    }
    ~dynamic_array() {
        if( data != nullptr){
            delete[] data;
        }
    }
    T& operator[](int index) {
        return data[index];
    }
    const T& operator[](int index) const {
        return data[index];
    }
    T& at(int index) {
        if (index < n) {
            return data[index];
        }
        throw "Index out of range";
    }
    size_t size() const {
        return n;
    }
    
    T* begin() {
        return data;
    }
    const T* begin() const {
        return data;
    }
    T* end() {
        return data + n;
    }
    const T* end() const {
        return data + n;
    }
    void resize (size_t k) {
        T* newData = nullptr;
        if(k > 0) {
            newData = new T[k];
        }
        for( auto i = 0 ; i < MIN(k,n) ; i++) {
            newData[i] = data[i];
        }
        if( data ) {
            delete[] data;
        }
        data = newData;
        n = k;
    }
    void push_back (const T& a) {
        resize( n+1 );
        data[n-1] = a;
    }
    void erase( T* it ) {
        for( ; it + 1 != end() ; it++) {
            *it = *(it + 1); // 한 칸씩 땡겨서 저장
        }
        resize(n-1); // 한 칸 줄인다.
    }
};


#endif /* dynamicArray_hpp */
