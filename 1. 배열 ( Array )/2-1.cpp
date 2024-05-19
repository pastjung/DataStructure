#include <iostream>
#include <string>
using namespace std;

#define SIZE 100

void calBank(int arr[], int size) {
	int korea = 0;
	int japan = 0;
	int china = 0;
	for (int i = 0; i < size; i = i + 3) {
		korea += arr[i];
		japan += arr[i + 1];
		china += arr[i + 2];
	}

	cout << korea << ' ' << japan << ' ' << china << "\n";
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