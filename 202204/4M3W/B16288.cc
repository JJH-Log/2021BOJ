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


int N, K, cnt;
int v[100];
bool used[100];
vector<int> w;
vector<int> d;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> v[i];

	while (true) {
		for (int i = 0; i < N; i++) {
			if (used[i]) continue;
			int idx = lower_bound(w.begin(), w.end(), v[i]) - w.begin();
			if (idx == w.size()) {
				w.push_back(v[i]);
				d.push_back(i);
			}
		}
		if (!w.size()) break;
		for (int i = 0; i < w.size(); i++) used[d[i]] = true;
		cnt++;
		w.clear(); d.clear();
	}
	if (cnt > K) cout << "NO";
	else cout << "YES";

	return 0;
}