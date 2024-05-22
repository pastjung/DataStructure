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

void tableInsert(int key, int value) {
	if (sz == MAX) return;

	Item* newItem = new Item();
	newItem->key = key;
	newItem->value = value;

	int index = hashfunc(key);
	while (sz != MAX) {
		if (HashArr[index].flag == false) {
			HashArr[index].flag = true;
			HashArr[index].data = newItem;
			sz++;
			break;
		}
		else {
			index = (index + 1) % MAX;
		}
	}
}

void tableSearch(int key, int value) {
	int index = hashfunc(key);
	int probing = 1;
	do {
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
				index = hashfunc(++index);
				probing++;
			}
		}
		else {
			index = hashfunc(++index);
			probing++;
		}

	} while (probing != MAX + 1);
}

void tableDelete(int key, int value) {
	int index = hashfunc(key);
	int probing = 1;
	do {
		Item* item = HashArr[index].data;
		bool flag = HashArr[index].flag;

		if (!flag) {
			cout << 0 << " " << probing << "\n";
			break;
		}
		else if (item->key == key) {
			if (item->value == value) {
				cout << 1 << " " << probing << "\n";

				Item* deleteItem = HashArr[index].data;
				HashArr[index].data->key = -1;
				HashArr[index].data->value = -1;
				//HashArr[index].flag = false;
				break;
			}
			else {
				index = hashfunc(++index);
				probing++;
			}
		}
		else {
			index = hashfunc(++index);
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
			tableInsert(hashfunc(X), X);
		}

		int M;
		cin >> M;
		for (int i = 0; i < M; i++) {
			int X;
			cin >> X;
			tableDelete(hashfunc(X), X);
		}

		tableClear();
	}
	return 0;
}