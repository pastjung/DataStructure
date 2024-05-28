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

class Edge {
public:
	string data;
	Vertex* start;
	Vertex* end;
	Edge(string data, Vertex* start, Vertex* end) {
		this->data = data;
		this->start = start;
		this->end = end;
	}
};

class Graph {
private:
	int vertex_count;
	int edge_count;
	vector<Vertex*> vertexs;
	vector<Edge*> edges;
	vector<vector<string>> edgeMatrix;
public:
	Graph(int N) : edgeMatrix(N, vector<string>(N, "")) {
		vertex_count = 0;
		edge_count = 0;
	}
	void insertVertex(int data);
	Vertex* findVertex(int data);
	void insertEdge(int start, int end, string data);
	void printCount();
	void deleteVertex(int data);
};

void Graph::insertVertex(int data) {
	Vertex* newVertex = new Vertex(data);
	vertexs.push_back(newVertex);
	vertex_count++;
}

Vertex* Graph::findVertex(int data) {
	for (Vertex* vertex : vertexs) {
		if (data == vertex->data) return vertex;
	}
	return NULL;
}

void Graph::insertEdge(int start, int end, string data) {
	Vertex* startVertex = findVertex(start);
	Vertex* endVertex = findVertex(end);
	if (startVertex == NULL || endVertex == NULL || edgeMatrix[start][end] != "") {
		cout << -1 << "\n";
	}
	else {
		Edge* newEdge = new Edge(data, startVertex, endVertex);
		Edge* newEdge2 = new Edge(data, endVertex, startVertex);

		edgeMatrix[start][end] = data;
		edgeMatrix[end][start] = data;
		edges.push_back(newEdge);
		edges.push_back(newEdge2);

		edge_count++;

	}
}

void Graph::printCount() {
	cout << vertex_count << ' ' << edge_count << "\n";
}

void Graph::deleteVertex(int data) {
	// ������ ������ ������ -1 ���
	Vertex* vertex = NULL;
	int index = -1;

	for (int i = 0; i < vertexs.size(); i++) {
		if (vertexs[i]->data == data) {
			vertex = vertexs[i];
			index = i;
			break;
		}
	}

	if (vertex == NULL) {
		cout << -1 << "\n";
	}
	else {
		// ������ ���� Ž��
		vector<int> deleteEdges;
		for (int i = 0; i < edges.size(); i = i + 2) {
			if (vertex == edges[i]->end || vertex == edges[i]->start) {
				edge_count--;
				deleteEdges.push_back(i);
			}
		}

		// ���� ����
		for (int i = deleteEdges.size() - 1; i >= 0; i--) {
			int index = deleteEdges[i];
			int start = edges[index]->start->data;
			int end = edges[index]->end->data;

			Edge* deleteEdge = edges[index];
			Edge* deleteEdge2 = edges[index + 1];

			edgeMatrix[start][end] = "";
			edgeMatrix[end][start] = "";

			edges.erase(edges.begin() + index);
			edges.erase(edges.begin() + index);

			delete deleteEdge;
			delete deleteEdge2;
		}

		// ���� ����
		vertexs.erase(vertexs.begin() + index);
		delete vertex;

		// �����ִ� ������ ���� ���
		cout << edge_count << ' ';

		// ������ ����Ǿ� �ִ� �������� ��� - ������ ������ ������ ���� ���
		for (int i = 0; i < edges.size(); i = i + 2) {
			cout << edges[i]->data << ' ';
		}

		cout << "\n";
	}
}

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
		string str;
		cin >> S >> D >> str;
		graph.insertEdge(S, D, str);
	}
	graph.printCount();

	for (int i = 0; i < K; i++) {
		int data;
		cin >> data;
		graph.deleteVertex(data);
	}

	return 0;
}