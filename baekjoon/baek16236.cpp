#include <iostream>

using namespace std;

void babyshark(int arr[20][20], int num) {
	int x, y;
	int min[3] = {9999,-1,-1};
	int shark=2;
	int temp=0;
	int temp_i, temp_j;
	int visit[20][20] = { 0 };
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (arr[i][j] == 9) { // 아기상어 위치
				x = j;
				y = i;
				break;
			}
		}
	}
	
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (arr[i][j] != 0 && shark > arr[i][j]) { // 아기상어보다 작은 물고기
				temp_i = y;
				temp_j = x;

				while (temp_i != y && temp_j == x) {
					if (visit[temp_i - 1][temp_j] != 0) {
						temp_i--;
					}
					else if (visit[temp_i + 1][temp_j] != 0) {

					}
					else if (visit[temp_i][temp_j - 1] != 0) {

					}
					else if (visit[temp_i][temp_j + 1] != 0) {

					}
				}
			}
		}
	}
	
}

void eat(int arr[20][20], int num, int x, int y) {
	

}
int main() {

	int num;
	int arr[20][20];

	cin >> num;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cin >> arr[i][j];
		}
	}
	
	babyshark(arr, num);

	return 0;
}
