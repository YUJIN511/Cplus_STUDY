#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<double, double> a, pair<double, double> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
	}
}
vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<pair<double, double>> player(N, pair<double, double>(0, 0));

	for (int i = 0; i<stages.size(); i++) {
		for (int j = 0; j < N; j++) {
			player[j].first += 1;
			if (stages[i] - 1 == j) {
				break;
			}
		}
		if (N>stages[i] - 1) player[stages[i] - 1].second += 1;
	}
	for (int i = 0; i < player.size(); i++) {
		if (player[i].second != 0) {
			player[i].first = (player[i].second) / (player[i].first);
		}
		else {
			player[i].first = 0;
		}
		player[i].second = i;
	}

	sort(player.begin(), player.end(), compare);

	for (int i = 0; i < player.size(); i++) {
		answer.push_back(player[i].second + 1);
	}

	return answer;
}

void main() {

	vector<int> input;
	/*input.push_back(2);
	input.push_back(1);
	input.push_back(2);
	input.push_back(6);
	input.push_back(2);
	input.push_back(4);
	input.push_back(3);
	input.push_back(3);
	*/
	input.push_back(4);
	input.push_back(4);
	input.push_back(4);
	input.push_back(4);
	input.push_back(4);

	solution(4, input);

}