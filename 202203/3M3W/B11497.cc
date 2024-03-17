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
#define MOD 1000
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

deque<int> dq;
int N, v[10000];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> v[i];
		sort(v, v + N);
		
		int res = 0;
		for (int i = N - 1; i >= 0; i--) {
			if (i == N - 1) dq.push_back(v[i]);
			else {
				if(dq.front() - v[i] >= dq.back() - v[i]) {
					res = max(res, dq.front() - v[i]);
					dq.push_front(v[i]);
				}
				else {
					res = max(res, dq.back() - v[i]);
					dq.push_back(v[i]);
				}
			}
		}
		res = max(res, abs(dq.front() - dq.back()));
		cout << res << '\n';
		while (!dq.empty()) dq.pop_back();
	}
	
	return 0;
}