#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

map<string, string[2]> family;
map<string, double> blood;

void blood_trait(string X) {
	if (blood.find(X) != blood.end()) return;
	if (family.find(X) == family.end()) blood[X] = 0;
	else {
		if (blood.find(family[X][0]) == blood.end()) blood_trait(family[X][0]);
		if (blood.find(family[X][1]) == blood.end()) blood_trait(family[X][1]);
		blood[X] = (blood[family[X][0]] + blood[family[X][1]]) / 2;
	}
}


int main() {

	int N, M, i;
	string dad, mom, son;
	string king, temp;
	double result = -1;
	cin >> N >> M;
	cin >> king;
	blood[king] = 1;

	for (i = 0; i < N; i++) {
		cin >> son >> dad >> mom;
		family[son][0] = dad;
		family[son][1] = mom;
	}

	for (auto iter = family.begin(); iter != family.end(); iter++) {
		blood_trait(iter->first);
	}

	for (i = 0; i < M; i++) {
		cin >> temp;
		if (blood.find(temp) == blood.end()) blood[temp] = 0;
		if (result < blood[temp]) {
			result = blood[temp];
			king = temp;
		}
	}
	cout << king;
	return 0;
}