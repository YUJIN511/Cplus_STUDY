#include <iostream>
#include <algorithm>

using namespace std;

int arr[501][501];
int sum[501][501] = {0,};
int max_sum=0;
int num;

void triangle() {

	sum[0][0] = arr[0][0];
	for (int i = 1; i < num; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				sum[i][j] = sum[i - 1][j] + arr[i][j];
			}
			else if (j == i) {
				sum[i][j] = sum[i - 1][j - 1] + arr[i][j];
			}
			else {
				sum[i][j] = max(sum[i - 1][j - 1], sum[i - 1][j]) + arr[i][j];
			}

			if (i == num - 1) {
				max_sum = max(max_sum, sum[i][j]);
			}
		}
	}
}

int main() {

	cin >> num;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	triangle();

	cout << max_sum << endl;

	return 0;
}
