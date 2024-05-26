#include <iostream>
using namespace std;

class ArrayQueue {
private:
	int* array;		// 동적으로 만들 큐	
	int capacity;	// 큐의 용량
	int start;		// front 의 위치
	int back;		// rear 의 위치
public:
	ArrayQueue(int capacity) {
		this->capacity = capacity + 1;
		this->array = new int[capacity];
		start = 1;
		back = 0;
	}
	void enqueue(int data);
	int size();
	bool isEmpty();

	void dequeue();
	void front();
	void rear();
};

void ArrayQueue::enqueue(int data) {
	if (capacity == size() + 1) {
		cout << "Full" << "\n";
	}
	else {
		if (size() == 0) {
			array[start] = data;
			back++;
		}
		else {
			if (capacity > back + 1) {
				array[++back] = data;
			}
			else {
				back = 0;
				array[back] = data;
			}
		}
	}
}

int ArrayQueue::size() {
	return (capacity + back - start + 1) % capacity;
}

bool ArrayQueue::isEmpty() {
	if (size() == 0)
		return true;
	else
		return false;
}

void ArrayQueue::dequeue() {
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

void ArrayQueue::front() {
	if (size() == 0)
		cout << "Empty" << "\n";
	else
		cout << array[start] << "\n";
}

void ArrayQueue::rear() {
	if (size() == 0)
		cout << "Empty" << "\n";
	else
		cout << array[back] << "\n";
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