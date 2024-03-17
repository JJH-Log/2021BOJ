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
vector<vector<int>> w;
int N, M;

void meltDown() { //record at w
	w = v;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j]) {
				for (int k = 0; k < 4; k++) {
					int dx = i + "1120"[k] - '1';
					int dy = j + "2011"[k] - '1';
					if (!v[dx][dy]) w[i][j]--;
				}
				if (w[i][j] < 0) w[i][j] = 0;
			}
		}
	}
	return;
}

bool isAllZero() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j]) return false;
		}
	}
	return true;
}

bool isConnected() {
	w = v;
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (w[i][j]) w[i][j] = 0, q.push({ i,j }), i = N, j = M;
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = x + "1120"[i] - '1';
			int dy = y + "2011"[i] - '1';
			if (w[dx][dy]) {
				w[dx][dy] = 0;
				q.push({ dx, dy });
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (w[i][j]) return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;
	cin >> N >> M;
	v.resize(N, vector<int>(M, 0));
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> v[i][j];
		}
	}
	int result = 0;
	while (true) {
		if (isAllZero()) {
			result = 0;
			break;
		}
		if(!isConnected()) break;
		meltDown();
		v = w;
		result++;
	}
	cout << result;
	return 0;
}