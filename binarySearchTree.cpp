#include "binarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
	size = 0;
}
BinarySearchTree::~BinarySearchTree()
{
	while (root != nullptr) {
		remove(root->data);
	}

	delete root;
}

void BinarySearchTree::insert(int value)
{
	Node* newNode = new Node{ value, nullptr, nullptr };

	if (root == nullptr) {
		root = newNode;
	}
	else {
		Node* current = root;
		Node* parent = nullptr;

		while (true) {
			parent = current;

			if (value < current->data) {
				current = current->left;
				if (current == nullptr) {
					parent = current;
					break;
				}
			}
			else {
				current = current->right;
				if (current == nullptr) {
					parent = current;
					break;
				}
			}

			if (value < parent->data) {
				parent->left = newNode;
			}
			else {
				parent->right = newNode;
			}

			size++;
		}
	}
}

bool BinarySearchTree::search(Node* current, int value)
{
	if (current != nullptr) {
		if (current->data == value) {
			return true;
		}
		else if (value < current->data) {
			return search(current->left, value);
		}
		else {
			return search(current->right, value);
		}
	}
	return false;
}
bool BinarySearchTree::search(int value)
{
	return search(root, value);
}

void BinarySearchTree::display(Node* current) {
	if (current != nullptr) {
		display(current->left);
		cout << current->data << " ";
		display(current->right);
	}
}
void BinarySearchTree::display()
{
	display(root);
}

int BinarySearchTree::getSize()
{
	return size;
}

int BinarySearchTree::getHeight()
{
	return getHeight(root);
}

int BinarySearchTree::getHeight(Node* current)
{
	if (current == nullptr) {
		return 0;
	}
	else {
		int leftHeight = getHeight(current->left);
		int rightHeight = getHeight(current->right);

		if (leftHeight > rightHeight) {
			return leftHeight + 1;
		}
		else {
			return rightHeight + 1;
		}
	}
}

int BinarySearchTree::getSuccessor(Node* current)
{
	if (current->right != nullptr) {
		current = current->right;
		while (current->left != nullptr) {
			current = current->left;
		}
		return current->data;
	}
	else {
		Node* successor = nullptr;
		Node* ancestor = root;

		while (ancestor != current) {
			if (current->data < ancestor->data) {
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else {
				ancestor = ancestor->right;
			}
		}
		if (successor == nullptr) {
			return -1;
		}
		else {
			return successor->data;
		}
	}
}
int BinarySearchTree::getSuccessor(int value)
{
	Node* current = root;
	Node* parent = nullptr;

	while (current != nullptr && current->data != value) {
		parent = current;
		if (value < current->data) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}

	if (current == nullptr) {
		return -1;
	}
	else {
		return getSuccessor(current);
	}
}

int BinarySearchTree::getPredecessor(Node* current)
{
	if (current->left != nullptr) {
		current = current->left;
		while (current->right != nullptr) {
			current = current->right;
		}
		return current->data;
	}
	else {
		Node* predecessor = nullptr;
		Node* ancestor = root;

		while (ancestor != current) {
			if (current->data > ancestor->data) {
				predecessor = ancestor;
				ancestor = ancestor->right;
			}
			else {
				ancestor = ancestor->left;
			}
		}
		if (predecessor == nullptr) {
			return -1;
		}
		else {
			return predecessor->data;
		}
	}
}
int BinarySearchTree::getPredecessor(int value)
{
	Node* current = root;
	Node* parent = nullptr;

	while (current != nullptr && current->data != value) {
		parent = current;
		if (value < current->data) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}

	if (current == nullptr) {
		return -1;
	}
	else {
		return getPredecessor(current);
	}
}

void BinarySearchTree::remove(int value)
{
	Node* current = root;
	Node* parent = nullptr;

	while (current != nullptr && current->data != value) {
		parent = current;
		if (value < current->data) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}

	if (current == nullptr) {
		return;
	}

	if (current->left == nullptr && current->right == nullptr) {
		if (current == root) {
			root = nullptr;
		}
		else if (current == parent->left) {
			parent->left = nullptr;
		}
		else {
			parent->right = nullptr;
		}
		delete current;
	}
	else if (current->left != nullptr && current->right != nullptr) {
		int successor = getSuccessor(current);
		remove(successor);
		current->data = successor;
	}
	else {
		Node* child = (current->left != nullptr) ? current->left : current->right;
		if (current == root) {
			root = child;
		}
		else if (current == parent->left) {
			parent->left = child;
		}
		else {
			parent->right = child;
		}
		delete current;
	}
}