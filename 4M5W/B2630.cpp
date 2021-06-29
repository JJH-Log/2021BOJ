#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

//바로 encoding 하는 것이 가능한 것인가 => string으로 표현하면?
vector<string> v;
int w, b;

void check(int x, int y, int L) {
	int i, j;
	char start;
	start = v[x][y];
	for (i = x; i < x + L; i++) {
		for (j = y; j < y + L; j ++){
			if (start != v[i][j]) {
				check(x, y, L / 2);
				check(x + L / 2, y, L / 2);
				check(x, y + L / 2, L / 2);
				check(x + L / 2, y + L / 2, L / 2);
				return;
			}
		}
	}
	if (start == '0') w++;
	else b++;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	char c;
	int i, j, N;
	w = 0;
	b = 0;
	cin >> N;
	for (i = 0; i < N; i++) {
		s = "";
		for (j = 0; j < N; j++) {
			cin >> c;
			s += c;
		}
		v.push_back(s);
	}
	check(0, 0, N);
	cout << w << "\n" << b;
}

