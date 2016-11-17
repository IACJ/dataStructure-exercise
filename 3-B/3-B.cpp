#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Student {
public:
	int id;
	string name;
	int chinese;
	int math;
	int english;
	int total;
};

bool cmp(const Student& a, const Student& b) {
	if (a.total>b.total) return true;
	if (a.total<b.total) return false;
	if (a.chinese>b.chinese) return true;
	if (a.chinese<b.chinese) return false;
	if (a.math>b.math) return true;
	if (a.math<b.math) return false;
	return false;
}


int main() {
	int n;
	cin >> n;
	Student* arr = new Student[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].id >> arr[i].name >> arr[i].chinese >> arr[i].math >> arr[i].english;
		arr[i].total = arr[i].math + arr[i].chinese + arr[i].english;
	}

	stable_sort(arr, arr + n, cmp);


	for (int i = 0; i < n; i++) {
		cout << arr[i].id << " " << arr[i].name << " " << arr[i].total << endl;
	}
	return 0;
}