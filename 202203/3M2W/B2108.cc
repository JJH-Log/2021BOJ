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
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N;
int v[500000];
int cnt[10000];
lld total;

int f1() { return round((double)total / N); }

int f2() { return v[N / 2]; } //after sort

int f3() {
	vector<int> ans;
	int tmp = 0;
	for (int i = 0; i < 10000; i++) {
		if (cnt[i]) {
			if (cnt[i] > tmp) {
				tmp = cnt[i];
				ans.clear();
				ans.push_back(i - 5000);
			}
			else if (cnt[i] == tmp) ans.push_back(i - 5000);
		}
	}
	sort(ans.begin(), ans.end());
	if (ans.size() == 1) return ans[0];
	return ans[1];
}

int f4() {
	int M =-5000;
	int m = 5000;
	for (int i = 0; i < 10000; i++) {
		if (cnt[i]) {
			M = max(M, i - 5000);
			m = min(m, i - 5000);
		}
	}
	return (M - m);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		cnt[v[i] + 5000]++;
		total += v[i];
	}
	sort(v, v + N);
	cout << f1() << '\n' << f2() << '\n' << f3() << '\n' << f4();

	return 0;
}