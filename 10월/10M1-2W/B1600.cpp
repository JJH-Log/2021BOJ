#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <math.h>
#include <set>
#include <cassert>
#include <sstream>
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

struct info {
	int d, k, x, y;
};

struct comp {
	bool operator()(info & A, info & B){
		return A.d > B.d;
	}
};

int v[200][200];
int vtd[31][200][200];
priority_queue<info, vector<info>, comp> pq;
int K, N, M;


int dx[12] = { -1, -2, -2, -1, 1, 2, 2, 1, 1, -1, 0, 0 };
int dy[12] = { -2, -1, 1, 2, 2, 1, -1, -2, 0, 0, 1, -1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> v[i][j];
	}

	vtd[0][0][0] = 1;
	pq.push({ 1, 0, 0, 0 });

	while (!pq.empty()) {
		info now = pq.top();
		pq.pop();
		if (now.d != vtd[now.k][now.x][now.y]) continue;

		for (int i = 0; i < 8; i++) {
			int nx = now.x + "10013443"[i] - '2';
			int ny = now.y + "01344310"[i] - '2';
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && now.k < K && !v[nx][ny]) {
				if (!vtd[now.k + 1][nx][ny] || vtd[now.k + 1][nx][ny] > vtd[now.k][now.x][now.y] + 1) {
					vtd[now.k + 1][nx][ny] = vtd[now.k][now.x][now.y] + 1;
					pq.push({ vtd[now.k + 1][nx][ny] , now.k + 1, nx, ny});
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = now.x + "2011"[i] - '1';
			int ny = now.y + "1120"[i] - '1';
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && !v[nx][ny]) {
				if (!vtd[now.k][nx][ny] || vtd[now.k][nx][ny] > vtd[now.k][now.x][now.y] + 1) {
					vtd[now.k][nx][ny] = vtd[now.k][now.x][now.y] + 1;
					pq.push({ vtd[now.k][nx][ny] , now.k, nx, ny });
				}
			}
		}
	}
	int result = 1e9;
	for (int i = 0; i <= 30; i++) {
		if (vtd[i][N - 1][M - 1]) result = min(result, vtd[i][N - 1][M - 1]);
	}

	if (result == 1e9) cout << -1;
	else cout << result - 1;


	return 0;
}