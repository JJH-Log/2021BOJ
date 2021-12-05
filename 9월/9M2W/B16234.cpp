#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<vector<int>> v, w;

queue<pair<int, int>> q, q2;
int N, L, R;

bool migrate() {
	bool result = false;
	w.resize(N, vector<int>(N, 0));

	vector<vector<bool>> vtd;
	vtd.resize(N, vector<bool>(N, false));

	int x, y, dx, dy, size, total;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!vtd[i][j]) {
				total = 0;
				vtd[i][j] = true;
				q.push({ i,j });
				q2.push({ i, j });
				total += v[i][j];
				while (!q.empty()) {
					x = q.front().first;
					y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						dx = x + "2011"[k] - '1';
						dy = y + "1120"[k] - '1';
						if (dx >= 0 && dx < N && dy >= 0 && dy < N) {
							if (!vtd[dx][dy] && L <= abs(v[x][y] - v[dx][dy]) && abs(v[x][y] - v[dx][dy]) <= R) {
								vtd[dx][dy] = true;
								q.push({ dx, dy });
								q2.push({ dx, dy });
								total += v[dx][dy];
							}
						}
					}
				}
				size = q2.size();
				if (size > 1) result = true;
				while (!q2.empty()) {
					x = q2.front().first;
					y = q2.front().second;
					w[x][y] = total / size;
					q2.pop();
				}
			}
		}
	}
	return result;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L >> R;
	v.resize(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> v[i][j];
	}
	int result = 0;
	while (migrate()) {
		v = w;
		w.clear();
		result++;
	}
	cout << result;

	return 0;
}