#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
#include <regex>
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
	vector<int> v;
	int dist;
};

set<vector<int>> S;
int K, N, x;
bool res;
vector<int> s;
queue<info> q;

vector<int> flip(vector<int> now, int idx) {
	for (int i = 0; 2 * i < N - 1; i++) swap(now[idx + i], now[idx + N - 1 - i]);
	return now;
}

bool check(vector<int> now) {
	for (int i = 0; i < now.size(); i++) if (i + 1 != now[i]) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> x;
		s.push_back(x);
	}
	q.push({ s, 0 });

	while (!q.empty()) {
		info now = q.front(); q.pop();
		if (check(now.v)) {
			cout << now.dist;
			return 0;
		}
		vector<int> tmp;
		for (int i = 0; i < K - N + 1; i++) {
			tmp = flip(now.v, i);
			if (!S.count(tmp)) {
				S.insert(tmp);
				q.push({ tmp, now.dist + 1 });
			}
		}
	}
	cout << -1;

	return 0;
}