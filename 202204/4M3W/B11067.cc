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
#include <string.h>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#include <numeric>
#define MOD 998244353
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct pos {
	int x, y;
};

bool compare(pos a, pos b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

int T, N, M;
pos v[100000];
pos res[100001];
int tar[100000];
stack<pos> st;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> v[i].x >> v[i].y;
		sort(v, v + N, compare);
		cin >> M;
		for (int i = 0; i < M; i++) cin >> tar[i];
		pos before = {-1, 0};
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (v[i].x == before.x) {
				++cnt;
				res[cnt] = v[i];
				before = v[i];
			}
			else {
				while (v[i].y != before.y) st.push(v[i++]);
				st.push(v[i]);
				while (!st.empty()) {
					pos now = st.top(); st.pop();
					++cnt;
					res[cnt] = now;
					before = now;
				}
			}
		}
		for (int i = 0; i < M; i++) cout << res[tar[i]].x << ' ' << res[tar[i]].y << '\n';
	}


	return 0;
}