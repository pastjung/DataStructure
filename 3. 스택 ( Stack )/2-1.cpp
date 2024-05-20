#include <iostream>
using namespace std;

class arrayStack {
public:
	int* array;
	int capacity;
	int topIndex;

	arrayStack(int capacity) {
		this->capacity = capacity;
		this->array = new int[capacity];
		topIndex = -1;
	}

	bool empty() {
		if (topIndex == -1)
			return true;
		else
			return false;
	}

	int top() {
		if (topIndex == -1)
			return -1;
		else
			return array[topIndex];
	}

	void push(int X) {
		topIndex++;
		array[topIndex] = X;
	}

	int pop() {
		if (topIndex == -1) return -1;
		int num = array[topIndex];
		topIndex--;
		return num;
	}

	int size() {
		return topIndex + 1;
	}

};

int main() {
	// Improve the input/output speed of cin, cout
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M;
	cin >> M;
	while (M--) {
		string formula;							// 연산 + 숫자를 보관하는 스택
		arrayStack nums = arrayStack(10000);	// 숫자만 저장하는 스택
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