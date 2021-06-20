#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

namespace ft {
	template<typename T>
	class vector_iterator {
	protected:
		T* _value;
	public:
		vector_iterator(T* val = 0);
		vector_iterator(const vector_iterator<T>& copy);
		virtual ~vector_iterator() {}

		vector_iterator& operator=(const vector_iterator &other);

		bool operator!=(const vector_iterator<T> &) const;
		bool operator==(const vector_iterator<T> &) const;

		T &operator*() const { return *_value; }
		T* operator->() const { return (_value); }

		vector_iterator operator++();
		vector_iterator operator++(int);
		vector_iterator operator--();
		vector_iterator operator--(int);
		vector_iterator operator-(int n) const;
		vector_iterator operator+(int n) const;

		bool operator>(const vector_iterator<T> &) const;
		bool operator<(const vector_iterator<T> &) const;
		bool operator>=(const vector_iterator<T> &) const;
		bool operator<=(const vector_iterator<T> &) const;

		T &operator+=(int n);
		T &operator-=(int n);

		T &operator[](int index) const;

		friend vector_iterator operator+(int n, const vector_iterator& it)
		{
			vector_iterator newIt(it);
			return (newIt += n);
		}
		friend vector_iterator operator-(int n, const vector_iterator& it)
		{
			vector_iterator newIt(it);
			return (newIt -= n);
		}
	};
	template <class T>
	class const_vector_iterator : public vector_iterator<T> {
	public:
		const_vector_iterator();
		const_vector_iterator(T* value);
		const_vector_iterator(const const_vector_iterator &other);
		virtual ~const_vector_iterator();
		const_vector_iterator &operator=(const const_vector_iterator &other);
		const T &operator*(void);
		const T &operator[](int n) const;
	};
}

#include "vector_iterator.ipp"

#endif