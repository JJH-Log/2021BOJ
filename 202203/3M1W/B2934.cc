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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXS 500000
#define DEAD 10000
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

/*
 #Reference: https://everenew.tistory.com/115
 [1] 펜윅트리의 구간 업데이트 
 ex) A[i] ~ A[j] 값을 k만큼 업데이트
 - 펜윅트리 B[k] = A[k] - A[k - 1] 로 정의한다.
 - 그러면 두 개의 점 업데이트로 변경 가능. 
 - update_range(A[i], A[j])  => update(B[i], k) , update(B[j + 1], -k)
 [2] 점 쿼리 구하기
  ex) A[x] 값 구하기
  - 펜윅트리 B[k] 에 대해, B[1] + B[2] + B[3]... + B[x] 를 해주면 된다.

*/


lld v[100010];
lld N, res;

void update(int x, lld k) {
	for (int i = x; i <= 100000; i += i & -i) v[i] += k;
}

void updateRange(int l, int r, lld k) {
	update(l, k);
	update(r + 1, -k);
}

lld query(int x) {
	lld ans = 0;
	for (int i = x; i > 0; i -= i & -i) ans += v[i];

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		lld ax, ay;
		cin >> x >> y;
		ax = query(x);
		ay = query(y);
		cout << ax + ay << '\n';
		updateRange(x + 1, y - 1, 1);
		updateRange(x, x, -ax);
		updateRange(y, y, -ay);
	}


	return 0;
}
