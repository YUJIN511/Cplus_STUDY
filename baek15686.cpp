#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int house[51][51];
vector <vector <int> >dis(51);
int INF = 9999;
vector< pair <int, int> > v;
int N;
int sum;

void c_dis(int y, int x) {

	int temp;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (house[i][j] == 1) {
				temp = abs(y - i) + abs(x - j);
				if (temp < dis[i][j]) {
					if (dis[i][j] != INF) {
						sum -= dis[i][j];
					}
					dis[i][j] = temp;
					sum += dis[i][j];
				}
			}
		}
	}

}

int main() {

	int M;
	vector<int> min;
	cin >> N >> M;

	for (int i = 0; i < N; i++) { // 값 입력
		for (int j = 0; j < N; j++) {
			cin >> house[i][j];
			dis[i].push_back(INF);
			if (house[i][j] == 2) {
				v.push_back(pair<int, int>(i, j));
			}
		}
	}

	sum = 0;
	if (v.size() > M) { // 치킨집 개수가 많을 때
		vector<int> com;

		for (int i = 0; i < M; i++) {
			com.push_back(1);
		}
		for (int i = 0; i < v.size() - M; i++) {
			com.push_back(0);
		}
		sort(com.begin(), com.end());
		// 조합
		do {
			for (int i = 0; i < com.size(); i++) {
				if (com[i] == 1) {
					c_dis(v[i].first, v[i].second); // 치킨집 거리
				}
			}
			min.push_back(sum);
			dis.clear();
			dis.resize(51);
			for (int i = 0; i < N; i++) {
				for(int j=0; j<N; j++){
					dis[i].push_back(INF);
				}
			}
			sum = 0;

		} while (next_permutation(com.begin(), com.end())); 


		sort(min.begin(), min.end());
		cout << min.front() << endl;
	}
	else {
		sum = 0;
		for (int i = 0; i < v.size(); i++) {
			c_dis(v[i].first, v[i].second);
		}
		cout << sum << endl;
	}

	return 0;
}