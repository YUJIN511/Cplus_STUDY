#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	//vector<pair<string, string>> uid;
	map <string, string> m;
	map <string, string>::iterator mit;
	int pos = 0;
	int check;
	string name;
	string op[3];

	for (int i = 0; i < record.size(); i++) {
		pos = record[i].find(" ");
		op[0] = record[i].substr(0, pos);
 		pos++;
		op[1] = record[i].substr(pos, record[i].find(" ", pos + 1) - pos);
		if (op[0] != "Leave") {
			op[2] = record[i].substr(record[i].find(" ", pos + 1) + 1);
		}
		check = 1;
		if (op[0] == "Enter" || op[0]=="Change") {
			mit = m.find(op[1]);
			if (mit!=m.end()) {
					mit->second = op[2];
					check = 0;
			}
 			if (check) {
				m.insert(make_pair(op[1], op[2]));
			}
		}
	}

	for (int i = 0; i < record.size(); i++) {
		pos = record[i].find(" ");
		op[0] = record[i].substr(0, pos);
		pos++;

		if (op[0] != "Change") {
			op[1] = record[i].substr(pos, record[i].find(" ", pos + 1) - pos);

			name = m.at(op[1]);
			if (op[0] == "Enter") {
				answer.push_back(name + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
			}
			else if (op[0] == "Leave") {
				answer.push_back(name + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
			}

			cout << answer[i] << endl;
		}
	}
	return answer;
}

void main() {

	vector<string> record;
	record.push_back("Enter uid1234 Muzi");
	record.push_back("Enter uid4567 Prodo");
	record.push_back("Leave uid1234");
	record.push_back("Enter uid1234 Prodo");
	record.push_back("Change uid4567 Ryan");
	solution(record);
}