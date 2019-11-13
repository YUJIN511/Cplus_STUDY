#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct POST {
	int y, x;
};

int N, L, R;
int A[50][50];

void create(int y, int x, int state[50][50], int area, int& count, int& sum){
	int visited[50][50] = {0, };

	const int dy[] = { 0, 0, -1, +1 };
	const int dx[] = { -1, +1, 0, 0 };
	
	queue<POST> q;
	POST head;
	head.y = y;
	head.x = x;
	visited[y][x] = 1;
	q.push(head);

	while (!q.empty()) {
		POST cur = q.front(); 
		q.pop();

		state[cur.y][cur.x] = area;
		++count;
		sum += A[cur.y][cur.x];

		for (int dir = 0; dir < 4; ++dir) {
			POST next;
			next.y = cur.y + dy[dir];
			next.x = cur.x + dx[dir];

			if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= N) {
				continue;
			}

			int delta = abs(A[cur.y][cur.x] - A[next.y][next.x]);
			if (visited[next.y][next.x] == 0 && 1 <= delta && delta <= R) {
				visited[next.y][next.x] = 1;
				q.push(next);
			}
		}

	}
}
int main() {

	int update = 1;
	int ret = 0;
	cin >> N;
	cin >> L;
	cin >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}

	while (update) {
		update = 0;

		int state[50][50] = { 0, };
		int area = 0;
		int count[2501] = { 0, };
		int sum[2501] = { 0, };

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (state[i][j] == 0) {
					++area;
					create(i,j,state,area, count[area], sum[area]);
				}
			}
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				int index = state[i][j];
				int avg = sum[index] / count[index];
				if (A[i][j] != avg) {
					A[i][j] = avg;
					update = 1;
				}
			}
		}
		if (update) {
			++ret;
		}

	}

	cout << ret << endl;

	return 0;
}
