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


vector<int> w[3200];
bool vtd[3200];
int bp[3200], bq[3200];
int v[80][80];
string s[80];
int N, M, oi, ei, result;

int mx[6] = { -1, -1, 0, 0, 1, 1 };
int my[6] = { -1, 1, -1, 1, -1, 1 };

void init() {
	oi = ei = result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (s[i][j] == 'x') v[i][j] = -1;
			else v[i][j] = j % 2 ? oi++ : ei++;
		}
	}
	fill(bp, bp + ei, -1);
	fill(bq, bq + oi, -1);
}

bool inRange(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < M;
}

void connect() {
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < M; j+=2) { //only even
			if (s[i][j] != 'x') {
				for (int k = 0; k < 6; k++) {
					int dx = i + mx[k];
					int dy = j + my[k];
					if (inRange(dx, dy) && s[dx][dy] != 'x') w[v[i][j]].push_back(v[dx][dy]);
				}
			}
		}
	}
}

bool binMatch(int now) {
	vtd[now] = true;
	for (auto tar : w[now]) {
		if (bq[tar] == -1 || !vtd[bq[tar]] && binMatch(bq[tar])) {
			bp[now] = tar;
			bq[tar] = now;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) cin >> s[i];
		init();
		connect();
		for (int i = 0; i < ei; i++) {
			fill(vtd, vtd + ei, 0);
			result += binMatch(i);
		}
		cout << ei + oi - result << '\n';
		for (int i = 0; i < ei; i++) w[i].clear();
	}

	return 0;
}
