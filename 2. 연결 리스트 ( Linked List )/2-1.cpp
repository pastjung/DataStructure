#include <iostream>
using namespace std;

class Node {
private:
	int element;
	Node* nextNode;
public:
	Node(int element) {
		this->element = element;
		this->nextNode = NULL;
	}
	friend class CircularLinkedList;
};

class CircularLinkedList {
private:
	Node* head;
	Node* tail;
public:
	CircularLinkedList() {
		head = NULL;
		tail = NULL;
	}
	~CircularLinkedList() { }

	void addNode(int index);
	void showList();
	void Delete(int index);
};

void CircularLinkedList::addNode(int element) {
	Node* newTail = new Node(element);

	if (tail == NULL) {
		head = newTail;
		tail = newTail;
	}
	else {
		newTail->nextNode = head;
		tail->nextNode = newTail;
		tail = newTail;
	}
}

void CircularLinkedList::showList() {
	if (head == NULL) {
		cout << -1 << "\n";
	}
	else {
		Node* printNode = head;
		do {
			cout << printNode->element << ' ';
			printNode = printNode->nextNode;
		} while (printNode != head);
		cout << "\n";
	}
}

void CircularLinkedList::Delete(int index) {
	Node* deleteNode = head;	// ������ ���
	Node* preDeleteNode = head;	// ������ ����� �ٷ� �� ���

	if (index == 0) {
		// index == 0 �� ��� x-1 ��° ��带 Tail �� ����
		head = head->nextNode;
		tail->nextNode = head;
	}
	else {
		// ������ ���� �ٷ� �� ��� Ž��
		for (int i = 0; i < index; i++) {
			preDeleteNode = deleteNode;
			deleteNode = deleteNode->nextNode;
		}

		if (deleteNode == head) {
			head = head->nextNode;
			tail->nextNode = head;
		}
		else if (deleteNode == tail) {
			preDeleteNode->nextNode = head;
			tail = preDeleteNode;
		}
		else {
			preDeleteNode->nextNode = deleteNode->nextNode;
		}
	}

	delete deleteNode;
}

int main() {
	// Improve the input/output speed of cin, cout
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M;
	cin >> M;
	while (M--) {
		CircularLinkedList list = CircularLinkedList();

		for (int i = 0; i < 10; i++) {
			int n;
			cin >> n;
			list.addNode(n);
		}

		for (int i = 0; i < 3; i++) {
			string str;
			int X;
			cin >> str >> X;
			if (str == "Delete") list.Delete(X);
			else cout << "�߸��� �Է�" << "\n";
		}

		list.showList();
	}

	return 0;
}