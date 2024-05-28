#include <iostream>
#include <vector>
using namespace std;

// 구현 방법 1 : 2차원 matrix 로 구현 - index 는 vertex, data 는 edge 정보를 담음
// 장점 : 구현이 쉽고, 조회가 빠르다
// 단점 : 메모리의 공간이 무조건 N*N 사이즈

// 구현 방법 2 : Linked List 형식으로 구현
// 장점 : 메모리가 필요한 만큼만 사용
// 단점 : 구현하기 복잡하고 조회가 어렵다.

class MatrixGraph {
private:
	vector<int> vertexs;
	vector<vector<string>> edges;
	int edgeSize;
	bool isDirection;	// True : 유향 그래프, False : 무향 그래프
public:
	MatrixGraph(int size, bool direction) {
		edges.resize(size, vector<string>(size, ""));	// 크기가 size인 벡터를 size 만큼 생성
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
			// 유향 그래프
			edges[start][end] = data;
			edgeSize++;
		}
		else if (isDirection == false && edges[start][end] == "") {
			// 무향 그래프
			edges[start][end] = data;
			edges[end][start] = data;
			edgeSize++;
		}
		else {
			cout << "이미 값이 존재" << "\n";
		}
	}
	else {
		cout << "존재하지 않는 인덱스" << "\n";
	}
}

void MatrixGraph::printCount() {
	// vertex와 edges 의 개수
	cout << "vertex 개수 : " << vertexs.size() << " edge 개수 : " << edgeSize << "\n";
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
		cout << "존재하지 않는 인덱스" << "\n";
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
		// 유향 그래프
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
		// 무향 그래프
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