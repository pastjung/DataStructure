#include <iostream>
using namespace std;

#define MAX 353333

class Item {
public:
	int key, value;
};

class arr {
public:
	Item* data;
	bool flag = false;
};

arr HashArr[MAX];
int sz = 0;

int hashfunc(int idx) {
	return idx % MAX;
}

int hashfunc2(int idx) {
	return (17 - (idx % 17));
}

void tableInsertDouble(int key, int value) {
	if (sz == MAX) return;

	Item* newItem = new Item();
	newItem->key = key;
	newItem->value = value;

	int j = 0;
	while (sz != MAX) {
		int index = hashfunc(value + j * hashfunc2(value));

		if (HashArr[index].flag == false) {
			HashArr[index].flag = true;
			HashArr[index].data = newItem;
			sz++;
			break;
		}
		else {
			j++;
		}
	}
}

void tableSearchDouble(int key, int value) {
	int probing = 1;
	int j = 0;

	do {
		int index = hashfunc(value + j * hashfunc2(value));

		Item* item = HashArr[index].data;
		bool flag = HashArr[index].flag;

		if (!flag) {
			cout << 0 << " " << probing << "\n";
			break;
		}
		else if (item->key == key) {
			if (item->value == value) {
				cout << 1 << " " << probing << "\n";
				break;
			}
			else {
				j++;
				probing++;
			}
		}
		else {
			j++;
			probing++;
		}

	} while (probing != MAX + 1);
}

void tableClear() {
	for (int i = 0; i < MAX; i++) {
		Item* deleteItem = HashArr[i].data;
		HashArr[i].data = NULL;
		HashArr[i].flag = false;
		delete deleteItem;
	}
	sz = 0;
}

int main() {
	// Improve the input/output speed of cin, cout
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int X;
			cin >> X;
			tableInsertDouble(hashfunc(X), X);
		}

		int M;
		cin >> M;
		for (int i = 0; i < M; i++) {
			int X;
			cin >> X;
			tableSearchDouble(hashfunc(X), X);
		}

		tableClear();
	}
	return 0;
}