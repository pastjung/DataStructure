#include <iostream>
using namespace std;

class arrayStack {
public:
	int* array;
	int capacity;
	int topIndex;

	arrayStack(int capacity) {
		this->capacity = capacity;
		this->array = new int[capacity];
		topIndex = -1;
	}

	bool empty() {
		if (topIndex == -1)
			return true;
		else
			return false;
	}

	int top() {
		if (topIndex == -1)
			return -1;
		else
			return array[topIndex];
	}

	void push(int X) {
		topIndex++;
		array[topIndex] = X;
	}

	int pop() {
		if (topIndex == -1) return -1;
		int num = array[topIndex];
		topIndex--;
		return num;
	}

	int size() {
		return topIndex + 1;
	}

};

int main() {
	// Improve the input/output speed of cin, cout
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M;
	cin >> M;
	arrayStack arr = arrayStack(M);
	while (M--) {
		string str;
		cin >> str;

		if (str == "empty") {
			cout << arr.empty() << "\n";
		}
		else if (str == "top") {
			cout << arr.top() << "\n";
		}
		else if (str == "push") {
			int num;
			cin >> num;
			arr.push(num);
		}
		else if (str == "pop") {
			cout << arr.pop() << "\n";
		}
		else if (str == "size") {
			cout << arr.size() << "\n";
		}
	}

	return 0;
}