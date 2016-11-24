#include<iostream>

using namespace std;


int main(){
	int N;
	cin >>N;
	while (N--){
		int* a = new int[9];
		for (int i=0;i<9;i++){
			cin >>a[i];
		}

		int val = a[0];
		for (int i=0;i<9;i++){
			if (a[i]<val){
				int temp = a[i];
				for (int j=i;j>0;j--){
					a[j] = a[j-1];
				}
				a[0] = temp;
			}
		}

		for (int i=0;i<8;i++){
			cout <<a[i] << ' ';
		}
		cout << a[8];
		cout <<endl;
	}
}