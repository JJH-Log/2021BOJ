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

struct bucket{
	int s, e;
	void _right() { s++, e++; }
	void _left() { s--, e--; }
};

int N, M, Q, X, res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> Q;
	bucket now;
	now.s = 1, now.e = M;
	for(int i = 0; i < Q; i++){
		cin >> X;
		if(now.s <= X && X <= now.e) continue;
		while(X < now.s) now._left(), res++;
		while(X > now.e) now._right(), res++;
	}
	cout << res;
	
	return 0;
}