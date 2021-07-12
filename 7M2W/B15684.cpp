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
int N, M, H;

int answer(int x, int h, int moved) {
	if (h == H) return x;
	if (v[x][h] != 0 && !moved) return answer(x + v[x][h], h, 1);
	else return answer(x, h + 1, 0);
}

bool isSorted() {
	for (int i = 0; i < N; i++) {
		if (i != answer(i, 0, 0)) {
			return false;
		}
	}
	return true;
}

bool bTracking(int idx, int idh, int cnt, int mcnt) {
	int result = false;
	if (cnt == mcnt) return isSorted();
	for (int i = idx; i < N - 1; i++) {
		for (int j = 0; j < H; j++) {
			if (i == idx && j == 0) j = idh;
			if (!v[i][j] && !v[i + 1][j]) {
				v[i][j] = 1, v[i + 1][j] = -1;
				result = result || bTracking(i, j, cnt + 1, mcnt);
				v[i][j] = 0, v[i + 1][j] = 0;
			}
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, h, x;
	cin >> N >> M >> H;
	v.resize(N, vector<int>(H, 0));
	for (i = 0; i < M; i++) {
		cin >> h >> x;
		v[x - 1][h - 1] = 1;
		v[x][h - 1] = -1;
	}
	for (i = 0; i <= 3; i++) {
		if (bTracking(0, 0, 0, i)) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}