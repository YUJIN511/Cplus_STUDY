#include <iostream>
#include <vector>

using namespace std;

int slop_x(vector<vector<int> >arr, vector<vector<int> >road, int N, int L) {
	int count;

	vector<int> x(N, 0);
	
	for (int i = 0; i < N; i++) {
		count = 1;
		for (int j = 0; j < N-1; j++) {
			////////////가로
			if (arr[i][j] == arr[i][j + 1]) { // 같은 높이
				count++;
			}
			else if (arr[i][j]-arr[i][j+1]==1) { // 1낮을때
				for (int k = 1; k < L; k++) {
					if (j+1+k>N-1 || arr[i][j + 1] != arr[i][j + 1 + k]) {
						goto EXIT;
					}
				}
				road[i][j+L] = 1;
				count += L;
				j += L-1;
			}
			else if (arr[i][j]-arr[i][j+1]==-1) { // 1 높을 때
				for (int k = 0; k < L; k++) {
					if (j-k<0 || road[i][j - k] == 1) {
						goto EXIT;
					}
				}
				for (int k = 1; k < L; k++) {
					if (j - k < 0 || arr[i][j] != arr[i][j - k]) {
						goto EXIT;
					}
				}
				road[i][j] = 1;
				count ++;
			}
		}
		if (count == N ) {
			x[i] = 1;
		}
	EXIT:;
	}
	
	count = 0;
	for (int i = 0; i < N; i++) {
		count += x[i];
	}

	return count;
}

int slop_y(vector<vector<int> >arr, vector<vector<int> >road, int N, int L) {
	int count;

	vector<int> y(N, 0);

	for (int j = 0; j < N; j++) {
		count = 1;
		for (int i = 0; i < N - 1; i++) {
			////////////세로
			if (arr[i][j] == arr[i+1][j]) { // 같은 높이
				count++;
			}
			else if (arr[i][j] - arr[i+1][j] == 1) { // 1낮을때
				for (int k = 1; k < L; k++) {
					if (i + 1 + k>N - 1 || arr[i+1][j] != arr[i+1+k][j]) {
						goto EXIT;
					}
				}
				road[i+L][j] = 1;
				count += L;
				i += L - 1;
			}
			else if (arr[i][j] - arr[i+1][j] == -1) { // 1 높을 때
				for (int k = 0; k < L; k++) {
					if (i-k<0 || road[i-k][j] == 1) {
						goto EXIT;
					}
				}
				for (int k = 1; k < L; k++) {
					if (i - k < 0 || arr[i][j] != arr[i-k][j]) {
						goto EXIT;
					}
				}
				road[i][j] = 1;
				count++;
			}
		}
		if (count == N) {
			y[j] = 1;
		}
	EXIT:;
	}

	count = 0;
	for (int i = 0; i < N; i++) {
		count += y[i];
	}
	return count;

}
int main() {

	int N, L;
	int temp;
	vector<vector<int> > arr;
	vector<vector<int> > road;

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		vector<int> element(N); // N*N 배열 만들기
		road.push_back(element);
		arr.push_back(element);
		for (int j = 0; j < N; j++) { 
			cin >> temp;
			road[i][j] = 0; // 길 배열 입력
			arr[i][j] = temp;  // 지도 배열 입력
		}
	}

	cout << slop_x(arr, road, N, L) + slop_y(arr, road, N, L) << endl;

	return 0;
}
