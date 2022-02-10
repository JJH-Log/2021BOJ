#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#define MOD 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<int> v; //for strahler
vector<bool> c; //check for combined || 1 + 1 => 2가 된 이후 2가 들어왔을 때 3으로 만드는 것을 방지
vector<vector<int>> w;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, T;
	int K, M, P;
	int i, x, y;
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> K >> M >> P;
		v.resize(M, -1);
		w.resize(M, vector<int>(1, 0));
		c.resize(M, false);
		for (i = 0; i < P; i++) {
			cin >> x >> y;
			x--, y--;
			w[x].push_back(y);
			w[y][0]++;
		}
		for (i = 0; i < M; i++) {
			if (!w[i][0]) v[i] = 1, q.push(i);
		}
		int now, next;
		while (!q.empty()) {
			now = q.front();
			q.pop();
			for (i = 1; i < w[now].size(); i++) {
				next = w[now][i];
				if (v[next] == v[now] && !c[next]) v[next] = v[now] + 1, c[next] = true;
				else if (v[next] <= v[now]) v[next] = v[now], c[next] = false;
				w[next][0]--;
				if (!w[next][0]) q.push(next);
			}
		}
		cout << K << ' ' << v[M - 1] << '\n';
		v.clear();
		w.clear();
		c.clear();
	}
	
	return 0;
}