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

int v[11][11];
bool lock[11];

int solve(int idx, int total){
	if(idx == 11) return total;
	int res = 0;
	for(int i = 0; i < 11; i++){
		if(!lock[i] && v[idx][i]){
			lock[i] = true;
			res = max(res, solve(idx + 1, total + v[idx][i]));
			lock[i] = false;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while(T--){
		for(int i = 0; i < 11; i++){
			for(int j = 0; j < 11; j++) cin >> v[i][j];
		}
		cout << solve(0, 0) << '\n';
	}

	return 0;
}