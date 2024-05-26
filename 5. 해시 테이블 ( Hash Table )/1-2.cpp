#include <iostream>
using namespace std;

#define MAX 353333

class Cell {
private:
	int key;
	int value;
	bool flag;
public:
	Cell() {
		key = -1;
		value = -1;
		flag = false;
	}
	friend class HashTable;
};

class HashTable {
private:
	Cell* cells;
	int size;
public:
	HashTable() {
		cells = new Cell[MAX];
		size = 0;
	}
	int hashfunc(int index);
	void insertCell(int key, int value);
	void searchCell(int key, int value);

	void deleteCell(int key, int value);
};

int HashTable::hashfunc(int index) {
	return index % MAX;
}

void HashTable::insertCell(int key, int value) {
	if (size == MAX) return;

	int index = hashfunc(key);
	while (size != MAX) {
		if (cells[index].flag == false) {
			cells[index].key = key;
			cells[index].value = value;
			cells[index].flag = true;
			size++;
			break;
		}
		else {
			index = (index + 1) % MAX;
		}
	}
}

void HashTable::searchCell(int key, int value) {
	int index = hashfunc(key);
	int probing = 1;
	do {
		Cell cell = cells[index];
		bool flag = cells[index].flag;

		if (!flag) {
			cout << 0 << ' ' << probing << "\n";
			break;
		}
		else if (cell.key == key && cell.value == value) {
			cout << 1 << ' ' << probing << "\n";
			break;
		}
		else {
			index = hashfunc(++index);
			probing++;
		}

	} while (probing != MAX + 1);
}

void HashTable::deleteCell(int key, int value) {
	int index = hashfunc(key);
	int probing = 1;
	do {
		Cell cell = cells[index];
		bool flag = cells[index].flag;

		if (!flag) {
			cout << 0 << ' ' << probing << "\n";
			break;
		}
		else if (cell.key == key && cell.value == value) {
			cout << 1 << ' ' << probing << "\n";

			cells[index].key = -1;
			cells[index].value = -1;
			break;
		}
		else {
			index = hashfunc(++index);
			probing++;
		}

	} while (probing != MAX + 1);
}

int main() {
	// Improve the input/output speed of cin, cout
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		HashTable table = HashTable();
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int X;
			cin >> X;
			table.insertCell(table.hashfunc(X), X);
		}

		int M;
		cin >> M;
		for (int i = 0; i < M; i++) {
			int X;
			cin >> X;
			table.deleteCell(table.hashfunc(X), X);
		}
	}
	return 0;
}