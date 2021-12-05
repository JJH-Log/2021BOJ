#define _CRT_SECURE_NO_WARNINGS
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
#include <cassert>
#include <sstream>
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

struct info {
	int x, y, d;
};

bool compare(info& A, info& B) {
	return A.d < B.d;
}

vector<info> v;
vector<vector<bool>> w;
vector<int> dn;
stack<int> s;
int N, dfsn;

int dfs(int now) {
	dn[now] = ++dfsn;
	s.push(now);
	int FLAG = dn[now];
	for (int i = 0; i < N; i++) {
		if (w[now][i]) {
			if (!dn[i]) FLAG = min(FLAG, dfs(i));
			else FLAG = min(FLAG, dn[i]);
		}
	}
	if (FLAG == dn[now]) {
		while (true) {
			int t = s.top();
			dn[t] = dn[now];
			s.pop();
			if (t == now) break;
		}
	}
	return FLAG;
}

bool check() {
	bool result = true;
	dn.resize(N, 0);
	dfsn = 0;
	dfs(0);
	for (int i = 0; i < N; i++) if (dn[i] != 1) result = false;
	dn.clear();
	return result;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, t;
	cin >> N;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> t;
			if (i != j) v.push_back({ i, j, t });
		}
	}
	if (N == 1) {
		cout << 0;
		return 0;
	}
	int l, r, result;
	sort(v.begin(), v.end(), compare);
	result = 1000000;

	w.resize(N, vector<bool>(N, false));
	l = r = 0;
	w[v[l].x][v[l].y] = true;
	r++;
	while (r != N * N - N) {
		if (!check()) w[v[r].x][v[r].y] = true, r++;
		else {
			result = min(result, v[r - 1].d - v[l].d);
			w[v[l].x][v[l].y] = false, l++;
		}
	}
	if(check()) result = min(result, v[r - 1].d - v[l].d);
	cout << result;

	return 0;
}