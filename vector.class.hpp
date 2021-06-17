#ifndef VECTOR_CLASS_HPP
#define VECTOR_CLASS_HPP
#include <iostream>

namespace ft {
    template<typename T, class Alloc = std::allocator<T> >
    class Vector {
	private:
    	Alloc _alloc;
    	T *_array;
    	size_t _size;
    	size_t _capacity;
    public:
        Vector();
        Vector(size_t n, const T &x = T());
        Vector(const Vector &);
        ~Vector();

        size_t size();
        size_t capacity();
        size_t max_size();
		bool empty() const;

		void push_back (const T& x);
		void pop_back();
		void clear();
        void reserve(size_t n); // Запросить изменение емкости
		void resize (size_t n, T x = T()); // Запросить изменение размера

        T& operator[](size_t n);
		const T& operator[] (size_t n) const;

		T& at(size_t n);
		const T& at (size_t n) const;
		T& front();
		const T& front() const;
		T& back();
		const T& back() const;

//		template <class InputIterator>
//		void assign (InputIterator first, InputIterator last);
//		void assign (size_t n, const T& val);
    };
}

#include "vector.class.ipp"

#endif
