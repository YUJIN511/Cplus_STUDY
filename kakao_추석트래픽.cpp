#include <iostream>
#include <string>
#include <vector>

using namespace std;

int time_cal(string S, double T) {

	int h, m;
	double s;

	h = std::stoi(S.substr(0, 2));
	m = std::stoi(S.substr(3, 2));
	s = std::stod(S.substr(6));

	s += T;
	if (s < 0) {
		s = 60 + T; // 소수점 셋째자리까지만
		m--;
	}
	else if(s)

	if (m + T < 0) {
		m = 60 + T;
		h--;
	}
	else if (minu + add > 59) {
		minu = minu + add - 60;
		hour++;
	}
	else {
		minu += add;
	}

	if (hour == 24) {
		hour = 0;
	}

	if (hour > 9) {
		time.replace(0, 2, std::to_string(hour));
	}
	else {
		time.replace(0, 1, "0");
		time.replace(1, 1, std::to_string(hour));
	}
	if (minu > 9) {
		time.replace(3, 2, std::to_string(minu));
	}
	else {
		time.replace(3, 1, "0");
		time.replace(4, 1, std::to_string(minu));
	}
	return time;
}

bool compare(string a, string b) {
	int ha = (a[0] - '0') * 10 + (a[1] - '0');
	int hb = (b[0] - '0') * 10 + (b[1] - '0');
	int ma = (a[3] - '0') * 10 + (a[4] - '0');
	int mb = (b[3] - '0') * 10 + (b[4] - '0');

	if (ha == hb) {
		return ma < mb;
	}
	else {
		return ha < hb;
	}
}

int solution(vector<string> lines) {
	int answer = 0;

	for (int i = 0; i < lines.size(); i++) {
		for (int j = i + 1; j < lines.size(); j++) {
			lines[i].substr(11, 12);// S:응답완료시간
			lines[i].substr(24, lines.size()-25);//T:처리시간
			time_cal(lines[i].substr(11, 12), 0.999); // 1초 후

			if (1) { // 구간에 존재하는지 확인


			}
		}
	}

	return answer;
}

void main() {

	cout << solution({
		"2016-09-15 20:59:57.421 0.351s",
		"2016-09-15 20:59:58.233 1.181s",
		"2016-09-15 20:59:58.299 0.8s",
		"2016-09-15 20:59:58.688 1.041s",
		"2016-09-15 20:59:59.591 1.412s",
		"2016-09-15 21:00:00.464 1.466s",
		"2016-09-15 21:00:00.741 1.581s",
		"2016-09-15 21:00:00.748 2.31s",
		"2016-09-15 21:00:00.966 0.381s",
		"2016-09-15 21:00:02.066 2.62s"}) << endl;


}