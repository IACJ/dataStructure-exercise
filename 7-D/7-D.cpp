#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Link_node {
public:
	int element;  // Value for this node
	Link_node *next;    // Pointer to next node 

	Link_node(const int e, Link_node* nextp = NULL) {
		element = e;  
		next = nextp;
	}
	Link_node(Link_node* nextp = NULL) {
	next = nextp;
	}
};


class LList {
private:
	Link_node* head;    //Point to list header
	Link_node* tail;
public:
	LList() {
		tail = head = new Link_node;
	}

	~LList() {
		this->clear();
		delete head;
	}
	void clear() {
		Link_node*  temp;
		Link_node*  fence = head->next;
		while (fence != NULL) {
			temp = fence;
			fence = fence->next;
			delete temp;
		}
		tail = fence = head;
		head->next = NULL;
	}

	bool append(const int item) {
		tail = tail->next = new Link_node(item, NULL);
		return true;
	}

	void print() const {

		Link_node* iterator = head->next;
		
		while (iterator != NULL) {
			cout << iterator->element << ' ';
			iterator = iterator->next;
		}
	}

	void swapPairs_controller() {
		Link_node* temp = head;
		
		while (temp->next != NULL && temp->next->next != NULL) {

			temp->next = swapPairs(temp->next);

			temp = temp->next->next;
		}

	}

	Link_node* swapPairs(Link_node* p) {
		Link_node* tempAddr = p->next;

		p->next = tempAddr->next;

		tempAddr->next = p;

		return tempAddr;

	}

};




int main() {
	int m;
	cin >> m;
	cin.get();
	while (m--) {
		LList temp_list;
		
		int temp;
		do {
			cin >> temp;
			if (temp == -1) {
				break;
			}

			temp_list.append(temp);

		} while (true);

		temp_list.swapPairs_controller();

		temp_list.print();

		cout << endl;
	}
}