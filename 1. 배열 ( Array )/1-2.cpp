#include <iostream>
#include <string>
using namespace std;

#define ARRAY_SIZE 10000

int arr[ARRAY_SIZE] = { 0, };

int at(int i) {
	return arr[i];
}

void set(int i, int X) {
	if (arr[i] != 0) arr[i] = X;
	else cout << 0 << "\n";
}

int findLast() {
	int i = 0;
	while (arr[i] != 0) {
		i++;
	}
	return i - 1;
}

void add(int i, int X) {
	int last = findLast();
	if (last == -1) {
		arr[0] = X;
	}
	else if (arr[i] == 0) {
		arr[last + 1] = X;
	}
	else {
		for (int index = last; index >= i; index--) {
			arr[index + 1] = arr[index];
		}
		arr[i] = X;
	}
}

void remove(int i) {
	if (arr[i] == 0) {
		cout << 0 << "\n";
	}
	else {
		int index = i;

		do {
			arr[index] = arr[index + 1];
			index++;
		} while (arr[index + 1] != 0);

		arr[index] = 0;
	}
}

void printArray() {
	if (arr[0] == 0) {
		cout << 0 << "\n";
	}
	else {
		int i = 0;
		while (arr[i] != 0) {
			cout << arr[i] << ' ';
			i++;
		}
		cout << "\n";
	}
}

int main() {
	// Improve the input/output speed of cin, cout
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M;
	cin >> M;
	while (M--) {
		string str;
		cin >> str;
		int a, b;
		if (str == "at") {
			cin >> a;
			cout << at(a) << "\n";
		}
		else if (str == "add") {
			cin >> a >> b;
			add(a, b);
		}
		else if (str == "set") {
			cin >> a >> b;
			set(a, b);
		}
		else if (str == "remove") {
			cin >> a;
			remove(a);
		}
		else {
			printArray();
		}
	}

	return 0;
}