#include <iostream>
#include <string>

using namespace std;
int T;

class Stack {
private:
	int arr[100] = {};
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
	int top() {
		return arr[size - 1];
	}
	void push(int element) {
		arr[size] = element;
		size++;
	}
	int pop() {
		size--;
		return arr[size];
	}
};

int main() {
	cin >> T;
	string str;
	Stack stack1 = Stack();
	while (T--) {
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] - '0' >= 0 && str[j] - '0' <= 9) {
				stack1.push(str[j] - '0');
			}
			else {
				int num2 = stack1.pop();
				int num1 = stack1.pop();

				if (str[j] == '+') {
					stack1.push((num1 + num2));
				}
				else if (str[j] == '-') {
					stack1.push((num1 - num2));
				}
				else if (str[j] == '*') {
					stack1.push((num1 * num2));
				}
			}
		}
		cout << stack1.top() % 10 << '\n';
	}
	return 0;
};