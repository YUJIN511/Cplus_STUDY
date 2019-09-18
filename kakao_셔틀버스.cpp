#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

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

string time_cal(string time, int add) {

	int hour= (time[0] - '0') * 10 + (time[1] - '0');
	int minu = (time[3] - '0') * 10 + (time[4] - '0');

	if(minu + add < 0){
		minu = 60 + add;
		hour--;
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
		time.replace(3, 1,"0");
		time.replace(4, 1, std::to_string(minu));
	}
	return time;
}

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	string time = "09:00";
	int temp=0;
	int pos = 0;

	sort(timetable.begin(), timetable.end(), compare); // timetable 정렬

	while(n-1!=0 ) { // n회
		if (compare(time_cal(time, t),"00:00") || time_cal(time,t)=="00:00") { // 막차 시간
			temp = 1;
			if (m == 1 && timetable.at(pos - 1) == time) {
				answer = time_cal(timetable.at(pos - 1), -1);
				return answer;
			}
			break;
		}
		for (int j = 0; j < m; j++) { // m명 탑승
			if (pos != timetable.size() && !compare(time, timetable.at(pos)) ) { // time보다 작거나 같을 때 true
				pos++;
			}
			else {
				break;
			}
		}
		//시간 증가

		time = time_cal(time, t);
		n--;
	}

	answer = time;
	if (timetable.size()==1) {
		return answer;
	}
	if (pos == timetable.size()) {
		if (temp == 1) {
			return answer;
		}
		return time_cal(answer, t*(n - 1));
	}
 // 마지막 버스
	for (int j = 0; j < m-1; j++) { // m명 탑승
		if (!compare(time, timetable.at(pos))) { // time보다 작거나 같을 때 true
			pos++;
		}
		else{
			return answer;
		}
	}

	if (pos!=0 && pos!=timetable.size() && !compare(timetable.at(pos), timetable.at(pos-1))&& !compare(time,timetable.at(pos))) {
		answer = time_cal(timetable.at(pos), -1);
	}
	return answer;
}

void main() {



	cout << solution(16, 60, 3, { "08:00","09:01", "09:08"}) << endl;

}