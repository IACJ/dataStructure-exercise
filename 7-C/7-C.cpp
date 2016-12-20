#include <iostream>
#include <vector>
using namespace std;

int main() {
	int m;
	cin >> m;
	cin.get();
	while (m--) {
		
		char c;
		
		vector<bool> mark(26, false);

		do {
			c = cin.get();

			if (c == '\r' || c == '\n') {
				break;
			}

			if (!mark[c - 'a']) {
				mark[c - 'a'] = true;
				cout << c;
			}

		} while (true);

		cout << endl;

	}
}