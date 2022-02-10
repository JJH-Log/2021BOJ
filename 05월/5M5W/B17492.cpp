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
#define MOD 10007
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<vector<int>> v;
int N;

int ans(int cnt) {
	int i, j, k, dx, dy, result;
	if (cnt == 1) return 1;
	result = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (v[i][j] == 2) {
				for (k = 0; k < 8; k++) {
					dx = "00011222"[k] - '1';
					dy = "01202012"[k] - '1';
					if (v[i + dx][j + dy] == 2 && v[i + 2 * dx][j + 2 * dy] == 0) {
						v[i][j] = 0;
						v[i + dx][j + dy] = 0;
						v[i + 2 * dx][j + 2 * dy] = 2;
						result = max(result, ans(cnt - 1));
						v[i][j] = 2;
						v[i + dx][j + dy] = 2;
						v[i + 2 * dx][j + 2 * dy] = 0;
					}
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

	int i, j, result, M;
	cin >> N;
	v.resize(N, vector<int>(N, 0));
	M = 0; result = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> v[i][j];
			if (v[i][j] == 2) M++;
		}
	}
	result = ans(M);
	if (result) cout << "Possible";
	else cout << "Impossible";
	return 0;
}