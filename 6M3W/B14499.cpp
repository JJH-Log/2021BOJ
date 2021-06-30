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
#define MOD 1000000007
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;


vector<vector<int>> v;
vector<int> w; //t, b, n, e, s, w

void roll(int T) {
	int temp;
	temp = w[0];
	if (T == 1) { w[0] = w[5]; w[5] = w[1]; w[1] = w[3]; w[3] = temp; }
	if (T == 2) { w[0] = w[3]; w[3] = w[1]; w[1] = w[5]; w[5] = temp; }
	if (T == 3) { w[0] = w[4]; w[4] = w[1]; w[1] = w[2]; w[2] = temp; }
	if (T == 4) { w[0] = w[2]; w[2] = w[1]; w[1] = w[4]; w[4] = temp; }
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	int x, y, k;
	int dx, dy;
	int i, j;
	cin >> N >> M >> x >> y >> K;
	v.resize(N, vector<int>(M, 0));
	w.resize(6, 0);
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) cin >> v[i][j];
	}
	for (i = 0; i < K; i++) {
		cin >> k;
		dx = "01102"[k] - '1';
		dy = "02011"[k] - '1';
		x += dx;
		y += dy;
		if (x >= 0 && x < N && y >= 0 && y < M) {
			roll(k);
			cout << w[0] << '\n';
			if (v[x][y]) w[1] = v[x][y], v[x][y] = 0;
			else v[x][y] = w[1];
		}
		else {
			x -= dx;
			y -= dy;
		}
	}


	return 0;
}