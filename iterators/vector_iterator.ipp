#include "vector_iterator.hpp"

template<typename T>
ft::vector_iterator<T>::vector_iterator(T *val) : _value(val) {}

template<typename T>
ft::vector_iterator<T>::vector_iterator(const vector_iterator<T>& copy) {
	_value = copy._value;
}

template<typename T>
T &ft::vector_iterator<T>::operator[](int index) {
	if (_value == 0 || index < 0) {
		T ref = 0;
		return ref;
	}
	T* tmp(this->_value);
	for (size_t i = 0; i < index; tmp++, i++);
	return *tmp;
}

template<typename T>
T &ft::vector_iterator<T>::operator+=(int n) {
	return *(_value += n);
}

template<typename T>
T &ft::vector_iterator<T>::operator-=(int n) {
	return *(_value -= n);
}

template<typename T>
bool ft::vector_iterator<T>::operator>(const vector_iterator<T> &x) const {
	return (_value > x._value);
}

template<typename T>
bool ft::vector_iterator<T>::operator<(const vector_iterator<T> &x) const {
	return (_value < x._value);
}

template<typename T>
bool ft::vector_iterator<T>::operator>=(const vector_iterator<T> &x) const {
	return (_value >= x._value);
}

template<typename T>
bool ft::vector_iterator<T>::operator<=(const vector_iterator<T> &x) const {
	return (_value <= x._value);
}

template<typename T>
bool ft::vector_iterator<T>::operator!=(const vector_iterator<T> &x) const {
	return (_value != x._value);
}

template<typename T>
bool ft::vector_iterator<T>::operator==(const vector_iterator<T> &x) const {
	return (_value == x._value);
}

template<typename T>
ft::vector_iterator<T> ft::vector_iterator<T>::operator++() {
	++_value;
	return *this;
}

template<typename T>
ft::vector_iterator<T> ft::vector_iterator<T>::operator++(int) {
	vector_iterator<T> copy(*this);
	++(*this);
	return (copy);
}

template<typename T>
ft::vector_iterator<T> ft::vector_iterator<T>::operator--() {
	--_value;
	return *this;
}

template<typename T>
ft::vector_iterator<T> ft::vector_iterator<T>::operator--(int) {
	vector_iterator<T> copy(*this);
	--(*this);
	return (copy);
}

template<typename T>
ft::vector_iterator<T> ft::vector_iterator<T>::operator-(int n) {
	vector_iterator copy(*this);
	for (int i = 0; i < n; i++) {
		--(copy);
	}
	return (copy);
}

template<typename T>
ft::vector_iterator<T> ft::vector_iterator<T>::operator+(int n) {
	vector_iterator copy(*this);
	for (int i = 0; i < n; i++) {
		++(copy);
	}
	return (copy);
}
