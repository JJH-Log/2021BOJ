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


vector<vector<pair<int,int>>> v;
vector<pair<int, int>> w;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, L;
	int i, x, y, t, wc;
	int nx, ny, nd, tx, ty, td;
	char c;
	pair<int, int> head;
	pair<int, int> tail;
	cin >> N >> K;
	v.resize(N, vector<pair<int,int>>(N, { 0, 0 }));
	for (i = 0; i < K; i++) {
		cin >> x >> y;
		v[x - 1][y - 1].first = 1;
	}
	cin >> L;
	for (i = 0; i < L; i++) {
		cin >> x >> c;
		w.push_back({ x, (int)c });
	}
	w.push_back({ -1, -1 });
	v[0][0] = { 2, 1 }; //0: N, 1: E, 2: S, 3: W
	head = { 0, 0 };
	tail = { 0, 0 };
	t = 0; wc = 0;
	while (true) {
		nx = head.first;
		ny = head.second;
		if (w[wc].first == t) {
			if (w[wc].second == (int)'L') v[nx][ny].second = (v[nx][ny].second + 3) % 4;
			else v[nx][ny].second = (v[nx][ny].second + 1) % 4;
			wc++;
		}
		nd = v[nx][ny].second;
		nx += "0121"[nd] - '1';
		ny += "1210"[nd] - '1';
		//cout << "nx , ny : " << nx << ' ' << ny << endl;
		t++;
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;
		if (v[nx][ny].first == 2) break;
		if (v[nx][ny].first == 0) {
			tx = tail.first;
			ty = tail.second;
			td = v[tx][ty].second;
			v[tx][ty] = { 0, 0 };
			tail = { tx + "0121"[td] - '1', ty + "1210"[td] - '1'};
		}
		//else cout << "APPLE!" << endl;
		v[nx][ny] = { 2, nd };
		head = { nx , ny };
	}
	cout << t;
	return 0;
}