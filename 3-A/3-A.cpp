#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void qsort1(int* arr, int l, int r) {
	int i = l;
	int j = r;
	int halfVal = arr[r];

	while (i <j) {
		while (arr[i] < halfVal) { i++; }
		while (arr[j] > halfVal) { j--; }
		if (i<j) {
			swap(arr[i], arr[j]);
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n = 0;
		char c = ' ';
		int* arr = new int[1024];
		do {
			cin >> arr[n++];
			c = cin.get();
		} while (c != '\n' && c != '\r');


		int val = arr[n - 1];
		qsort1(arr, 0, n - 1);

		for (int i = 0; i<n; i++) {
			if (arr[i] == val) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}