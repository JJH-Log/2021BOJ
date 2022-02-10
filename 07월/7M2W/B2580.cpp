#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#define MOD 1000000000
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<vector<int>> v;
vector<vector<vector<bool>>> mask;
vector<vector<int>> result;

void ans(int now, int depth) {
	if (result.size() == 9) return;
	int i, j, t, k, FLAG;
	FLAG = 1;
	for (t = now; t < 81; t++) {
		i = t / 9;
		j = t % 9;
		if (v[i][j] == 0) {
			FLAG = 0;
			for (k = 0; k < 9; k++) {
				if (mask[0][i][k] && mask[1][j][k] && mask[2][(i / 3) * 3 + (j / 3)][k]) {
					mask[0][i][k] = false, mask[1][j][k] = false;
					mask[2][(i / 3) * 3 + (j / 3)][k] = false;
					v[i][j] = k + 1;
					ans(t + 1, depth + 1);
					mask[0][i][k] = true, mask[1][j][k] = true;
					mask[2][(i / 3) * 3 + (j / 3)][k] = true;
					v[i][j] = 0;
				}
			}
			return;
		}
	}
	if(FLAG) result = v;
	//cout << "DEPTH : " << depth << endl;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	v.resize(9, vector<int>(9, 0));
	mask.resize(3, vector<vector<bool>>(9, vector<bool>(9, true)));

	int i, j;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			cin >> v[i][j];
			if (v[i][j]) {
				mask[0][i][v[i][j] - 1] = false;
				mask[1][j][v[i][j] - 1] = false;
				mask[2][(i / 3) * 3 + (j / 3)][v[i][j] - 1] = false;
			}
		}
	}
	ans(0, 0);
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) cout << result[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}