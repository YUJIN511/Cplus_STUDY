#include <iostream>

using namespace std;

int r, c;

void move(int A[101][101], int s[10000][6], int n) {

	if (s[n][3]== 1) { // ��
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
	else if (s[n][3] == 2) { // �Ʒ�
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
	else if (s[n][3] == 3) { // ������
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
	else { // ����
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

	int num; // ��� ����
	int s[10000][6]; // ��� ����
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

	for (int i = 1; i <= c; i++) { // ���ÿ��� �̵�
		//����
		for (int j = 1; j <= r; j++) {
			if (A[j][i] != 0) { // ���� ����� ��� ���
				sum += s[A[j][i]][4]; // ���� ���ũ��
				s[A[j][i]][0] = -1; // �����ٴ� ǥ��
				A[j][i] = 0; // ��ĭ
				break;
			}
		}
		//��� �ڸ� �̵�
		for (int j = 1; j <= num; j++) {
			if (s[j][0] != -1) { // ������ ��� 
				A[s[j][0]][s[j][1]] = 0; // �ʱ�ȭ
				temp = s[j][2];
				move(A, s, j);
				s[j][2] = temp;
			}
		}
		
		//��� �ڸ� ��ġ
		for (int j = 1; j <= num; j++) {
			if (s[j][0] != -1) { // ������ ���
				if (A[s[j][0]][s[j][1]] != 0) { // ��� �ڸ� ��ġ����
					A[s[j][0]][s[j][1]] = j;
				}
				else { // ��� �ڸ��� ��ġ�� ���
					if (s[j][4] > s[A[s[j][0]][s[j][1]]][4]) {
						s[A[s[j][0]][s[j][1]]][0] = -1;// ��Ƹ���
						A[s[j][0]][s[j][1]] = j;
					}
				}
			}
		}
	}


	cout << sum << endl;


	return 0;
}