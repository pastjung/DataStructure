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


int main() {
	// Improve the input/output speed of cin, cout
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Tree tree = Tree(1);

	int N;
	cin >> N;
	while (N--) {
		string str;
		cin >> str;
		if (str == "insert") {
			int parent, data;
			cin >> parent >> data;
			tree.insertNode(parent, data);
		}
		else if (str == "printChild") {
			int parent;
			cin >> parent;
			tree.printChildNodes(parent);
		}
		else if (str == "printDepth") {
			int data;
			cin >> data;
			tree.printDepth(data);
		}
	}

	return 0;
}