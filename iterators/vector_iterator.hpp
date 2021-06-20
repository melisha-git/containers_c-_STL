#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

namespace ft {
	//Default iterator
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

		vector_iterator &operator+=(int n);
		vector_iterator &operator-=(int n);

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

	// const default iterator
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

	// reverse iterator
	template <class T>
	class vector_reverse_iterator : public vector_iterator<T> {
	public:
		vector_reverse_iterator(T* val = 0) : vector_iterator<T>(val) {}
		vector_reverse_iterator(const vector_reverse_iterator<T>& copy) {
			this->_value = copy._value;
		}
		virtual ~vector_reverse_iterator() {}

		vector_reverse_iterator operator++() {
			--this->_value;
			return *this;
		}
		vector_reverse_iterator operator++(int) {
			vector_iterator<T> copy(*this);
			++(*this);
			return (copy);
		}
		vector_reverse_iterator operator--() {
			++this->_value;
			return *this;
		}
		vector_reverse_iterator operator--(int) {
			vector_iterator<T> copy(*this);
			--(*this);
			return (copy);
		}

		bool operator<(const vector_reverse_iterator<T> &other) const {
			return (this->_value > other._value);
		}
		bool operator>(const vector_reverse_iterator<T> &other) const {
			return (this->_value < other._value);
		}
		bool operator>=(const vector_reverse_iterator<T> &other) const {
			return (this->_value <= other._value);
		}
		bool operator<=(const vector_reverse_iterator<T> &other) const {
			return (this->_value >= other._value);
		}

		vector_reverse_iterator &operator+=(int n) {
			for (;n + 2 > 0; n--)
				this->_value += 1;
			return *(this);
		}
		vector_reverse_iterator &operator-=(int n) {
			for (;n > 0; n--)
				this->_value += 1;
			return *(this);
		}

		T &operator[](int index) const {
			T *tmp(this->_value);
				tmp -= index;
			return *tmp;
		}

		friend vector_reverse_iterator operator+(int n, const vector_reverse_iterator& it)
		{
			vector_reverse_iterator newIt(it);
			return (newIt += n);
		}
		friend vector_reverse_iterator operator-(int n, const vector_reverse_iterator& it)
		{
			vector_reverse_iterator newIt(it);
			return (newIt -= n);
		}
	};

	// const reverse iterator
	template <class T>
	class const_vector_reverse_iterator : public vector_reverse_iterator<T> {
	public:
		const_vector_reverse_iterator() {};
		const_vector_reverse_iterator(T* val) {
			this->_value = val;
		};
		const_vector_reverse_iterator(const const_vector_reverse_iterator &other) {
			*this = other;
		};
		~const_vector_reverse_iterator() {};
		const_vector_reverse_iterator &operator=(const const_vector_reverse_iterator &other) {
			this->_value = other._value;
			return (*this);
		};
		const T &operator*(void) {
			return (*this->_value);
		};
		const T &operator[](int n) const {
			return (*(*this - n));
		}
	};
}

#include "vector_iterator.ipp"

#endif