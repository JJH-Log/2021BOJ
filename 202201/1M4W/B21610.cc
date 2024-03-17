#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#define MOD 10007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int N, M;
int v[50][50];
int c[50][50];

struct magician {
	pii dir[8] = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };
	pii diag[4] = { {-1, 1}, {1, -1}, {1, 1}, {-1, -1} };

	void moveCloud(int d, int s) {
		int t[50][50];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int x = (i + dir[d].first * s + 100 * N) % N;
				int y = (j + dir[d].second * s + 100 * N) % N;
				t[x][y] = c[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) c[i][j] = t[i][j];
		}
	}

	void doRain() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) if (c[i][j]) v[i][j]++;
		}
	}

	void copyWater() {
		int t[50][50];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				t[i][j] = 0;
				if (c[i][j]) {
					for (int k = 0; k < 4; k++) {
						int x = i + diag[k].first;
						int y = j + diag[k].second;
						if (x >= 0 && x < N && y >= 0 && y < N && v[x][y]) t[i][j]++;
					}
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) v[i][j] += t[i][j];
		}
	}

	void makeCloud() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (c[i][j]) c[i][j] = 0;
				else if (v[i][j] >= 2) c[i][j] = 1, v[i][j] -= 2;
			}
		}
	}

} *Shark;




int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Shark = new magician();
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> v[i][j];
	}
	int d, s;
	c[N - 2][0] = c[N - 2][1] = c[N - 1][0] = c[N - 1][1] = 1;
	
	for (int i = 0; i < M; i++) {
		cin >> d >> s;
		Shark->moveCloud(d - 1, s);
		Shark->doRain();
		Shark->copyWater();
		Shark->makeCloud();
	}
	lld result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) result += v[i][j];
	}
	cout << result;

	return 0;
}