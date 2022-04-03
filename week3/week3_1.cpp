#include <iostream>
#include <string>

using namespace std;
int N, T;

class Stack {
private:
	int arr[10] = {};
	int size;
public:
	Stack() {
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
	void top() {
		if (empty()) {
			cout << -1;
		}
		else {
			cout << arr[size - 1];
		}
	}
	void push(int element) {
		if (size == T) {
			cout << "FULL";
			return;
		}
		else {
			arr[size] = element;
			size++;
		}
	}
	void pop() {
		if (empty()) {
			cout << -1;
			return;
		}
		else {
			this->top();
			size--;
		}
	}
};

int main() {
	cin >> T >> N;
	string str;
	int tmp;
	Stack* stack1 = new Stack();
	while (N--) {
		cin >> str;
		if (str == "empty") {
			if (stack1->empty()) {
				cout << 1;
			}
			cout << 0;
			cout << "\n";
		}
		else if (str == "top") {
			stack1->top();
			cout << "\n";
		}
		else if (str == "push") {
			cin >> tmp;
			stack1->push(tmp);
			cout << "\n";
		}
		else if (str == "pop") {
			stack1->pop();
			cout << "\n";
		}
	}
};