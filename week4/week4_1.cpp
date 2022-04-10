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
	friend class queue;
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
	void appendNode(int x) {
		node* curNode = new node();
		curNode->value = x;
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
			cout << "Empty";
			return;
		}
		else if (this->size==1) {
			delete this->head;
			this->head = nullptr;
			this->tail = nullptr;
		}
		else {
			node* prevNode = this->head;
			int a = prevNode->value;
			this->head = prevNode->next;
			delete prevNode;
			cout << a;
		}
		this->size--;
	}
	friend class queue;
};

class queue {
private:
	Linkedlist* ll;
	int sizeofq;
public:
	queue() {
		this->ll = new Linkedlist();
		this->sizeofq = 0;
	}
	void enqueue(int x) {
		ll->appendNode(x);
	}
	void dequeue() {
		ll->deleteNode();
	}
	void isEmpty() {
		if (ll->empty()) {
			cout << "true";
		}
		else {
			cout << "False";
		}
	}
	void size() {
		cout << ll->size;
	}
	void front() {
		if (ll->empty()) {
			cout << "Empty";
		}
		else {
			cout << ll->head->value;
		}
	}
	void rear() {
		if (ll->empty()) {
			cout << "Empty";
		}
		else {
			cout << ll->tail->value;
		}
	}
};

int main() {
	int T;
	int tmp;
	string cmd;
	cin >> T;
	queue* que = new queue();
	while (T--) {
		cin >> cmd;
		if (cmd == "enqueue") {
			cin >> tmp;
			que->enqueue(tmp);
		}
		else if (cmd == "dequeue") {
			que->dequeue();
		}
		else if (cmd == "isEmpty") {
			que->isEmpty();
		}
		else if (cmd == "size") {
			que->size();
		}
		else if (cmd == "front") {
			que->front();
		}
		else if (cmd == "rear") {
			que->rear();
		}
	}
	delete que;
}
