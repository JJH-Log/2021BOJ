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

vector<pair<int, int>> v;
vector<vector<bool>> w;

pair<int, int> curvedPos(int bx, int by, int x, int y) {
	int tx = x - bx;
	int ty = y - by;
	return { ty + bx, tx - by };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y, bx, by, d, i, j, n, N, g, G, cnt;
	w.resize(101, vector<bool>(101, false));
	cin >> N;
	for (n = 0; n < N; n++) {
		cin >> x >> y >> d >> G;
		v.push_back({ x, y });
		v.push_back({ x + "2101"[d] - '1' , y + "1012"[d] - '1' });
		cnt = 2;
		for (g = 0; g < G; g++) {
			bx = v[cnt - 1].first;
			by = v[cnt - 1].second;
			for (i = cnt - 2; i >= 0; i--) {
				x = v[i].first;
				y = v[i].second;
				v.push_back(curvedPos(bx, -by, x, -y));
				cnt++;
			}
		}
		for (i = 0; i < cnt; i++) {
			x = v[i].first, y = v[i].second;
			if (x >= 0 && x <= 100 && y >= 0 && y <= 100) w[x][y] = true;
		}
		v.clear();
	}
	int result = 0;
	for (i = 0; i < 100; i++) {
		for (j = 0; j < 100; j++) {
			if (w[i][j] && w[i + 1][j] && w[i][j + 1] && w[i + 1][j + 1]) result++;
		}
	}
	cout << result;
	return 0;
}