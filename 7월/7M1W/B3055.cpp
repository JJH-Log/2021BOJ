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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, j, k, x, y, N, M, t, FLAG;
	string s;
	cin >> N >> M;
	v.resize(N, vector<int>(M, 0));
	for (i = 0; i < N; i++) {
		cin >> s;
		for (j = 0; j < M; j++) {
			if (s[j] == 'D') v[i][j] = -99;
			else if (s[j] == 'X') v[i][j] = -1;
			else if (s[j] == '*') v[i][j] = 10001;
			else if (s[j] == 'S') v[i][j] = 1;
		}
	}
	t = 1;

	while (true) {
		FLAG = 1;
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				if (v[i][j] == t) {
					FLAG = 0;
					for (k = 0; k < 4; k++) {
						x = i + "2011"[k] - '1';
						y = j + "1120"[k] - '1';
						if (x >= 0 && x < N && y >= 0 && y < M) {
							if (v[x][y] == -99) {
								cout << t;
								return 0;
							}
							if (!v[x][y]) v[x][y] = t + 1;
						}
					}
				}
			}
		}
		if (FLAG) {
			cout << "KAKTUS";
			return 0;
		}
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				if (v[i][j] == 10000 + t) {
					for (k = 0; k < 4; k++) {
						x = i + "2011"[k] - '1';
						y = j + "1120"[k] - '1';
						if (x >= 0 && x < N && y >= 0 && y < M) {
							if (v[x][y] >= 0 && v[x][y] < 10001) v[x][y] = 10001 + t;
						}
					}
				}
			}
		}
		t++;
	}
	return 0;
}