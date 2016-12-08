#include <iostream>
#include <algorithm>
using namespace std;

class minHeap {
public:
	int * Heap;
	int size;
	int n;

	minHeap(int* h,int num,int max){
		Heap = h;
		n = num;
		size = max;
		buildHeap();
	}

	void buildHeap() {
		for (int i = n / 2 - 1; i >= 0; i--) {
			siftdown(i);
		}
	}

	int getSize() const {
		return n;
	}

	bool isLeaf(int pos) {
		return (pos >= n / 2) && (pos < n);
	}

	int leftChild(int pos)  {
		return 2 * pos + 1;
	}

	int rightChild(int pos) {
		return 2 * pos + 2;
	}

	int parent(int pos)const {
		return (pos - 1) / 2;
	}

	void siftdown(int pos) {

		while ( !isLeaf(pos) ) {

			int j = leftChild(pos);
			int rc = rightChild(pos);

			if ((rc < n) && Heap[j] > Heap[rc]) {
				j = rc;   // j   is   the  smaller child
			}
			if (Heap[pos] <= Heap[j]) {
				return;
			}
			swap(Heap[pos], Heap[j]);
			pos = j;
		}

	}

	bool removemin(int& it) {
		if (n == 0) return false;
		swap(Heap[0], Heap[--n]);
		if (n != 0) siftdown(0);
		it = Heap[n];
		return true;
	}


};



int main() {

		


	int i = 0;
	char c;
	int * arr = new int[200000];

	while (cin >> arr[i++]);

	int n = i - 1;



	minHeap h(arr, n, n);


	for (int i = 0; i < n - 1; i++) {
		cout << arr[i] << ' ';
	}
	cout << arr[n - 1] << endl;

	int temp;
	for (int i = 0; i < n; i++) {
		h.removemin(temp);
	}

	for (int i = 0; i < n - 1; i++) {
		cout << arr[i] << ' ';
	}
	cout << arr[n - 1] << endl;

}