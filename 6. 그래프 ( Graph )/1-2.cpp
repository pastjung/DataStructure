#include <iostream>
#include <vector>
using namespace std;

class Vertex {
public:
	int data;
	Vertex(int data) {
		this->data = data;
	}
};

class Graph {
private:
	int vertex_count;
	int edge_count;
	vector<Vertex*> vertexs;
	vector<vector<int>> edges;
public:
	Graph(int N) : edges(N, vector<int>(N, 0)) {
		vertex_count = 0;
		edge_count = 0;
	}

	void insertVertex(int data) {
		Vertex* newVertex = new Vertex(data);
		vertexs.push_back(newVertex);
		vertex_count++;
	}

	Vertex* findVertex(int data) {
		for (Vertex* vertex : vertexs) {
			if (data == vertex->data) return vertex;
		}
		return NULL;
	}

	void insertEdge(int start, int end) {
		if (findVertex(start) == NULL || findVertex(end) == NULL || edges[start][end] == 1) {
			cout << -1 << "\n";
		}
		else {
			edges[start][end] = 1;
			edges[end][start] = 1;
			edge_count++;
		}
	}
	void printCount() {
		cout << vertex_count << ' ' << edge_count << "\n";
	}

	void isAdjacentTo(int A, int B) {
		if (findVertex(A) == NULL || findVertex(B) == NULL) {
			cout << -1 << "\n";
		}
		else {
			cout << edges[A][B] << "\n";
		}
	}
};

int main() {
	// Improve the input/output speed of cin, cout
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;
	Graph graph = Graph(2000);
	for (int i = 0; i < N; i++) {
		int I;
		cin >> I;
		graph.insertVertex(I);
	}

	for (int i = 0; i < M; i++) {
		int S, D;
		cin >> S >> D;
		graph.insertEdge(S, D);
	}
	graph.printCount();

	for (int i = 0; i < K; i++) {
		int A, B;
		cin >> A >> B;
		graph.isAdjacentTo(A, B);
	}

	return 0;
}