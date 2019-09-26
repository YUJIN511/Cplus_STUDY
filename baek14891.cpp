#include <iostream>

using namespace std;

void rotation(int num, int dir, char T[4][10], int lock) {
	char temp[9];
	for (int i = 0; i < 8; i++) {
		temp[i] = T[num - 1][i];
	}

	if (dir == 1) { // �ð����
		for (int i = 1; i < 8; i++) {
			T[num - 1][i] = temp[i - 1];
		}
		T[num - 1][0] = temp[7];
	}
	else { // �ݽð����
		for (int i = 0; i < 7; i++) {
			T[num - 1][i] = temp[i + 1];
		}
		T[num - 1][7] = temp[0];
	}

	if (num == 1) { // 1�� ��Ϲ���
		if (temp[2] == T[1][6]) { // 1�� �� == 2�� ��
			return;
		}
		else if (lock != 2) { // �ٸ� ��
			rotation(2, dir*-1, T, 1);
		}
	}
	else if (num == 4) { // 4�� ��Ϲ���
		if (temp[6] == T[2][2]) { // 4�� �� == 3�� ��
			return;
		}
		else if (lock != 3) { // �ٸ� ��
			rotation(3, dir*-1, T, 4);
		}
	}
	else { // ������ ��Ϲ���
		if (lock == 0 && temp[6] != T[num - 2][2] && temp[2] != T[num][6]) { // ���� �� ������ �� ��� �ٸ���
			rotation(num - 1, dir*-1, T, num);
			rotation(num + 1, dir*-1, T, num);
		}
		else if (lock != num - 1 && temp[6] != T[num - 2][2]) { // ���� �ظ� �ٸ���
			rotation(num - 1, dir*-1, T, num);
		}
		else if (lock != num + 1 && temp[2] != T[num][6]) { // ������ �ظ� �ٸ���
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
		rotation(num, dir, T, 0);// ȸ��
	}

	cout << (T[0][0] - '0') * 1 + (T[1][0] - '0') * 2 + (T[2][0] - '0') * 4 + (T[3][0] - '0') * 8 << endl;
	return 0;
}