#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
	int answer = 0;



	return answer;
}

int main() {

	int m, n;
	vector<string> board;
	char arr[1000];
	char* token;

	cin >> m;
	cin >> n;
	cin.ignore();
	cin.getline(arr, 100);

	token = strtok(arr, "[\",]");
	while (token != NULL) {
		//cout << token<<endl;
		board.push_back(token);
		token = strtok(NULL, "[\",]");
	}
	
	solution(m, n, board);

	return 0;
}