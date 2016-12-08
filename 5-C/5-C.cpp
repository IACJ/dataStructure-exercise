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
		while (HT[pos].key != 0 && HT[pos].key != -1) {
			i++;
			pos = (home + p(key, i)) % M;
		}
		HT[pos] = KVPair(key, value);
	}

	void del(int key) {
		int home, pos;
		home = pos = h(key);
		int i = 0;
		while (HT[pos].key != 0 && HT[pos].key != key) {
			i++;
			pos = (home + p(key, i)) % M;
		}

		if (HT[pos].key == key) {
			HT[pos].key = -1;
		}
	}

	int find(int key) {
		int home, pos;
		home = pos = h(key);
		int i = 0;
		while (HT[pos].key != 0 && HT[pos].key != key) {
			i++;
			pos = (home + p(key, i)) % M;
		}

		if (HT[pos].key == key) {
			return pos;
		}
		else {
			return -1;
		}
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

	cin.get();
	int temp;
	int c;

	do {
		cin >> temp;
		h.insert(temp, temp);
		c = cin.get();
	} while (c != '\r' && c != '\n');


	do {
		cin >> temp;
		h.del(temp);
		c = cin.get();
	} while (c != '\r' && c != '\n');


	do {
		cin >> temp;
		int ans = h.find(temp);
		if (ans == -1) {
			cout << "NO" << endl;
		}
		else {
			cout << ans << endl;
		}

		c = cin.get();
	} while (c != '\r' && c != '\n');

	return 0;
}