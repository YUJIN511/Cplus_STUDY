#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> arr;
int visit[110];
int check[110];
vector <int> set;

void DFS(int num) {
	visit[num] = 1;
	int temp;

	if (visit[arr[num]] == 0) {
		DFS(arr[num]);
	}
	else if (check[arr[num]] == 0) { //처음인지 확인
		set.push_back(num);
		temp = arr[num];
		while (temp != num) {
			set.push_back(temp);
			temp = arr[arr[num]];
		}
	}
	check[num] = 1;
}

int main() {
	int N;
	int temp;
	cin >> N;

	arr.push_back(0);
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	for (int i = 1; i <= N; i++) {
		DFS(i);
	}

	sort(set.begin(), set.end());
	cout << set.size() << endl;

	for (int i = 0; i < set.size(); i++) {
		cout << set[i] << endl;
	}
	return 0;
}