#include<iostream>
#include<string>
#include<algorithm>
using namespace std;



class Tree_node {
public:
	char item;
	Tree_node* lc;
	Tree_node* rc;
	Tree_node(char val = 'A', Tree_node* lc = NULL, Tree_node* rc = NULL) {
		item = val;
		this->lc = lc;
		this->rc = rc;
	}
	~Tree_node() {
		cout << "fuck!\n";
	}

};

class Queue {
public:
	int capacity;
	int head;
	int tail;
	Tree_node ** Arr;
	Queue(int capacity = 65535) {
		this->capacity = capacity;
		Arr = new Tree_node *[capacity];
		head = 0;
		tail = 0;
	}
	bool isEmpty() {
		return head == tail ? true : false;
	}
	void enQueue(Tree_node * item) {
		Arr[tail++] = item;
	}
	Tree_node * deQueue() {
		return Arr[head++];
	}
};

class Tree {
public:
	Tree_node* root;
	Tree(string input) {
		root = NULL;
		int strn = 0;
		build_help(input, strn, root);
	}
	void build_help(string input, int& strn, Tree_node*& rt) {
		if (rt == NULL) {
			rt = new Tree_node(input[strn]);
		}
		if (input.size() == strn + 1) {
			return;
		}
		if (input[strn] <= 'z' && input[strn] >= 'a') {
			build_help(input, ++strn, rt->lc);
			build_help(input, ++strn, rt->rc);
		}
	}
	int height() {
		return height_help(root);
	}
	int height_help(Tree_node* root) {
		if (root == NULL) {
			return 0;
		}
		return max(1 + height_help(root->lc), 1 + height_help(root->rc));
	}
	char isBalance() {
		return isBalance_help(root);
	}
	char isBalance_help(Tree_node* rt) {
		if (rt == NULL) {
			return 'B';
		}
		if (isBalance_help(rt->lc) == 'N') {
			return 'N';
		}
		if (isBalance_help(rt->rc) == 'N') {
			return 'N';
		}
		if (abs(height_help(rt->lc) - height_help(rt->rc)) > 1) {
			return 'N';
		}
		return 'B';
	}
	void levelOrder() {
		Queue * queue = new Queue;
		queue->enQueue(root);
		while (!queue->isEmpty()) {
			Tree_node* temp = queue->deQueue();
			cout << temp->item;
			if (temp->lc != NULL) {
				queue->enQueue(temp->lc);
			}
			if (temp->rc != NULL) {
				queue->enQueue(temp->rc);
			}
		}
		cout << endl;
	}
};
int main() {
	int T;
	cin >> T;
	for (int times = 0; times<T; times++) {
		string input;
		cin >> input;
		Tree* theTree = new Tree(input);
		theTree->levelOrder();
		delete theTree;
	}
	return 0;
}