#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int solution(string dartResult) {
	int answer = 0;
	int pos = 0;
	int power = 0;
	int point = 0;

	while (pos < dartResult.size()) {

		if (dartResult[pos] == '1' && dartResult[pos + 1] == '0') {
			point = 10;
			pos++;
		}
		else {
			point = dartResult[pos]- '0';
		}

		if (dartResult[pos + 1] == 'S') { // single
			power = 1;
		}
		else if (dartResult[pos + 1] == 'D') { // double
			power = 2;
		}
		else { // triple
			power = 3;
		}

		if (dartResult[pos + 2] == '*') { // ��Ÿ�� ����?
			if (pos + 3 < dartResult.size() && dartResult.find("*", pos + 3) < pos+6) { // ��Ÿ�� ��ø
				answer += pow(point,power) * 4;
			}
			else { // �� ��ø
				answer += pow(point, power) * 2;
			}
		}
		else if (dartResult[pos + 2] == '#') { // ������ ����?
			if (pos + 3 < dartResult.size() && dartResult.find("*", pos + 3) < pos+6) { // ��Ÿ�� ��ø
				answer += pow(point, power) * -2;
			}
			else { // �� ��ø
				answer += pow(point, power) * -1;
			}
		}
		else { // ��ɼ�
			if (pos + 3 < dartResult.size() && dartResult.find("*", pos + 3) < pos+6) { // ��Ÿ�� ��ø
				 answer += pow(point, power) * 2;
			}
			else { // �� ��ø
				answer += pow(point, power);
			}
			pos -= 1;
		}
		pos += 3;
	}
	cout << answer<<endl;

	return answer;
}

void main() {

	solution("1D2S3T*");


}