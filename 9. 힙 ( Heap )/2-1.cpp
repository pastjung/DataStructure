#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
	vector<int> data;
	int heap_size;
public:
	Heap() {
		heap_size = 0;
		data.push_back(-1);
	}
	void swap(int index1, int index2);
	void upHeap(int index);
	void insert(int e);
	int size();
	bool isEmpty();
	void print();

	void downHeap(int index);
	int pop();
	int top();

	int printNum(int index);
	int orderedPrint(int index);
};

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

void Heap::downHeap(int index) {
	if (2 * index > heap_size) {
		// �ڽ��� ���� ���
		return;
	}
	else if (2 * index + 1 <= heap_size) {
		// ������ �ڽ��� �����ϴ� ���
		if (data[2 * index] <= data[2 * index + 1]) {
			swap(index, 2 * index);
			downHeap(2 * index);
		}
		else {
			swap(index, 2 * index + 1);
			downHeap(2 * index + 1);
		}
	}
	else {
		// ���� �ڽĸ� �����ϴ� ���
		swap(index, 2 * index);
		downHeap(2 * index);
	}
}

int Heap::pop() {
	if (heap_size == 0) return -1;
	else {
		int root = data[1];

		data[1] = data[heap_size];
		data.pop_back();
		heap_size--;
		downHeap(1);
		return root;
	}
}

int Heap::top() {
	if (heap_size == 0) return -1;
	else return data[1];
}

int Heap::printNum(int index) {
	return data[index];
}

// �������� ������ ������ ���ϴ� index �� �� ���
int Heap::orderedPrint(int index) {

	Heap originalHeap = *this;
	Heap orderedHeap = Heap();

	// �������� ����
	while (originalHeap.heap_size != 0) {
		orderedHeap.insert(originalHeap.pop());
	}

	return orderedHeap.printNum(index);
}

int main() {
	// Improve the input/output speed of cin, cout
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		Heap heap = Heap();

		int N, P;
		cin >> N >> P;
		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			heap.insert(data);
		}
		cout << heap.printNum(P) << "\n";
		cout << heap.orderedPrint(P) << "\n";
	}
	return 0;
}