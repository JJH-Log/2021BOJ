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

vector<int> p;
int N, v[100];
int cnt[78498];

void parse(int X) {
	for (int i = 0; X > 1 && i < 78498; i++) {
		while (X % p[i] == 0) {
			cnt[i]++;
			X /= p[i];
		}
	}
}

int counts(int div, int tar) {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int now = v[i];
		int cnt = 0;
		while (now % div == 0) {
			now /= div;
			cnt++;
		}
		if (tar - cnt > 0) ans += (tar - cnt);
	}
	return ans;
}


vector<int> getPrime(int bound) {
	vector<int> prime;
	prime.push_back(2);
	for (int i = 3; i <= bound; i += 2) {
		bool ans = true;
		for (int j = 0; ans && prime[j] <= sqrt(i); j++) {
			if (i % prime[j] == 0) ans = false;
		}
		if (ans) prime.push_back(i);
	}
	return prime;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	p = getPrime(1000000);
	cin >> N;
	int result, ans;
	result = 1, ans = 0;
	for (int i = 0; i < N; i++) cin >> v[i];
	for (int i = 0; i < N; i++) parse(v[i]);
	for (int i = 0; i < 78498; i++) {
		if (cnt[i] >= N) {
			int tar = cnt[i] / N;
			for (int j = 0; j < tar; j++) result *= p[i];
			ans += counts(p[i], tar);
		}
	}
	cout << result << ' ' << ans;
	return 0;
}
