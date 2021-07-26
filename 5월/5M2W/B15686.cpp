#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

vector<pair<int, int>> c;
vector<pair<int, int>> h;
vector<vector<int>> dist;
vector<vector<int>> a;
int N, M, cs, hs;

int pick(int idx, int cnt) {
	int i, j, result;
	result = 1000000000;
	for (i = idx; i < cs; i++) {
		if (!cnt) { for (j = 0; j < hs; j++)  a[cnt][j] = dist[j][i]; }
		else { for (j = 0; j < hs; j++) a[cnt][j] = min(a[cnt - 1][j], dist[j][i]); }
		if (cnt == M - 1) {
			int temp = 0;
			for (j = 0; j < hs; j++) temp += a[cnt][j];
			result = min(result, temp);
		}
		else result = min(result, pick(i + 1, cnt + 1));
	}
	return result;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, temp, result;
	cin >> N >> M;
	h.resize(100, pair<int, int>());
	c.resize(13, pair<int, int>());
	cs = 0; hs = 0;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			cin >> temp;
			if (temp == 1) h[hs] = { i,j }, hs++;
			if (temp == 2) c[cs] = { i,j }, cs++;
		}
	}
	dist.resize(hs, vector<int>(cs, 50000));
	a.resize(cs, vector<int>(hs, 0));
	for (i = 0; i < hs; i++) {
		for (j = 0; j < cs; j++) {
			dist[i][j] = abs(h[i].first - c[j].first) + abs(h[i].second - c[j].second);
		}
	}
	result = pick(0, 0);
	cout << result;
	return 0;
}