#include "vector.class.hpp"

/*
 * Constructor or destructor
 */

//Default constructor

template<typename T, class Alloc >
ft::vector<T, Alloc >::vector() : _array(nullptr), _size(0), _capacity(0) {
	_array = _alloc.allocate(_capacity);
}

//Constructor

template<typename T, class Alloc >
ft::vector<T, Alloc>::vector(size_t n, const T &x, const Alloc &alloc) : _size(n), _capacity(n), _alloc(alloc) {
	_array = _alloc.allocate(_capacity);
	for (size_t i = 0; i < _size; ++i)
		_alloc.construct(&_array[i], x);
}

//Copy constructor

template<typename T, class Alloc >
ft::vector<T, Alloc>::vector(const vector & other) : _size(other._size), _capacity(other._capacity) {
	_array = _alloc.allocate(other._size);
	for (size_t i = 0; i != other._size; i++)
		_alloc.construct(&_array[i], other._array[i]);
}

//Destructor

template<typename T, class Alloc >
ft::vector<T, Alloc >::~vector() {
	for (size_t i = 0; i < _size; i++) {
		_alloc.destroy(&_array[i]);
	}
	_alloc.deallocate(_array, this->_capacity);
}

/*
 * get and set
 */

//get size

template<typename T, class Alloc >
size_t ft::vector<T, Alloc>::size() const {
	return _size;
}

//get max size

template<typename T, class Alloc >
size_t ft::vector<T, Alloc>::max_size() {
	return _alloc.max_size();
}

//get capacity

template<typename T, class Alloc >
size_t ft::vector<T, Alloc>::capacity() {
	return _capacity;
}

//vector is empty?

template<typename T, class Alloc >
bool ft::vector<T, Alloc>::empty() const {
	return _size ? 0 : 1;
}

/*
 * member-functions
 */

//Удалить конец вектора

template<typename T, class Alloc >
void ft::vector<T, Alloc>::pop_back() {
	if (_size) {
		_alloc.destroy(&(_array[_size - 1]));
		_size--;
	}
}

// Запросить изменение емкости

template<typename T, class Alloc >
void ft::vector<T, Alloc>::reserve(size_t n) {
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
	this->~vector();
	_array = _copy;
}

// Добавить в конец вектора новый элемент

template<typename T, class Alloc >
void  ft::vector<T, Alloc>::push_back(const T &x) {
	if (_size >= _capacity) {
		reserve(!_capacity ? 1 : _capacity * 2);
	}
	_alloc.construct(&_array[_size], x);
	_size += 1;
}

//Запросить изменение размера

template<typename T, class Alloc >
void ft::vector<T, Alloc>::resize(size_t n, T x) {
	if (n > _capacity)
		reserve(n);
	while (n > _size)
		push_back(x);
	while (n < _size)
		pop_back();
	_size = n;
}

//Очистить вектор полностью

template<typename T, class Alloc >
void ft::vector<T, Alloc>::clear() {
	while (_size) {
		pop_back();
	}
}

/*
 * operators
 */

// Оператор []

template<typename T, class Alloc >
T & ft::vector<T, Alloc >::operator[](size_t n) {
	return _array[n];
}

template<typename T, class Alloc >
const T& ft::vector<T, Alloc>::operator[](size_t n) const {
	return  _array[n];
}

template<typename T, class Alloc >
ft::vector<T, Alloc> & ft::vector<T,  Alloc>::operator=(const vector <T, Alloc> &x) {
	this->clear();
	this->~vector();
	_size = x._size;
	_capacity = x._capacity;
	_array = _alloc.allocate(x._size);
	for (size_t i = 0; i < x._size; i++) {
		_alloc.construct(&_array[i], x._array[i]);
	}
	return *this;
}

/*
 * Element access
 */

// оператор [], но с исключением

