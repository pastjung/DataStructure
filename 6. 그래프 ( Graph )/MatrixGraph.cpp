#include <iostream>
#include <vector>
using namespace std;

// ���� ��� 1 : 2���� matrix �� ���� - index �� vertex, data �� edge ������ ����
// ���� : ������ ����, ��ȸ�� ������
// ���� : �޸��� ������ ������ N*N ������

// ���� ��� 2 : Linked List �������� ����
// ���� : �޸𸮰� �ʿ��� ��ŭ�� ���
// ���� : �����ϱ� �����ϰ� ��ȸ�� ��ƴ�.

class MatrixGraph {
private:
	vector<int> vertexs;
	vector<vector<string>> edges;
	int edgeSize;
	bool isDirection;	// True : ���� �׷���, False : ���� �׷���
public:
	MatrixGraph(int size, bool direction) {
		edges.resize(size, vector<string>(size, ""));	// ũ�Ⱑ size�� ���͸� size ��ŭ ����
		this->isDirection = direction;
		this->edgeSize = 0;
	}
	void insertVertex(int data);
	bool findVertex(int data);
	void insertEdge(int start, int end, string data);
	void printCount();

	int isAdjacentTo(int start, int end);
	void deleteVertex(int data);
};


void MatrixGraph::insertVertex(int data) {
	vertexs.push_back(data);
}

bool MatrixGraph::findVertex(int data) {
	for (int vertex : vertexs) {
		if (vertex == data) return true;
	}
	return false;
}

void MatrixGraph::insertEdge(int start, int end, string data) {
	if (findVertex(start) && findVertex(end)) {
		if (isDirection == true && edges[start][end] == "") {
			// ���� �׷���
			edges[start][end] = data;
			edgeSize++;
		}
		else if (isDirection == false && edges[start][end] == "") {
			// ���� �׷���
			edges[start][end] = data;
			edges[end][start] = data;
			edgeSize++;
		}
		else {
			cout << "�̹� ���� ����" << "\n";
		}
	}
	else {
		cout << "�������� �ʴ� �ε���" << "\n";
	}
}

void MatrixGraph::printCount() {
	// vertex�� edges �� ����
	cout << "vertex ���� : " << vertexs.size() << " edge ���� : " << edgeSize << "\n";
}

int MatrixGraph::isAdjacentTo(int start, int end) {
	if (findVertex(start) && findVertex(end)) {
		if (edges[start][end] == "") {
			return 0;
		}
		else {
			return 1;
		}
	}
	else {
		cout << "�������� �ʴ� �ε���" << "\n";
		return -1;
	}
}

void MatrixGraph::deleteVertex(int data) {
	if (!findVertex(data)) {
		cout << -1 << "\n";
		return;
	}

	for (int i = 0; i < vertexs.size(); i++) {
		if (data == vertexs[i]) {
			vertexs.erase(vertexs.begin() + i);
			break;
		}
	}

	if (isDirection) {
		// ���� �׷���
		for (int i = 0; i < edges[data].size(); i++) {
			if (edges[data][i] != "") {
				edges[data][i] = "";
				edgeSize--;
			}

			if (edges[i][data] != "") {
				edges[i][data] = "";
				edgeSize--;
			}
		}
	}
	else {
		// ���� �׷���
		for (int i = 0; i < edges[data].size(); i++) {
			if (edges[data][i] != "") {
				edges[data][i] = "";
				edges[i][data] = "";
				edgeSize--;
			}
		}
	}
}

int main() {
	// Improve the input/output speed of cin, cout
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, M, K;
	cin >> N >> M >> K;
	MatrixGraph graph = MatrixGraph(2000, false);
	for (int i = 0; i < N; i++) {
		int I;
		cin >> I;
		graph.insertVertex(I);
	}

	for (int i = 0; i < M; i++) {
		int S, D;
		string str;
		cin >> S >> D >> str;
		graph.insertEdge(S, D, str);
	}
	graph.printCount();

	for (int i = 0; i < K; i++) {
		int data;
		cin >> data;
		graph.deleteVertex(data);
		graph.printCount();
	}

	return 0;
}