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
		T &operator[](int index);
		T &operator+=(int n);
		T &operator-=(int n);
		bool operator>(const vector_iterator<T> &) const;
		bool operator<(const vector_iterator<T> &) const;
		bool operator>=(const vector_iterator<T> &) const;
		bool operator<=(const vector_iterator<T> &) const;
	};
}

#include "vector_iterator.ipp"

#endif
