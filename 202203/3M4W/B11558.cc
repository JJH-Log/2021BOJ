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

int N, M;
int v[10100];
bool vtd[10100];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while(T--){
		cin >> N;
		fill(vtd + 1, vtd + N + 1, 0);
		for (int i = 1; i <= N; i++) cin >> v[i];
		M = 0;
		int now = 1;

		while(M < N - 1 && now != N){
			now = v[now];
			M++;
		}
		cout << (now == N? M : 0) << '\n';
	}

	return 0;
}