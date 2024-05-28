#include <iostream>
using namespace std;

class ArrayStack {
private:
	int* array;		// 배열
	int capacity;	// 배열의 크기
	int topIndex;	// top 의 index
public:
	ArrayStack(int capacity) {
		this->capacity = capacity;
		this->array = new int[capacity];
		topIndex = -1;
	}
	bool empty();
	int top();
	void push(int X);

	int pop();
	int size();
};

bool ArrayStack::empty() {
	if (topIndex == -1)
		return true;
	else
		return false;
}

int ArrayStack::top() {
	if (topIndex == -1)
		return -1;
	else
		return array[topIndex];
}

void ArrayStack::push(int X) {
	topIndex++;
	array[topIndex] = X;
}

int ArrayStack::pop() {
	if (topIndex == -1) return -1;
	int num = array[topIndex];
	topIndex--;
	return num;
}

int ArrayStack::size() {
	return topIndex + 1;
}

int main() {
	// Improve the input/output speed of cin, cout
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M;
	cin >> M;
	ArrayStack arr = ArrayStack(M);
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