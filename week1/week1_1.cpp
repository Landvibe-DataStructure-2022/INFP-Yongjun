#include <iostream>
#include <string>
using namespace std;

int arr[10000]; // ���������� �迭 �����ϸ� ��� ���� 0���� �ʱ�ȭ
int size_; // �迭�� ũ��

void at(int index) {
	cout << arr[index];
}
void add(int index, int value) {
	for (int j = size_-1; j > index; j--) {
		arr[j] = arr[j-1];
	}
	arr[index] = value;
}
void remove(int index) {
	for (int k = index; k < size_ - 1; k++) {
		arr[k] = arr[k + 1];
	}
	arr[size_ - 1] = 0;
}
void set(int index, int value) {
	arr[index] = value;
	cout << value;
}
void print() {
	for (int l = 0; l < size_; l++) {
		cout << arr[l] << " ";
	}
}
void find_max() {
	int tmd = 0;
	for (int h = 0; h < size_; h++) {
		if (tmd < arr[h]) {
			tmd = arr[h];
		}
	}
	cout << tmd;
}

int main() {
	int T = 0;
	int Index,Value = 0;
	cin >> size_ >> T;
	string str;
	while (T--) {
		cin >> str;
		if (str == "at") {
			cin >> Index;
			at(Index);
		}
		else if (str == "add") {
			cin >> Index >> Value;
			add(Index, Value);
		}
		else if (str == "remove") {
			cin >> Index;
			remove(Index);
		}
		else if (str == "set") {
			cin >> Index >> Value;
			set(Index, Value);
		}
		else if (str == "print") {
			print();
		}
		else if (str == "find_max") {
			find_max();
		}
	}
}