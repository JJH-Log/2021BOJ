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
#define MOD 14579
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int K, N;
int v[50];
int gap, before, M, m;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> K;
	for (int t = 1; t <= K; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> v[i];
		sort(v, v + N);
		m = M = before = v[0];
		gap = 0;
		for (int i = 1; i < N; i++) {
			m = min(m, v[i]);
			M = max(M, v[i]);
			gap = max(gap, v[i] - v[i - 1]);
		}

		cout << "Class " << t << '\n';
		cout << "Max " << M << ", Min " << m << ", Largest gap " << gap << "\n";
	}
	
	return 0;
}
