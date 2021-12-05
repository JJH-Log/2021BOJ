#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <math.h>
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
vector<int> bp, bq;
vector<bool> vtd;
int N, M;

bool binMatch(int now) {
	vtd[now] = true;
	for (auto& next : w[now]) {
		if (bq[next] == -1 || !vtd[bq[next]] && binMatch(bq[next])) {
			bp[now] = next;
			bq[next] = now;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	bp.resize(N, -1);
	bq.resize(M, -1);
	w.resize(N);
	int t, x;
	for (int i = 0; i < N; i++) {
		cin >> t;
		for (int j = 0; j < t; j++) {
			cin >> x;
			w[i].push_back(x - 1);
		}
	}
	int result = 0;
	for (int i = 0; i < N; i++) {
		if (bp[i] == -1) {
			vtd.resize(N, false);
			result += binMatch(i);
			vtd.clear();
		}
	}
	cout << result;
	return 0;
}