#include <iostream>
#include <vector>
using namespace std;

class Node {
private:
	int data;
	Node* parent;
	vector<Node*> childs;
public:
	Node() {
		this->data = NULL;
		this->parent = NULL;
	}
	Node(int data) {
		this->data = data;
		this->parent = NULL;
	}
	friend class Tree;
};

class Tree {
private:
	Node* root;
	vector<Node*> nodes;
public:
	Tree(int data) {
		root = new Node(data);
		nodes.push_back(root);
	}
	Node* findNode(int data);
	void insertNode(int parent, int data);
	void printChildNodes(int parent);

	void printDepth(int data);

	void preOrderTraversal(Node* currentNode);
	void postOrderTraversal(Node* currentNode);

	int maxTreeDepth(Node* currentNode);
};


Node* Tree::findNode(int data) {
	for (Node* node : nodes) {
		if (data == node->data) {
			return node;
		}
	}
	return NULL;
}

void Tree::insertNode(int parent, int data) {
	Node* newNode = new Node(data);
	Node* parentNode = findNode(parent);

	if (parentNode != NULL) {
		newNode->parent = parentNode;
		parentNode->childs.push_back(newNode);
		nodes.push_back(newNode);
	}
	else {
		cout << -1 << "\n";
	}
}

void Tree::printChildNodes(int parent) {
	Node* parentNode = findNode(parent);

	if (parentNode == NULL) return;

	if (parentNode->childs.size() == 0) {
		cout << 0 << "\n";
	}
	else {
		for (Node* child : parentNode->childs) {
			cout << child->data << ' ';
		}
		cout << "\n";
	}
}

void Tree::printDepth(int data) {
	Node* node = findNode(data);

	int depth = -1;

	while (node != NULL) {
		depth++;
		node = node->parent;
	}

	cout << depth << "\n";
}

void Tree::preOrderTraversal(Node* currentNode) {
	// 루트 방문
	cout << currentNode->data << ' ';

	// 자식 방문
	for (Node* child : currentNode->childs) {
		preOrderTraversal(child);
	}
}

void Tree::postOrderTraversal(Node* currentNode) {
	// 자식 방문
	for (Node* child : currentNode->childs) {
		postOrderTraversal(child);
	}

	// 루트 방문
	cout << currentNode->data << ' ';
}

int Tree::maxTreeDepth(Node* currentNode) {
	if (currentNode->childs.size() == 0) {
		return 0;
	}

	int max = 0;
	for (Node* child : currentNode->childs) {
		if (max < maxTreeDepth(child)) {
			max = maxTreeDepth(child);
		}
	}
	return max + 1;
}

int main() {
	// Improve the input/output speed of cin, cout
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	while (N--) {
		Tree tree = Tree(1);
		int M;
		cin >> M;
		for (int i = 0; i < M; i++) {
			int parent, data;
			cin >> parent >> data;
			tree.insertNode(parent, data);
		}
		Node* root = tree.findNode(1);
		tree.preOrderTraversal(root);
		cout << "\n";
		tree.postOrderTraversal(root);
		cout << "\n";
		cout << tree.maxTreeDepth(root) << "\n";
	}

	return 0;
}