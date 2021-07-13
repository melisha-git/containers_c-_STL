#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP
#include "../utils_containers/pair.hpp"
#include "utils_iterators/iterator_traits.hpp"


namespace ft {
	template <class Key, class T, class Compare, typename Node>
	class map_iterator {
	public:
		typedef Key	key_type;
		typedef Compare key_compare;
		typedef T	mapped_type;

		typedef ft::pair<const key_type, mapped_type> value_type;
		typedef long difference_type;
		typedef size_t size_type;

		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef value_type&  reference;
		typedef value_type*  pointer;
	protected:
		key_compare _comp;
		Node *_node;
		Node *_lastNode;
	public:
		map_iterator(Node *node = 0, const key_compare &comp = key_compare())
			: _comp(comp) {
			setFirst(node);
			setLast(node);
		}
		map_iterator(const map_iterator<Key, T, Compare, Node>& copy) {
			_node = copy.getNode();
			_lastNode = copy.getLastNode();
			_comp = copy.getCompare();
		}
		virtual ~map_iterator() {}

		map_iterator &operator=(const map_iterator& other) {
			if (*this != other) {
				_node = other.getNode();
				_lastNode = other.getLastNode();
				_comp = other.getCompare();
			}
			return *this;
		}
		reference operator*() const { return (_node->value); }
		pointer operator->() const { return &_node->value; }
		map_iterator& operator++() {
			if (_node == searchMaxNode(_node));
			else if (_node->right) {
				_node = _node->right;
				while (_node->left)
					_node = _node->left;
			} else if (_node->parrent) {
				value_type save = _node->value;
				while (_node->parrent && save.first > _node->parrent->value.first)
					_node = _node->parrent;
				if (!_node->parrent)
					return operator++();
				_node = _node->parrent;
			}
			return (*this);
		}
		map_iterator operator++(int) {
			map_iterator res(*this);
			++(*this);
			return res;
		}
		map_iterator& operator--() {
			if (_node == searchMinNode(_node));
			else if (_node->left) {
				_node = _node->left;
				while (_node->right)
					_node = _node->right;
			} else if (_node->parrent) {
				value_type save = _node->value;
				while (_node->parrent && save.first < _node->parrent->value.first)
					_node = _node->parrent;
				if (!_node->parrent)
					return operator++();
				_node = _node->parrent;
			}
			return (*this);
		}
		map_iterator operator--(int) {
			map_iterator res(*this);
			--(*this);
			return res;
		}

		bool operator==(const map_iterator& it) const   { return (it._node == _node); }
		bool operator!=(const map_iterator& it) const   { return (it._node != _node); }

		Node * getNode() const { return _node; }
		Node * getLastNode() const         { return _lastNode; }
		key_compare getCompare() const      { return _comp; }

	protected:
		void setFirst(Node *root) {
			if (root) {
				for (; root->left; root = root->left);
			}
			_node = root;
		}
		void setLast(Node *root) {
			if (root) {
				for (; root->right; root = root->right);
			}
			_lastNode = root;
		}
		Node* searchMaxNode(Node *root)
		{
			if (root) {
				if (root->parrent) {
					while (root->parrent)
						root = root->parrent;
				}
				while (root->right)
					root = root->right;
			}
			return root;
		}
		Node* searchMinNode(Node *root)
		{
			while (root->parrent)
				root = root->parrent;
			while (root->left)
				root = root->left;
			return root;
		}
	};

	template <class Key, class T, class Compare, typename Node>
	class const_map_iterator : public map_iterator<Key, T, Compare, Node> {
	public:
		typedef Key	key_type;
		typedef Compare key_compare;
		typedef T	mapped_type;

