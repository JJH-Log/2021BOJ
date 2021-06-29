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

vector<map<int, int>> v; //Node | dist
vector<int> dist;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, W;
	int i, j, k, t, T;
	int x, y, d;
	int FLAG;
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> N >> M >> W;
		v.clear();
		v.resize(N + 1);
		dist.clear();
		dist.resize(N + 1, 30000000);
		for (i = 0; i < M; i++) {
			cin >> x >> y >> d;
			if (!v[x].count(y)) v[x][y] = d;
			else v[x][y] = min(v[x][y], d);
			if (!v[y].count(x)) v[y][x] = d;
			else v[y][x] = min(v[y][x], d);
		}
		for (i = 0; i < W; i++) {
			cin >> x >> y >> d;
			if (!v[x].count(y)) v[x][y] = -d;
			else v[x][y] = min(v[x][y], -d);
		}

		for (j = 1; j < N; j++) {
			for (i = 1; i <= N; i++) {
				for (auto it = v[i].begin(); it != v[i].end(); it++) {
					if (dist[it->first] > dist[i] + it->second) {
						dist[it->first] = dist[i] + it->second;
					}
				}
			}
		}
		FLAG = 1;
		for (i = 1; i <= N; i++) {
			for (auto it = v[i].begin(); it != v[i].end(); it++) {
				if (dist[it->first] > dist[i] + it->second) FLAG = 0;
			}
		}
		if (!FLAG) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}