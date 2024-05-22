#include <iostream>
using namespace std;

class arrayQueue {
public:
	int* array;
	int capacity;;
	int start;
	int back;

	arrayQueue(int capacity) {
		this->capacity = capacity + 1;
		this->array = new int[capacity];
		start = 1;
		back = 0;
	}

	void enqueue(int X) {
		if (capacity == size() + 1) {
			cout << "Full" << "\n";
		}
		else {
			if (size() == 0) {
				array[start] = X;
				back++;
			}
			else {
				if (capacity > back + 1) {
					array[++back] = X;
				}
				else {
					back = 0;
					array[back] = X;
				}
			}
		}
	}

	void dequeue() {
		if (size() == 0) {
			cout << "Empty" << "\n";
		}
		else {
			int deleteData = array[start];
			array[start] = NULL;
			if (size() == 1) {
				start = 1;
				back = 0;
			}
			else {
				start = (start + 1) % capacity;
			}
			cout << deleteData << "\n";
		}
	}

	int size() {
		return (capacity + back - start + 1) % capacity;
	}

	bool isEmpty() {
		if (size() == 0)
			return true;
		else
			return false;
	}

	void front() {
		if (size() == 0)
			cout << "Empty" << "\n";
		else
			cout << array[start] << "\n";
	}

	void rear() {
		if (size() == 0)
			cout << "Empty" << "\n";
		else
			cout << array[back] << "\n";
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
		else if (str == "dequeue") {
			arr.dequeue();
		}
		else if (str == "front") {
			arr.front();
		}
		else if (str == "rear") {
			arr.rear();
		}


	}

	return 0;
}