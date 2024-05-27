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
	int height;
public:
	BST() {
		root = NULL;
		height = 0;
	}
	void insertNode(Node* newNode);
	Node* findNode(int data);
	int findDepth(Node* node);
	int calChild(Node* node);

	void printHeight();

	Node* getRoot();
	void translant(Node* preNode, Node* postNode);
	Node* findMinNode(Node* node);
	void deleteNode(Node* node);
	void preOrderTraversal(Node* currentNode);
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
		int newNodeHeight = 0;

		while (leafNode != NULL) {
			newNodeHeight++;
			if (leafNode->data < newNode->data) {
				if (leafNode->rightChild == NULL) {
					// 오른쪽 자식에 추가
					newNode->parent = leafNode;
					leafNode->rightChild = newNode;

					if (height < newNodeHeight) {
						height = newNodeHeight;
					}
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

					if (height < newNodeHeight) {
						height = newNodeHeight;
					}
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

void BST::printHeight() {
	cout << height << "\n";
}

Node* BST::getRoot() {
	return root;
}

void BST::translant(Node* preNode, Node* postNode) {
	// postNode 를 preNode 위치로 이동
	if (postNode->parent == NULL) {
		// preNode == root 일 때
		root = postNode;
	}
	else if (postNode == postNode->parent->leftChild) {
		// preNode == 왼쪽 자식
		postNode->parent->leftChild = postNode;
	}
	else {
		// preNode == 오른쪽 자식
		postNode->parent->rightChild = postNode;
	}

	if (postNode != NULL) {
		postNode->parent = postNode->parent;
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

		// delNode의 우측 서브 트리에서 최소값 탐색
		Node* minNode = findMinNode(delNode->rightChild);	

		// 정리 : minNode 의 우측 서브 트리를 minNode 위치로 이동
		if (minNode->parent != delNode) {
			
			// 최소 노드의 부모가 삭제하려는 노드인 경우
			// 최소 노드는 항상 왼쪽에 위치하므로 왼쪽 노드는 항상 NULL, 오른쪽 자식만 변경
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

		bst.preOrderTraversal(bst.getRoot());
		cout << "\n";
	}
	return 0;
}