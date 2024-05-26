#include <iostream>
using namespace std;

class ArrayQueue {
private:
	int* array;			// 동적으로 만들 큐
	int capacity;		// 큐의 용량
	int back;			// rear 의 위치
public:
	ArrayQueue(int capacity) {
		this->capacity = capacity;
		this->array = new int[capacity];
		back = -1;
	}
	void enqueue(int data);
	int size();
	bool isEmpty();
};

void ArrayQueue::enqueue(int data) {
	if (capacity == size()) {
		cout << "Full" << "\n";
		return;
	}
	else {
		back++;
		array[back] = data;
	}
}

int ArrayQueue::size() {
	return back + 1;
}

bool ArrayQueue::isEmpty() {
	if (size() == 0) return true;
	else return false;
}

int main() {
	// Improve the input/output speed of cin, cout
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int S;
	cin >> S;
	ArrayQueue arr = ArrayQueue(S);

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