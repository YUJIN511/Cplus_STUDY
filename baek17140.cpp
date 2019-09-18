#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r_max;
int c_max;

bool myCom(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.second < b.second) return true;
	if (a.second == b.second && a.first < b.first) return true;
	return false;
}

void row_cal(int A[1001][101]) {
	vector<pair<int, int> > v;
	int check;
	int count = 0;
	int num;
	int max = c_max;

	for (int i = 0; i < r_max; i++) { 
		num = 0;
		check = c_max;
		while (check != 0) {
			for (int j = 0; j < c_max; j++) {
				if (num == 0 && num == A[i][j]) {
					check--;
				}
				else if (num == A[i][j]) {
					count++;
					check--;
				}
			}
			if (count != 0) {
				v.push_back(pair<int, int>(num, count));
			}
			num++;
			count = 0;
		}
		if (max < v.size() * 2) max = v.size() * 2;
		sort(v.begin(), v.end(), myCom);
		for (int j = 0; j < v.size(); j++) { //A ��� Ȯ��
			A[i][j * 2] = v[j].first;
			A[i][j * 2 + 1] = v[j].second;
		}
		if (v.size() * 2 < c_max) {
			for (int j = v.size()*2; j < max; j++) { //A ��� Ȯ��
				A[i][j] =0;
			}
		}
		v.clear();
	}
	c_max = max;
}

void col_cal(int A[101][101]) {
	vector<pair<int, int> > v;
	int check;
	int count = 0;
	int num;
	int max = r_max;

	for (int i = 0; i < c_max; i++) {
		num = 0;
		check = r_max;
		while (check != 0) {
			for (int j = 0; j < r_max; j++) {
				if (num == 0 && num == A[j][i]) {
					check--;
				}
				else if (num == A[j][i]) {
					count++;
					check--;
				}
			}
			if (count != 0) {
				v.push_back(pair<int, int>(num, count));
			}
			num++;
			count = 0;
		}
		if (max < v.size() * 2) max = v.size() * 2;
		sort(v.begin(), v.end(), myCom);
		for (int j = 0; j < v.size(); j++) { //A ��� Ȯ��
			A[j * 2][i] = v[j].first;
			A[j * 2 + 1][i] = v[j].second;
		}
		if (v.size() * 2 < c_max) {
			for (int j = v.size()*2; j < max; j ++) { //A ��� Ȯ��
				A[j][i] = 0;
			}
		}
		v.clear();
	}
	r_max = max;

}

int main() {
	
	int A[101][101] = { { 0, } }; // A ��� 0���� �ʱ�ȭ
	int r, c, k;
	int time = 0;
	 
	cin >> r; cin >> c; cin >> k; // �� �Է�
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> A[i][j];
		}
	}
	r_max = 3; c_max = 3;

	while (A[r-1][c-1]!=k) { // k�� �Ǹ� �ݺ��� Ż��
		if (r_max >= c_max) { // ��� �� ũ�� ��
			row_cal(A); // R����
		}
		else {
			col_cal(A); // C����
		}
		time++;
		if (time > 100) {
			cout << "-1"<<endl;
			return 0;
		}
	}

	cout << time << endl;
	
	return 0;
}