#ifndef STACK_CLASS_HPP
#define STACK_CLASS_HPP

#include "../vector/vector.class.hpp"

namespace ft {
	template<class T, class Container = ft::vector<T> >
	class stack {
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;
	private:
		container_type _value;
	public:
		explicit stack(const container_type &ctnr = container_type()) {
			_value = ctnr;
		}

		bool empty() const {
			return _value.empty();
		}

		size_type size() const {
			return _value.size();
		}
		value_type& top() {
			return _value.back();
		}
		const value_type& top() const {
			return _value.back();
		}
		void push(const value_type &val) {
			_value.push_back(val);
		}

		void pop() {
			_value.pop_back();
		}

		friend bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs._value == rhs._value);
		}
		friend bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs._value != rhs._value);
		}
		friend bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs._value < rhs._value);
		}
		friend bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs._value <= rhs._value);
		}
		friend bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs._value > rhs._value);
		}
		friend bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs._value >= rhs._value);
		}
	};
}

#endif