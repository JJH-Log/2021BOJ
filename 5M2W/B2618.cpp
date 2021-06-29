#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

int dist(pair<short, short> A, pair<short, short> B) {
	return abs(A.first - B.first) + abs(A.second - B.second);
}

vector<vector<pair<short, int>>> v; //<이전 인덱스 , 누적 합>
vector<pair<short, short>> p; //pos

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, k, d, W, N, x, y, result;
	cin >> N >> W;
	v.resize(W + 1, vector<pair<short, int>>(W + 1, { 0, 2e9 }));
	p.resize(W + 1, { 0,0 });
	for (i = 1; i <= W; i++) {
		cin >> x >> y;
		p[i] = make_pair(x, y);
	}

	v[0][0] = { 0, 0 };
	for (i = 1; i <= W; i++) {
		p[0] = { 1,1 };
		for (j = 0; j < i; j++) {
			if (j == i - 1 && i != 1) {
				for (k = 2; i - k >= 0; k++) {
					d = dist(p[i], p[i - k]);
					if (v[i][j].second > v[i - k][j].second + d) {
						v[i][j].first = i - k;
						v[i][j].second = v[i - k][j].second + d;
					}
				}
			}
			else {
				v[i][j].first = i - 1;
				v[i][j].second = v[i - 1][j].second + dist(p[i], p[i - 1]);
			}
		}
		p[0] = { N, N };
		for (j = 0; j < i; j++) {
			if (j == i - 1 && i != 1) {
				for (k = 2; i - k >= 0; k++) {
					d = dist(p[i], p[i - k]);
					if (v[j][i].second > v[j][i - k].second + d) {
						v[j][i].first = i - k;
						v[j][i].second = v[j][i - k].second + d;
					}
				}
			}
			else {
				v[j][i].first = i - 1;
				v[j][i].second = v[j][i - 1].second + dist(p[i], p[i - 1]);
			}
		}
	}

	result = 2e9;
	for (i = 0; i < W; i++) {
		if (v[W][i].second < result) {
			result = v[W][i].second;
			x = W, y = i;
		}
		if (v[i][W].second < result) {
			result = v[i][W].second;
			x = i, y = W;
		}
	}
	int trace = W;
	int trp;
	string ans = "";
	while (true) {
		if (x == 0 && y == 0) break;
		trp = v[x][y].first;
		if (x > y) {
			ans += "1";
			trace--;
			if (trp == trace) x = trace;
			else {
				while (trp != trace - 1) {
					ans += "2";
					trace--;
				}
				x=trp , y=trace;
			}
		}
		else {
			ans += "2";
			trace--;
			if (trp == trace) y = trace;
			else {
				while (trp != trace - 1) {
					ans += "1";
					trace--;
				}
				x = trace, y = trp;
			}
		}
	}
	reverse(ans.begin(), ans.end());
	cout << result << '\n';
	for (i = 0; i < W; i++) cout << ans[i] << '\n';
	return 0;
}