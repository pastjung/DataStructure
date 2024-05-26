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
	friend class LinkedList;
};

class LinkedList {
private:
	Node* head;
	Node* tail;
public:
	LinkedList() {
		head = NULL;
		tail = NULL;
	}
	~LinkedList() { }

	bool empty();
	void addFront(int element);
	void removeFront();
	int front();
};

void LinkedList::addFront(int element) {
	Node* newHead = new Node(element);

	if (head == NULL) {
		// ����Ʈ�� ��� ���� ��
		head = newHead;
		tail = newHead;
	}
	else {
		// ����Ʈ�� ���Ұ� ������ ��
		newHead->nextNode = head;
		head = newHead;
	}
}

void LinkedList::removeFront() {
	if (head == NULL) {
		// ����Ʈ�� ��� ���� ��
		cout << -1 << "\n";
	}
	else {
		cout << head->element << "\n";

		Node* deleteNode = head;	// ������ ���
		head = head->nextNode;

		if (head == NULL) {
			tail = NULL;
		}

		delete deleteNode;
	}
}

int LinkedList::front() {
	if (head == NULL) {
		return -1;
		cout << -1 << "\n";
	}
	else {
		return head->element;
	}
}

bool LinkedList::empty() {
	if (head == NULL) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	// Improve the input/output speed of cin, cout
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	LinkedList linkedList = LinkedList();

	int M;
	cin >> M;
	while (M--) {
		string str;
		cin >> str;
		if (str == "addFront") {
			int num;
			cin >> num;
			linkedList.addFront(num);
		}
		else {
			if (str == "removeFront") {
				linkedList.removeFront();
			}
			else if (str == "front") {
				cout << linkedList.front() << "\n";
			}
			else if (str == "empty") {
				cout << linkedList.empty() << "\n";
			}
		}
	}

	return 0;
}