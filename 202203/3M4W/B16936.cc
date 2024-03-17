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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N;
lld v[100];
bool lock[100];
vector<int> w[100];
stack<int> st;

bool dfs(int now, int cnt) {
	bool res = false;
	lock[now] = 1;
	if (cnt == N - 1) {
		st.push(now);
		return true;
	}
	for (auto next : w[now]) {
		if (!lock[next]) {
			if (dfs(next, cnt + 1)) {
				st.push(now);
				return true;
			}
		}
	}
	lock[now] = 0;
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> v[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[j] % 2 == 0 && v[j] / 2 == v[i]) w[i].push_back(j);
			if (v[i] % 3 == 0 && v[i] / 3 == v[j]) w[i].push_back(j);
		}
	}

	for (int i = 0; i < N; i++) {
		if (dfs(i, 0)) {
			while (!st.empty()) {
				cout << v[st.top()] << ' ';
				st.pop();
			}
			return 0;
		}
	}


	
	return 0;
}