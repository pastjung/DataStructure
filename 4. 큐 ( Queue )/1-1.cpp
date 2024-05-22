#include <iostream>
using namespace std;

class arrayQueue {
public:
	int* array;
	int capacity;;
	int back;

	arrayQueue(int capacity) {
		this->capacity = capacity;
		this->array = new int[capacity];
		back = -1;
	}

	void enqueue(int X) {
		if (capacity == size() + 1) {
			cout << "Full" << "\n";
			return;
		}
		else {
			back++;
			array[back] = X;
		}
	}

	int size() {
		return back + 1;
	}

	bool isEmpty() {
		if (size() == 0) return true;
		else return false;
	}
};

int main() {
	// Improve the input/output speed of cin, cout
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int S;
	cin >> S;
	arrayQueue arr = arrayQueue(S);

	int N;
	cin >> N;
	while (N--) {
		string str;
		cin >> str;

		if (str == "enqueue") {
			int num;
			cin >> num;
			arr.enqueue(num);
		}
		else if (str == "size") {
			cout << arr.size() << "\n";
		}
		else if (str == "isEmpty") {
			cout << arr.isEmpty() << "\n";
		}

	}

	return 0;
}