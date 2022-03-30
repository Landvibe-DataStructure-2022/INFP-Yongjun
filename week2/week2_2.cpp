#include <iostream>
#include <string>

using namespace std;

class Node {
private:
	int data;
	Node* prev;
	Node* next;
public:
	Node() {
		this->data = 0;
		this->next = nullptr;
		this->prev = nullptr;
	}
	~Node() {
		this->data = 0;
		this->next = nullptr;
		this->prev = nullptr;
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
	void Print_reverse() {
		if (empty()) {
			cout << "empty";
			return;
		}
		Node* curNode = this->tail;
		while (curNode != nullptr) {
			cout << curNode->data << " ";
			curNode = curNode->prev;
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
			AppendNode->prev = this->tail;
			this->tail = AppendNode;

		}
		this->size++;
		Print();
	}
	int Delete(int index) {
		if (empty()||index>=this->size) {
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
				for (int i = 0; i < index; i++) {
					DeleteNode = DeleteNode->next;
				}
				DeleteNode->prev->next = DeleteNode->next;
				if (DeleteNode == this->tail) {
					this->tail = this->tail->prev;
				}
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
				this->head->prev = InsertNode;
				InsertNode->next = this->head;
				this->head = InsertNode;
				Print();
			}
		}
		else {
			Node* curNode = this->head;
			for (int j = 0; j < index; j++) {
				curNode = curNode->next;
			}
			curNode->prev->next = InsertNode;
			InsertNode->next = curNode;
			curNode->prev = InsertNode;
			if (index == this->size) {
				InsertNode->prev = this->tail;
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
	void Max() {
		if (empty()){
			cout << "empty";
			return;
		}
		int maxofdata = 0;
		Node* checkNode = this->head;
		for (int k = 0; k < this->size; k++) {
			if (maxofdata < checkNode->data) {
				maxofdata = checkNode->data;
			}
			checkNode = checkNode->next;
		}
		cout << maxofdata;
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
		else if (str == "Max") {
			ll->Max();
			cout << "\n";
		}
		else if (str == "Print_reverse") {
			ll->Print_reverse();
			cout << "\n";
		}
	}
	return 0;
}