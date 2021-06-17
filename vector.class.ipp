#include "vector.class.hpp"

/*
 * Constructor or destructor
 */

template<typename T, class Alloc >
ft::Vector<T, Alloc >::Vector() : _array(nullptr), _size(0), _capacity(0) {
	_array = _alloc.allocate(_capacity);
} //Default constructor

template<typename T, class Alloc >
ft::Vector<T, Alloc>::Vector(size_t n, const T &x) : _size(n), _capacity(n) {
	_array = _alloc.allocate(_capacity);
	for (size_t i = 0; i < _size; ++i)
		_alloc.construct(&_array[i], x);
}

template<typename T, class Alloc >
ft::Vector<T, Alloc>::Vector(const Vector & other) : _size(other._size), _capacity(other._capacity) {
	_array = _alloc.allocate(other._size);
	for (size_t i = 0; i != other._size; i++)
		_alloc.construct(&_array[i], other._array[i]);
}

template<typename T, class Alloc >
ft::Vector<T, Alloc >::~Vector() { //Destructor
	for (size_t i = 0; i < _size; i++) {
		_alloc.destroy(&_array[i]);
	}
	_alloc.deallocate(_array, this->_capacity);
}

/*
 * get and set
 */

template<typename T, class Alloc >
size_t ft::Vector<T, Alloc>::size() {
	return _size;
}

template<typename T, class Alloc >
size_t ft::Vector<T, Alloc>::max_size() {
	return _alloc.max_size();
}

template<typename T, class Alloc >
size_t ft::Vector<T, Alloc>::capacity() {
	return _capacity;
}

template<typename T, class Alloc >
bool ft::Vector<T, Alloc>::empty() const {
	return _size ? 0 : 1;
}

/*
 * member-functions
 */

template<typename T, class Alloc >
void ft::Vector<T, Alloc>::pop_back() {
	if (_size) {
		_alloc.destroy(&(_array[_size - 1]));
		_size--;
	}
}

template<typename T, class Alloc >
void ft::Vector<T, Alloc>::reserve(size_t n) {
	if (n <= _capacity)
		return ;
	if (n > this->max_size()) {
		throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
	}
	_capacity = n;
	T *_copy = _alloc.allocate(_capacity);
	if (!(_copy))
		throw std::bad_alloc();
	for (size_t i = 0; i < _size; i++) {
		_alloc.construct(&_copy[i], _array[i]);
	}
	this->~Vector();
	_array = _copy;
}

template<typename T, class Alloc >
void  ft::Vector<T, Alloc>::push_back(const T &x) {
	if (_size >= _capacity) {
		reserve(!_capacity ? 1 : _capacity * 2);
	}
	_array[_size] = x;
	_size += 1;
}

template<typename T, class Alloc >
void ft::Vector<T, Alloc>::resize(size_t n, T x) {
	if (n > _capacity)
		reserve(n);
	while (n > _size)
		push_back(x);
	while (n < _size)
		pop_back();
	_size = n;
}

template<typename T, class Alloc >
void ft::Vector<T, Alloc>::clear() {
	while (_size) {
		pop_back();
	}
}

/*
 * operators
 */

template<typename T, class Alloc >
T & ft::Vector<T, Alloc >::operator[](size_t n) {
	return _array[n];
}

template<typename T, class Alloc >
const T& ft::Vector<T, Alloc>::operator[](size_t n) const {
	return  _array[n];
}

/*
 * Element access
 */

template<typename T, class Alloc >
T & ft::Vector<T, Alloc >::at(size_t n) {
	if (n < 0 || n >= _size)
		throw std::out_of_range("vector");
	return _array[n];
}

template<typename T, class Alloc >
const T & ft::Vector<T, Alloc >::at(size_t n) const {
	if (n < 0 || n >= _size)
		throw std::out_of_range("vector");
	return _array[n];
}

template<typename T, class Alloc >
T& ft::Vector<T, Alloc >::front() {
	return _array[0];
}

template<typename T, class Alloc >
const T& ft::Vector<T, Alloc >::front() const {
	return _array[0];
}

template<typename T, class Alloc >
T& ft::Vector<T, Alloc >::back() {
	return _array[_size - 1];
}

template<typename T, class Alloc >
const T& ft::Vector<T, Alloc >::back() const {
	return _array[_size - 1];
}

/*
 * Modifiers:
 */