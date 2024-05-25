#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* parent;
	Node* leftChild;
	Node* rightChild;

	Node(int data);
	void insertLeftChild(Node* child);
	void insertRightChild(Node* child);
};

Node::Node(int data) {
	this->data = data;
	this->parent = NULL;
	this->leftChild = NULL;
	this->rightChild = NULL;
}

void Node::insertLeftChild(Node* child) {
	child->parent = this;
	this->leftChild = child;
}

void Node::insertRightChild(Node* child) {
	child->parent = this;
	this->rightChild = child;
}

class BST {
public:
	Node* root;
	int height;

	BST();
	void insertNode(Node* newNode);
	Node* findNode(int data);
	int findDepth(Node* node);
	int calChild(Node* node);
	void translant(Node* u, Node* v);
	Node* findMinNode(Node* node);
	void deleteNode(Node* node);
	void preOrderTraversal(Node* currentNode);
};

BST::BST() {
	root = NULL;
	height = 0;
}

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
		int tempHeight = 0;

		while (leafNode != NULL) {
			tempHeight++;
			if (leafNode->data < newNode->data) {
				if (leafNode->rightChild == NULL) {
					newNode->parent = leafNode;
					leafNode->rightChild = newNode;

					if (height < tempHeight) height = tempHeight;
					break;
				}
				else {
					leafNode = leafNode->rightChild;
				}
			}
			else {
				if (leafNode->leftChild == NULL) {
					newNode->parent = leafNode;
					leafNode->leftChild = newNode;

					if (height < tempHeight) height = tempHeight;
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

void BST::translant(Node* u, Node* v) {
	// deleteNode : 삭제할 노드
	// minNode : 삭제할 노드의 하위 노드 중 최소값을 가진 노드
	if (u->parent == NULL) {
		// deleteNode == root 일 때
		root = v;
	}
	else if (u == u->parent->leftChild) {
		// deleteNode == 왼쪽 자식
		u->parent->leftChild = v;
	}
	else {
		// deleteNode == 오른쪽 자식
		u->parent->rightChild = v;
	}

	if (v != NULL) {
		v->parent = u->parent;
	}
}

Node* BST::findMinNode(Node* node) {
	while (node->leftChild != NULL) {
		node = node->leftChild;
	}
	return node;
}

void BST::deleteNode(Node* delNode) {
	if (delNode->leftChild == NULL) {
		// delNode 가 최소 노드(leafNode) 인 경우
		translant(delNode, delNode->rightChild);
	}
	else if (delNode->rightChild == NULL) {
		// delNode 가 우측 leafNode 인 경우
		translant(delNode, delNode->leftChild);
	}
	else {
		// delNode 가 내부 노드인 경우
		Node* minNode = findMinNode(delNode->rightChild);	// delNode의 우측 서브 트리에서 최소값 탐색

		if (minNode->parent != delNode) {
			// 정리 : minNode 의 서브트리를 minNode 위치로 이동
			// 최소 노드의 부모가 삭제하려는 노드인 경우
			// 최저 노드는 항상 왼쪽에 위치하므로 왼쪽 노드는 항상 NULL, 오른쪽 자식만 변경
			translant(minNode, minNode->rightChild);
			minNode->rightChild = delNode->rightChild;
			minNode->rightChild->parent = minNode;
		}
		// 정리 : minNode 를 delNode의 자리로 이동
		translant(delNode, minNode);
		minNode->leftChild = delNode->leftChild;
		minNode->leftChild->parent = minNode;
	}
}

void BST::preOrderTraversal(Node* currentNode) {
	if (root == NULL) {
		cout << 0 << "\n";
	}
	else {
		// 루트 방문
		cout << currentNode->data << ' ';

		// 자식 방문
		if (currentNode->leftChild != NULL) {
			preOrderTraversal(currentNode->leftChild);
		}

		if (currentNode->rightChild != NULL) {
			preOrderTraversal(currentNode->rightChild);
		}
	}
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
			Node* deleteNode = bst.findNode(data);
			if (deleteNode != NULL) {
				bst.deleteNode(deleteNode);
			}
		}

		bst.preOrderTraversal(bst.root);
		cout << "\n";
	}
	return 0;
}