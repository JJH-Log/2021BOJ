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

struct info{
	int cnt, idx;
};

bool compare(info A, info B){
	if(A.cnt == B.cnt) return A.idx > B.idx;
	return A.cnt > B.cnt;
}

info v[50];
int N, res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v[i].cnt;
		v[i].idx = i;
	}
	sort(v, v + N, compare);
	while(v[0].idx){
		int tar = 0;
		for (int i = 0; i < N; i++) if(v[i].idx == 0) tar = i;
		v[0].cnt--, v[tar].cnt++, res++;
		sort(v, v + N, compare);
	}
	cout << res;


	return 0;
}