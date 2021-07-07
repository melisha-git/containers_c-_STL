#ifndef TREE_CLASS_HPP
#define TREE_CLASS_HPP
#include <iostream>

template<typename T, class _Allocator = std::allocator<T> >
class tree {
private:
    struct Node {
		T value;
		Node *parrent;
		Node *left;
		Node *right;
    };
	size_t _size;
	_Allocator _allocT;
	std::allocator<Node> _allocNode;
	Node *_root;
public:
	tree(const _Allocator &alloc = _Allocator()) : _size(0), _allocT(alloc) {
		_root = _allocNode.allocate(1);
		_allocT.construct(&_root->value, T());
		_root->parrent = nullptr;
		_root->left = nullptr;
		_root->right = nullptr;
	}
	~tree() {
		deleteNode(&_root);
	}
	void returnPointerRoot() {
		while (_root->parrent != nullptr) {
			_root = _root->parrent;
		}
	}
	void deleteNode(Node **root) {
		if (*root)
		{
			deleteNode(&(*root)->left);
			deleteNode(&(*root)->right);
			_allocT.destroy(&(*root)->value);
			_allocNode.deallocate(*root, 1);
			*root = nullptr;
			_size--;
		}
	}
	void addNode(const T &value) {
		if (_size == 0) {
			_allocT.destroy(&_root->value);
			_allocT.construct(&_root->value, T(value));
		} else {
			if (value < _root->value) {
				if (_root->left) {
					_root = _root->left;
					return addNode(value);
				} else {
					_root->left = createNode(value, _root);
				}
			} else if (value > _root->value) {
				if (_root->right) {
					_root = _root->right;
					return addNode(value);
				} else {
					_root->right = createNode(value, _root);
				}
			}
		}
		returnPointerRoot();
		_size++;
	}
	Node *createNode(const T &value, Node *root) {
		Node *newNode;
		newNode = _allocNode.allocate(1);
		_allocT.construct(&newNode->value, T(value));
		newNode->parrent = root;
		newNode->left = nullptr;
		newNode->right = nullptr;
		return newNode;
	}
	void print() {
		printBT(_root);
	}
	void printBT(const std::string& prefix, const Node* node, bool isLeft)
	{
    	if( node != nullptr )
    	{
    	    std::cout << prefix;
    	    std::cout << (isLeft ? "├──" : "└──" );
    	    std::cout << node->value << std::endl;
    	    // enter the next tree level - left and right branch
    	    printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
    	    printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    	}
	}
	void printBT(const Node* node)
	{
	    printBT("", node, false);    
	}
	Node *searchNode(const T &value) {
		if (_size == 0)
			return nullptr;
		if (_root->value == value)
		{
			Node *tmp = _root;
			returnPointerRoot();
			return tmp;
		}
		if (value >= _root->value) {
			if (_root->right != nullptr) {
				_root = _root->right;
				return searchNode(value);
			}
		} else if (value <= _root->value) {
			if (_root->left != nullptr) {
				_root = _root->left;
				return searchNode(value);
			}
		}
		while (_root->parrent != nullptr) {
			_root = _root->parrent;
		}
		returnPointerRoot();
		return nullptr;
	}
	T &operator[](const T& k) {
		Node *tmp = this->searchNode(k);
		if (tmp != nullptr)
			return tmp->value;
		this->addNode(k);
		tmp = this->searchNode(k);
		return tmp->value;
	}
};

#endif