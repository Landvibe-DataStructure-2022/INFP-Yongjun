#include <iostream>

using namespace std;

int arr[10000];
int size_;
int tmp;

void shift(int d) {
	while(d--) {
		for (int j = size_; j >= 2; j--) {
			if (j == size_) {
				tmp = arr[size_ - 1];
			}
				arr[j - 1] = arr[j - 2];
			if (j == 2) {
				arr[0] = tmp;
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