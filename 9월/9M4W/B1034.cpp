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

vector<map<string, int>> v;
int N, M, K;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
	int cnt;
	cin >> N >> M;
	v.resize(M + 1);
	for (int i = 0; i < N; i++) {
		cin >> s;
		cnt = 0;
		for (int j = 0; j < M; j++) if (s[j] == '0') cnt++;
		if (!v[cnt].count(s)) v[cnt][s] = 1;
		else v[cnt][s]++;
	}
	cin >> K;

	int now;
	if (K % 2) now = min(K, 49);
	else now = min(K, 50);

	int result = 0;
	for (; now >= 0; now -= 2) {
		if (now > M) continue;
		for (auto it = v[now].begin(); it != v[now].end(); it++) result = max(result, it->second);
	}
	cout << result;

	return 0;
}