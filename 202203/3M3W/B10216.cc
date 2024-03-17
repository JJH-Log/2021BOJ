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

struct pos{
	int x, y, r;
	bool isRange(pos X){
		return ((X.x - x) * (X.x - x) + (X.y - y) * (X.y - y) <= (r + X.r) * (r + X.r));
	}
};

int N;
pos v[3000];
int u[3000];
int res;

int find(int X){
	if(u[X] == X) return X;
	return u[X] = find(u[X]);
}

bool merge(int a, int b){
	a = find(a); b = find(b);
	if(a == b) return false;
	if(a > b) swap(a, b);
	u[b] = a;
	return true;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while(T--){
		cin >> N;
		for(int i = 0; i < N; i++) cin >> v[i].x >> v[i].y >> v[i].r;
		
		iota(u, u + N, 0);
		res = N;

		for(int i = 0; i < N; i++){
			for(int j = i + 1; j < N; j++) if(v[i].isRange(v[j])) res -= merge(i, j);
		}

		cout << res << '\n';
	}
	
	return 0;
}