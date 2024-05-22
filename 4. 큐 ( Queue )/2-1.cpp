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

	int dequeue() {
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

	int T;
	cin >> T;
	while (T--) {
		int p1_count = 0;
		int p2_count = 0;

		int N;
		cin >> N;

		arrayQueue P1 = arrayQueue(N);
		for (int i = 0; i < N; i++) {
			int n;
			cin >> n;
			P1.enqueue(n);
		}

		arrayQueue P2 = arrayQueue(N);
		for (int i = 0; i < N; i++) {
			int n;
			cin >> n;
			P2.enqueue(n);
		}

		for (int i = 0; i < N; i++) {
			int p1 = P1.dequeue();
			int p2 = P2.dequeue();

			if (p1 < p2) p2_count++;
			else if (p1 > p2) p1_count++;
		}

		if (p1_count < p2_count) cout << 2 << "\n";
		else if (p1_count > p2_count) cout << 1 << "\n";
		else cout << 0 << "\n";

	}

	return 0;
}