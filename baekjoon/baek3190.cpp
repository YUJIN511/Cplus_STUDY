#include <iostream>
#include <vector>

using namespace std;

int N, L;
int board[101][101];

int solution(int move[101][2]) {

	int dx[5] = {0, 1,0,-1,0 }; // 1:우 2:하 3:좌 4:상
	int dy[5] = {0, 0,1,0,-1 };
	int s_len = 1;
	int hx = 1, hy = 1;
	int tx = 1, ty = 1;
	int x = 1, y = 1;
	int s_dir = 1;
	int time = 0;
	int m = 0;
	int temp;


	while (1) {
		time++;
		hx += dx[s_dir]; // 뱀 머리 이동
		hy += dy[s_dir];
		if (hx > N || hy> N || hx<1 || hy<1 || board[hy][hx]>0) { // 게임 끝
			return time;
		}
		board[y][x] = s_dir;

		if (board[hy][hx] == -1) { // 사과 먹은경우
			board[hy][hx] = 0;
			s_len++;
		}
		else { // 안먹은 경우
			temp = board[ty][tx];
			board[ty][tx] = 0;
			tx += dx[temp];
			ty += dy[temp];

		}
		x = hx;
		y = hy;

		if (m<L && move[m][0] == time) { // 방향 바꾸기
			if (move[m][1] == 1) { // 오른쪽 90도
				s_dir++;
				if (s_dir == 5) s_dir = 1;
			}
			else { // 왼쪽 90도
				s_dir--;
				if (s_dir == 0) s_dir = 4;
			}
			m++;
		}
	}
	
}
int main() {

	int K;
	int x, y;
	char temp;
	int move[101][2]; // D는 1, L은 0

	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> y >> x;
		board[y][x] = -1;
	}

	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> x >> temp;
		move[i][0] = x;
		if (temp == 'D') {
			move[i][1] = 1;
		}
		else {
			move[i][1] = 0;
		}
	}

	cout << solution(move) << endl;

	return 0;
}
