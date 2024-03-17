#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

struct info {
	int X;
	int Y;
	int D;
};

vector<vector<int>> v;
vector<info> w;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, j, k, N, M;
	int x, y, d;
	int xt, yt;
	cin >> N >> M;
	v.resize(N, vector<int>(N, (int)1e9));
	for (i = 0; i < N; i++) v[i][i] = 0;
	for (i = 0; i < M; i++) {
		cin >> x >> y >> d;
		x--, y--;
		v[x][y] = min(v[x][y], d);
		v[y][x] = min(v[y][x], d);
		w.push_back({ x,y,d });
	}
	for (k = 0; k < N; k++) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
			}
		}
	}
	double result, ans;
	result = (int)1e9;
	for (k = 0; k < N; k++) {
		ans = 0;
		for (i = 0; i < w.size(); i++) {
			xt = v[k][w[i].X];
			yt = v[k][w[i].Y];
			if (xt < yt) swap(xt, yt);
			if (xt - yt >= w[i].D) ans = max(ans, (double)yt + w[i].D);
			else ans = max(ans, ((double)xt + yt + w[i].D) / 2);
		}
		result = min(result, ans);
	}
	cout << fixed;
	cout.precision(1);
	cout << result;
	return 0;
}
