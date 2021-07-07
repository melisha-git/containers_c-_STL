#ifndef MAP_CLASS_HPP
#define MAP_CLASS_HPP
#include <iostream>
#include <cmath>
#include "ft_utils.hpp"

namespace ft {
	//CLASS MAP
	template<class _Key, class _Tp, class _Compare = ft::less<_Key>, class _Allocator = std::allocator<std::pair<const _Key, _Tp> > >
	class map {
	private:
		typedef std::pair<const _Key, _Tp> value_type;
	private:
		struct Node {
			Node *parent;
			Node *left;
			Node *right;
			value_type pair;
		};
		Node *_first;
		Node *_last;
		size_t _size;
		_Allocator _allocator; // Вызов конструктора для pair
		std::allocator<Node> _allocNode; //Выделение памяти для новой ячейки
		_Compare _comp;
	public:
		explicit map (const _Compare& comp = _Compare(), const _Allocator& alloc = _Allocator()) : _size(0), _allocator(alloc), _comp(comp) {

		}
		size_t size () const { return _size; }
		bool empty () const { return _size == 0; }
		size_t max_size () const {
			int coef = 20;
			if (sizeof(_Key) > sizeof(_Tp))
				coef = 15;
			return _allocNode.max_size() - (_allocator.max_size() / coef);
		}
		_Allocator get_allocator() const { return _allocator; }
	};
}

#endif