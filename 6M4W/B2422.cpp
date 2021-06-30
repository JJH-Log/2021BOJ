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
int N, M, result;
vector<int> w;

void ans(int idx, int cnt) {
	int i, j;
	int flag;
	if (cnt == 3) {
		result++;
		return;
	}
	for (i = idx; i <= N; i++) {
		flag = 1;
		for (j = cnt - 1; j >= 0; j--) {
			if (!v[w[j]][i]) flag = 0;
		}
		if (flag) {
			w[cnt] = i;
			ans(i + 1, cnt + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, x, y;
	cin >> N >> M;
	v.resize(N + 1, vector<int>(N + 1, 1));
	w.resize(3, 0);
	for (i = 0; i < M; i++) {
		cin >> x >> y;
		v[x][y] = 0, v[y][x] = 0;
	}
	result = 0;
	ans(1, 0);
	cout << result;
	return 0;
}