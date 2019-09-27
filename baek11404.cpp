#include <iostream>
using namespace std;

int main() {

	int N, M;
	int INF = 100001;
	int city[103][103] = {0,};
	int temp[3];
	cin >> N; // 도시 개수
	cin >> M; // 버스 개수
	

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) {
				city[i][j] = INF;
			}
		}
	}

	for (int i = 0; i < M; i++) { // 입력
		cin >> temp[0];
		cin >> temp[1];
		cin >> temp[2];
		if (city[temp[0]][temp[1]] ==INF  || city[temp[0]][temp[1]] > temp[2]) {
			city[temp[0]][temp[1]] = temp[2];
		}
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (city[i][j] > city[i][k] + city[k][j]) {
					city[i][j] = city[i][k] + city[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (city[i][j] == INF) {
				cout << 0<<" ";
			}
			else {
				cout << city[i][j] << " ";
			}
		}
		cout << endl;
	}
	
	return 0;

}

