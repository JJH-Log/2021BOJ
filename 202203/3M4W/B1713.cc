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

struct info {
	int num, rec, idx;
};

bool compare(info A, info B) {
	if (A.rec == B.rec) return A.idx < B.idx;
	return A.rec < B.rec;
}

int N, M, x;
info v[20];
vector<int> res;

int isOn(int tar) {
	for (int i = 0; i < N; i++) if (v[i].num == tar) return i;
	return -1;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> x;
		int ans = isOn(x);
		if (ans == -1) {
			sort(v, v + N, compare);
			v[0] = { x, 1, i };
		}
		else v[ans].rec++;
	}

	for (int i = 0; i < N; i++) if (v[i].num) res.push_back(v[i].num);
	sort(res.begin(), res.end());
	for (auto t : res) cout << t << ' ';

	return 0;
}