#ifndef TREE_TREE_ITERATOR_HPP
#define TREE_TREE_ITERATOR_HPP
#include "tree.class.hpp"

namespace ft {
	template <class _TreeIterator, class _Key, class _Tp>
	class tree_iterator {
		typedef _Key key_type;
		typedef _Tp mapped_type;
		typedef std::pair<const key_type, mapped_type> value_type;
//		typedef _TreeIterator::
	private:
		_TreeIterator *_i;
		_TreeIterator *_save;
	public:
		tree_iterator() : _i(0) {}
		tree_iterator(_TreeIterator *i) : _i(i) {
			while (_i->left)
				_i = i->left;
		}

		value_type &operator*() const { return _i->value; }
		value_type*operator->() const { return &_i->value; }
		bool operator!=(const tree_iterator&) {

		}
	};
}

#endif
