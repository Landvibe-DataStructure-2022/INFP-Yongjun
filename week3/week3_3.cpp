#include <iostream>
#include <string>
using namespace std;

class node {
private:
	int value;
	node* next;
public:
	node() {
		this->value = 0;
		this->next = nullptr;
	}
	friend class Linkedlist;
	friend class stack;
};

class Linkedlist {
private:
	node* head;
	node* tail;
	int size;
public:
	Linkedlist() {
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
	void appendNode(int data) {
		node* curNode = new node();
		curNode->value = data;
		if (empty()) {
			this->head = curNode;
			this->tail = curNode;
		}
		else {
			this->tail->next = curNode;
			this->tail = curNode;
		}
		this->size++;
	}
	void deleteNode() {
		if (empty()) {
			cout << -1;
			return;
		}
		node* prevNode = this->head;
		node* deleteNode = this->tail;
		if (this->size == 1) {
			cout << this->head->value;
			this->head = nullptr;
			this->tail = nullptr;
			delete deleteNode;
		}
		else {
			for (int i = 2; i < size; i++) {
				prevNode = prevNode->next;
			}
			cout << deleteNode->value;
			this->tail = prevNode;
			delete deleteNode;
		}
	}
	friend class stack;
};

class stack {
private:
	Linkedlist* ll;
public:
	stack() {
		this->ll = new Linkedlist();
	}
	bool empty() {
		if (ll->empty()) {
			return true;
		}
		else {
			return false;
		}
	}
	int top() {
		if (this->ll->empty()) {
			return -1;
		}
		else { 
			return this->ll->tail->value; 
		}
	}
	void push(int x) {
		ll->appendNode(x);
	}
	void pop() {
		ll->deleteNode();
	}
};

int main() {
	string cmd;
	int N;
	int z;
	stack* sta = new stack();
	cin >> N;
	while (N--) {
		cin >> cmd;
		if (cmd == "empty") {
			if (sta->empty()) {
				cout << 1;
			}
			else {
				cout << 0;
			}
		}
		else if (cmd == "top") {
			cout << sta->top();
		}
		else if (cmd == "push") {
			cin >> z;
			sta->push(z);
		}
		else if (cmd == "pop") {
			sta->pop();
		}
	}
}