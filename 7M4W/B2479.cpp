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
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

map<string, pair<int, int>> m; // distance from start : idx
vector<string> v;
queue<string> q;
stack<int> st;
int N, K;

void bDFS(int X, int dist) {
	st.push(X + 1);
	if (!dist) return;
	for (int i = 0; i < K; i++) {
		string s = v[X];
		if (s[i] == '0') s.replace(i, 1, "1");
		else s.replace(i, 1, "0");
		if (m.count(s) && m[s].first == dist - 1) {
			bDFS(m[s].second, dist - 1);
			return;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, x, y;
	string s;
	cin >> N >> K;
	v.resize(N);
	for (i = 0; i < N; i++) {
		cin >> s;
		m[s] = { -1, i };
		v[i] = s;
	}
	cin >> x >> y;
	x--, y--;
	q.push(v[x]); m[v[x]] = { 0, x };
	while (!q.empty()) {
		string now = q.front();
		q.pop();
		for (i = 0; i < K; i++) {
			s = now;
			if (s[i] == '0') s.replace(i, 1, "1");
			else s.replace(i, 1, "0");
			if (m.count(s) && m[s].first == -1) m[s] = { m[now].first + 1,m[s].second }, q.push(s);
		}
	}
	if (m[v[y]].first == -1) cout << -1;
	else {
		bDFS(y, m[v[y]].first);
		while (!st.empty()) {
			cout << st.top() << ' ';
			st.pop();
		}
	}
	

	return 0;
}