#include <iostream>
using namespace std;

class ArrayStack {
private:
	int* array;		// �迭
	int capacity;	// �迭�� ũ��
	int topIndex;	// top �� index
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
	while (M--) {
		ArrayStack nums = ArrayStack(10000);	// ���ڸ� �����ϴ� ����
		string formula;							// ���� + ���ڸ� �����ϴ� ����
		cin >> formula;

		for (int i = 0; i < formula.size(); i++) {
			if ('1' <= formula[i] && formula[i] <= '9') {
				nums.push(formula[i] - '0');
			}
			else if (formula[i] == '+') {
				int b = nums.pop();
				int a = nums.pop();
				nums.push(a + b);
			}
			else if (formula[i] == '-') {
				int b = nums.pop();
				int a = nums.pop();
				nums.push(a - b);
			}
			else if (formula[i] == '*') {
				int b = nums.pop();
				int a = nums.pop();
				nums.push(a * b);
			}
		}
		cout << nums.pop() << "\n";
	}

	return 0;
}