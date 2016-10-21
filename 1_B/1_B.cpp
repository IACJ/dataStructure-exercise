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

	bool isEmpty() {
		return top == 0 ? true : false;
	}

};


int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string input;
		cin >> input;
		Stack stack(65535);
		char temp;
		int j;
		for (j = 0; j < input.size(); j++) {
			if (input[j] == '(') {
				stack.push(input[j]);
				continue;
			}  
			if (input[j] == ')') {
				if (!stack.pop(temp) || temp != '(') {
					break;
				}
			}
		}
		if (j == input.size() && stack.isEmpty()) {
			cout << "TRUE" << endl;
		} else {
			cout << "FALSE" << endl;
		}
		
	}
}