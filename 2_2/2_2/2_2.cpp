#include<iostream>
#include<cmath>
#include<string>
using namespace std;


class Tree_node{
public:
	int item;
	Tree_node* lc;
	Tree_node* rc;
	Tree_node(int val=0, Tree_node* lc=NULL, Tree_node* rc=NULL){
		item = val;
		this->lc = lc;
		this->rc = rc;
	}
	~Tree_node(){
		cout <<"fuck!\n";
	}
		
};

class Tree{
public:
	Tree_node* root;
	Tree(string input){
		root = NULL;
		int strn = 0;
		build_help(input,strn,root);
	}
	void build_help(string input, int& strn, Tree_node*& rt){
		//cout <<"mark3";
		if (rt == NULL){
			rt = new Tree_node();
		}
		//cout <<"mark2";
		if (input.size() == strn+1){
			return;
		}
		if (input[strn] <='z' && input[strn] >='a'){
			//cout <<"mark1";
			build_help(input,++strn,rt->lc);
			build_help(input,++strn,rt->rc);
		}
	}

	int height() {
		return height_help(root);
	}
	int height_help(Tree_node* root){
		if (root == NULL){
			return 0;
		}
		return max(1+ height_help(root->lc), 1+ height_help(root->rc));
	}

	char isBalance(){
		return isBalance_help(root);
	}

	char isBalance_help(Tree_node* rt){
		if (rt == NULL){
			return 'B';
		}
		if (isBalance_help(rt->lc) == 'N'){
			return 'N';
		}
		if (isBalance_help(rt->rc) == 'N'){
			return 'N';
		}
		if ( abs( height_help(rt->lc) -  height_help(rt->rc)) >1){
			return 'N';
		}
		return 'B';
	}
};



int main(){
	int T;
	cin >> T;
	for (int times=0; times<T; times++){
		string input;
		cin >>input;
		Tree* theTree = new Tree(input);
		cout << theTree->isBalance() <<endl;
		delete theTree;
	}
	return 0;
}