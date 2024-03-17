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

int res, N, M;
string s;
char c[1000][1000];
vector<string> v;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) c[i][j] = s[j];
	}
	for (int j = 0; j < M; j++) {
		s = "";
		for (int i = 0; i < N; i++) s += c[i][j];
		reverse(s.begin(), s.end());
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size() - 1; i++) {
		int cnt = 0;
		while (v[i][cnt] == v[i + 1][cnt]) cnt++;
		res = max(res, cnt);
	}
	cout << N - res - 1;

	return 0;
}
