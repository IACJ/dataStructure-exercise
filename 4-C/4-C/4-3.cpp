#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	while (N--){
		int m;
		cin >> m;
		long long *a = new long long [m+10];
		a[0] = 0;
		a[1] = 1;
		for (int i = 2; i<=m;i++){
			a[i] = a[i-1] + a[i-2];
		}
		cout << a[m] << endl;
		delete [] a;
	}
	return 0;
}