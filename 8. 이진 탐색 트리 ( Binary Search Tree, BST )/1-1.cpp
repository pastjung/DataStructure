#include <iostream>
using namespace std;

class Node {
private:
	int data;
	Node* parent;
	Node* leftChild;
	Node* rightChild;
public:
	Node(int data) {
		this->data = data;
		this->parent = NULL;
		this->leftChild = NULL;
		this->rightChild = NULL;
	}
	friend class BST;
};

class BST {
private:
	Node* root;
public:
	BST() {
		root = NULL;
	}
	void insertNode(Node* newNode);
	Node* findNode(int data);
	int findDepth(Node* node);
	int calChild(Node* node);
};

Node* BST::findNode(int data) {
	Node* temp = root;

	while (temp != NULL) {
		if (temp->data == data) {
			return temp;
		}
		else if (temp->data < data) {
			temp = temp->rightChild;
		}
		else {
			temp = temp->leftChild;
		}
	}

	return NULL;
}

void BST::insertNode(Node* newNode) {
	if (root == NULL) {
		root = newNode;
	}
	else {
		Node* leafNode = root;
		while (leafNode != NULL) {
			if (leafNode->data < newNode->data) {
				if (leafNode->rightChild == NULL) {
					// 오른쪽 자식에 추가
					newNode->parent = leafNode;
					leafNode->rightChild = newNode;
					break;
				}
				else {
					leafNode = leafNode->rightChild;
				}
			}
			else {
				if (leafNode->leftChild == NULL) {
					// 왼쪽 자식에 추가
					newNode->parent = leafNode;
					leafNode->leftChild = newNode;
					break;
				}
				else {
					leafNode = leafNode->leftChild;
				}
			}
		}
	}
}

int BST::findDepth(Node* node) {
	Node* temp = node;
	int degree = 0;

	while (temp != NULL) {
		if (temp == root) {
			return degree;
		}
		else {
			degree++;
			temp = temp->parent;
		}
	}
}

int BST::calChild(Node* node) {
	if (node->rightChild != NULL)
		return 2;
	else if (node->leftChild != NULL)
		return 1;
	else
		return 0;
}

int main() {
	// Improve the input/output speed of cin, cout
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		BST bst = BST();

		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			Node* newNode = new Node(data);
			bst.insertNode(newNode);
		}

		int M;
		cin >> M;
		for (int i = 0; i < M; i++) {
			int data;
			cin >> data;
			Node* node = bst.findNode(data);

			if (node == NULL) {
				cout << 0 << "\n";
			}
			else {
				cout << bst.calChild(node) << ' ' << bst.findDepth(node) << "\n";
			}
		}
	}
	return 0;
}