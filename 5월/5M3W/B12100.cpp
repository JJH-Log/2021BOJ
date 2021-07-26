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



vector<vector<int>> v;

int getMax(vector<vector<int>> T) {
	int i, j, result;
	result = 0;
	for (i = 0; i < T.size(); i++) {
		for (j = 0; j < T.size(); j++) {
			result = max(result, T[i][j]);
		}
	}
	return result;
}


vector<vector<int>> move(int dx, int dy, vector<vector<int>> T) {
	vector<vector<int>> t;
	vector<vector<int>> check;
	int i, j, k, s;
	t = T;
	s = T.size();
	check.resize(s, vector<int>(s, 1));
	if (!dy) {
		if (dx == 1) {
			for (j = 0; j < s; j++) {
				for (i = s - 1; i >= 0; i--) {
					k = i;
					while ((k + 1 != s) && (!t[k + 1][j])) { swap(t[k][j], t[k + 1][j]); k++; }
					if (k != s - 1) {
						if (t[k][j] == t[k + 1][j] && check[k+1][j]) {
							t[k][j] = 0;
							t[k + 1][j] *= 2;
							check[k + 1][j] = 0;
						}
					}
				}
			}
		}
		else {
			for (j = 0; j < s; j++) {
				for (i = 0; i < s; i++) {
					k = i;
					while ((k != 0) && (!t[k - 1][j])) { swap(t[k][j], t[k - 1][j]); k--;}
					if (k != 0) {
						if (t[k][j] == t[k - 1][j] && check[k-1][j]) {
							t[k][j] = 0;
							t[k - 1][j] *= 2;
							check[k - 1][j] = 0;
						}
					}
				}
			}
		}
	}
	else {
		if (dy == 1) {
			for (i = 0; i < s; i++) {
				for (j = s - 1; j >= 0; j--) {
					k = j;
					while ((k + 1 != s) && (!t[i][k + 1])) {swap(t[i][k], t[i][k + 1]); k++;}
					if (k != s - 1) {
						if (t[i][k] == t[i][k + 1] && check[i][k+1]) {
							t[i][k] = 0;
							t[i][k + 1] *= 2;
							check[i][k + 1] = 0;
						}
					}
				}
			}
		}
		else {
			for (i = 0; i < s; i++) {
				for (j = 0; j < s; j++) {
					k = j;
					while ((k != 0) && (!t[i][k - 1])) {swap(t[i][k], t[i][k - 1]); k--; }
					if (k != 0) {
						if (t[i][k] == t[i][k - 1] && check[i][k-1]) {
							t[i][k] = 0;
							t[i][k - 1] *= 2;
							check[i][k - 1] = 0;
						}
					}
				}
			}
		}
	}
	return t;
}


int simulate(vector<vector<int>> T, int cnt) {
	int result;
	if (cnt == 5) return getMax(T);
	result = 0;
	for (int i = 0; i < 4; i++) {
		int dx = "2011"[i] - '1';
		int dy = "1120"[i] - '1';
		result = max(result, simulate(move(dx, dy, T), cnt + 1));
	}
	return result;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N;
	cin >> N;
	v.resize(N, vector<int>(N, 0));
	for (i = 0; i < N * N; i++) cin >> v[i / N][i % N];
	cout << simulate(v, 0);
	return 0;
}
