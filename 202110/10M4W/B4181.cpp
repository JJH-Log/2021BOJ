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
	int x, y;
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
	int tx, ty, sz;
	char c;

	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> tx >> ty >> c;
		if (c == 'Y') v.push_back({ tx, ty });
	}
	sort(v.begin(), v.end(), cmpPos);
	base = v[0], sz = v.size();
	for (i = 0; i < v.size(); i++) v[i].x -= base.x, v[i].y -= base.y;
	sort(v.begin(), v.end(), cmpVec);

	
	cout << sz << '\n';
	for (i = 0; i < sz; i++) {
		if (i && ((lld)v[i].x * v[sz - 1].y == (lld)v[i].y * v[sz - 1].x)) break;
		cout << (v[i].x + base.x) << ' ' << (v[i].y + base.y) << '\n';
	}
	for (j = sz - 1; j >= i; j--) cout << (v[j].x + base.x) << ' ' << (v[j].y + base.y) << '\n';
		
	return 0;
}