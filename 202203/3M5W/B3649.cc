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

lld X, N;
lld v[1000000];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	
	while (true) {
		cin >> X;
		if (cin.eof()) break;
		X *= 1e7;
		cin >> N;
		for (int i = 0; i < N; i++) cin >> v[i];
		sort(v, v + N);

		int i, j;
		i = 0, j = N - 1;
		while(i < j){
			if (v[i] + v[j] > X) j--;
			else if (v[i] + v[j] < X) i++;
			else break;
		}
		if (i != j && v[i] + v[j] == X) cout << "yes " << v[i] << ' ' << v[j] << '\n';
		else cout << "danger\n";
	}

	return 0;
}