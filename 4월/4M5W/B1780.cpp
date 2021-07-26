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
map<int, int> m;

void check(int x, int y, int l) {
	int start = v[x][y];
	int i, j;
	for (i = x; i < x + l; i++) {
		for (j = y; j < y + l; j++) {
			if (v[i][j] != start) {
				check(x, y, l / 3);
				check(x + l / 3, y, l / 3);
				check(x + l / 3 * 2, y, l / 3);
				check(x, y + l / 3, l / 3);
				check(x + l / 3, y + l / 3, l / 3);
				check(x + l / 3 * 2, y + l/3, l / 3);
				check(x, y + l / 3 * 2, l / 3);
				check(x + l / 3, y + l / 3 * 2, l / 3);
				check(x + l / 3 * 2, y + l / 3 * 2, l / 3);
				return;
			}
		}
	}
	m[start]++;
	return;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, j, N;
	cin >> N;
	v.resize(N, vector<int>(N, 0));
	m[-1] = 0;
	m[0] = 0;
	m[1] = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}
	check(0, 0, N);
	cout << m[-1] << "\n" << m[0] << "\n" << m[1];
	return 0;
}

