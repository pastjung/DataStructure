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

	int dequeue();
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

int ArrayQueue::dequeue() {
	if (size() == 0) {
		// cout << "Empty" << "\n";
		return -1;
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
		// cout << deleteData << "\n";
		return deleteData;
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

	int T;
	cin >> T;
	while (T--) {
		int p1_count = 0;
		int p2_count = 0;

		int p1_remain = 0;
		int p2_remain = 0;

		int N;
		cin >> N;

		ArrayQueue P1 = ArrayQueue(N);
		for (int i = 0; i < N; i++) {
			int n;
			cin >> n;
			P1.enqueue(n);
		}

		ArrayQueue P2 = ArrayQueue(N);
		for (int i = 0; i < N; i++) {
			int n;
			cin >> n;
			P2.enqueue(n);
		}

		for (int i = 0; i < N; i++) {
			int p1 = P1.dequeue();
			int p2 = P2.dequeue();

			if (p1 + p1_remain < p2 + p2_remain) {
				p1_remain = 0;
				p2_remain = p2 + p2_remain - (p1 + p1_remain) - 1;
				p2_count++;
			}
			else if (p1 + p1_remain > p2 + p2_remain) {
				p1_remain = p1 + p1_remain - (p2 + p2_remain) - 1;
				p2_remain = 0;
				p1_count++;
			}
			else {
				p1_remain = 0;
				p2_remain = 0;
			}
		}

		if (p1_count < p2_count) cout << 2 << "\n";
		else if (p1_count > p2_count) cout << 1 << "\n";
		else cout << 0 << "\n";
	}

	return 0;
}