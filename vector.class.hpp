#ifndef VECTOR_CLASS_HPP
#define VECTOR_CLASS_HPP

#include <iostream>
#include "iterators/vector_iterator.hpp"

namespace ft {
	template <typename U>
	void swap(U& a, U&b)
	{
		U tmp = a;
		a = b;
		b = tmp;
	}
}

namespace ft {
	// CLASS VECTOR
    template<typename T, class Alloc = std::allocator<T> >
    class Vector {
	private:
    	T *_array;
    	size_t _size;
    	size_t _capacity;
    	Alloc _alloc;
    public:
    	typedef typename ft::const_vector_reverse_iterator<T> const_reverse_iterator;
    	typedef typename ft::vector_reverse_iterator<T> reverse_iterator;
		typedef typename ft::vector_iterator<T> iterator;
		typedef typename ft::const_vector_iterator<T> const_iterator;
        explicit Vector();
		Vector(size_t n, const T &x = T(), const Alloc &alloc = Alloc());
        Vector(const Vector &);
        ~Vector();

        size_t size() const;
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
		iterator insert (iterator position, const T& val);
		void insert (iterator position, size_t n, const T& val);
		void insert (iterator position, iterator first, iterator last);
		iterator erase(iterator position);
		iterator erase (iterator first, iterator last);
		void swap (Vector& x);

		Alloc get_allocator() const;

		const_reverse_iterator rbegin()  const   { return const_reverse_iterator(_array + _size - 1); }
		const_reverse_iterator rend()	const	  { return const_reverse_iterator(_array - 1); }
		reverse_iterator rbegin()     { return reverse_iterator(_array + _size - 1); }
		reverse_iterator rend()		  { return reverse_iterator(_array - 1); }
		iterator        begin()       { return iterator(_array); }
		const_iterator  begin() const { return const_iterator(_array); }
		iterator        end()         { return iterator(_array + _size); }
		const_iterator  end() const   { return const_iterator(_array + _size); }


		friend bool operator==(const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs) {
			if (lhs.size() != rhs.size())
				return false;
			iterator itl = lhs.begin();
			iterator itr = rhs.begin();
			for (; itl < lhs.end(); ++itl, ++itr) {
				if (*itl != *itr)
					return false;
			}
			return true;
		}
		friend bool operator!=(const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs) {
			if (lhs.size() != rhs.size())
				return true;
			iterator itl = lhs.begin();
			iterator itr = rhs.begin();
			for (; itl < lhs.end(); ++itl, ++itr) {
				if (*itl != *itr)
					return true;
			}
			return false;
		}
		friend bool operator<(const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs) {
			if (lhs.size() < rhs.size())
				return true;
			iterator itl = lhs.begin();
			iterator itr = rhs.begin();
			for (; itl < lhs.end(); ++itl, ++itr) {
				if (*itl != *itr) {
					if (*itl < *itr)
						return true;
					else
						return false;
				}
			}
			return false;
		}
		friend bool operator>(const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs) {
			if (lhs.size() > rhs.size())
				return true;
			const_iterator itl = lhs.begin();
			const_iterator itr = rhs.begin();
			for (; itl < lhs.end(); ++itl, ++itr) {
				if (*itl != *itr) {
					if (*itl > *itr)
						return true;
					else
						return false;
				}
			}
			return false;
		}
		friend bool operator<=(const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs) {
			if (lhs.size() < rhs.size())
				return true;
			iterator itl = lhs.begin();
			iterator itr = rhs.begin();
			for (; itl < lhs.end(); ++itl, ++itr) {
				if (*itl != *itr) {
					if (*itl < *itr)
						return true;
					else
						return false;
				}
			}
			return true;
		}
		friend bool operator>=(const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs) {
			if (lhs.size() > rhs.size())
				return true;
			const_iterator itl = lhs.begin();
			const_iterator itr = rhs.begin();
			for (; itl < lhs.end(); ++itl, ++itr) {
				if (*itl != *itr) {
					if (*itl > *itr)
						return true;
					else
						return false;
				}
			}
			return true;
		}
		friend void swap(Vector<T,Alloc>& x, Vector<T,Alloc>& y) {
			ft::swap(x, y);
		}
    };
    template<class Alloc>
    class Vector<bool, Alloc> {
    private:
    	bool *_array;
    	size_t _size;
    	size_t _capacity;
    	Alloc _alloc;
	public:
		void flip() {
			for (size_t i = 0; i < _size; i++) {
				_array[i] ^= (1<<0);
			}
		}
		static void swap (bool& ref1, bool &ref2) {
			ft::swap(ref1, ref2);
		}
		typedef typename ft::const_vector_reverse_iterator<bool> const_reverse_iterator;
		typedef typename ft::vector_reverse_iterator<bool> reverse_iterator;
		typedef typename ft::vector_iterator<bool> iterator;
		typedef typename ft::const_vector_iterator<bool> const_iterator;
		explicit Vector() : _array(nullptr), _size(0), _capacity(0) {
			_array = _alloc.allocate(_capacity);
		}
		Vector(size_t n, const bool &x = bool(), const Alloc &alloc = Alloc()) {
			_size = 0;
			_capacity = 0;
			_array = _alloc.allocate(_capacity);
			for (size_t i = 0; i < n; ++i) {
				this->push_back(x);
			}
		}
		Vector(const Vector<bool> &other) : _size(other._size), _capacity(other._capacity) {
			_array = _alloc.allocate(other._size);
			for (size_t i = 0; i != other._size; i++)
				_alloc.construct(&_array[i], other._array[i]);
		}
		~Vector() {
			for (size_t i = 0; i < _size; i++) {
				_alloc.destroy(&_array[i]);
			}
			_alloc.deallocate(_array, this->_capacity);
		}

