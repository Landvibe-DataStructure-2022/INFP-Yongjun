#include <iostream>

using namespace std;

int arr[10000];
int size_;
int tmp;

void shift(int d) {
	while (d--) {
		for (int j = 1; j <= size_-1; j++) {
			if (j == 1) {
				tmp = arr[0];
			}
			arr[j - 1] = arr[j];
			if (j == size_-1) {
				arr[size_-1] = tmp;
			}
		}
		tmp = 0;
	}
}

int main() {
	int t, D = 0;
	cin >> t;
	while (t--) {
		cin >> size_ >> D;
		for (int i = 1; i <= size_; i++) {
			cin >> arr[i - 1];
		}
		shift(D);
		for (int l = 1; l <= size_; l++) {
			cout << arr[l - 1] << " ";
		}
	}
}