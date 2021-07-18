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
int N, L;

int isPassible(int x, int y, int dx, int dy, int flat, int diag) {
	if (!diag) flat++;
	if (diag) diag--;

	if ((dx == 1 && x == N - 1) || (dy == 1 && y == N - 1)) {
		if (!diag) return 1;
		else return 0;
	}

	if (v[x][y] == v[x + dx][y + dy]) return isPassible(x + dx, y + dy, dx, dy, flat, diag);
	else if(v[x][y] + 1 == v[x + dx][y + dy]){
		if (flat >= L && !diag) return isPassible(x + dx, y + dy, dx, dy, 0, diag);
		else return 0;
	}
	else if (v[x][y] - 1 == v[x + dx][y + dy]) {
		if (!diag) return isPassible(x + dx, y + dy, dx, dy, 0, L);
		else return 0;
	}
	else return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, result;
	cin >> N >> L;
	v.resize(N, vector<int>(N, 0));
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}
	result = 0;
	for (i = 0; i < N; i++) {
		result += isPassible(0, i, 1, 0, 0, 0);
		result += isPassible(i, 0, 0, 1, 0, 0);
	}
	cout << result;

	return 0;
}