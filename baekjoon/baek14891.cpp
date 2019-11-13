#include <iostream>

using namespace std;

void rotation(int num, int dir, char T[4][10], int lock) {
	char temp[9];
	for (int i = 0; i < 8; i++) {
		temp[i] = T[num - 1][i];
	}

	if (dir == 1) { // 시계방향
		for (int i = 1; i < 8; i++) {
			T[num - 1][i] = temp[i - 1];
		}
		T[num - 1][0] = temp[7];
	}
	else { // 반시계방향
		for (int i = 0; i < 7; i++) {
			T[num - 1][i] = temp[i + 1];
		}
		T[num - 1][7] = temp[0];
	}

	if (num == 1) { // 1번 톱니바퀴
		if (temp[2] == T[1][6]) { // 1번 극 == 2번 극
			return;
		}
		else if (lock != 2) { // 다른 극
			rotation(2, dir*-1, T, 1);
		}
	}
	else if (num == 4) { // 4번 톱니바퀴
		if (temp[6] == T[2][2]) { // 4번 극 == 3번 극
			return;
		}
		else if (lock != 3) { // 다른 극
			rotation(3, dir*-1, T, 4);
		}
	}
	else { // 나머지 톱니바퀴
		if (lock == 0 && temp[6] != T[num - 2][2] && temp[2] != T[num][6]) { // 왼쪽 극 오른쪽 극 모두 다른지
			rotation(num - 1, dir*-1, T, num);
			rotation(num + 1, dir*-1, T, num);
		}
		else if (lock != num - 1 && temp[6] != T[num - 2][2]) { // 왼쪽 극만 다를때
			rotation(num - 1, dir*-1, T, num);
		}
		else if (lock != num + 1 && temp[2] != T[num][6]) { // 오른쪽 극만 다를때
			rotation(num + 1, dir*-1, T, num);
		}
	}
	return;
}


int main() {

	char T[4][10];
	int count;
	int num;
	int dir;

	cin.getline(T[0], 10);
	cin.getline(T[1], 10);
	cin.getline(T[2], 10);
	cin.getline(T[3], 10);
	cin >> count;

	for (int i = 0; i < count; i++) {
		cin >> num;
		cin >> dir;
		rotation(num, dir, T, 0);// 회전
	}

	cout << (T[0][0] - '0') * 1 + (T[1][0] - '0') * 2 + (T[2][0] - '0') * 4 + (T[3][0] - '0') * 8 << endl;
	return 0;
}
