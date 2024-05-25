#include <iostream>
#include <vector>
using namespace std;

class Heap {
public:
	vector<int> data;
	int heap_size;

	Heap();

	void swap(int index1, int index2);
	void upHeap(int index);
	void insert(int e);
	int size();
	bool isEmpty();
	void print();
};

Heap::Heap() {
	heap_size = 0;
	data.push_back(-1);
}

void Heap::swap(int index1, int index2) {
	int temp = data[index1];
	data[index1] = data[index2];
	data[index2] = temp;
}

void Heap::upHeap(int index) {
	if (index == 1) return;
	else {
		if (data[index] < data[index / 2]) {
			swap(index, index / 2);
			upHeap(index / 2);
		}
	}
}

void Heap::insert(int e) {
	data.push_back(e);
	heap_size++;
	upHeap(heap_size);
}

int Heap::size() {
	return heap_size;
}

bool Heap::isEmpty() {
	if (heap_size == 0) {
		return true;
	}
	else {
		return false;
	}
}

void Heap::print() {
	if (heap_size == 0) {
		cout << -1 << "\n";
	}
	else {
		for (int i = 1; i <= heap_size; i++) {
			cout << data[i] << ' ';
		}
		cout << "\n";
	}
}

int main() {
	// Improve the input/output speed of cin, cout
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Heap heap = Heap();

	int T;
	cin >> T;
	while (T--) {
		string str;
		cin >> str;
		if (str == "isEmpty") {
			cout << heap.isEmpty() << "\n";
		}
		else if (str == "insert") {
			int data;
			cin >> data;
			heap.insert(data);
		}
		else if (str == "size") {
			cout << heap.size() << "\n";
		}
		else if (str == "print") {
			heap.print();
		}
	}
	return 0;
}