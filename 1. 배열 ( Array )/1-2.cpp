#include <iostream>
#include <string>
using namespace std;

#define ARRAY_SIZE 10000

class Array {
private:
	int size;
	int* arr;
public:
	Array(int size) {
		this->size = 0;
		arr = new int[size]();	// 기본적으로 0으로 초기화 되지만, 명시적으로 표기.
	}

	int at(int index);
	void set(int index, int data);
	int findLast();
	void add(int index, int data);

	void remove(int index);
	void printArray();
};

int Array::at(int index) {
	return arr[index];
}

void Array::set(int index, int data) {
	if (arr[index] != 0) {
		arr[index] = data;
	}
	else {
		cout << 0 << "\n";
	}
}

int Array::findLast() {
	int index = 0;
	while (arr[index] != 0) {
		index++;
	}
	return index - 1;
}

void Array::add(int index, int data) {
	int last = findLast();
	if (last == -1) {
		arr[0] = data;
	}
	else if (arr[index] == 0) {
		arr[last + 1] = data;
	}
	else {
		for (int i = last; i >= index; i--) {
			arr[i + 1] = arr[i];
		}
		arr[index] = data;
	}
}

void Array::remove(int index) {
	if (arr[index] == 0) {
		cout << 0 << "\n";
	}
	else {
		int removeIndex = index;

		do {
			arr[removeIndex] = arr[removeIndex + 1];
			removeIndex++;
		} while (arr[removeIndex + 1] != 0);

		arr[removeIndex] = 0;
	}
}

void Array::printArray() {
	if (arr[0] == 0) {
		cout << 0 << "\n";
	}
	else {
		int index = 0;
		while (arr[index] != 0) {
			cout << arr[index] << ' ';
			index++;
		}
		cout << "\n";
	}
}

int main() {
	// Improve the input/output speed of cin, cout
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Array arr = Array(ARRAY_SIZE);

	int M;
	cin >> M;
	while (M--) {
		string str;
		cin >> str;
		int a, b;
		if (str == "at") {
			cin >> a;
			cout << arr.at(a) << "\n";
		}
		else if (str == "add") {
			cin >> a >> b;
			arr.add(a, b);
		}
		else if (str == "set") {
			cin >> a >> b;
			arr.set(a, b);
		}
		else if (str == "remove") {
			cin >> a;
			arr.remove(a);
		}
		else if (str == "printArray") {
			arr.printArray();
		}
	}

	return 0;
}