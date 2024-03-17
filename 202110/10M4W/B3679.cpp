#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <math.h>
#include <set>
#include <cassert>
#include <sstream>
#define MOD 1000000
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

struct pos {
	int x, y, idx;
};

vector<pos> v;
pos base;

bool cmpPos(pos& A, pos& B) {	
	if (A.x == B.x) return A.y < B.y;
	return A.x < B.x;
}

bool cmpVec(pos& A, pos& B) {
	lld result = (lld)A.x * B.y - (lld)B.x * A.y;
	if (result == 0) return abs(A.x) + abs(A.y) < abs(B.x) + abs(B.y);
	return result > 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, i, j;
	cin >> T;
	while (T--) {
		cin >> N;
		v.resize(N);
		for (i = 0; i < N; i++) {
			cin >> v[i].x >> v[i].y;
			v[i].idx = i;
		}
		sort(v.begin(), v.end(), cmpPos);
		base = v[0];
		for (i = 0; i < N; i++) v[i].x -= base.x, v[i].y -= base.y;
		sort(v.begin(), v.end(), cmpVec);
		for (i = 0; i < N; i++) {
			if (i && ((lld)v[i].x * v[N - 1].y == (lld)v[i].y * v[N - 1].x)) break;
			cout << v[i].idx << ' ';
			//cout << v[i].x << ' ' << v[i].y << '\n';
		}
		for (j = N - 1; j >= i; j--) {
			cout << v[j].idx << ' ';
			//cout << v[j].x << ' ' << v[j].y << '\n';
		}
		cout << '\n';
		v.clear();
	}

	return 0;
}