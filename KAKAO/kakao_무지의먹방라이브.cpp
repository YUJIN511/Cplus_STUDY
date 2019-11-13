#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> food_times, long long k) {
	long long answer = 0;
	map <long long, int> pos;
	map<long long, int>::iterator it, d;

	for (long long i = 0; i < food_times.size(); i++) {
		pos.insert(pair<long long, int>(i, food_times[i]));
	}

	it = pos.begin();

	while (k != 0) {

		it->second -= 1;
		if (it->second == 0) { // À½½ÄÀ» ´Ù ¸Ô¾úÀ» °æ¿ì
			d = it++;
			pos.erase(d);
		}
		else {
			it++;
		}
		if (it == pos.end()) {
			it = pos.begin();
		}

		if (pos.size() == 0) {
			answer = -1;
			return answer; 
		}
		k--;
	}

	answer = it->first + 1;
	return answer;
}

void main() {

	cout << solution({ 3, 1, 2 }, 7);

}
