#include <iostream>
using namespace std;

class KVPair {
public:
	int key;
	int val;
	KVPair(int key = 0, int val = 0) {
		this->key = key;
		this->val = val;
	}
};

class HashDict {
public:
	int M;
	KVPair* HT;

	HashDict(int M) {
		this->M = M;
		HT = new KVPair[this->M];
		for (int i = 0; i<M; i++) {
			HT[i].key = 0;
		}
	}
	int h(int key) {
		return key %  M;
	}

	int p(int key, int i) {
		return i;
	};

	void insert(int key, int value) {
		int home, pos;
		home = pos = h(key);
		int i = 0;
		while (HT[pos].key != 0) {
			i++;
			pos = (home + p(key, i)) % M;
		}
		HT[pos] = KVPair(key, value);
	}

	void show() {
		for (int i = 0; i<M; i++) {
			if (HT[i].key != 0) {
				cout << i << " " << HT[i].key << endl;
			}
		}
	}

};


int main() {
	int n;
	cin >> n;
	HashDict h(n);

	int temp;
	while (cin >> temp) {
		h.insert(temp, temp);
	}

	h.show();

	return 0;
}