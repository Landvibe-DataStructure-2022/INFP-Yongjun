#include <iostream>
#include <string>

using namespace std;

class Node {
private:
	int data;
	Node* next;
public:
	Node() {
		this->data = 0;
		this->next = nullptr;
	}
	~Node() {
		this->data = 0;
		this->next = nullptr;
	}
	friend class Linkedlist;
};

class Linkedlist {
private:
	Node* head;
	Node* tail;
	int size;
public:
	Linkedlist() {
		this->head = nullptr;
		this->tail = nullptr;
		this->size = 0;
	}
	~Linkedlist() {
		this->head = nullptr;
		this->tail = nullptr;
		this->size = 0;
	}
	bool empty() {
		if (this->size == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	void Print() {
		if (empty()) {
			cout << "empty";
			return;
		}
		Node* curNode = this->head;
		while (curNode != nullptr) {
			cout << curNode->data << " ";
			curNode = curNode->next;
		}
	}
	void Append(int value) {
		Node* AppendNode = new Node;
		AppendNode->data = value;
		if (empty()) {
			this->head = AppendNode;
			this->tail = AppendNode;
		}
		else {
			this->tail->next = AppendNode;
			this->tail = AppendNode;
		}
		this->size++;
		Print();
	}
	int Delete(int index) {
		if (empty() || index >= this->size) {
			return -1;
		}
		else {
			Node* DeleteNode = this->head;
			if (index == 0) {
				if (this->size == 1) {
					this->head = nullptr;
					this->tail = nullptr;
				}
				else {
					this->head = DeleteNode->next;
				}
			}
			else {
				Node* PrevNode = this->head;
				for (int i = 0; i < index; i++) {
					DeleteNode = DeleteNode->next;
					PrevNode->next = DeleteNode;
				}
				if (DeleteNode == this->tail) {
					this->tail = PrevNode;
				}
				PrevNode->next = DeleteNode->next;
			}
			int value_1 = DeleteNode->data;
			delete DeleteNode;
			return value_1;
		}
	}
	void Insert(int index, int value) {
		if (index > this->size) {
			cout << "Index Error";
			return;
		}
		Node* InsertNode = new Node;
		InsertNode->data = value;
		if (index == 0) {
			if (this->size == 0) {
				Append(index);
			}
			else {
				InsertNode->next = this->head;
				this->head = InsertNode;
				Print();
			}
		}
		else {
			Node* curNode = this->head;
			for (int j = 1; j < index; j++) {
				curNode = curNode->next;
			}
			InsertNode->next = curNode->next;
			curNode->next = InsertNode;
			if (index == this->size) {
				this->tail = InsertNode;
			}
			Print();
		}
	}
	void Sum() {
		int sum = 0;
		Node* curNode = this->head;
		for (int k = 0; k < this->size; k++) {
			sum = sum + curNode->data;
			curNode = curNode->next;
		}
		cout << sum;
	}
	void Min() {
		if (empty()) {
			cout << "empty";
			return;
		}
		Node* checkNode = this->head;
		int minofdata = this->head->data;
		for (int i = 0; i < this->size; i++) {
			if (minofdata > checkNode->data) {
				minofdata = checkNode->data;
			}
			checkNode = checkNode->next;
		}
		cout << minofdata;
	}
};

int main() {
	int M;
	int X;
	int I;
	string str;
	cin >> M;
	Linkedlist* ll = new Linkedlist;
	while (M--) {
		cin >> str;
		if (str == "Print") {
			ll->Print();
			cout << "\n";
		}
		else if (str == "Append") {
			cin >> X;
			ll->Append(X);
			cout << "\n";
		}
		else if (str == "Delete") {
			cin >> I;
			cout << ll->Delete(I) << "\n";
		}
		else if (str == "Insert") {
			cin >> I >> X;
			ll->Insert(I, X);
			cout << "\n";
		}
		else if (str == "Sum") {
			ll->Sum();
			cout << "\n";
		}
		else if (str == "Min") {
			ll->Min();
			cout << "\n";
		}
	}
	return 0;
}