		size_t size() const { return _size; }
		size_t capacity() { return _capacity; }
		size_t max_size() { return _alloc.max_size(); }
		bool empty() const { return _size ? 0 : 1; }

		void push_back (const bool& x) {
			if (_size >= _capacity) {
				reserve(!_capacity ? 1 : _capacity * 8);
			}
			_alloc.construct(&_array[_size], x);
			_size += 1;
		}

		void pop_back() {
			if (_size) {
				_alloc.destroy(&(_array[_size - 1]));
				_size--;
			}
		}
		void clear() {
			while (_size) {
				pop_back();
			}
		}

		void reserve(size_t n) {
			if (n <= _capacity)
				return ;
			if (n > this->max_size()) {
				throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
			}
			_capacity = n;
			bool *_copy = _alloc.allocate(_capacity);
			if (!(_copy))
				throw std::bad_alloc();
			for (size_t i = 0; i < _size; i++) {
				_alloc.construct(&_copy[i], _array[i]);
			}
			this->~Vector();
			_array = _copy;
		}
		void resize (size_t n, bool x = bool()) {
			if (n > _capacity)
				reserve(n);
			while (n > _size)
				push_back(x);
			while (n < _size)
				pop_back();
			_size = n;
		}

		Vector& operator=(const Vector& x) {
			this->clear();
			this->~Vector();
			_size = x._size;
			_capacity = x._capacity;
			_array = _alloc.allocate(x._size);
			for (size_t i = 0; i < x._size; i++) {
				_alloc.construct(&_array[i], x._array[i]);
			}
			return *this;
		}
		bool& operator[](size_t n) { return _array[n]; }
		const bool& operator[] (size_t n) const { return  _array[n]; }

		bool& at(size_t n) {
			if (n < 0 || n >= _size)
				throw std::out_of_range("vector");
			return _array[n];
		}
		const bool& at (size_t n) const {
			if (n < 0 || n >= _size)
				throw std::out_of_range("vector");
			return _array[n];
		}
		bool& front() { return _array[0]; }
		const bool& front() const { return _array[0]; }
		bool& back() { return _array[_size - 1]; }
		const bool& back() const { return _array[_size - 1]; }

