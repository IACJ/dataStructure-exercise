#include<iostream>
#include<cmath>
using namespace std;


class BST_node{
public:
	int item;
	BST_node* lc;
	BST_node* rc;
	BST_node(int val=0, BST_node* lc=NULL, BST_node* rc=NULL){
		item = val;
		this->lc = lc;
		this->rc = rc;
	}
	~BST_node(){
		cout <<"fuck!\n";
	}
		
};

class BST{
public:
	BST_node* root;
	BST(int* arr, int&n){
		root = NULL;
		for(int i = 0; i < n; i++){

			insert_help(root,arr[i]);

		}
	}
	void insert_help(BST_node*& root,int val){

		if (root == NULL){
			root = new BST_node(val);
			return;
		}
		if (val < root->item){
			insert_help(root->lc,val);
			
			return;
		}
		insert_help(root->rc,val);
		return;
	}
	int height() {
		return height_help(root);
	}
	int height_help(BST_node* root){
		if (root == NULL){
			return 0;
		}
		return max(1+ height_help(root->lc), 1+ height_help(root->rc));
	}
};


void getArr(int* arr, int&n){
	char c;
	n = 0;
	do{
		cin >> arr[n++];
		c = cin.get();		
		if (c == '\r' || c == '\n'){
			return;
		}
	}while(1);
	return;
}
int main(){
	int T;
	cin >> T;
	cin.get();
	for (int times=0; times<T; times++){
		int* arr = new int[65535];
		int n;
		getArr(arr,n);
		BST* theTree = new BST(arr,n);
		cout << theTree->height() <<endl;
		delete[] arr;
	}
	return 0;
}