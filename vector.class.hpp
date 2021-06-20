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
    	Alloc _alloc;
    	T *_array;
    	size_t _size;
    	size_t _capacity;
    public:
    	typedef typename ft::const_vector_reverse_iterator<T> const_reverse_iterator;
    	typedef typename ft::vector_reverse_iterator<T> reverse_iterator;
		typedef typename ft::vector_iterator<T> iterator;
		typedef typename ft::const_vector_iterator<T> const_iterator;
        explicit Vector();
		explicit Vector(size_t n, const T &x = T(), const Alloc &alloc = Alloc());
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
}

#include "vector.class.ipp"

#endif
