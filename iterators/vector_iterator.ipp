#include "vector_iterator.hpp"

template<typename T>
ft::vector_iterator<T>::vector_iterator(T *val) : _value(val) {}

template<typename T>
ft::vector_iterator<T>::vector_iterator(const vector_iterator<T>& copy) {
	_value = copy._value;
}

template<typename T>
ft::vector_iterator<T> &ft::vector_iterator<T>::operator=(const ft::vector_iterator<T> &other) {
	if (this != &other) {
		_value = other._value;
	}
	return *this;
}

template<typename T>
T &ft::vector_iterator<T>::operator[](int index) const {
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
ft::vector_iterator<T> ft::vector_iterator<T>::operator-(int n) const {
	vector_iterator copy(*this);
	for (int i = 0; i < n; i++) {
		--(copy);
	}
	return (copy);
}

template<typename T>
ft::vector_iterator<T> ft::vector_iterator<T>::operator+(int n) const {
	vector_iterator copy(*this);
	for (int i = 0; i < n; i++) {
		++(copy);
	}
	return (copy);
}


template<typename T>
ft::const_vector_iterator<T>::const_vector_iterator() {}

template<typename T>
ft::const_vector_iterator<T>::const_vector_iterator(T *value) {
	this->_value = value;
}

template<typename T>
ft::const_vector_iterator<T>::const_vector_iterator(const const_vector_iterator &other) {
	this->_value = other._value;
}

template<typename T>
ft::const_vector_iterator<T>::~const_vector_iterator() {}

template<typename T>
ft::const_vector_iterator<T> &ft::const_vector_iterator<T>::operator=(const const_vector_iterator &other) {
	this->_value = other._value;
	return *this;
}

template<typename T>
const T &ft::const_vector_iterator<T>::operator*() {
	return *this->_value;
}

template<typename T>
const T &ft::const_vector_iterator<T>::operator[](int n) const {
	return this->_value[n];
}