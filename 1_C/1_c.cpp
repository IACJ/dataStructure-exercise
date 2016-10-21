#include<iostream>
#include<string>
using namespace std;

class triple {
public:
	string name;
	string author;
	string price;
};

class List {
private:
	int length;
	int capacity;
	triple * theArray;
public:
	List(int capacity = 65535) {
		length= 0;
		this->capacity = capacity;
		theArray = new triple[capacity];
	}

	~List() {
		delete[] theArray;
	}

	bool findByNameAndAuthor(string name, string author) {
		for (int i = 0; i < length; i++) {
			if (theArray[i].name == name && theArray[i].author == author) {
				return true;
			}
		}
		return false;
	}

	bool add(string name, string author,string price) {
		if (length == capacity) {
			return false;
		}
		if (findByNameAndAuthor(name, author) == true) {
			return false;
		}
		theArray[length].name = name;
		theArray[length].author = author;
		theArray[length].price = price;
		length++;
		return true;
	}

	bool remove(string name, string author) {
		if (length == capacity) {
			return false;
		}

		for (int i = 0; i < length; i++) {
			if (theArray[i].name == name && theArray[i].author == author) {
				for (int j = length - 2; j >= i; j--) {
					theArray[j] = theArray[j + 1];
				}
				length--;
				return true;
			}
		}
		return false;
	}



	int countByName(string name) {
		int count = 0;
		for (int i = 0; i < length; i++) {
			if (theArray[i].name == name ) {
				count++;
			}
		}
		return count;
	}


	bool isEmpty() {
		return length == 0 ? true : false;
	}

};


void getout(string& input,int&j, string&item) {
	//ignore
	while (input[j] != '(') {
		j++;
	}
	//getvalue
	j++;
	while (input[j] != ')') {
		item += input[j];
		j++;
	}
}

int main() {
	int T;
	cin >> T;
	string useless;
	getline(cin,useless);
	List list;

	for (int i = 0; i < T; i++) {
		string input;
		getline(cin,input);
		switch (input[0])
		{
		case'A': {
			int j = 0;
			string name, author, price;
			getout(input, j, name);
			getout(input, j, author);
			getout(input, j, price);
			if (list.add(name, author, price)) {
				cout << "SUCCESS" << endl;
			} else {
				cout << "FAIL" << endl;
			}
			break;
		}
		case'R': {
			int j = 0;
			string name, author;
			getout(input, j, name);
			getout(input, j, author);
			if (list.remove(name, author)) {
				cout << "SUCCESS" << endl;
			} else {
				cout << "FAIL" << endl;
			}
			break;
		}
			
		case'F': {
			int j = 0;
			string name;
			getout(input, j, name);
			cout << list.countByName(name) << endl;;
			break;
		}
		}
	}
}