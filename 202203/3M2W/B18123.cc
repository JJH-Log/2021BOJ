#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 31
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;



set<string> s[MAXN];
vector<int> w[MAXN];
int rm;
int sz[MAXN];
int N, S;
int T = 30;

void addEdge(int x, int y) {
	w[x].push_back(y);
	w[y].push_back(x);
}

int getRm(int x, int y) {
	if (x > y) return getRm(y, x);
	return 100 * x + y;
}

int getSize(int now, int parent) {
	sz[now] = 1;
	for (auto next : w[now]) if (next != parent) sz[now] += getSize(next, now);
	return sz[now];
}

int getCentroid(int now, int parent, int cap) {
	for (auto next : w[now]) if (next != parent && sz[next] > cap) return getCentroid(next, now, cap);
	return now;
}

int checkDoubleCenter(int now, int cap) {
	int ans = -1;
	for (auto next : w[now]) if (sz[next] == cap) ans = next;
	if (ans == -1) return now;
	addEdge(now, T);
	addEdge(ans, T);
	rm = getRm(now, ans);
	return T;
}

string getTreeHash(int now, int parent) {
	string ans = "(";
	vector<string> tmp;
	for (auto next : w[now]) if (next != parent && rm != getRm(now, next)) tmp.push_back(getTreeHash(next, now));
	sort(tmp.begin(), tmp.end());
	for (auto tar : tmp) ans += tar;
	return ans + ")";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S;
		for (int j = 1; j < S; j++) {
			int x, y;
			cin >> x >> y;
			addEdge(x, y);
		}
		getSize(0, -1);
		int center = getCentroid(0, -1, S / 2);
		
		if (S % 2 == 0) center = checkDoubleCenter(center, S / 2);
		s[S].insert(getTreeHash(center, -1));
		memset(sz, 0, sizeof(sz));
		for (int i = 0; i < MAXN; i++) w[i].clear();
		rm = 0;
	}
	int res = 0;
	for (int i = 0; i < MAXN; i++) res += s[i].size();
	cout << res;

	return 0;
}