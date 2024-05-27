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
					// ������ �ڽĿ� �߰�
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
					// ���� �ڽĿ� �߰�
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
	// postNode �� preNode ��ġ�� �̵�
	if (postNode->parent == NULL) {
		// preNode == root �� ��
		root = postNode;
	}
	else if (postNode == postNode->parent->leftChild) {
		// preNode == ���� �ڽ�
		postNode->parent->leftChild = postNode;
	}
	else {
		// preNode == ������ �ڽ�
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
		// delNode �� �ּ� ���(leafNode) �� ���
		translant(delNode, delNode->rightChild);
	}
	else if (delNode->rightChild == NULL) {
		// delNode �� ���� leafNode �� ���
		translant(delNode, delNode->leftChild);
	}
	else {
		// delNode �� ���� ����� ���

		// delNode�� ���� ���� Ʈ������ �ּҰ� Ž��
		Node* minNode = findMinNode(delNode->rightChild);	

		// ���� : minNode �� ���� ���� Ʈ���� minNode ��ġ�� �̵�
		if (minNode->parent != delNode) {
			
			// �ּ� ����� �θ� �����Ϸ��� ����� ���
			// �ּ� ���� �׻� ���ʿ� ��ġ�ϹǷ� ���� ���� �׻� NULL, ������ �ڽĸ� ����
			translant(minNode, minNode->rightChild);
			minNode->rightChild = delNode->rightChild;
			minNode->rightChild->parent = minNode;
		}

		// ���� : minNode �� delNode�� �ڸ��� �̵�
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
		// ��Ʈ �湮
		cout << currentNode->data << ' ';

		// �ڽ� �湮
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