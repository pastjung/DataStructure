#include <iostream>
#include <string>
using namespace std;

#define SIZE 100

void calBank(int arr[], int size) {
	int korea = 0;
	int korea_num = 0;

	int japan = 0;
	int japan_num = 0;

	int china = 0;
	int china_num = 0;

	for (int i = 0; i < size; i += 3) {
		if (arr[i] != 0) {
			korea += arr[i];
			korea_num++;
		}

		if (arr[i + 1] != 0) {
			japan += arr[i + 1];
			japan_num++;
		}

		if (arr[i + 2] != 0) {
			china += arr[i + 2];
			china_num++;
		}
	}

	cout << korea << ' ' << japan << ' ' << china << "\n";

	if (korea_num != 0) {
		cout << korea / korea_num;
	}
	else
		cout << 0;
	cout << ' ';

	if (japan_num != 0) {
		cout << japan / japan_num;
	}
	else
		cout << 0;
	cout << ' ';

	if (china_num != 0) {
		cout << china / china_num;
	}
	else
		cout << 0;
	cout << "\n";
}

int main() {
	// Improve the input/output speed of cin, cout
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M;
	cin >> M;
	while (M--) {
		int N;
		cin >> N;
		int arr[SIZE] = { 0, };

		for (int i = 0; i < N; i++) {
			int money;
			cin >> money;
			arr[i] = money;
		}
		calBank(arr, N);
	}

	return 0;
}