		typedef ft::pair<const key_type, mapped_type> value_type;
		typedef long difference_type;
		typedef size_t size_type;

		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef value_type&  reference;
		typedef value_type*  pointer;
	public:
		const_map_iterator(Node *node = 0, const key_compare &comp = key_compare()) : map_iterator<Key, T, Compare, Node>(node, comp) {}
		const_map_iterator(const map_iterator<Key, T, Compare, Node> &other) : map_iterator<Key, T, Compare, Node>(other) {}
		virtual ~const_map_iterator() {}
		const_map_iterator &operator=(const const_map_iterator<Key, T, Compare, Node> &other) {
			if (*this != other) {
				this->_node = other.getNode();
				this->_lastNode = other.getLastNode();
				this->_comp = other.getCompare();
			}
			return *this;
		}
		const value_type& operator*() const { return (this->_node->value); }
		const value_type* operator->() const { return &this->_node->value; }
	};

	template <class Key, class T, class Compare, typename Node>
	class map_reverse_iterator : public map_iterator<Key, T, Compare, Node> {
	public:
		typedef Key	key_type;
		typedef Compare key_compare;
		typedef T	mapped_type;

		typedef ft::pair<const key_type, mapped_type> value_type;
		typedef long difference_type;
		typedef size_t size_type;

		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef value_type&  reference;
		typedef value_type*  pointer;
	public:
		map_reverse_iterator(Node *node = 0, const key_compare &comp = key_compare()) : map_iterator<Key, T, Compare, Node>(node, comp) {}
		map_reverse_iterator(const map_reverse_iterator<Key, T, Compare, Node>& copy) {
			this->_node = copy.getNode();
			this->_lastNode = copy.getLastNode();
			this->_comp = copy.getCompare();
		}
		virtual ~map_reverse_iterator() {}

		map_reverse_iterator operator++() {
			if (this->_node == this->searchMinNode(this->_node));
			else if (this->_node->left) {
				this->_node = this->_node->left;
				while (this->_node->right)
					this->_node = this->_node->right;
			} else if (this->_node->parrent) {
				value_type save = this->_node->value;
				while (this->_node->parrent && save.first < this->_node->parrent->value.first)
					this->_node = this->_node->parrent;
				if (!this->_node->parrent)
					return operator++();
				this->_node = this->_node->parrent;
			}
			return (*this);
		}
		map_reverse_iterator operator++(int) {
			map_reverse_iterator copy(*this);
			++(*this);
			return (copy);
		}
		map_reverse_iterator operator--() {
			if (this->_node == this->searchMaxNode(this->_node));
			else if (this->_node->right) {
				this->_node = this->_node->right;
				while (this->_node->left)
					this->_node = this->_node->left;
			} else if (this->_node->parrent) {
				value_type save = this->_node->value;
				while (this->_node->parrent && save.first > this->_node->parrent->value.first)
					this->_node = this->_node->parrent;
				if (!this->_node->parrent)
					return operator++();
				this->_node = this->_node->parrent;
			}
			return (*this);
		}
		map_reverse_iterator operator--(int) {
			map_reverse_iterator copy(*this);
			--(*this);
			return (copy);
		}
	};

	template <class Key, class T, class Compare, typename Node>
	class const_reverse_map_iterator : public map_reverse_iterator<Key, T, Compare, Node> {
	public:
		typedef Key	key_type;
		typedef Compare key_compare;
		typedef T	mapped_type;

		typedef ft::pair<const key_type, mapped_type> value_type;
		typedef long difference_type;
		typedef size_t size_type;

		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef value_type&  reference;
		typedef value_type*  pointer;
	public:
		const_reverse_map_iterator(Node *node = 0, const key_compare &comp = key_compare()) : map_reverse_iterator<Key, T, Compare, Node>(node, comp) {}
		const_reverse_map_iterator(const map_reverse_iterator<Key, T, Compare, Node> &other) : map_reverse_iterator<Key, T, Compare, Node>(other) {}
		virtual ~const_reverse_map_iterator() {}
		const_reverse_map_iterator &operator=(const const_reverse_map_iterator &other) {
			if (*this != other) {
				this->_node = other.getNode();
				this->_lastNode = other.getLastNode();
				this->_comp = other.getCompare();
			}
			return *this;
		}
		const value_type& operator*() const { return (this->_node->value); }
		const value_type* operator->() const { return &this->_node->value; }
	};
}

#endif