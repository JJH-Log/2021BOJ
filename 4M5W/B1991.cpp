#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
using namespace std;

vector<vector<int>> v;

void ans(int x, int y, int L) {
	int i, j, start;
	start = v[x][y];
	for (i = x; i < x + L; i++) {
		for (j = y; j < y + L; j++) {
			if (v[i][j] != start) {
				cout << "(";
				ans(x, y, L / 2);
				ans(x, y + (L / 2), L / 2);
				ans(x + (L / 2), y, L / 2);
				ans(x + (L / 2), y + (L / 2), L / 2);
				cout << ")";
				return;
			}
		}
	}
	cout << start;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int i, j, N;
	cin >> N;
	v.resize(N, vector<int>(N, 0));
	for (i = 0; i < N; i++) {
		cin >> s;
		for (j = 0; j < N; j++) {
			v[i][j] = s[j] - '0';
		}
	}
	ans(0, 0, N);
}

