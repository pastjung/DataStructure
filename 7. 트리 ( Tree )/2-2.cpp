#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int data;
	Node* parent;
	vector<Node*> childs;

	Node() {
		this->data = NULL;
		this->parent = NULL;
	}
	Node(int data) {
		this->data = data;
		this->parent = NULL;
	}
};

class Tree {
private:
	Node* root;
	vector<Node*> nodes;
public:
	Tree() {
		root = NULL;
	}
	Tree(int data) {
		root = new Node(data);
		nodes.push_back(root);
	}
	Node* findNode(int data) {
		for (Node* node : nodes) {
			if (data == node->data) {
				return node;
			}
		}
		return NULL;
	}
	void insert(int parent, int data) {
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

	void printChild(int parent) {
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

	void printDepth(int data) {
		Node* node = findNode(data);

		int depth = -1;

		while (node != NULL) {
			depth++;
			node = node->parent;
		}

		cout << depth << "\n";
	}

	void preorderTraversal(Node* currentNode) {
		// 루트 방문
		cout << currentNode->data << ' ';

		// 자식 방문
		for (Node* child : currentNode->childs) {
			preorderTraversal(child);
		}
	}

	void postorderTraversal(Node* currentNode) {
		// 자식 방문
		for (Node* child : currentNode->childs) {
			postorderTraversal(child);
		}

		// 루트 방문
		cout << currentNode->data << ' ';
	}

	int maxTreeDepth(Node* currentNode) {
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
};


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
			tree.insert(parent, data);
		}
		Node* root = tree.findNode(1);
		tree.preorderTraversal(root);
		cout << "\n";
		tree.postorderTraversal(root);
		cout << "\n";
		cout << tree.maxTreeDepth(root) << "\n";
	}

	return 0;
}