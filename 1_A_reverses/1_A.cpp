#include<iostream>
#include<string>
using namespace std;

class Stack {
private:
	int top;
	int capacity;
	char * theArray;
public:
	Stack(int capacity = 1024) {
		top = 0;
		this->capacity = capacity;
		theArray = new char[capacity];
	}
	~Stack() {
		delete[] theArray;
	}

	bool push(char item) {
		if (top == capacity) {
			return false;
		}
		theArray[top++] = item;
		return true;
	}

	bool pop(char& item) {
		if (top == 0) {
			return false;
		}
		item = theArray[--top];
		return true;
	}

	void clear() {
		top = 0;
	}
};


int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string input;
		cin >> input;
		Stack stack(65535);

		for (int j = 0; j < input.size(); j++) {
			stack.push(input[j]);
		}

		for (int j = 0; j < input.size(); j++) {
			char temp = ' ';
			stack.pop(temp);
			cout << temp;
		}
		cout << endl;
	}
}