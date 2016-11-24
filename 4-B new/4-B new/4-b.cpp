#include<iostream>
#include<string>
using namespace std;

class BST_node{
public:
	int val;
	BST_node* l;
	BST_node* r;

	BST_node(int val =0,BST_node* l=NULL,BST_node* r=NULL){
		this->val = val;
		this->l = l;
		this->r = r;
	}
};

class Queue{
public:
	int head;
	int tail;
	BST_node** arr;

	Queue(){
		head = tail =0;
		arr = new BST_node*[1024];
	}

	bool isEmpty(){
		return tail == head;
	}

	void enqueue(BST_node* item){
		arr[tail++] = item;
	}

	BST_node* dequeue(){
		return arr[head++];
	}
};

class BST{
public:
	BST_node* root;

	BST(string input){
		root =NULL;
		int i = 0;
		while (i < input.size()){
			int temp = 0;
			do{
				temp *= 10;
				temp += input[i]-'0';
				i++;
			}while (i < input.size() && input[i] != ',');
			
			insert_help(root,temp);
			i++;
		}
	}

	void print(){
		Queue queue;
		queue.enqueue(root);


		while (!queue.isEmpty()){

			BST_node* temp = queue.dequeue();

			cout <<temp->val<<' ';

			if (temp->l != NULL){
				queue.enqueue(temp->l);
			}
			if (temp->r != NULL){
				queue.enqueue(temp->r);
			}
		}
	cout <<endl;
	}

	void insert_help(BST_node*& rt,int val){
		if (rt == NULL){
			rt = new BST_node(val);
			return;
		}
		if (val < rt->val ){
			insert_help(rt->l,val);
			
		}else{
			insert_help(rt->r,val);
			
		}
	}

};


int main() {
	int N;
	cin  >> N ;
	cin.get();
	while (N--){
		char s [1024];
		cin.getline(s,1024);
		string input = s;

		BST* p = new BST(input);
		p->print();
	}

	return 0;
}
