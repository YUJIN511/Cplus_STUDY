#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	int check ;
	vector<vector<int>> arr(m, vector<int>(n, 1));

	while (1) {
		check = 0;
		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (board[i].substr(j, 1) != "X") {
					if (board[i].substr(j, 2) == board[i + 1].substr(j, 2) && board[i].substr(j + 1, 1) == board[i + 1].substr(j, 1)) {
						arr[i][j] = 0;
						arr[i][j + 1] = 0;
						arr[i + 1][j] = 0;
						arr[i + 1][j + 1] = 0;
						check = 1;
					}
				}
			}
		}
		if (check == 0) {
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (arr[i][j] == 0) answer++;
				}
			}
			return answer;
		}
		for (int i = 0; i < n; i++) {
			for (int j = m - 1; j > 0; j--) {
				if (arr[j][i] == 0) {
					for (int k = j - 1; k >= 0; k--) {
						if (arr[k][i] == 1) {
							arr[j][i] = 1;	board[j].replace(i, 1, board[k].substr(i, 1));
							arr[k][i] = 0;	board[k].replace(i, 1, "X");
							break;
						}
						else {
							board[k].replace(i, 1, "X");
						}
					}
				}
			}
		}
	}
	
}

void main() {

	cout << solution(6,6,{ "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" }) << endl;
}