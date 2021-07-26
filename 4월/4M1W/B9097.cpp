#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
using namespace std;


struct xyd {
	int x;
	int y;
	int d;
};

xyd make_xyd(int X, int Y, int D) {
	xyd temp;
	temp.x = X;
	temp.y = Y;
	temp.d = D;
	return temp;
}


queue<xyd> check;

string quadTree() {
	int i, j, temp, N;
	int tx, ty, td;
	string s = "";
	string result = "";
	cin >> N;

	vector<vector<int>> v;
	v.resize(N, vector<int>(N, 0));
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &v[i][j]);
		}
	}
	check.push(make_xyd(0,0,N));
	while (!check.empty()) {
		tx = check.front().x;
		ty = check.front().y;
		td = check.front().d;
		check.pop();
		temp = v[tx][ty];
		for (i = 0; i < td; i++) {
			for (j = 0; j < td; j++) {
				if (v[tx + i][ty + j] != temp) {
					i = td;
					j = td;
					s += "1";
					check.push(make_xyd(tx, ty, td / 2));
					check.push(make_xyd(tx, ty + (td / 2), td / 2));
					check.push(make_xyd(tx + (td / 2), ty, td / 2));
					check.push(make_xyd(tx + (td / 2), ty + (td / 2), td / 2));
					temp = -1;
				}
			}
		}
		if (temp != -1) s = s + "0" + to_string(temp);
	}
	for (i = s.length() - 1; i >= 0; i -= 4) {
		if (i < 3) {
			if (i == 2) temp = 4 * (s[i - 2] - '0') + 2 * (s[i - 1] - '0') + s[i] - '0';
			if (i == 1) temp = 2 * (s[i - 1] - '0') + s[i] - '0';
			if (i == 0) temp = s[i] - '0';
		}
		else {
			temp = 8 * (s[i - 3] - '0') + 4 * (s[i - 2] - '0') + 2 * (s[i - 1] - '0') + s[i] - '0';
		}
		if (temp <= 9) result += to_string(temp);
		else result += 'A' + (temp - 10);
	}
	reverse(result.begin(), result.end());
	return result + "\n";
}

int main() {
	int tcase;
	cin >> tcase;
	for (int i = 0; i < tcase; i++) {
		cout << quadTree();
	}
}