template<typename T, class Alloc >
T & ft::vector<T, Alloc >::at(size_t n) {
	if (n < 0 || n >= _size)
		throw std::out_of_range("vector");
	return _array[n];
}

template<typename T, class Alloc >
const T & ft::vector<T, Alloc >::at(size_t n) const {
	if (n < 0 || n >= _size)
		throw std::out_of_range("vector");
	return _array[n];
}

// Вернуть первый элемент вектора

template<typename T, class Alloc >
T& ft::vector<T, Alloc >::front() {
	return _array[0];
}

template<typename T, class Alloc >
const T& ft::vector<T, Alloc >::front() const {
	return _array[0];
}

//Вернуть последний элемент вектора

template<typename T, class Alloc >
T& ft::vector<T, Alloc >::back() {
	return _array[_size - 1];
}

template<typename T, class Alloc >
const T& ft::vector<T, Alloc >::back() const {
	return _array[_size - 1];
}

/*
 * Modifiers:
 */

template<typename T, class Alloc >
void ft::vector<T, Alloc>::assign(iterator first, iterator last) {
    this->clear();
    size_t n(0);
    for (iterator it = first; it < last; it++) {
        n++;
    }
	if (n > _capacity) {
		_alloc.deallocate(_array, _capacity);
		_array = _alloc.allocate(n);
		_capacity = n;
	}
	int i = 0;
	for (iterator it = first; it < last; i++, it++) {
		_alloc.construct(&_array[i], *it);
	}
	_size = n;
}

template<typename T, class Alloc >
void ft::vector<T, Alloc>::assign(size_t n, const T &x) {
	this->clear();
	if (n > _capacity) {
		_alloc.deallocate(_array, _capacity);
		_array = _alloc.allocate(n);
		_capacity = n;
	}
	for (size_t i = 0; i < n; i++) {
		_alloc.construct(&_array[i], x);
	}
	_size = n;
}

template<typename T, class Alloc >
void ft::vector<T, Alloc>::swap(vector <T, Alloc> &x) {
	ft::swap(*this, x);
}

/*
 * get Allocator type
 */

template<typename T, class Alloc >
Alloc ft::vector<T, Alloc>::get_allocator() const {
	return _alloc;
}

/*
 * iterators
 */

template<typename T, class Alloc >
ft::vector_iterator<T> ft::vector<T, Alloc>::insert(ft::vector_iterator<T> position, const T& val) {
	vector copy(*this);
	if (_size >= _capacity) {
		reserve(!_capacity ? 1 : _capacity * 2);
	}
	this->clear();
	iterator it = this->begin();
	int flag = 0;
	for (size_t i = 0; i < copy._size + 1; i++) {
		if (it == position) {
			_alloc.construct(&_array[i], val);
			flag = 1;
		}
		else if (flag == 1)
			_alloc.construct(&_array[i], copy[i - 1]);
		++it;
	}
	_size = copy.size() + 1;
	return position;
}

template<typename T, class Alloc >
void ft::vector<T, Alloc>::insert(ft::vector_iterator<T> position, size_t n, const T& val) {
	for (size_t i = 0; i < n; i++) {
		this->insert(position, val);
	}
}

template<typename T, class Alloc >
void ft::vector<T, Alloc>::insert(ft::vector_iterator<T> position, ft::vector_iterator<T> first, ft::vector_iterator<T> last) {
	while (first < last) {
		this->insert(position, *first);
		++position;
		++first;
	}
}

template<typename T, class Alloc >
ft::vector_iterator<T> ft::vector<T, Alloc>::erase(iterator position) {
	iterator save = position;
	while (save < position) {
		*save = *(save + 1);
		save++;
	}
	_size--;
	return position;
}

template<typename T, class Alloc >
ft::vector_iterator<T> ft::vector<T, Alloc>::erase(ft::vector_iterator<T> first, ft::vector_iterator<T> last) {
	while (first != last) {
		this->erase(first);
		last--;
	}
	return first;
}