		void assign (iterator first, iterator last) {
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
		void assign (size_t n, const bool& x) {
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
		iterator insert (iterator position, const bool& val) {
			Vector copy(*this);
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
		void insert (iterator position, size_t n, const bool& val) {
			for (size_t i = 0; i < n; i++) {
				this->insert(position, val);
			}
		}
		void insert (iterator position, iterator first, iterator last) {
			while (first < last) {
				this->insert(position, *first);
				++position;
				++first;
			}
		}
		iterator erase(iterator position) {
			iterator save = position;
			while (save < position) {
				*save = *(save + 1);
				save++;
			}
			_size--;
			return position;
		}
		iterator erase (iterator first, iterator last) {
			while (first != last) {
				this->erase(first);
				last--;
			}
			return first;
		}
		void swap (Vector<bool>& x) {
			ft::swap(*this, x);
		}

		Alloc get_allocator() const { return _alloc; }

		const_reverse_iterator rbegin()  const   { return const_reverse_iterator(_array + _size - 1); }
		const_reverse_iterator rend()	const	  { return const_reverse_iterator(_array - 1); }
		reverse_iterator rbegin()     { return reverse_iterator(_array + _size - 1); }
		reverse_iterator rend()		  { return reverse_iterator(_array - 1); }
		iterator        begin()       { return iterator(_array); }
		const_iterator  begin() const { return const_iterator(_array); }
		iterator        end()         { return iterator(_array + _size); }
		const_iterator  end() const   { return const_iterator(_array + _size); }


		friend bool operator==(const Vector<bool, Alloc>& lhs, const Vector<bool, Alloc>& rhs) {
			if (lhs.size() != rhs.size())
				return false;
			iterator itl = lhs.begin();
			iterator itr = rhs.begin();
			for (; itl < lhs.end(); ++itl, ++itr) {
				if (*itl != *itr)
					return false;
			}
			return true;
		}
		friend bool operator!=(const Vector<bool, Alloc>& lhs, const Vector<bool, Alloc>& rhs) {
			if (lhs.size() != rhs.size())
				return true;
			iterator itl = lhs.begin();
			iterator itr = rhs.begin();
			for (; itl < lhs.end(); ++itl, ++itr) {
				if (*itl != *itr)
					return true;
			}
			return false;
		}
		friend bool operator<(const Vector<bool, Alloc>& lhs, const Vector<bool, Alloc>& rhs) {
			if (lhs.size() < rhs.size())
				return true;
			iterator itl = lhs.begin();
			iterator itr = rhs.begin();
			for (; itl < lhs.end(); ++itl, ++itr) {
				if (*itl != *itr) {
					if (*itl < *itr)
						return true;
					else
						return false;
				}
			}
			return false;
		}
		friend bool operator>(const Vector<bool, Alloc>& lhs, const Vector<bool, Alloc>& rhs) {
			if (lhs.size() > rhs.size())
				return true;
			const_iterator itl = lhs.begin();
			const_iterator itr = rhs.begin();
			for (; itl < lhs.end(); ++itl, ++itr) {
				if (*itl != *itr) {
					if (*itl > *itr)
						return true;
					else
						return false;
				}
			}
			return false;
		}
		friend bool operator<=(const Vector<bool, Alloc>& lhs, const Vector<bool, Alloc>& rhs) {
			if (lhs.size() < rhs.size())
				return true;
			iterator itl = lhs.begin();
			iterator itr = rhs.begin();
			for (; itl < lhs.end(); ++itl, ++itr) {
				if (*itl != *itr) {
					if (*itl < *itr)
						return true;
					else
						return false;
				}
			}
			return true;
		}
		friend bool operator>=(const Vector<bool, Alloc>& lhs, const Vector<bool, Alloc>& rhs) {
			if (lhs.size() > rhs.size())
				return true;
			const_iterator itl = lhs.begin();
			const_iterator itr = rhs.begin();
			for (; itl < lhs.end(); ++itl, ++itr) {
				if (*itl != *itr) {
					if (*itl > *itr)
						return true;
					else
						return false;
				}
			}
			return true;
		}
		friend void swap(Vector<bool,Alloc>& x, Vector<bool,Alloc>& y) {
			ft::swap(x, y);
		}
    };
}

#include "vector.class.ipp"

#endif