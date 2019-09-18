#include <iostream>

using namespace std;

int r, c;

void move(int A[101][101], int s[10000][6], int n) {

	if (s[n][3]== 1) { // 위
		while (s[n][2] != 0 && s[n][2] >= (s[n][0]-1)) {
			s[n][2] = s[n][2] - (s[n][0] - 1);
			s[n][0] = 1;
			s[n][3] = 2;
			move(A, s, n);
		}
		if (s[n][2] != 0) {
			s[n][0] -= s[n][2];
			s[n][2] = 0;
		}
	}
	else if (s[n][3] == 2) { // 아래
		while (s[n][2]!=0 && s[n][2] >= (r-s[n][0])) {
			s[n][2] = s[n][2] - (r - s[n][0]);
			s[n][0] = r;
			s[n][3] = 1;
			move(A, s, n);
		}
		if (s[n][2] != 0) {
			s[n][0] += s[n][2];
			s[n][2] = 0;
		}
	}
	else if (s[n][3] == 3) { // 오른쪽
		while (s[n][2] != 0 && s[n][2] >= (c - s[n][1])) {
			s[n][2] = s[n][2] - (c - s[n][1]);
			s[n][1] = c;
			s[n][3] = 4;
			move(A, s, n);
		}
		if (s[n][2] != 0) {
			s[n][1] += s[n][2];
			s[n][2] = 0;
		}
	}
	else { // 왼쪽
		while (s[n][2] != 0 && s[n][2] >= (s[n][1] - 1)) {
			s[n][2] = s[n][2] - (s[n][1] - 1);
			s[n][1] = 1;
			s[n][3] = 3;
			move(A, s, n);
		}
		if (s[n][2] != 0) {
			s[n][1] -= s[n][2];
			s[n][2] = 0;
		}
	}

}
int main() {

	int num; // 상어 갯수
	int s[10000][6]; // 상어 정보
	int A[101][101] = { { 0 }, };
	int sum = 0;
	int temp;
	cin >> r >> c >> num;

	for (int i = 1; i <= num; i++) {
		for (int j = 0; j <5; j++) {
			cin >> s[i][j];
		}
		A[s[i][0]][s[i][1]] = i;
	}
	
	if (num == 0) {
		cout << sum << endl;
		return 0;
	}

	for (int i = 1; i <= c; i++) { // 낚시왕의 이동
		//낚시
		for (int j = 1; j <= r; j++) {
			if (A[j][i] != 0) { // 땅과 가까운 상어 잡기
				sum += s[A[j][i]][4]; // 잡은 상어크기
				s[A[j][i]][0] = -1; // 잡혔다는 표시
				A[j][i] = 0; // 빈칸
				break;
			}
		}
		//상어 자리 이동
		for (int j = 1; j <= num; j++) {
			if (s[j][0] != -1) { // 안잡힌 상어 
				A[s[j][0]][s[j][1]] = 0; // 초기화
				temp = s[j][2];
				move(A, s, j);
				s[j][2] = temp;
			}
		}
		
		//상어 자리 배치
		for (int j = 1; j <= num; j++) {
			if (s[j][0] != -1) { // 안잡힌 상어
				if (A[s[j][0]][s[j][1]] != 0) { // 상어 자리 겹치는지
					A[s[j][0]][s[j][1]] = j;
				}
				else { // 상어 자리가 겹치는 경우
					if (s[j][4] > s[A[s[j][0]][s[j][1]]][4]) {
						s[A[s[j][0]][s[j][1]]][0] = -1;// 잡아먹힘
						A[s[j][0]][s[j][1]] = j;
					}
				}
			}
		}
	}


	cout << sum << endl;


	return 0;
}