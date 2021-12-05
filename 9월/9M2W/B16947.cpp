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

vector<vector<int>> w;
vector<int> v;
int N;

int dfs(int now, int parent) {
	int FLAG = -1;
	v[now] = 1;
	for (auto next : w[now]) {
		if (next == parent || v[next] == 0) continue;
		if (v[next] == 1) FLAG = next;
		else FLAG = max(FLAG, dfs(next, now));
	}
	if (FLAG != -1) v[now] = 0;
	if (now == FLAG) FLAG = -1;
	return FLAG;
}

void dfs2(int now, int parent) {
	for (auto next : w[now]) {
		if (next == parent || !v[next]) continue;
		v[next] = v[now] + 1;
		dfs2(next, now);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, x, y;
	cin >> N;
	w.resize(N);
	v.resize(N, -1);
	for (i = 0; i < N; i++) {
		cin >> x >> y;
		x--, y--;
		w[x].push_back(y);
		w[y].push_back(x);
	}
	dfs(0, -1);
	for (int i = 0; i < N; i++) if (!v[i]) dfs2(i, -1);
	for (int i = 0; i < N; i++) cout << v[i] << ' ';
	return 0;
}