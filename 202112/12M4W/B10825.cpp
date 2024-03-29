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
#define MOD 10007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

struct info{
	string n;
	int k, e, m;
	bool operator < (const info& X) const {
		if (k == X.k) {
			if (e == X.e) {
				if (m == X.m) return n < X.n;
				return m > X.m;
			}
			return e < X.e;
		}
		return k > X.k;
	}
};

vector<info> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) cin >> v[i].n >> v[i].k >> v[i].e >> v[i].m;
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) cout << v[i].n << '\n';


	return 0;
}
