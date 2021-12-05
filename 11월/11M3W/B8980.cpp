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
#include <sstream>
#define MOD 1000000009
#define BOUND 10000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

struct info {
	int s, e, c;
};

bool compare(info A, info B) {
	if (A.e == B.e) return A.s < B.s;
	else return A.e < B.e;
}

vector<info> v;
vector<int> cap;
int N, M, C;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> C >> M;
	v.resize(M);
	cap.resize(N, C);
	for (int i = 0; i < M; i++) {
		cin >> v[i].s >> v[i].e >> v[i].c;
		v[i].s--, v[i].e--;
	}
	sort(v.begin(), v.end(), compare);
	lld result = 0;
	for (int i = 0; i < M; i++) {
		int able = C;
		bool FLAG = true;
		for (int j = v[i].s; j < v[i].e; j++) able = min(able, cap[j]);
		result += min(able, v[i].c);
		for (int j = v[i].s; j < v[i].e; j++) cap[j] -= min(able, v[i].c);
	}
	cout << result;
	return 0;
}
