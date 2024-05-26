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
	
	void showList();
	void addBack(int element);
};

void LinkedList::addFront(int element) {
	Node* newHead = new Node(element);

	if (head == NULL) {
		head = newHead;
		tail = newHead;
	}
	else {
		newHead->nextNode = head;
		head = newHead;
	}
}

void LinkedList::removeFront() {
	if (head == NULL) {
		// 리스트가 비어 있을 때
		cout << -1 << "\n";
	}
	else {
		cout << head->element << "\n";

		Node* deleteNode = head;	// 삭제될 노드
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

void LinkedList::showList() {
	if (head == NULL) {
		cout << -1 << "\n";
	}
	else {
		Node* printNode = head;	// 임시 변수
		
		while (printNode != NULL) {
			cout << printNode->element << ' ';
			printNode = printNode->nextNode;
		}
		cout << "\n";
	}
}

void LinkedList::addBack(int element) {
	Node* newTail = new Node(element);

	if (tail == NULL) {
		// 리스트가 비어 있을 때
		head = newTail;
		tail = newTail;
	}
	else {
		// 리스트에 원소가 존재할 때
		tail->nextNode = newTail;
		tail = newTail;
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
		else if (str == "addBack") {
			int num;
			cin >> num;
			linkedList.addBack(num);
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
			else if (str == "showList") {
				linkedList.showList();
			}
		}
	}

	return 0;
}