// 04102019Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <random>
#include <queue>

using namespace std;

void ArrayHeapTest();

struct node {
	int value = 0;
	struct node* left = nullptr;
	struct node* right = nullptr;
};

struct node* root = nullptr;

void insert_integer(struct node** tree, int value);
void print_tree_pre(struct node* tree);
void print_tree_in(struct node* tree);
void print_tree_post(struct node* tree);
void get_tree_by_level(struct node* tree);

void terminate_tree(struct node* tree);

int main()
{
	//ArrayHeapTest();
	root = new node;
	root->value = 0;


	default_random_engine random_num;
	uniform_int_distribution<signed> random_num_dis(-15, 15);
	for (int i = 0; i < 15; i++) {
		int temp = random_num_dis(random_num);
		cout << temp << endl;
		insert_integer(&root, temp);
	}


	print_tree_pre(root);
	cout << endl;

	print_tree_in(root);
	cout << endl;

	print_tree_post(root);
	cout << endl;

	get_tree_by_level(root);
	cout << endl;

	terminate_tree(root);
	//print_tree_post(root);
	cout << endl;

}

void ArrayHeapTest() {
	int* ptr_intarray = new int[10];
	cout << "Now ptr's address is " << ptr_intarray << endl;

	for (int i = 0; i < 10; i++)
		ptr_intarray[i] = i * 2;

	for (int i = 0; i < 10; i++)
		cout << "No." << i + 1 << " number is " << ptr_intarray[i] << endl;

	delete[]ptr_intarray;
	//cout << "Now ptr's address is " << ptr_intarray << endl;

	ptr_intarray = NULL;

	cout << "Now ptr's address is " << ptr_intarray << endl;


}

void insert_integer(struct node** tree, int value) {
	node* root1 = *tree;

	if (value < root1->value) {
		if (root1->left == nullptr) {
			root1->left = new node;
			root1->left->value = value;
		}
		else {
			insert_integer(&(root1->left), value);
		}
	}
	else if (value > root1->value) {
		if (root1->right == nullptr) {
			root1->right = new node;
			root1->right->value = value;
		}
		else
		{
			insert_integer(&(root1->right), value);
		}
	}
	else {
		cout << "Element " << value << " exists." << endl;
		return;
	}
}

void print_tree_pre(struct node* tree) {
	if (tree != nullptr) {
		cout << tree->value << ' ';
		print_tree_pre(tree->left);
		print_tree_pre(tree->right);
	}
}

void print_tree_in(struct node* tree) {
	if (tree != nullptr) {
		print_tree_in(tree->left);
		cout << tree->value << ' ';
		print_tree_in(tree->right);
	}
}

void print_tree_post(struct node* tree) {
	if (tree != nullptr) {
		print_tree_post(tree->left);
		print_tree_post(tree->right);
		cout << tree->value << ' ';
	}
}

void terminate_tree(struct node* tree) {
	if (tree != nullptr) {
		terminate_tree(tree->left);
		terminate_tree(tree->right);

		delete tree;
		tree = nullptr;
	}
}

void get_tree_by_level(struct node* tree) {
	queue<node*> node_queue;
	if (tree != nullptr) {
		node_queue.push(tree);
	}

	while (node_queue.size() > 0) {
		cout << node_queue.front()->value << ' ';
		if (node_queue.front()->left != nullptr)
			node_queue.push(node_queue.front()->left);
		if (node_queue.front()->right != nullptr)
			node_queue.push(node_queue.front()->right);
		node_queue.pop();
	}

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
