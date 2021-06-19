#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

namespace ft {
	template<typename T>
	class vector_iterator {
	private:
		T* _value;
	public:
		vector_iterator(T* val = 0);
		vector_iterator(const vector_iterator<T>& copy);
		~vector_iterator() {}
		vector_iterator operator++();
		vector_iterator operator++(int);
		vector_iterator operator--();
		vector_iterator operator--(int);
		T &operator*() const { return *_value; }
		T &operator[](int index);
		T &operator+=(int n);
		T &operator-=(int n);
		bool operator>(const vector_iterator<T> &) const;
		bool operator<(const vector_iterator<T> &) const;
		bool operator>=(const vector_iterator<T> &) const;
		bool operator<=(const vector_iterator<T> &) const;
		bool operator!=(const vector_iterator<T> &) const;
		bool operator==(const vector_iterator<T> &) const;
		vector_iterator operator-(int n);
		vector_iterator operator+(int n);
	};
}

#include "vector_iterator.ipp"

#endif