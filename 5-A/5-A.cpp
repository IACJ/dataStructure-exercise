#include <iostream>
using namespace std;

class KVPair_Node {
public:

	long long  key;
	int valfucku;
	KVPair_Node* next;

	KVPair_Node(int key = 0, int fuckit = 0, KVPair_Node* next = NULL) {
		this->key = key;
		valfucku = 0;
		this->next = next;
	}
};

class SeparateChainingSlot {
public:
	int n;
	KVPair_Node* root;
	SeparateChainingSlot() {
		n = 0;
		root = NULL;
	}
	~SeparateChainingSlot() {
		KVPair_Node* p = root;
		KVPair_Node* toDel;
		while (p != NULL) {
			toDel = p;
			p = p->next;
			delete toDel;
		}
	}
	void add(int key) {
		n++;
		if (root == NULL) {
			root = new KVPair_Node(key, key);
			return;
		}
		KVPair_Node* p = root->next;
		while (p != NULL) {
			p = p->next;
		}
		p = new KVPair_Node(key, key);
	}
	int size() {
		return n;
	}
};
class HashOpenChaining {
public:
	int M;
	SeparateChainingSlot* HT;
	HashOpenChaining(int M) {
		this->M = M;
		HT = new SeparateChainingSlot[this->M];
		for (int i = 0; i<this->M; i++) {
			HT[i].n = 0;
			HT[i].root = NULL;
		}
	}
	~HashOpenChaining() {
		delete[] HT;
	}
	int h(int key) {
		return key %  M;
	}
	void insert(int key) {
		int home = h(key);
		HT[home].add(key);
	}
	int count(int key) {
		return HT[key].size();
	}
};


int main() {
	int t;
	cin >> t;
	while (t--) {
		int N, M, K;
		cin >> N >> M >> K;
		HashOpenChaining*  h = new HashOpenChaining(M);
		int temp;
		for (int i = 0; i<N; i++) {
			cin >> temp;
			h->insert(temp);
		}
		cout << h->count(K) << endl;
		delete h;
	}
	return 0;
}