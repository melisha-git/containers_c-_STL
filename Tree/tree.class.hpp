#ifndef TREE_CLASS_HPP
#define TREE_CLASS_HPP
#include <iostream>
#include "tree_iterator.hpp"

namespace ft {
	template<class _Key, class _Tp, class Allocator = std::allocator<std::pair<const _Key, _Tp> > >
	class tree {
	public:
		typedef _Key key_type;
		typedef _Tp mapped_type;
		typedef std::pair<const key_type, mapped_type> value_type;
		typedef Allocator allocator_type;
	private:
		struct Node {
			value_type value;
			Node *parrent;
			Node *left;
			Node *right;
		};
		size_t _size;
		allocator_type _allocT;
		std::allocator<Node> _allocNode;
		Node *_root;
		Node *_last;
	public:
		typedef ft::tree_iterator<Node, key_type, mapped_type> iterator;

		tree(const allocator_type &alloc = allocator_type()) : _size(0), _allocT(alloc) {
			_root = _allocNode.allocate(1);
			_allocT.construct(&_root->value, value_type());
			_root->parrent = nullptr;
			_root->left = nullptr;
			_root->right = nullptr;
			_last = _root;
		}

		tree(const tree &x) : _size(0) {
			_root = _allocNode.allocate(1);
			_root->parrent = nullptr;
			_root->left = nullptr;
			_root->right = nullptr;
			this->operator=(x);
			_last = _root;
		}

		tree &operator=(const tree &x) {
			this->clear();
			preOrder(x._root);
			return *this;
		}

		~tree() {
			deleteNode(&_root);
			_size = 0;
		}


		void print() {
			printBT(_root);
		}

		mapped_type &operator[](const key_type &k) {
			value_type pair(k, 0);
			Node *tmp = this->searchNode(pair);
			if (tmp != nullptr)
				return tmp->value.second;
			this->addNode(pair);
			tmp = this->searchNode(pair);
			return tmp->value.second;
		}

		size_t size() const { return _size; }

		bool empty() const { return _size == 0; }

		size_t max_size() const {
			int coef = 20;
			if (sizeof(_Key) > sizeof(_Tp))
				coef = 15;
			return _allocNode.max_size() - (_allocT.max_size() / coef);
		}

		Allocator get_allocator() const { return _allocT; }

		void clear() {
			deleteNode(&_root);
			_root = _allocNode.allocate(1);
			_allocT.construct(&_root->value, value_type());
			_root->parrent = nullptr;
			_root->left = nullptr;
			_root->right = nullptr;
			_size = 0;
		}

		size_t erase(const key_type &k) {
			tree tmp(*this);
			value_type v(k, 0);
			Node *newNode = searchNode(v);
			if (!newNode) {
				return 0;
			} else {
				this->clear();
				this->addNo(tmp, k);
			}
			return 1;
		}

		void swap(tree &x) {
			tree tmp(*this);
			*this = x;
			x = tmp;
		}

		size_t count(const key_type &k) const {
			value_type q(k, 0);
			Node *tmp = searchNode(_root, q);
			return tmp == nullptr ? 0 : 1;
		}
		iterator begin() {
			return iterator(_root);
		}
		iterator end() {
			return iterator(_last);
		}
	private:
		void addNode(const value_type &value) {
			if (_size == 0) {
				_allocT.destroy(&_root->value);
				_allocT.construct(&_root->value, value_type(value));
			} else {
				if (value.first < _root->value.first) {
					if (_root->left) {
						_root = _root->left;
						return addNode(value);
					} else {
						_root->left = createNode(value, _root);
					}
				} else if (value.first > _root->value.first) {
					if (_root->right) {
						_root = _root->right;
						return addNode(value);
					} else {
						_root->right = createNode(value, _root);
						_last = _root->right;
					}
				}
			}
			returnPointerRoot();
			_size++;
		}

		Node *createNode(const value_type &value, Node *root) {
			Node *newNode;
			newNode = _allocNode.allocate(1);
			_allocT.construct(&newNode->value, value_type(value));
			newNode->parrent = root;
			newNode->left = nullptr;
			newNode->right = nullptr;
			return newNode;
		}

		Node *searchNode(Node *root, const value_type &value) const {
			if (!root)
				return nullptr;
			if (root->value.first == value.first)
				return root;
			if (value > root->value) {
				if (root->right != nullptr) {
					root = root->right;
					return searchNode(root, value);
				}
			} else if (value.first < root->value.first) {
				if (root->left != nullptr) {
					root = root->left;
					return searchNode(root, value);
				}
			}
			return nullptr;
		}

		Node *searchNode(const value_type &value) {
			if (_size == 0)
				return nullptr;
			if (_root->value.first == value.first) {
				Node *tmp = _root;
				returnPointerRoot();
				return tmp;
			}
			if (value > _root->value) {
				if (_root->right != nullptr) {
					_root = _root->right;
					return searchNode(value);
				}
			} else if (value.first < _root->value.first) {
				if (_root->left != nullptr) {
					_root = _root->left;
					return searchNode(value);
				}
			}
			returnPointerRoot();
			return nullptr;
		}

		void printBT(const std::string &prefix, const Node *node, bool isLeft) {
			if (node != nullptr) {
				std::cout << prefix;
				std::cout << (isLeft ? "├──" : "└──");
				std::cout << node->value.first << node->value.second << std::endl;
				printBT(prefix + (isLeft ? "│   " : "    "), node->left, true);
				printBT(prefix + (isLeft ? "│   " : "    "), node->right, false);
			}
		}

		void printBT(const Node *node) {
			printBT("", node, false);
		}

		void preOrder(Node *root) {
			value_type tmp(root->value.first, root->value.second);
			this->addNode(tmp);
			if (root != nullptr) {
				if (root->left != nullptr)
					preOrder(root->left);
				if (root->right != nullptr)
					preOrder(root->right);
			}
		}

		void addNo(tree tmp, const key_type &k) {
			value_type q(tmp._root->value.first, tmp._root->value.second);
			if (q.first != k)
				addNode(q);
			if (tmp._root != nullptr) {
				if (tmp._root->left != nullptr) {
					tmp._root = tmp._root->left;
					addNo(tmp, k);
				}
				tmp.returnPointerRoot();
				if (tmp._root->right != nullptr) {
					tmp._root = tmp._root->right;
					addNo(tmp, k);
				}
			}
			tmp.returnPointerRoot();
		}

		void deleteNode(Node **root) {
			if (*root) {
				deleteNode(&(*root)->left);
				deleteNode(&(*root)->right);
				_allocT.destroy(&(*root)->value);
				_allocNode.deallocate(*root, 1);
				*root = nullptr;
				_size--;
			}
		}

		void returnPointerRoot() {
			while (_root->parrent != nullptr) {
				_root = _root->parrent;
			}
		}
	};
}

#endif