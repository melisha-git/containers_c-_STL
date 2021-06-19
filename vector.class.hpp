#ifndef VECTOR_CLASS_HPP
#define VECTOR_CLASS_HPP

#include <iostream>
#include "iterators/vector_iterator.hpp"

namespace ft {
    template<typename T, class Alloc = std::allocator<T> >
    class Vector {
	private:
    	Alloc _alloc;
    	T *_array;
    	size_t _size;
    	size_t _capacity;
    public:
		typedef typename ft::vector_iterator<T> iterator;
        explicit Vector();
		explicit Vector(size_t n, const T &x = T(), const Alloc &alloc = Alloc());
        Vector(const Vector &);
        ~Vector();

        size_t size();
        size_t capacity();
        size_t max_size();
		bool empty() const;

		void push_back (const T& x);
		void pop_back();
		void clear();
        void reserve(size_t n);
		void resize (size_t n, T x = T());

		Vector& operator=(const Vector& x);
        T& operator[](size_t n);
		const T& operator[] (size_t n) const;

		T& at(size_t n);
		const T& at (size_t n) const;
		T& front();
		const T& front() const;
		T& back();
		const T& back() const;

        void assign (iterator first, iterator last);
		void assign (size_t n, const T& val);
		//iterator insert (iterator position, const value_type& val);
		//void insert (iterator position, size_type n, const value_type& val);
		//template <class InputIterator>
		//    void insert (iterator position, InputIterator first, InputIterator last);
		//iterator erase (iterator position);
		//iterator erase (iterator first, iterator last);
		void swap (Vector& x);

		Alloc get_allocator() const;
//		friend bool operator== (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);

		iterator begin() { return iterator(_array); }
		iterator end() { return iterator(_array + _size); }
    };
}

template <class T, class Alloc>
bool operator== (const ft::Vector<T, Alloc>& lhs, const ft::Vector<T, Alloc>& rhs){
	if (lhs.size() != rhs.size())
		return false;
	return true;
}

#include "vector.class.ipp"

#endif
