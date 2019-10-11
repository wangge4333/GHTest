// BinaryTreeClassTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <random>
#include <queue>

using namespace std;

class Node {
private:
	int value;
	class Node* left = nullptr;
	class Node* right = nullptr;
public:
	int get_Value() const { return value; };
	void set_Value(int _value);
	Node* get_Left() const { return left; };
	Node* get_Right() const { return right; };
	void new_Left();
	void new_Right();


	Node();
	~Node();
};

Node::Node() :value(0) {};

Node::~Node() { 
	cout << "Node " << value << " has been deleted. " << endl; 
}

void Node::set_Value(int _value) {
	value = _value;
}

void Node::new_Left() {
	left = new Node();
}

void Node::new_Right() {
	right = new Node();
}

class BinarySearchTree {
private:
	Node* root;
public:
	BinarySearchTree();
	~BinarySearchTree();
	Node* get_Root() { return root; };
	void insert_integer(class Node* root, int value);
	void print_tree_pre(class Node* root);
	void print_tree_in(class Node* root);
	void print_tree_post(class Node* root);
	void get_tree_by_level(class Node* root);

	void terminate_tree(class Node* tree);
};

BinarySearchTree::BinarySearchTree() {
	root = new Node();
}

BinarySearchTree::~BinarySearchTree() {
	terminate_tree(root);
	cout << "Tree has been deleted." << endl;
}

void BinarySearchTree::insert_integer(class Node* root, int value) {
	if (value < root->get_Value()) {
		if (root->get_Left() == nullptr) {
			root->new_Left();
			root->get_Left()->set_Value(value);
		}
		else {
			insert_integer(root->get_Left(), value);
		}
	}
	else if (value > root->get_Value()) {
		if (root->get_Right() == nullptr) {
			root->new_Right();
			root->get_Right()->set_Value(value);
		}
		else
		{
			insert_integer(root->get_Right(), value);
		}
	}
	else {
		cout << "Element " << value << " exists." << endl;
		return;
	}
}

void BinarySearchTree::print_tree_pre(class Node* tree) {
	if (tree != nullptr) {
		cout << tree->get_Value() << ' ';
		print_tree_pre(tree->get_Left());
		print_tree_pre(tree->get_Right());
	}
}

void BinarySearchTree::print_tree_in(class Node* tree) {
	if (tree != nullptr) {
		print_tree_in(tree->get_Left());
		cout << tree->get_Value() << ' ';
		print_tree_in(tree->get_Right());
	}
}

void BinarySearchTree::print_tree_post(class Node* tree) {
	if (tree != nullptr) {
		print_tree_post(tree->get_Left());
		print_tree_post(tree->get_Right());
		cout << tree->get_Value() << ' ';
	}
}

void BinarySearchTree::terminate_tree(class Node* tree) {
	if (tree != nullptr) {
		terminate_tree(tree->get_Left());
		terminate_tree(tree->get_Right());

		delete tree;
		tree = nullptr;
	}
}

void BinarySearchTree::get_tree_by_level(class Node* tree) {
	queue<Node*> node_queue;
	if (tree != nullptr) {
		node_queue.push(tree);
	}

	while (node_queue.size() > 0) {
		cout << node_queue.front()->get_Value() << ' ';
		if (node_queue.front()->get_Left() != nullptr)
			node_queue.push(node_queue.front()->get_Left());
		if (node_queue.front()->get_Right() != nullptr)
			node_queue.push(node_queue.front()->get_Right());
		node_queue.pop();
	}

}

int main()
{
	BinarySearchTree* tree = new BinarySearchTree();

	default_random_engine random_num;
	uniform_int_distribution<signed> random_num_dis(-15, 15);
	for (int i = 0; i < 15; i++) {
		int temp = random_num_dis(random_num);
		cout << temp << endl;
		tree->insert_integer(tree->get_Root(), temp);
	}


	tree->print_tree_pre(tree->get_Root());
	cout << endl;

	tree->print_tree_in(tree->get_Root());
	cout << endl;

	tree->print_tree_post(tree->get_Root());
	cout << endl;

	tree->get_tree_by_level(tree->get_Root());
	cout << endl;

	delete tree;
	cout << endl;

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
