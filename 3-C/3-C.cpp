#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	char * inp = new char[1024];
	cin.getline(inp, 1024);
	string a = inp;

	int * mark = new int[26];

	for (int i = 0; i<26; i++) {
		mark[i] = 0;
	}


	for (int i = 0; i<a.size(); i++) {
		if (a[i] >= 'A' && a[i] <= 'Z') {
			mark[a[i] - 'A']++;
		}
	}

	int j = 0;
	while (mark[j] == 0) {
		j++;
	}


	for (int i = 0; i<a.size(); i++) {
		if (a[i] >= 'A' && a[i] <= 'Z') {
			a[i] = 'A' + j;
			mark[j] --;
			while (j<26 && mark[j] == 0) {
				j++;
			}
		}
	}

	cout << a;
	return 0;
}