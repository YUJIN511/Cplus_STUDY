#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<vector<int> > v;
	int R, C, T;
	int temp;
	int air;
	cin >> R >> C >> T;
	
	v.resize(R);

	for (int i = 0; i < R; i++) { // �Է� �� ����
		for (int j = 0; j < C; j++) {
			cin >> temp;
			v[i].push_back(temp);
			if (temp == -1) {// ����û���� ��ġ
				air = i;
			}
		}
	}

	while (T > 0) {
		vector <vector<int> > v1(v);
		// �̼����� Ȯ��
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				temp = 0;
				if (v1[i][j] > 0) { // �̼����� ���
					if (i != 0 && v[i - 1][j] != -1) { // ��
						v[i - 1][j] += v1[i][j] / 5;
						temp++;
					}
					if (i != R - 1 && v[i + 1][j] != -1) { // �Ʒ�
						v[i + 1][j] += v1[i][j] / 5;
						temp++;
					}
					if (j != 0 && v[i][j - 1] != -1) { // ����
						v[i][j - 1] += v1[i][j] / 5;
						temp++;
					}
					if (j != C - 1 && v[i][j + 1] != -1) { // ������
						v[i][j + 1] += v1[i][j] / 5;
						temp++;
					}
					v[i][j] -= (v1[i][j] / 5)*temp;
				}
			}
		}
		//����û����
		for (int i = air + 1; i < R - 1; i++) {
			v[i][0] = v[i + 1][0];
		}
		for (int i = 0; i < C - 1; i++) {
			v[R - 1][i] = v[R - 1][i + 1];
		}
		for (int i = R - 1; i > air; i--) {
			v[i][C - 1] = v[i - 1][C - 1];
		}
		for (int i = C - 1; i > 1; i--) {
			v[air][i] = v[air][i - 1];
		}
		v[air][1] = 0;
		air--;
		for (int i = air - 1; i > 0; i--) {
			v[i][0] = v[i - 1][0];
		}
		for (int i = 0; i < C - 1; i++) {
			v[0][i] = v[0][i + 1];
		}
		for (int i = 0; i < air; i++) {
			v[i][C - 1] = v[i + 1][C - 1];
		}
		for (int i = C - 1; i > 1; i--) {
			v[air][i] = v[air][i - 1];
		}
		v[air][1] = 0;
		air++;
		T--;
	}
	temp = 0;
	for (int i = 0; i < R; i++) { // ���� �̼����� ��
		for (int j = 0; j < C; j++) {
			temp += v[i][j];
		}
	}
	cout << temp+2 << endl;

	return 0;
}